# N0 seam map: where flat names live today

2026-07-15. **Scouting inventory for the N0 qualified-name substrate**
([modules.md](modules.md) §8, §10 N0; [roadmap.md](roadmap.md) W1). A
verified file:line work-map of every seam where relation/struct/type
names are created, compared, split, concatenated, mangled, or
serialized. Line numbers are as of this date and will drift; the seam
structure is the durable content.

Headline: there is **no functional dotted-name support** in the
compiler or runtime today — names are flat Racket symbols end-to-end.
The only dot tolerance is in the persistence layer (§7, §8). The binary
`.` operator in the expression grammar is dormant in practice and is the
**tightest-binding** binary operator (modules.md §8.1's "low-precedence"
was imprecise; corrected there).

## Seam 1 — Lexer & parser (`compiler/lexer.rkt`, `compiler/parser.rkt`)

- Identifier rule (lexer 80–82): `[A-Za-z0-9_]` then `[A-Za-z0-9_']*` —
  no dots. `.` is not in the operator-lexeme exclusion set (89–107), so
  a `.` between alphanumerics lexes as a standalone single-char `op`
  token. Verified subtlety: consecutive punctuation lexes greedily, so
  `...` (the sequence-pattern ellipsis, parser 397) is ONE token while
  `a.b.c` is five — a name-path parser can consume single `.` tokens
  without colliding with `...`.
- Operator table (parser 388–401): `(bin ".")` is the last entry =
  tightest-binding. A clause head like `(model.value x)` parses via the
  operator into a nested `syn` form whose operator slot is not a symbol,
  so every downstream `(? symbol? name)` match fails — this is *why*
  dotted names are unusable today, and why N0 adds explicit `id(.id)+`
  name-path parsing in name positions rather than widening the id regex.
- Experimental `import`/`export ... as ...` (313–320): parsed but dead —
  no module-system consumer.
- N0 changes: name-path production in name positions only;
  expression-context `.` untouched. Low byte-identity risk: no real
  program uses dotted names today.

## Seam 2 — Module resolver & program tuples (`compiler/modules.rkt`)

- Include dedup/set-union: `program-merge-include` (95), dedup by
  canonical path via `seen-inc` (99–100, 135); `program-merge-run`
  appends prereqs (88–90). This is what N1's occurrence tree replaces.
- Positional program tuples (the struct-ification target, coordinated
  with RF1): `(program reqs mods)` (88–95); 4-field after
  `lift-type-envs` (738); `(program type-env mods decomps)` after
  `linearize-programs` (793); 5-field after `thread-manifests` (840),
  predicate at `ir-stack.rkt:64–66`.
- Qualification-pass insertion point (modules.md §8.2): between
  `include-module` (63/97) and `organize-module` (400) /
  `lift-type-envs` (681).
- Type-env construction and merge (raw symbol keys): `unify-type-envs`
  183–231, `base-type-env` 250–303, `organize-module`/`extract-type-env`
  400–628.
- Generated names minted here: `$oracle$~a` (247–248); `_lat_…`
  (389–393, deterministic); anonymous `union` gensym (405); `_list_~a`
  (428); `_map_~a_~a` (447); decomposition `R_has`/`R_at` synthesis with
  regex `^(.+)_(has|at)$` (770, 764–787); `demand-ans-name` uses
  (526/555/557); reserved-name gate `check-not-reserved!` (470–479).
- Manifest builder `update-manifest` (801–835): `(rel name arity)` /
  `(struct name arity+1)` / `(lat name arity spec)` keyed by symbol.
- Risk: the generated-name concatenations (`~a_ans`, `_list_~a`, …) are
  where modules.md §2.2's "`a.bc.r` vs `ab.c.r` must never collide"
  bites — they must derive from the *encoded* owner symbol
  (`qname-derive`), never raw dotted text.

## Seam 3 — Type environments & extraction (`compiler/ir-shared.rkt`, `compiler/type-system.rkt`)

