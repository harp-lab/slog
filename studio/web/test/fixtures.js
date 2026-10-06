// Entry events as the studio sent them (captured from a real session server):
// Run then `add edge 4 5` on tests/reach.slog; and dred.slog, which adds an
// edge chain, then a shortcut edge, then deletes the chain's first edge.
// Paths are shortened to /work.

export const reach = [
 {
  "error": null,
  "line": "trace on rules",
  "ms": 9804,
  "origin": "evaluate",
  "result": {
   "current": "scratch",
   "held": false,
   "kind": "trace",
   "lines": [
    "each change carries its execution trace: strata, iterations, signed counts",
    "samples: the 8 rows of smallest value hash per relation, iteration and sign",
    "rule fires per iteration"
   ],
   "sessions": [
    {
     "changed": false,
     "current": true,
     "database": null,
     "mode": "mutable",
     "name": "scratch"
    }
   ],
   "title": "Trace on"
  },
  "t": "entry"
 },
 {
  "error": null,
  "line": "run /work/reach.slog",
  "ms": 744,
  "origin": "evaluate",
  "result": {
   "brief-lines": [
    "program completed at a settled daemon boundary",
    "committed"
   ],
   "change": {
    "counts": "valid",
    "operation": "run",
    "refusals": [],
    "requested": [],
    "routes": [],
    "size-deltas": [
     {
      "after": 6,
      "before": null,
      "net": 6,
      "relation": "path"
     },
     {
      "after": 3,
      "before": null,
      "net": 3,
      "relation": "edge"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "_enum"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "div_by_zero"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "error"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "int_overflow"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "malformed_deduction"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "modulo_by_zero"
     }
    ],
    "size-deltas-omitted": 6,
    "sizes-observed": true,
    "status": "settled",
    "strata": [
     {
      "flavor": "normal",
      "hash": "7f89b299",
      "iterations": 2,
      "ms": 1.927,
      "scc": 0
     },
     {
      "flavor": "normal",
      "hash": "3978c1a7",
      "iterations": 4,
      "ms": 12.406,
      "scc": 1
     }
    ],
    "target": "scratch",
    "tiers": [],
    "trace": {
     "dropped": 0,
     "strata": [
      {
       "fixpoint": {
        "iterations": 2,
        "ms": 1.927
       },
       "flavor": "normal",
       "iterations": [
        {
         "iteration": 1,
         "relations": [
          {
           "dups": 0,
           "kinds": {
            "none": 3
           },
           "minus": 0,
           "plus": 3,
           "relation": "edge",
           "sample": [
            {
             "kind": "none",
             "row": "3 4",
             "sign": "+"
            },
            {
             "kind": "none",
             "row": "1 2",
             "sign": "+"
            },
            {
             "kind": "none",
             "row": "2 3",
             "sign": "+"
            }
           ],
           "sample-omitted": 0,
           "size-after": 3,
           "vid": 3
          }
         ],
         "rules": [
          {
           "driver-rows": 1,
           "fires": 1,
           "loc": "reach.slog:4:1",
           "rule": null,
           "tag": "once",
           "work": 0
          }
         ]
        },
        {
         "iteration": 2,
         "relations": [],
         "rules": []
        }
       ],
       "parks": [],
       "scc": 0,
       "stratum": "7f89b299"
      },
      {
       "fixpoint": {
        "iterations": 4,
        "ms": 12.406
       },
       "flavor": "normal",
       "iterations": [
        {
         "iteration": 1,
         "relations": [
          {
           "dups": 0,
           "kinds": {
            "none": 3
           },
           "minus": 0,
           "plus": 3,
           "relation": "path",
           "sample": [
            {
             "kind": "none",
             "row": "3 4",
             "sign": "+"
            },
            {
             "kind": "none",
             "row": "1 2",
             "sign": "+"
            },
            {
             "kind": "none",
             "row": "2 3",
             "sign": "+"
            }
           ],
           "sample-omitted": 0,
           "size-after": 3,
           "vid": 11
          }
         ],
         "rules": [
          {
           "driver-rows": 3,
           "fires": 3,
           "loc": "reach.slog:9:1",
           "rule": null,
           "tag": "all:edge",
           "work": 0
          }
         ]
        },
        {
         "iteration": 2,
         "relations": [
          {
           "dups": 0,
           "kinds": {
            "none": 2
           },
           "minus": 0,
           "plus": 2,
           "relation": "path",
           "sample": [
            {
             "kind": "none",
             "row": "1 3",
             "sign": "+"
            },
            {
             "kind": "none",
             "row": "2 4",
             "sign": "+"
            }
           ],
           "sample-omitted": 0,
           "size-after": 5,
           "vid": 11
          }
         ],
         "rules": [
          {
           "driver-rows": 3,
           "fires": 2,
           "loc": "reach.slog:14:1",
           "rule": null,
           "tag": "delta:path",
           "work": 2
          }
         ]
        },
        {
         "iteration": 3,
         "relations": [
          {
           "dups": 0,
           "kinds": {
            "none": 1
           },
           "minus": 0,
           "plus": 1,
           "relation": "path",
           "sample": [
            {
             "kind": "none",
             "row": "1 4",
             "sign": "+"
            }
           ],
           "sample-omitted": 0,
           "size-after": 6,
           "vid": 11
          }
         ],
         "rules": [
          {
           "driver-rows": 2,
           "fires": 1,
           "loc": "reach.slog:14:1",
           "rule": null,
           "tag": "delta:path",
           "work": 1
          }
         ]
        },
        {
         "iteration": 4,
         "relations": [],
         "rules": [
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "reach.slog:14:1",
           "rule": null,
           "tag": "delta:path",
           "work": 0
          }
         ]
        }
       ],
       "parks": [],
       "scc": 1,
       "stratum": "3978c1a7"
      }
     ]
    },
    "update-revision": 1
   },
   "current": "scratch",
   "held": false,
   "kind": "run",
   "lines": [
    "program completed at a settled daemon boundary",
    "settled \u00b7 update revision 1 \u00b7 counts valid",
    "size changes: path +6 (new -> 6); edge +3 (new -> 3); _enum 0 (new -> 0); div_by_zero 0 (new -> 0); error 0 (new -> 0); int_overflow 0 (new -> 0); malformed_deduction 0 (new -> 0); modulo_by_zero 0 (new -> 0)",
    "...and 6 more relation-size changes",
    "trace 7f89b299: 2 iterations \u00b7 edge +3",
    "trace 3978c1a7: 4 iterations \u00b7 path +6"
   ],
   "sessions": [
    {
     "changed": true,
     "current": true,
     "database": null,
     "mode": "mutable",
     "name": "scratch"
    }
   ],
   "title": "Run /work/reach.slog"
  },
  "t": "entry"
 },
 {
  "error": null,
  "line": "tables",
  "ms": 7,
  "origin": "evaluate",
  "result": {
   "boundary-key": "b1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0",
   "current": "scratch",
   "held": false,
   "kind": "tables",
   "lines": [
    "edge/2  table \u00b7 int int  3 rows",
    "path/2  table \u00b7 int int  6 rows"
   ],
   "relations": [
    {
     "arity": 2,
     "boundary-key": "b1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0",
     "detail": [
      "int",
      "int"
     ],
     "kind": "table",
     "name": "edge",
     "rows": 3,
     "version-key": "v1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:2"
    },
    {
     "arity": 2,
     "boundary-key": "b1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0",
     "detail": [
      "int",
      "int"
     ],
     "kind": "table",
     "name": "path",
     "rows": 6,
     "version-key": "v1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:10"
    }
   ],
   "relations-filter": "",
   "relations-scope": "committed boundary b1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0",
   "relations-total": 14,
   "sessions": [
    {
     "changed": true,
     "current": true,
     "database": null,
     "mode": "mutable",
     "name": "scratch"
    }
   ],
   "title": "Live relations"
  },
  "t": "entry"
 },
 {
  "error": null,
  "line": "add edge 4 5",
  "ms": 588,
  "origin": "repl",
  "result": {
   "brief-lines": [
    "(edge 4 5)",
    "committed"
   ],
   "change": {
    "counts": "valid",
    "operation": "add",
    "refusals": [],
    "requested": [
     {
      "added": 1,
      "relation": "edge",
      "removed": 0
     }
    ],
    "routes": [
     {
      "detail": [
       "1"
      ],
      "kind": "maintain"
     }
    ],
    "size-deltas": [
     {
      "after": 10,
      "before": 6,
      "net": 4,
      "relation": "path"
     },
     {
      "after": 4,
      "before": 3,
      "net": 1,
      "relation": "edge"
     }
    ],
    "size-deltas-omitted": 0,
    "sizes-observed": true,
    "status": "settled",
    "strata": [
     {
      "flavor": "count",
      "hash": "7f89b299",
      "iterations": 2,
      "ms": 12.253,
      "scc": 2
     },
     {
      "flavor": "count",
      "hash": "3978c1a7",
      "iterations": 2,
      "ms": 0.804,
      "scc": 2
     },
     {
      "flavor": "maint1",
      "hash": "3978c1a7",
      "iterations": 2,
      "ms": 8.413,
      "scc": 2
     }
    ],
    "target": "scratch",
    "tiers": [],
    "trace": {
     "dropped": 0,
     "strata": [
      {
       "fixpoint": {
        "iterations": 2,
        "ms": 12.253
       },
       "flavor": "count",
       "iterations": [
        {
         "iteration": 1,
         "relations": [
          {
           "dups": 0,
           "kinds": {
            "nonrec": 3
           },
           "minus": 0,
           "plus": 3,
           "relation": "edge",
           "sample": [
            {
             "kind": "nonrec",
             "row": "3 4",
             "sign": "+"
            },
            {
             "kind": "nonrec",
             "row": "1 2",
             "sign": "+"
            },
            {
             "kind": "nonrec",
             "row": "2 3",
             "sign": "+"
            }
           ],
           "sample-omitted": 0,
           "size-after": 3,
           "vid": 3
          }
         ],
         "rules": [
          {
           "driver-rows": 0,
           "fires": 1,
           "loc": "reach.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:root:0.0",
           "tag": "once",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "reach.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:root:0.0",
           "tag": "once/nonrec",
           "work": 0
          }
         ]
        },
        {
         "iteration": 2,
         "relations": [],
         "rules": []
        }
       ],
       "parks": [],
       "scc": 2,
       "stratum": "7f89b299_count"
      },
      {
       "fixpoint": {
        "iterations": 2,
        "ms": 0.804
       },
       "flavor": "count",
       "iterations": [
        {
         "iteration": 1,
         "relations": [
          {
           "dups": 0,
           "kinds": {
            "nonrec": 3,
            "rec": 3
           },
           "minus": 0,
           "plus": 6,
           "relation": "path",
           "sample": [
            {
             "kind": "rec",
             "row": "1 4",
             "sign": "+"
            },
            {
             "kind": "nonrec",
             "row": "3 4",
             "sign": "+"
            },
            {
             "kind": "nonrec",
             "row": "1 2",
             "sign": "+"
            },
            {
             "kind": "nonrec",
             "row": "2 3",
             "sign": "+"
            },
            {
             "kind": "rec",
             "row": "1 3",
             "sign": "+"
            },
            {
             "kind": "rec",
             "row": "2 4",
             "sign": "+"
            }
           ],
           "sample-omitted": 0,
           "size-after": 6,
           "vid": 11
          }
         ],
         "rules": [
          {
           "driver-rows": 0,
           "fires": 3,
           "loc": "reach.slog:14:1",
           "rule": "r1:m1:p1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:root:0.2",
           "tag": "seeded",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "reach.slog:14:1",
           "rule": "r1:m1:p1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:root:0.2",
           "tag": "seeded/rec",
           "work": 6
          },
          {
           "driver-rows": 0,
           "fires": 3,
           "loc": "reach.slog:9:1",
           "rule": "r1:m1:p1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:root:0.1",
           "tag": "seeded",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "reach.slog:9:1",
           "rule": "r1:m1:p1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:root:0.1",
           "tag": "seeded/nonrec",
           "work": 3
          }
         ]
        },
        {
         "iteration": 2,
         "relations": [],
         "rules": []
        }
       ],
       "parks": [],
       "scc": 2,
       "stratum": "3978c1a7_count"
      },
      {
       "fixpoint": {
        "iterations": 2,
        "ms": 8.413
       },
       "flavor": "maint1",
       "iterations": [
        {
         "iteration": 1,
         "relations": [
          {
           "dups": 0,
           "kinds": {
            "nonrec": 1,
            "rec": 3
           },
           "minus": 0,
           "plus": 4,
           "relation": "path",
           "sample": [
            {
             "kind": "rec",
             "row": "3 5",
             "sign": "+"
            },
            {
             "kind": "rec",
             "row": "2 5",
             "sign": "+"
            },
            {
             "kind": "rec",
             "row": "1 5",
             "sign": "+"
            },
            {
             "kind": "nonrec",
             "row": "4 5",
             "sign": "+"
            }
           ],
           "sample-omitted": 0,
           "size-after": 10,
           "vid": 11
          }
         ],
         "rules": [
          {
           "driver-rows": 0,
           "fires": 1,
           "loc": "reach.slog:9:1",
           "rule": "r1:m1:p1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:root:0.1",
           "tag": "all:edge",
           "work": 0
          },
          {
           "driver-rows": 0,
           "fires": 3,
           "loc": "reach.slog:14:1",
           "rule": "r1:m1:p1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:root:0.2",
           "tag": "all:edge",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "reach.slog:14:1",
           "rule": "r1:m1:p1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:root:0.2",
           "tag": "all:edge/rec",
           "work": 3
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "reach.slog:9:1",
           "rule": "r1:m1:p1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:root:0.1",
           "tag": "all:edge/nonrec",
           "work": 0
          }
         ]
        },
        {
         "iteration": 2,
         "relations": [],
         "rules": [
          {
           "driver-rows": 4,
           "fires": 0,
           "loc": "reach.slog:14:1",
           "rule": "r1:m1:p1:layer-1a10f599450-4d348f3-14d58bd4-8739153:0:root:0.2",
           "tag": "delta:path/rec",
           "work": 0
          }
         ]
        }
       ],
       "parks": [],
       "scc": 2,
       "stratum": "3978c1a7_maint1"
      }
     ]
    },
    "update-revision": 2
   },
   "current": "scratch",
   "held": false,
   "kind": "mutation",
   "lines": [
    "(edge 4 5)",
    "settled \u00b7 update revision 2 \u00b7 counts valid",
    "requested: edge +1",
    "size changes: path +4 (6 -> 10); edge +1 (3 -> 4)",
    "route: maintain 1",
    "trace 7f89b299_count: 2 iterations \u00b7 edge +3",
    "trace 3978c1a7_count: 2 iterations \u00b7 path +6",
    "trace 3978c1a7_maint1: 2 iterations \u00b7 path +4"
   ],
   "sessions": [
    {
     "changed": true,
     "current": true,
     "database": null,
     "mode": "mutable",
     "name": "scratch"
    }
   ],
   "title": "Add \u00b7 edge"
  },
  "t": "entry"
 }
];

