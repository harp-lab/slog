# Slog configuration

Slog's settings are themselves a small **Slog program**. The compiler runs it
once, caches the result, and thereafter just reads the cache — so configuration
costs nothing on a warm run.

## Files

| File | Tracked | Purpose |
|------|---------|---------|
| `default-config.slog` | yes | Shipped defaults + derivation rules. **Do not edit.** |
| `config.slog` | no (gitignored) | Your local config. If absent, the defaults are used directly. |
| `system.slog` | no (gitignored) | Regenerated each run with detected system facts (`sys_cores`, `sys_ram_mb`). |
| `cache/<hash>/` | no (gitignored) | Computed settings, keyed by a hash of the config files + detected system. Safe to delete; recomputed on next run. |

## How it works

1. The front end detects the system and writes `system.slog`.
2. It runs `config.slog` (or, if absent, `default-config.slog`) through the normal
   Slog pipeline, producing a settings database (`setting_int`, `setting_str`).
3. The result is cached under `cache/<hash>/`. The hash covers the config files
   and the detected system, so a changed config **or** a different machine
   (different core/RAM count) recomputes automatically.
4. The settings populate the `SLOG_*` environment defaults the rest of the
   toolchain reads.

## Reconfiguring

Copy the template and edit your copy:

```sh
cp config/default-config.slog config/config.slog   # optional: config.slog ships pre-made
$EDITOR config/config.slog
```

`config.slog` `include`s the defaults; to override a single setting, add an
`override_int` / `override_str` fact (these win over the computed defaults):

```
include "default-config.slog"
rule (override_int "threads" 4)
rule (override_str "opt" "2")
```

Or delete the `include` line and define the `setting_int` / `setting_str`
database yourself for full control.

## Precedence

Highest wins:

```
command-line flag / SLOG_* env var   >   config.slog   >   default-config.slog   >   built-in code default
```

An `SLOG_*` variable you set explicitly is **never** overwritten by the config
system. Disable the config system entirely with `SLOG_NO_CONFIG=1` (built-in
dynamic defaults, e.g. threads = cores − 1, still apply).

## Settings currently honored

| Setting (`setting_int`/`setting_str`) | Env var | Default |
|--------|---------|---------|
| `threads` | `SLOG_THREADS` | cores − 1 |
| `build_jobs` | `SLOG_BUILD_JOBS` | cores |
| `opt` | `SLOG_OPT` | `tiered` |
| `max_ms` | `SLOG_MAX_MS` | `8000` |
| `slice_ms` | `SLOG_SLICE_MS` | `500` |
| `mem_max` | `SLOG_MEM_MAX` | `4G` |

> Setting names and string values must not contain spaces (settings are read
> back from space-separated CSV).