- `ir-shared.rkt`: explicit invariant "variables (and relation names)
  are plain symbols" (105–107); type env = 3 symbol-keyed hashes
  (aliases/rels/funs, 156–173); `rule-location-string` = basename:line
  (60–65); lattice/listof/mapof specs carry member/element type names
  verbatim (201–280).
- `type-system.rkt`: the residual-`any` check interns a
  `malformed_deduction` struct embedding the relation display name AS AN
  INTERNED STRING (523) — a relation name that is runtime *content*, so
  a spelling change churns goldens and the daemon signature (Seam 8).
  `$seq_at/$seq_atr` name test at 426.

## Seam 4 — Generated/internal `$`- and `_`-prefix conventions

| convention | minted at | prefix-tested at |
|---|---|---|
| `$oracle$<name>` | modules.rkt:248 | rel-env lookup |
| `$sup<fnv>x<line>x<col>x<alt>x<stage>` | demand.rkt:715–722 | demand.rkt:1089, emit-cpp.rkt:895 (`"$"` prefix) |
| `$seq_at/atr/posdem/pos` | seq-expand.rkt:73,80,164–197 | compile.rkt:181,343,852; operationalization.rkt:190,200–201; type-system.rkt:426; emit-cpp.rkt:433; daemon/operators.h:913–936; daemon/database.h:3148 |
| `$sq*` gensym locals | seq-expand.rkt:335–752 | (variables; escaped later) |
| `$stat_fixpoint/fires/size` | daemon/database.h:4183–4211 | database.h:4208,5163 (`rfind("$stat_",0)`); session.rkt:487 |
| `<R>_ans` (demand answers) | demand.rkt:71–72 | emit-cpp.rkt:894 (`_ans$` regex) |
| `<R>_has` / `<R>_at` | modules.rkt:764–787 | regex at 770 |
| `_lat…/_list_…/_map_…/_union_<members…>` | modules.rkt:389–447 (union gensym → deterministic, RF1 slice 0) | rel-env membership |
| `latchk_<n>`, `temp[<flavor>]<level>x<n>` | operationalization.rkt:959–961; join-planning.rkt fresh-temp! (RF1 slice 0) | (latchk bypasses `esc`; temps normalized as `temp[A-Za-z0-9]+` by tests/stats-tests.sh) |
| `v_<var>` refs, `const<sha24>` globals | emit-cpp.rkt:48–53,71; operationalization.rkt:294–298 | canonicalize-vrefs 70–84 |

Per modules.md §10 N5.2 these prefixes migrate *deliberately after*
namespace policy exists — N0 leaves them intact and only ensures the
QName mangler cannot accidentally produce a colliding shape.

## Seam 5 — C++ codegen & mangling (`compiler/emit-cpp.rkt`, `compiler/utils.rkt`)

- The mangler: `escape-id-for-C` (utils.rkt:65–81) doubles `_`,
  hex-encodes non-alnum as `_0XXXX`. Applied today only to VARIABLES and
  prim names (operationalization.rkt:833), NOT relation names.
- Relation names reach C++ as verbatim STRING LITERALS
  (`db->getRelation("~a")`: emit-cpp.rkt 201, 206, 335–339, 433, 438,
  472–477, 960–983, 1007; `rel-name-tokens` 1286–1287) — the daemon name
  equals the symbol's printed form; dots are legal in a C string.
- The `v_` collision trap (emit-cpp.rkt:61–84; warned compile.rkt:
  108–114): daemon names matching `\bv_[A-Za-z0-9_]+` are protected in
  `keep-names`; a QName encoding must never produce that shape.
- Content-addressed TU text: `content-hash` (96–99) sha256s the emitted
  C++ (names verbatim) → per-`.o` cache key. Rule-location strings baked
  into error emits (131–137).

## Seam 6 — Wire protocol & session (`compiler/actions.rkt`, `compiler/session.rkt`)

- Protocol shape: one line per message = a plugin `.so` path; names
  travel INSIDE compiled plugins as C++ literals, plus daemon→client
  reply s-expressions.