export const dred = [
 {
  "error": null,
  "line": "trace on rules",
  "ms": 10435,
  "origin": "evaluate",
  "result": {
   "current": "scratch",
   "held": false,
   "kind": "trace",
   "lines": [
    "each change carries its execution trace: strata, iterations, signed counts",
    "samples: the 8 rows of smallest value hash per relation, iteration and sign",
    "rule fires per iteration"
   ],
   "sessions": [
    {
     "changed": false,
     "current": true,
     "database": null,
     "mode": "mutable",
     "name": "scratch"
    }
   ],
   "title": "Trace on"
  },
  "t": "entry"
 },
 {
  "error": null,
  "line": "run /work/dred.slog",
  "ms": 600,
  "origin": "evaluate",
  "result": {
   "brief-lines": [
    "program completed at a settled daemon boundary",
    "committed"
   ],
   "change": {
    "counts": "valid",
    "operation": "run",
    "refusals": [],
    "requested": [],
    "routes": [],
    "size-deltas": [
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "_enum"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "div_by_zero"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "edge"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "error"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "int_overflow"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "malformed_deduction"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "modulo_by_zero"
     },
     {
      "after": 0,
      "before": null,
      "net": 0,
      "relation": "mpz_overflow"
     }
    ],
    "size-deltas-omitted": 6,
    "sizes-observed": true,
    "status": "settled",
    "strata": [
     {
      "flavor": "normal",
      "hash": "15cdb80e",
      "iterations": 1,
      "ms": 1.242,
      "scc": 0
     }
    ],
    "target": "scratch",
    "tiers": [],
    "trace": {
     "dropped": 0,
     "strata": [
      {
       "fixpoint": {
        "iterations": 1,
        "ms": 1.242
       },
       "flavor": "normal",
       "iterations": [
        {
         "iteration": 1,
         "relations": [],
         "rules": []
        }
       ],
       "parks": [],
       "scc": 0,
       "stratum": "15cdb80e"
      }
     ]
    },
    "update-revision": 1
   },
   "current": "scratch",
   "held": false,
   "kind": "run",
   "lines": [
    "program completed at a settled daemon boundary",
    "settled \u00b7 update revision 1 \u00b7 counts valid",
    "size changes: _enum 0 (new -> 0); div_by_zero 0 (new -> 0); edge 0 (new -> 0); error 0 (new -> 0); int_overflow 0 (new -> 0); malformed_deduction 0 (new -> 0); modulo_by_zero 0 (new -> 0); mpz_overflow 0 (new -> 0)",
    "...and 6 more relation-size changes",
    "trace 15cdb80e: 1 iteration \u00b7 no change"
   ],
   "sessions": [
    {
     "changed": true,
     "current": true,
     "database": null,
     "mode": "mutable",
     "name": "scratch"
    }
   ],
   "title": "Run /work/dred.slog"
  },
  "t": "entry"
 },
 {
  "error": null,
  "line": "tables",
  "ms": 3,
  "origin": "evaluate",
  "result": {
   "boundary-key": "b1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0",
   "current": "scratch",
   "held": false,
   "kind": "tables",
   "lines": [
    "edge/2  table \u00b7 int int  0 rows",
    "path/2  table \u00b7 int int  0 rows"
   ],
   "relations": [
    {
     "arity": 2,
     "boundary-key": "b1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0",
     "detail": [
      "int",
      "int"
     ],
     "kind": "table",
     "name": "edge",
     "rows": 0,
     "version-key": "v1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:2"
    },
    {
     "arity": 2,
     "boundary-key": "b1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0",
     "detail": [
      "int",
      "int"
     ],
     "kind": "table",
     "name": "path",
     "rows": 0,
     "version-key": "v1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:10"
    }
   ],
   "relations-filter": "",
   "relations-scope": "committed boundary b1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0",
   "relations-total": 14,
   "sessions": [
    {
     "changed": true,
     "current": true,
     "database": null,
     "mode": "mutable",
     "name": "scratch"
    }
   ],
   "title": "Live relations"
  },
  "t": "entry"
 },
 {
  "error": null,
  "line": "add edge 1 2",
  "ms": 369,
  "origin": "repl",
  "result": {
   "brief-lines": [
    "(edge 1 2)",
    "committed"
   ],
   "change": {
    "counts": "valid",
    "operation": "add",
    "refusals": [],
    "requested": [
     {
      "added": 1,
      "relation": "edge",
      "removed": 0
     }
    ],
    "routes": [
     {
      "detail": [
       "1"
      ],
      "kind": "maintain"
     }
    ],
    "size-deltas": [
     {
      "after": 1,
      "before": 0,
      "net": 1,
      "relation": "edge"
     },
     {
      "after": 1,
      "before": 0,
      "net": 1,
      "relation": "path"
     }
    ],
    "size-deltas-omitted": 0,
    "sizes-observed": true,
    "status": "settled",
    "strata": [
     {
      "flavor": "count",
      "hash": "15cdb80e",
      "iterations": 1,
      "ms": 0.883,
      "scc": 1
     },
     {
      "flavor": "maint1",
      "hash": "15cdb80e",
      "iterations": 2,
      "ms": 1.647,
      "scc": 1
     }
    ],
    "target": "scratch",
    "tiers": [],
    "trace": {
     "dropped": 0,
     "strata": [
      {
       "fixpoint": {
        "iterations": 1,
        "ms": 0.883
       },
       "flavor": "count",
       "iterations": [
        {
         "iteration": 1,
         "relations": [],
         "rules": [
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:3:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.0",
           "tag": "seeded/nonrec",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.1",
           "tag": "seeded/rec",
           "work": 0
          }
         ]
        }
       ],
       "parks": [],
       "scc": 1,
       "stratum": "15cdb80e_count"
      },
      {
       "fixpoint": {
        "iterations": 2,
        "ms": 1.647
       },
       "flavor": "maint1",
       "iterations": [
        {
         "iteration": 1,
         "relations": [
          {
           "dups": 0,
           "kinds": {
            "nonrec": 1
           },
           "minus": 0,
           "plus": 1,
           "relation": "path",
           "sample": [
            {
             "kind": "nonrec",
             "row": "1 2",
             "sign": "+"
            }
           ],
           "sample-omitted": 0,
           "size-after": 1,
           "vid": 11
          }
         ],
         "rules": [
          {
           "driver-rows": 0,
           "fires": 1,
           "loc": "dred.slog:3:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.0",
           "tag": "all:edge",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:3:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.0",
           "tag": "all:edge/nonrec",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.1",
           "tag": "all:edge/rec",
           "work": 0
          }
         ]
        },
        {
         "iteration": 2,
         "relations": [],
         "rules": [
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.1",
           "tag": "delta:path/rec",
           "work": 0
          }
         ]
        }
       ],
       "parks": [],
       "scc": 1,
       "stratum": "15cdb80e_maint1"
      }
     ]
    },
    "update-revision": 2
   },
   "current": "scratch",
   "held": false,
   "kind": "mutation",
   "lines": [
    "(edge 1 2)",
    "settled \u00b7 update revision 2 \u00b7 counts valid",
    "requested: edge +1",
    "size changes: edge +1 (0 -> 1); path +1 (0 -> 1)",
    "route: maintain 1",
    "trace 15cdb80e_count: 1 iteration \u00b7 no change",
    "trace 15cdb80e_maint1: 2 iterations \u00b7 path +1"
   ],
   "sessions": [
    {
     "changed": true,
     "current": true,
     "database": null,
     "mode": "mutable",
     "name": "scratch"
    }
   ],
   "title": "Add \u00b7 edge"
  },
  "t": "entry"
 },
 {
  "error": null,
  "line": "add edge 2 3",
  "ms": 236,
  "origin": "repl",
  "result": {
   "brief-lines": [
    "(edge 2 3)",
    "committed"
   ],
   "change": {
    "counts": "valid",
    "operation": "add",
    "refusals": [],
    "requested": [
     {
      "added": 1,
      "relation": "edge",
      "removed": 0
     }
    ],
    "routes": [
     {
      "detail": [
       "1"
      ],
      "kind": "maintain"
     }
    ],
    "size-deltas": [
     {
      "after": 3,
      "before": 1,
      "net": 2,
      "relation": "path"
     },
     {
      "after": 2,
      "before": 1,
      "net": 1,
      "relation": "edge"
     }
    ],
    "size-deltas-omitted": 0,
    "sizes-observed": true,
    "status": "settled",
    "strata": [
     {
      "flavor": "maint1",
      "hash": "15cdb80e",
      "iterations": 2,
      "ms": 5.237,
      "scc": 2
     }
    ],
    "target": "scratch",
    "tiers": [],
    "trace": {
     "dropped": 0,
     "strata": [
      {
       "fixpoint": {
        "iterations": 2,
        "ms": 5.237
       },
       "flavor": "maint1",
       "iterations": [
        {
         "iteration": 1,
         "relations": [
          {
           "dups": 0,
           "kinds": {
            "nonrec": 1,
            "rec": 1
           },
           "minus": 0,
           "plus": 2,
           "relation": "path",
           "sample": [
            {
             "kind": "nonrec",
             "row": "2 3",
             "sign": "+"
            },
            {
             "kind": "rec",
             "row": "1 3",
             "sign": "+"
            }
           ],
           "sample-omitted": 0,
           "size-after": 3,
           "vid": 11
          }
         ],
         "rules": [
          {
           "driver-rows": 0,
           "fires": 1,
           "loc": "dred.slog:3:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.0",
           "tag": "all:edge",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:3:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.0",
           "tag": "all:edge/nonrec",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.1",
           "tag": "all:edge/rec",
           "work": 1
          },
          {
           "driver-rows": 0,
           "fires": 1,
           "loc": "dred.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.1",
           "tag": "all:edge",
           "work": 0
          }
         ]
        },
        {
         "iteration": 2,
         "relations": [],
         "rules": [
          {
           "driver-rows": 2,
           "fires": 0,
           "loc": "dred.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.1",
           "tag": "delta:path/rec",
           "work": 0
          }
         ]
        }
       ],
       "parks": [],
       "scc": 2,
       "stratum": "15cdb80e_maint1"
      }
     ]
    },
    "update-revision": 3
   },
   "current": "scratch",
   "held": false,
   "kind": "mutation",
   "lines": [
    "(edge 2 3)",
    "settled \u00b7 update revision 3 \u00b7 counts valid",
    "requested: edge +1",
    "size changes: path +2 (1 -> 3); edge +1 (1 -> 2)",
    "route: maintain 1",
    "trace 15cdb80e_maint1: 2 iterations \u00b7 path +2"
   ],
   "sessions": [
    {
     "changed": true,
     "current": true,
     "database": null,
     "mode": "mutable",
     "name": "scratch"
    }
   ],
   "title": "Add \u00b7 edge"
  },
  "t": "entry"
 },
 {
  "error": null,
  "line": "add edge 1 3",
  "ms": 273,
  "origin": "repl",
  "result": {
   "brief-lines": [
    "(edge 1 3)",
    "committed"
   ],
   "change": {
    "counts": "valid",
    "operation": "add",
    "refusals": [],
    "requested": [
     {
      "added": 1,
      "relation": "edge",
      "removed": 0
     }
    ],
    "routes": [
     {
      "detail": [
       "1"
      ],
      "kind": "maintain"
     }
    ],
    "size-deltas": [
     {
      "after": 3,
      "before": 2,
      "net": 1,
      "relation": "edge"
     }
    ],
    "size-deltas-omitted": 0,
    "sizes-observed": true,
    "status": "settled",
    "strata": [
     {
      "flavor": "maint1",
      "hash": "15cdb80e",
      "iterations": 2,
      "ms": 2.403,
      "scc": 3
     }
    ],
    "target": "scratch",
    "tiers": [],
    "trace": {
     "dropped": 0,
     "strata": [
      {
       "fixpoint": {
        "iterations": 2,
        "ms": 2.403
       },
       "flavor": "maint1",
       "iterations": [
        {
         "iteration": 1,
         "relations": [
          {
           "dups": 1,
           "kinds": {},
           "minus": 0,
           "plus": 0,
           "relation": "path",
           "sample": [],
           "sample-omitted": 0,
           "size-after": 3,
           "vid": 11
          }
         ],
         "rules": [
          {
           "driver-rows": 0,
           "fires": 1,
           "loc": "dred.slog:3:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.0",
           "tag": "all:edge",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:3:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.0",
           "tag": "all:edge/nonrec",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.1",
           "tag": "all:edge/rec",
           "work": 0
          }
         ]
        },
        {
         "iteration": 2,
         "relations": [],
         "rules": []
        }
       ],
       "parks": [],
       "scc": 3,
       "stratum": "15cdb80e_maint1"
      }
     ]
    },
    "update-revision": 4
   },
   "current": "scratch",
   "held": false,
   "kind": "mutation",
   "lines": [
    "(edge 1 3)",
    "settled \u00b7 update revision 4 \u00b7 counts valid",
    "requested: edge +1",
    "size changes: edge +1 (2 -> 3)",
    "route: maintain 1",
    "trace 15cdb80e_maint1: 2 iterations \u00b7 path"
   ],
   "sessions": [
    {
     "changed": true,
     "current": true,
     "database": null,
     "mode": "mutable",
     "name": "scratch"
    }
   ],
   "title": "Add \u00b7 edge"
  },
  "t": "entry"
 },
 {
  "error": null,
  "line": "del edge 1 2",
  "ms": 272,
  "origin": "repl",
  "result": {
   "brief-lines": [
    "(edge 1 2)",
    "committed"
   ],
   "change": {
    "counts": "valid",
    "operation": "del",
    "refusals": [],
    "requested": [
     {
      "added": 0,
      "relation": "edge",
      "removed": 1
     }
    ],
    "routes": [
     {
      "detail": [
       "1"
      ],
      "kind": "maintain-recursive-negative"
     }
    ],
    "size-deltas": [
     {
      "after": 2,
      "before": 3,
      "net": -1,
      "relation": "edge"
     },
     {
      "after": 2,
      "before": 3,
      "net": -1,
      "relation": "path"
     }
    ],
    "size-deltas-omitted": 0,
    "sizes-observed": true,
    "status": "settled",
    "strata": [
     {
      "flavor": "maint4neg",
      "hash": "15cdb80e",
      "iterations": 3,
      "ms": 0.928,
      "scc": 4
     }
    ],
    "target": "scratch",
    "tiers": [],
    "trace": {
     "dropped": 0,
     "strata": [
      {
       "fixpoint": {
        "iterations": 3,
        "ms": 0.928
       },
       "flavor": "maint4neg",
       "iterations": [
        {
         "iteration": 1,
         "relations": [
          {
           "dups": 0,
           "kinds": {
            "nonrec": 1
           },
           "minus": 1,
           "plus": 0,
           "relation": "path",
           "sample": [
            {
             "kind": "nonrec",
             "row": "1 2",
             "sign": "-"
            }
           ],
           "sample-omitted": 0,
           "size-after": 2,
           "vid": 11
          }
         ],
         "rules": [
          {
           "driver-rows": 0,
           "fires": 1,
           "loc": "dred.slog:3:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.0",
           "tag": "all:edge",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:3:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.0",
           "tag": "all:edge/nonrec",
           "work": 0
          },
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.1",
           "tag": "all:edge/rec",
           "work": 0
          }
         ]
        },
        {
         "iteration": 2,
         "relations": [
          {
           "dups": 1,
           "kinds": {},
           "minus": 0,
           "plus": 0,
           "relation": "path",
           "sample": [],
           "sample-omitted": 0,
           "size-after": 2,
           "vid": 11
          }
         ],
         "rules": [
          {
           "driver-rows": 1,
           "fires": 0,
           "loc": "dred.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.1",
           "tag": "delta:path/rec",
           "work": 1
          },
          {
           "driver-rows": 0,
           "fires": 1,
           "loc": "dred.slog:4:1",
           "rule": "r1:m1:p1:layer-1a10f59c0dc-17fb59e2-f747922-1c53cf1e:0:root:0.1",
           "tag": "delta:path",
           "work": 0
          }
         ]
        },
        {
         "iteration": 3,
         "relations": [],
         "rules": []
        }
       ],
       "parks": [],
       "scc": 4,
       "stratum": "15cdb80e_maint4neg"
      }
     ]
    },
    "update-revision": 5
   },
   "current": "scratch",
   "held": false,
   "kind": "mutation",
   "lines": [
    "(edge 1 2)",
    "settled \u00b7 update revision 5 \u00b7 counts valid",
    "requested: edge -1",
    "size changes: edge -1 (3 -> 2); path -1 (3 -> 2)",
    "route: maintain-recursive-negative 1",
    "trace 15cdb80e_maint4neg: 3 iterations \u00b7 path -1"
   ],
   "sessions": [
    {
     "changed": true,
     "current": true,
     "database": null,
     "mode": "mutable",
     "name": "scratch"
    }
   ],
   "title": "Del \u00b7 edge"
  },
  "t": "entry"
 }
];
