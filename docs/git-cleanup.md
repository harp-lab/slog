# Git history cleanup: purging committed build artifacts

*Diagnosed 2026-07-12. **Not yet done** — deferred to a good time (it rewrites
history and needs a coordinated force-push to the shared `harp-lab/slog`
remote). This note is the recipe for when we do it.*

## The problem

`.git` is ~479 MB (pack 477 MB) for a repo whose real source is ~20 MB. The
bloat is **compiled build artifacts that were committed and later removed** but
still live in every commit's history:

| path | uncompressed in history | in current HEAD |
|---|---|---|
| `build/*.so` (compiled daemons, e.g. `build/685e854b.so` = 35 MB) | **3,226 MiB** / 2,614 blobs | 0 |
| `out/` | (part of the 99.4%) | 0 |
| `data/` | (part of the 99.4%) | 0 |
| `daemon/slogd` (compiled daemon binary) | ~2 MB across versions | 0 |
| **everything else** (compiler, daemon *source*, tests, docs, examples) | **~20 MiB** | tracked |

**99.4% of all blob content is `build`/`out`/`data`.** They were added around
commits `0b3345a` / `85d3c2d` and removed in `8c2dda5` ("merged and cleaned up
added gitignore"). All three are now in `.gitignore` (`build/*`, `out/*`,
`data/*`, plus `*.so`/`*.o`/`*.zo` and `slogd`), so nothing new is being tracked
— the waste is purely historical.

Note: a plain `git gc`/`repack` will **not** help — the blobs are still
reachable through old commits. Only rewriting history drops them.

Expected result after cleanup: pack shrinks from **477 MB to roughly 5–10 MB**.

## Recommended recipe (`git-filter-repo`)

`git-filter-repo` is the modern, fast, safe tool (single Python script). It is
**not currently installed**; install first:

```sh
pip install git-filter-repo         # or: apt install git-filter-repo
                                     # or: download the one-file script from
                                     # https://github.com/newren/git-filter-repo
git filter-repo --version           # confirm it's on PATH
```

filter-repo insists on a fresh clone (it aborts otherwise). Work on a throwaway
clone so the live checkout is never at risk:

```sh
# 1. fresh mirror-ish clone of the current remote
git clone git@github.com:harp-lab/slog.git slog-clean
cd slog-clean

# 2. strip the artifact paths from ALL history + all branches/tags.
#    --path matches an exact file OR a directory prefix, so
#    `--path daemon/slogd` removes ONLY the binary, never daemon/slogd.cpp/.rkt/.h.
git filter-repo \
  --path build --path out --path data \
  --path daemon/slogd --path daemon/slogd.cpp.old \
  --invert-paths

# 3. reclaim space
git reflog expire --expire=now --all
git gc --prune=now --aggressive
du -sh .git          # expect ~5-10 MB

# 4. sanity: HEAD tree unchanged, artifacts gone from history
git ls-files build out data | wc -l          # -> 0
git log --oneline | wc -l                     # -> 74 (same commits, new SHAs)
git rev-list --objects --all | git cat-file \
  --batch-check='%(objecttype) %(objectname) %(objectsize) %(rest)' \
  | awk '/^blob/{t+=$3} END{printf "%.1f MiB\n", t/1048576}'   # -> ~20 MiB
```

filter-repo removes the `origin` remote by design (to stop an accidental push).
When you and any collaborators are ready:

```sh
git remote add origin git@github.com:harp-lab/slog.git
git push --force --all origin
git push --force --tags origin
```

## Before force-pushing — the coordination cost

Rewriting history changes **every commit SHA from the first artifact commit
onward**. Consequences on the shared `harp-lab/slog` remote:

- Every existing clone diverges. Collaborators must **re-clone**, or on a clean
  checkout `git fetch && git reset --hard origin/master` (any unpushed local
  work must be `git rebase --onto` / cherry-picked across, keyed by patch not
  SHA — old SHAs are gone).
- Open PRs against old SHAs will need rebasing.
- Tags/release refs (if any) move; re-point anything that pins a SHA.

Pick a quiet window, tell the team, and ideally have everyone push/land their
work first. Keep the pre-rewrite state recoverable: the old remote history
survives in collaborators' reflogs for a while, and you can keep a bare backup
(`git clone --mirror` of the current remote) before the force-push.

## Alternatives

- **BFG Repo-Cleaner** — `bfg --delete-folders '{build,out,data}'` then the same
  reflog-expire + gc. Faster on huge repos, needs Java. filter-repo is fine at
  this scale.
- **`git filter-branch`** (built-in, no install, but slow and error-prone):
  `git filter-branch --index-filter 'git rm -r --cached --ignore-unmatch build out data daemon/slogd' --prune-empty --tag-name-filter cat -- --all` then reflog-expire + gc. Only if you can't install filter-repo.