- actions.rkt bakes names into C++ literals across the action set
  (60–624); only begin-segment/keyed, inject-version, set-evaluation
  route through `escape-c-string-literal` (308–329). Reply builders emit
  names as s-expr tokens (`relation_size` 595, `schema-rel` 616–622,
  `found` 371/388, `countrow` 562/571, `inputledger` 505–511, `sig`
  584). Action `.so` cache key = sha256(src + header fingerprint)
  (641–648) — names verbatim in `src`.
- session.rkt: `session-schema-manifest` (764–773) round-trips the
  `(schema)` action; `session-rename!`/`session-drop!` (782–805)
  normalize names to symbols for recipe steps. N2 demotes the manifest
  to the codegen-ABI view behind a `session-catalog`.
- Reply-parse tolerance: `schema-rel` name = `[^ ]+` (runslog.rkt:157);
  space-delimited parsers break on spaces/parens, not dots — general
  components need the wire codec.

## Seam 7 — Persistence (`compiler/dbmeta.rkt`, `compiler/runslog.rkt`, `compiler/freeze.rkt`)

- dbmeta.rkt recipe/edit grammar (364–405): names are symbols in
  rename/drop/inject/add/del/batch/overlay; import-delta/link carry
  name-pair maps (383–385); `signature` file keyed by name symbol
  (528–551); META is a forward-compatible symbol→value hash — the N4
  `catalog` key lands there.
- runslog.rkt: `db-manifest-from-name` regex
  `^table\.(.+)\.arity\.([0-9]+)$` (116–141) splits on the LAST
  `.arity.` — dotted names already round-trip; `segment-write-set`
  (204–217) same split.
- freeze.rkt frozen-fact streams embed names as symbols/text (130–212).

## Seam 8 — Daemon (`daemon/database.h`, `daemon.h`, `operators.h`)

- All name storage is flat `std::string`: `Relation::name` (158, 2036),
  `relations` map (2285/3007), `rel_bindings` (2292/3006),
  `bind_versions` (2339), `planned_version_keys` (2982); rename/drop
  mutate by string (3110–3132).
- Struct identity: `struct_id_max++` monotone allocator (`addStruct`
  3040–3047; modules.md §6.3 wants lowest-free bitmap — N3);
  `structs_by_id` name-discovered scan (2344, 3516–3525; §8.5.3 wants
  TypeDescriptors — N3).
- On-disk dirs: `relationDirBIN` writes
  `table.<name>.arity.<A>/`, `struct.<name>.arity.<A>.id.<SID>/`,
  `lat.<name>.arity.<A>.spec.<TOK>/` (4695–4708);
  `parseRelationDirName` (4710–4777) splits on last `.arity.` with the
  comment "so dotted relation names survive" (4717).
- CSV filename = `dir + name + ".csv"` (4099) — raw path component (a
  `/` would break it). Struct id columns render as the relation name in
  CSV (4018) AND in the id-free signature checksum (`signatureOf`
  4050–4068) — the struct display name is *content* in drift detection.
- Prefix tests: `$stat_` (4208, 5163); lattice-spec token rfind
  (1297–1301); dir-format prefixes (4734–4788); `$seq_*`
  (operators.h:913–936, database.h:3148).
- Stats: `ensureStatsRelation("$stat_…")` (4145–4149); `bumpFires` keyed
  on `(rule_loc, variant)` strings where variant embeds the relation
  name (4125, 4139–4143).
- N0 touches almost none of this (daemon work is N3); the formats
  already tolerate dots.

## Seam 9 — Plans, slots, hashes (`compiler/canonical-plan.rkt`, `join-planning.rkt`, `operationalization.rkt`)

- canonical-plan.rkt: names are slotted to dense ints in op bodies
  (rel-slot, 74–132, 182–187) but re-enter the serialized plan verbatim
  via the relation decl list (253), the `dynamic` sorted name list
  (259), and the VariantTag base-tag `delta:<name>`/`all:<name>`
  (146–155) — all sha256'd into `kernel-plan-key` (278–282).
- join-planning.rkt: rel-env extended by name (115–122) — hash keys
  only, not hashed into plan keys here.
