/*
 * Copyright (c) 2017, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/**
   \file
   \brief directive/pragma data structures.
 */

#ifdef FE90
/* INDEPENDENT information */
typedef struct _newvar_ {
  int var;
  struct _newvar_ *next;
} NEWVAR;

typedef struct _reducvar_ {
  int var;    /* REDUCTION variable */
  int newvar; /* INDEP loop's copy of REDUCTION variable */
  struct _reducvar_ *next;
} REDUCVAR;

typedef struct _reduc_ja_spec {/* HPF/JA REDUCTION clause item */
  int var;                     /* reduction variable */
  int newvar;                  /* INDEP loop's copy of reduction variable */
  int nlocvars;                /* number of location variables */
  REDUCVAR *locvar_list;       /* [ / location variable list / ] */
  struct _reduc_ja_spec *next;
} REDUC_JA_SPEC;

typedef struct _reduc_ja { /* HPF/JA REDUCTION clause (with reduc-op) */
  int opr;                 /* if != 0, OP_xxx value */
  int intrin;              /* if != 0, sptr to intrinsic */
  REDUC_JA_SPEC *speclist; /* list of reduction variables */
  struct _reduc_ja *next;
} REDUC_JA;

typedef struct {
  NEWVAR *new_list;
  int onhome;
  REDUCVAR *reduction_list;
  REDUC_JA *reduction_ja_list;
  NEWVAR *index_list;
} INDEP_INFO;

typedef struct _hpf2_on_info_ {
  NEWVAR *new_list;
  int onhome;
  int block; /* if == 0, simple on dir */
  struct _hpf2_on_info_ *next;
} HPF2_ON_INFO;

typedef struct _index_reuse_ {/* contents of one INDEX_REUSE directive */
  int condvar;                /* if != 0, sptr to scalar logical temporary
                                 storing the 'index reuse condition' */
  NEWVAR *reuse_list;         /* list of array variables in INDEX_REUSE */
  struct _index_reuse_ *next;
} INDEX_REUSE;

#endif

typedef struct {
  /* NOTES:
   * 1.  all members must be int
   * 2.  any additions/modifications imply load_dirset() and store_dirset()
   *     in direct.c, and set_flg() in pragma.c, must be modified.
   * 3.  set_flg() cares about the order in which the members occur.
   * 4.  the member x must be the last member in this structure.
   *     DIRSET_XFLAG is x's offset (in units of ints) from the beginning
   *     of the structure.
   */
  int opt;
  int vect;
  int depchk;
  int fcon;   /* C-only, but always declared */
  int single; /* C-only, but always declared */
  int tpvalue[TPNVERSION]; /* target processor(s), for unified binary */
  int x[sizeof(flg.x) / sizeof(int)]; /* same as flg.x[...] */
} DIRSET;

#define DIRSET_XFLAG 15

typedef struct lpprg_ {/* pragma information for loops */
  int beg_line;        /* beginning line # of loop */
  int end_line;        /* ending line # of loop */
  DIRSET dirset;       /* dirset for the loop */
#ifdef FE90
  INDEP_INFO *indep;             /* locates a loop's INDEP_INFO */
  INDEX_REUSE *index_reuse_list; /* locates a loop's INDEX_REUSE */
#endif
} LPPRG;

typedef struct {/* loop pragma stack */
  int dirx;     /* index into lpg of the loop's dirset */
} LPG_STK;

/** \brief Directive structure
 */
typedef struct {
  DIRSET gbl;        /**< Holding area for global-scoped pragmas */
  DIRSET rou;        /**< Holding area for routine-scoped pragmas */
  DIRSET loop;       /**< Holding area for loop-scoped pragmas */
  DIRSET rou_begin;  /**< Pragmas which apply to the beginning of a routine.
                       *  For C, this structure must be saved away for each
                       *  function appearing in the source file.
                       */
  LOGICAL loop_flag; /**< Seen pragma with loop scope */
  LOGICAL in_loop;   /**< Currently in loop with pragmas */
  LOGICAL carry_fwd; /**< If global/routine pragma seen, must be carried
                      * forward to all outer loops which follow in the
                      * routine.
                      */
  /**
   * for C, need to allocate a DIRSET for each function -- is located
   * by the function's ENTRY aux structure and is assigned by dir_rou_end().
   *
   * for C & Fortran, need to allocate a DIRSET for a loop which has
   * pragmas associated with it.
   */
  DIRSET *stgb;
  int size;
  int avail;
  /**
   * for C & Fortran, each function is associated with a set of
   * loop pragma information. The set is organized as a table
   * and will be ordered according to occurrence of loops (with
   * associated pragmas) in the function.
   */
  struct {
    LPPRG *stgb;
    int size;
    int avail;
  } lpg;
  struct {
    LPG_STK *stgb;
    int size;
    int top;
  } lpg_stk;
#ifdef FE90
  struct {
    LPPRG *stgb;
    int size;
    int avail;
  } dynlpg;
  INDEP_INFO *indep; /**< Locates where to record an INDEPENDENT's INDEP_INFO
                      * while processing the INDEPENDENT statement;
                      * locates a loop's INDEP_INFO structure after
                      * a call to open_pragma()
                      */
  INDEX_REUSE *index_reuse_list; /**< Likewise for an INDEX_REUSE structure */
#endif
} DIRECT;

extern DIRECT direct;

void direct_init(void); /* direct.c */
int direct_import(FILE *);
void direct_rou_end(void);
void direct_loop_enter(void);
void direct_loop_end(int, int);
void direct_rou_load(int);
void direct_rou_setopt(int, int);
void load_dirset(DIRSET *);  /* utility to load a dirset into flg */
void store_dirset(DIRSET *); /* store flg into a dirset */
void dirset_options(LOGICAL);

void push_lpprg(int);

void ili_lpprg_init(void); /* ilidir.c */
void open_pragma(int);
void close_pragma(void);
#ifdef FE90
void open_dynpragma(int, int);
void save_dynpragma(int);
#endif
void push_pragma(int);
void pop_pragma(void);
void direct_fini(void);
#ifdef FE90
void direct_loop_save(void);
#endif
void direct_export(FILE *ff);
void direct_xf(char *fn, int x, int v);
void direct_yf(char *fn, int x, int v);