- operationalization.rkt: `esc` (833) escapes variables only;
  `latchk_` counter (959–961); `const-global-name` sha256 (294–298).

## Seam 10 — Tests that pin encodings

- Mangler hex scheme pinned: `tests/api/count-ir-oracle.rkt:124–126`
  and `tests/unit/partial-prim-tests.rkt:71` match `_0002b` etc. — the
  QName C++ mangler MUST reuse the exact `_0XXXX` scheme.
- Directory format pinned: `tests/api-tests.sh:91` touches
  `data/apidb/table.edge.arity.2/*`.
- Golden outputs embed constructor display names throughout (e.g.
  `(countrow out (pair 1 2) 0 1 0)`, session-tests.sh:812; all
  `tests/stats-expected/*.fires`). A display-spelling change churns
  every golden.
- `tests/unit/canonical-plan-tests.rkt` catches KernelPlan
  name-encoding regressions.

## The 5 riskiest spots for the byte-identical gate

All hinge on the N0 rule: a single-component QName lowers to a symbol
whose printed form is byte-identical to today's flat symbol.

1. **`compiler/compile.rkt:128–147` — `progstr`/`job-hash`** (the `.so`
   cache key): sorts and prints type-env-rels, rule text, dbmanifest,
   decomps. Any printed-form drift busts every stratum cache slot.
2. **`compiler/canonical-plan.rkt:146–155, 253, 259, 281–282` — the
   KernelPlanKey**: names re-enter via base-tags, the dynamic list, and
   decl list; `bumpFires` keys on the same variant strings
   (database.h:4139–4143). Drift silently splits or collides plan
   identities.
3. **`daemon/database.h:4050–4068` (`signatureOf`) + `:4018` (CSV)**:
   struct constructor name is content in the save/verify signature —
   re-encoding = spurious drift on reload/merge plus golden churn.
4. **`emit-cpp.rkt:96–99` (`content-hash`) + getRelation literals +
   `utils.rkt:65–81` (`escape-id-for-C`)**: TU text is content-addressed
   with names verbatim; the `_0XXXX` scheme is test-pinned.
5. **`compile.rkt:225–239` (`rule-text`/`rule-id-of`) + rule-location
   (`ir-shared.rkt:60–65`)**: RuleIds hash rule source text; locations
   key stats and `malformed_deduction` facts.

Honorable mentions: `operationalization.rkt:294–298` (const-global
sha256 — fires when a relation name is interned as a constant, i.e. the
malformed-deduction path) and `actions.rkt:641–648` (action cache key).

## Suggested minimal `compiler/names.rkt` API

One authority; no other pass may join or split components (modules.md
§8.1):

```text
;; representation
(qname comp ...) / qname?            ; nonempty immutable vector of validated components
qname-components / qname-root?      ; single-component (root) predicate
valid-component?                    ; reject '.', space, parens, '/', control; define $-policy

;; comparison & determinism (feeds cache-key sorts)
qname=?  qname<?                    ; total order matching symbol<? on root names

;; display / wire / filesystem (one reversible codec each)
qname->display                      ; dotted human-facing form
qname->wire / wire->qname           ; action strings & schema replies
qname->fs-name / fs-name->qname     ; data/ dirs + CSV names

;; C++ mangling (MUST reproduce the _0XXXX scheme — test-pinned)
qname->cxx-ident

;; N0 lowering — the load-bearing byte-identity contract
qname->symbol / symbol->qname       ; INVARIANT: identity on single-component
                                    ; names' printed form, so every root
                                    ; program, cache key, plan key, signature,
                                    ; and golden stays byte-for-byte identical
                                    ; until N1 introduces multi-component names

;; owner-scoped generated names (replaces prefix-text ownership)
qname-derive                        ; owner + role (ans|has|at|lat|list|map|sup|oracle)
                                    ; -> child QName owned by the owner structurally
```

Prefix substitution (`qname-subst`) and interface satisfaction are N2
concerns but should live in this module from day one so no other pass
grows its own splitter.
