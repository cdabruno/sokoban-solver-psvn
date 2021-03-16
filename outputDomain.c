#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS
#define __STDC_LIMIT_MACROS
#include <inttypes.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>


#define psvn2c_PSVN_API

#define HAVE_BWD_MOVES


/* number of variables in a state */
#define NUMVARS 49


typedef int8_t var_t;
#define PRI_VAR PRId8
#define SCN_VAR SCNd8

#define NUMDOMAINS 1
static var_t domain_sizes[ NUMDOMAINS ] = { 4 };
static int var_domains[ NUMVARS ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const char *domain_0[ 4 ] = {"P", "R", "W", "N" };
static const char **var_domain_names[ NUMVARS ] = { domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0 };

typedef struct {
 var_t vars[ NUMVARS ];
} state_t;

typedef int (*funcptr)( const state_t *, void * );
typedef void (*actfuncptr)( const state_t *, state_t * );

typedef struct {
 const state_t *my_state;
 funcptr my_funcptr;
} ruleid_iterator_t;

#define num_fwd_rules 58
#define num_bwd_rules 58
static const char *fwd_rule_name[ 58 ] = { "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN" };
#define get_fwd_rule_label( ruleid ) (fwd_rule_name[(ruleid)]) 
static const char *bwd_rule_name[ 58 ] = { "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN" };
#define get_bwd_rule_label( ruleid ) (bwd_rule_name[(ruleid)]) 
#define cost_of_cheapest_fwd_rule 0
#define cost_of_costliest_fwd_rule 1
static const int fwd_rule_cost[ 58 ] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#define get_fwd_rule_cost( ruleid ) (fwd_rule_cost[(ruleid)]) 
#define cost_of_cheapest_bwd_rule 0
#define cost_of_costliest_bwd_rule 1
static const int bwd_rule_cost[ 58 ] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#define get_bwd_rule_cost( ruleid ) (bwd_rule_cost[(ruleid)]) 

static void fwdrule1( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = 1;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule2( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = 0;
  child_state->vars[ 25 ] = 1;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule3( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = 1;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule4( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = 0;
  child_state->vars[ 32 ] = 1;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule5( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 1;
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = 3;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule6( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 1;
  child_state->vars[ 24 ] = 0;
  child_state->vars[ 25 ] = 3;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule7( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 1;
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = 3;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule8( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 1;
  child_state->vars[ 31 ] = 0;
  child_state->vars[ 32 ] = 3;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule9( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 1;
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 0;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule10( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = 1;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 0;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule11( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 1;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule12( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 1;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule13( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 1;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 3;
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule14( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 1;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 3;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule15( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 3;
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 0;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 1;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule16( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = 3;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 0;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 1;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule17( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 3;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 1;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule18( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 3;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 1;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule19( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 1;
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule20( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 1;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule21( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 3;
  child_state->vars[ 9 ] = 0;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule22( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 3;
  child_state->vars[ 16 ] = 0;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule23( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule24( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = 0;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule25( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = 3;
  child_state->vars[ 25 ] = 0;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule26( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule27( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = 0;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule28( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = 3;
  child_state->vars[ 32 ] = 0;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule29( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 3;
  child_state->vars[ 37 ] = 0;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule30( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 0;
  child_state->vars[ 9 ] = 3;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule31( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 0;
  child_state->vars[ 16 ] = 3;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule32( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule33( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = 3;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule34( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = 0;
  child_state->vars[ 25 ] = 3;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule35( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule36( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = 3;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule37( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = 0;
  child_state->vars[ 32 ] = 3;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule38( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 0;
  child_state->vars[ 37 ] = 3;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule39( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 0;
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 3;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule40( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = 0;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 3;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule41( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 0;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule42( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 0;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule43( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule44( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule45( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = 0;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = 3;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule46( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = 0;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = 3;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule47( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 3;
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule48( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 3;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule49( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 3;
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 0;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule50( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = 3;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 0;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule51( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 3;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule52( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 3;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule53( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule54( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule55( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = 3;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = 0;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule56( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = 3;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = 0;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule57( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 0;
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void fwdrule58( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 0;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static actfuncptr fwd_rules[ 58 ] = { fwdrule1, fwdrule2, fwdrule3, fwdrule4, fwdrule5, fwdrule6, fwdrule7, fwdrule8, fwdrule9, fwdrule10, fwdrule11, fwdrule12, fwdrule13, fwdrule14, fwdrule15, fwdrule16, fwdrule17, fwdrule18, fwdrule19, fwdrule20, fwdrule21, fwdrule22, fwdrule23, fwdrule24, fwdrule25, fwdrule26, fwdrule27, fwdrule28, fwdrule29, fwdrule30, fwdrule31, fwdrule32, fwdrule33, fwdrule34, fwdrule35, fwdrule36, fwdrule37, fwdrule38, fwdrule39, fwdrule40, fwdrule41, fwdrule42, fwdrule43, fwdrule44, fwdrule45, fwdrule46, fwdrule47, fwdrule48, fwdrule49, fwdrule50, fwdrule51, fwdrule52, fwdrule53, fwdrule54, fwdrule55, fwdrule56, fwdrule57, fwdrule58 };

static int fwdfn13( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = 0;
    return 57;
  } else {
    return -1;
  }
}

static int fwdfn14( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = 0;
    return 47;
  } else {
    return -1;
  }
}

static int fwdfn12( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn13( state, next_func );
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    *((funcptr *)next_func) = fwdfn14;
    return 53;
  }
}

static int fwdfn15( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn13( state, next_func );
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    return fwdfn14( state, next_func );
  }
}

static int fwdfn16( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn13;
    return 43;
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    return fwdfn14( state, next_func );
  }
}

static int fwdfn11( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn12( state, next_func );
  case 1:
    return fwdfn15( state, next_func );
  case 2:
    return fwdfn15( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn16;
    return 51;
  }
}

static int fwdfn10( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn11;
    return 39;
  } else {
    return fwdfn11( state, next_func );
  }
}

static int fwdfn18( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn13;
    return 43;
  } else {
    return fwdfn13( state, next_func );
  }
}

static int fwdfn20( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = 0;
    return 53;
  } else {
    return -1;
  }
}

static int fwdfn19( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn20;
    return 47;
  } else {
    return fwdfn20( state, next_func );
  }
}

static int fwdfn17( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn18( state, next_func );
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    return fwdfn19( state, next_func );
  }
}

static int fwdfn22( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn12;
    return 41;
  case 1:
    return fwdfn15( state, next_func );
  case 2:
    return fwdfn15( state, next_func );
  default:
    return fwdfn16( state, next_func );
  }
}

static int fwdfn21( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn22;
    return 49;
  } else {
    return fwdfn22( state, next_func );
  }
}

static int fwdfn9( const state_t *state, void *next_func )
{
  switch( state->vars[ 16 ] ) {
  case 0:
    return fwdfn10( state, next_func );
  case 1:
    return fwdfn17( state, next_func );
  case 2:
    return fwdfn17( state, next_func );
  default:
    return fwdfn21( state, next_func );
  }
}

static int fwdfn8( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn9;
    return 56;
  } else {
    return fwdfn9( state, next_func );
  }
}

static int fwdfn23( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn9;
    return 46;
  } else {
    return fwdfn9( state, next_func );
  }
}

static int fwdfn7( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn8( state, next_func );
  case 1:
    return fwdfn9( state, next_func );
  case 2:
    return fwdfn9( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn23;
    return 52;
  }
}

static int fwdfn24( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn7;
    return 48;
  } else {
    return fwdfn7( state, next_func );
  }
}

static int fwdfn6( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn24;
    return 40;
  } else {
    return fwdfn7( state, next_func );
  }
}

static int fwdfn27( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn8( state, next_func );
  case 1:
    return fwdfn9( state, next_func );
  case 2:
    return fwdfn9( state, next_func );
  default:
    return fwdfn23( state, next_func );
  }
}

static int fwdfn26( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn27;
    return 48;
  } else {
    return fwdfn27( state, next_func );
  }
}

static int fwdfn25( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    return fwdfn26( state, next_func );
  } else {
    return fwdfn27( state, next_func );
  }
}

static int fwdfn29( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn8;
    return 42;
  case 1:
    return fwdfn9( state, next_func );
  case 2:
    return fwdfn9( state, next_func );
  default:
    return fwdfn23( state, next_func );
  }
}

static int fwdfn30( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn29;
    return 48;
  } else {
    return fwdfn29( state, next_func );
  }
}

static int fwdfn28( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn29;
    return 50;
  case 1:
    return fwdfn29( state, next_func );
  case 2:
    return fwdfn29( state, next_func );
  default:
    return fwdfn30( state, next_func );
  }
}

static int fwdfn5( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn6( state, next_func );
  case 1:
    return fwdfn25( state, next_func );
  case 2:
    return fwdfn25( state, next_func );
  default:
    return fwdfn28( state, next_func );
  }
}

static int fwdfn4( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn5;
    return 55;
  } else {
    return fwdfn5( state, next_func );
  }
}

static int fwdfn31( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn5;
    return 45;
  } else {
    return fwdfn5( state, next_func );
  }
}

static int fwdfn3( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return fwdfn4( state, next_func );
  case 1:
    return fwdfn5( state, next_func );
  case 2:
    return fwdfn5( state, next_func );
  default:
    return fwdfn31( state, next_func );
  }
}

static int fwdfn2( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn3;
    return 54;
  } else {
    return fwdfn3( state, next_func );
  }
}

static int fwdfn32( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn3;
    return 44;
  } else {
    return fwdfn3( state, next_func );
  }
}

static int fwdfn1( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return fwdfn2( state, next_func );
  case 1:
    return fwdfn3( state, next_func );
  case 2:
    return fwdfn3( state, next_func );
  default:
    return fwdfn32( state, next_func );
  }
}

static int fwdfn46( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 27;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn47( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 36;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn45( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return fwdfn46( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn47;
    return 26;
  }
}

static int fwdfn44( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn45;
    return 34;
  } else {
    return fwdfn45( state, next_func );
  }
}

static int fwdfn48( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return fwdfn46( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    return fwdfn47( state, next_func );
  }
}

static int fwdfn50( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn46;
    return 35;
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    return fwdfn47( state, next_func );
  }
}

static int fwdfn49( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn50;
    return 25;
  } else {
    return fwdfn50( state, next_func );
  }
}

static int fwdfn43( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn44( state, next_func );
  case 1:
    return fwdfn48( state, next_func );
  case 2:
    return fwdfn48( state, next_func );
  default:
    return fwdfn49( state, next_func );
  }
}

static int fwdfn42( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn43;
    return 24;
  } else {
    return fwdfn43( state, next_func );
  }
}

static int fwdfn51( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn43;
    return 33;
  } else {
    return fwdfn43( state, next_func );
  }
}

static int fwdfn41( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return fwdfn42( state, next_func );
  case 1:
    return fwdfn43( state, next_func );
  case 2:
    return fwdfn43( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn51;
    return 23;
  }
}

static int fwdfn40( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn41;
    return 31;
  } else {
    return fwdfn41( state, next_func );
  }
}

static int fwdfn52( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return fwdfn42( state, next_func );
  case 1:
    return fwdfn43( state, next_func );
  case 2:
    return fwdfn43( state, next_func );
  default:
    return fwdfn51( state, next_func );
  }
}

static int fwdfn54( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn42;
    return 32;
  case 1:
    return fwdfn43( state, next_func );
  case 2:
    return fwdfn43( state, next_func );
  default:
    return fwdfn51( state, next_func );
  }
}

static int fwdfn53( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn54;
    return 22;
  } else {
    return fwdfn54( state, next_func );
  }
}

static int fwdfn39( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn40( state, next_func );
  case 1:
    return fwdfn52( state, next_func );
  case 2:
    return fwdfn52( state, next_func );
  default:
    return fwdfn53( state, next_func );
  }
}

static int fwdfn38( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn39;
    return 21;
  } else {
    return fwdfn39( state, next_func );
  }
}

static int fwdfn55( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn39;
    return 30;
  } else {
    return fwdfn39( state, next_func );
  }
}

static int fwdfn37( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn38( state, next_func );
  case 1:
    return fwdfn39( state, next_func );
  case 2:
    return fwdfn39( state, next_func );
  default:
    return fwdfn55( state, next_func );
  }
}

static int fwdfn36( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn37;
    return 20;
  } else {
    return fwdfn37( state, next_func );
  }
}

static int fwdfn57( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn38;
    return 38;
  case 1:
    return fwdfn39( state, next_func );
  case 2:
    return fwdfn39( state, next_func );
  default:
    return fwdfn55( state, next_func );
  }
}

static int fwdfn56( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn57;
    return 29;
  } else {
    return fwdfn57( state, next_func );
  }
}

static int fwdfn35( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return fwdfn36( state, next_func );
  case 1:
    return fwdfn37( state, next_func );
  case 2:
    return fwdfn37( state, next_func );
  default:
    return fwdfn56( state, next_func );
  }
}

static int fwdfn34( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn35;
    return 28;
  } else {
    return fwdfn35( state, next_func );
  }
}

static int fwdfn58( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn35;
    return 37;
  } else {
    return fwdfn35( state, next_func );
  }
}

static int fwdfn33( const state_t *state, void *next_func )
{
  switch( state->vars[ 36 ] ) {
  case 0:
    return fwdfn34( state, next_func );
  case 1:
    return fwdfn35( state, next_func );
  case 2:
    return fwdfn35( state, next_func );
  default:
    return fwdfn58( state, next_func );
  }
}

static int fwdfn66( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 18;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn65( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 1 ) {
    return fwdfn66( state, next_func );
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn67( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn65;
    return 8;
  } else {
    return fwdfn65( state, next_func );
  }
}

static int fwdfn64( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return fwdfn67( state, next_func );
  } else {
    return fwdfn65( state, next_func );
  }
}

static int fwdfn69( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 16;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn70( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 10;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn68( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn69( state, next_func );
  case 1:
    return fwdfn33( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn70( state, next_func );
  }
}

static int fwdfn73( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 14;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn72( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    return fwdfn73( state, next_func );
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn74( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn72;
    return 12;
  } else {
    return fwdfn72( state, next_func );
  }
}

static int fwdfn71( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 1 ) {
    return fwdfn74( state, next_func );
  } else {
    return fwdfn72( state, next_func );
  }
}

static int fwdfn63( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn64( state, next_func );
  case 1:
    return fwdfn68( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn71( state, next_func );
  }
}

static int fwdfn75( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn63;
    return 9;
  } else {
    return fwdfn63( state, next_func );
  }
}

static int fwdfn62( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    return fwdfn75( state, next_func );
  } else {
    return fwdfn63( state, next_func );
  }
}

static int fwdfn76( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn62;
    return 3;
  } else {
    return fwdfn62( state, next_func );
  }
}

static int fwdfn61( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn76( state, next_func );
  } else {
    return fwdfn62( state, next_func );
  }
}

static int fwdfn83( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 14;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn84( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 8;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn82( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return fwdfn83( state, next_func );
  case 1:
    return fwdfn33( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn84( state, next_func );
  }
}

static int fwdfn85( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 10;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn81( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn33( state, next_func );
  case 1:
    return fwdfn82( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn85( state, next_func );
  }
}

static int fwdfn86( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn81;
    return 9;
  } else {
    return fwdfn81( state, next_func );
  }
}

static int fwdfn80( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    return fwdfn86( state, next_func );
  } else {
    return fwdfn81( state, next_func );
  }
}

static int fwdfn79( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn80;
    return 2;
  } else {
    return fwdfn80( state, next_func );
  }
}

static int fwdfn90( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn66;
    return 8;
  } else {
    return fwdfn66( state, next_func );
  }
}

static int fwdfn89( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return fwdfn90( state, next_func );
  } else {
    return fwdfn66( state, next_func );
  }
}

static int fwdfn88( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn89( state, next_func );
  case 1:
    return fwdfn33( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn74( state, next_func );
  }
}

static int fwdfn91( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn88;
    return 9;
  } else {
    return fwdfn88( state, next_func );
  }
}

static int fwdfn87( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    return fwdfn91( state, next_func );
  } else {
    return fwdfn88( state, next_func );
  }
}

static int fwdfn94( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    return fwdfn83( state, next_func );
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn95( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    return fwdfn84( state, next_func );
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn93( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return fwdfn94( state, next_func );
  case 1:
    return fwdfn33( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn95( state, next_func );
  }
}

static int fwdfn96( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn93;
    return 9;
  } else {
    return fwdfn93( state, next_func );
  }
}

static int fwdfn92( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    return fwdfn96( state, next_func );
  } else {
    return fwdfn93( state, next_func );
  }
}

static int fwdfn100( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 16;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn99( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn100( state, next_func );
  case 1:
    return fwdfn82( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn33( state, next_func );
  }
}

static int fwdfn101( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn99;
    return 9;
  } else {
    return fwdfn99( state, next_func );
  }
}

static int fwdfn98( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    return fwdfn101( state, next_func );
  } else {
    return fwdfn99( state, next_func );
  }
}

static int fwdfn97( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn98;
    return 6;
  } else {
    return fwdfn98( state, next_func );
  }
}

static int fwdfn78( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn79( state, next_func );
  case 1:
    return fwdfn87( state, next_func );
  case 2:
    return fwdfn92( state, next_func );
  default:
    return fwdfn97( state, next_func );
  }
}

static int fwdfn77( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn78;
    return 19;
  } else {
    return fwdfn78( state, next_func );
  }
}

static int fwdfn103( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn62;
    return 7;
  } else {
    return fwdfn62( state, next_func );
  }
}

static int fwdfn102( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn103( state, next_func );
  } else {
    return fwdfn62( state, next_func );
  }
}

static int fwdfn60( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn61( state, next_func );
  case 1:
    return fwdfn77( state, next_func );
  case 2:
    return fwdfn62( state, next_func );
  default:
    return fwdfn102( state, next_func );
  }
}

static int fwdfn104( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn60;
    return 1;
  } else {
    return fwdfn60( state, next_func );
  }
}

static int fwdfn59( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 1 ) {
    return fwdfn104( state, next_func );
  } else {
    return fwdfn60( state, next_func );
  }
}

static int fwdfn110( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn65;
    return 11;
  } else {
    return fwdfn65( state, next_func );
  }
}

static int fwdfn111( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn110;
    return 3;
  } else {
    return fwdfn110( state, next_func );
  }
}

static int fwdfn109( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn111( state, next_func );
  } else {
    return fwdfn110( state, next_func );
  }
}

static int fwdfn113( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 2;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn114( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 6;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn112( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn113( state, next_func );
  case 1:
    return fwdfn66( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn114( state, next_func );
  }
}

static int fwdfn116( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn65;
    return 17;
  } else {
    return fwdfn65( state, next_func );
  }
}

static int fwdfn117( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn116;
    return 7;
  } else {
    return fwdfn116( state, next_func );
  }
}

static int fwdfn115( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn117( state, next_func );
  } else {
    return fwdfn116( state, next_func );
  }
}

static int fwdfn108( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn109( state, next_func );
  case 1:
    return fwdfn112( state, next_func );
  case 2:
    return fwdfn65( state, next_func );
  default:
    return fwdfn115( state, next_func );
  }
}

static int fwdfn118( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn108;
    return 8;
  } else {
    return fwdfn108( state, next_func );
  }
}

static int fwdfn107( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return fwdfn118( state, next_func );
  } else {
    return fwdfn108( state, next_func );
  }
}

static int fwdfn106( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn107;
    return 0;
  } else {
    return fwdfn107( state, next_func );
  }
}

static int fwdfn121( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn68;
    return 11;
  } else {
    return fwdfn68( state, next_func );
  }
}

static int fwdfn122( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn121;
    return 3;
  } else {
    return fwdfn121( state, next_func );
  }
}

static int fwdfn120( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn122( state, next_func );
  } else {
    return fwdfn121( state, next_func );
  }
}

static int fwdfn125( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 10;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn124( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn125;
    return 2;
  } else {
    return fwdfn125( state, next_func );
  }
}

static int fwdfn127( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 16;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn126( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn127;
    return 6;
  } else {
    return fwdfn127( state, next_func );
  }
}

static int fwdfn123( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn124( state, next_func );
  case 1:
    return fwdfn33( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn126( state, next_func );
  }
}

static int fwdfn129( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn68;
    return 17;
  } else {
    return fwdfn68( state, next_func );
  }
}

static int fwdfn130( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn129;
    return 7;
  } else {
    return fwdfn129( state, next_func );
  }
}

static int fwdfn128( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn130( state, next_func );
  } else {
    return fwdfn129( state, next_func );
  }
}

static int fwdfn119( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn120( state, next_func );
  case 1:
    return fwdfn123( state, next_func );
  case 2:
    return fwdfn68( state, next_func );
  default:
    return fwdfn128( state, next_func );
  }
}

static int fwdfn133( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 11;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn134( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn133;
    return 3;
  } else {
    return fwdfn133( state, next_func );
  }
}

static int fwdfn132( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn134( state, next_func );
  } else {
    return fwdfn133( state, next_func );
  }
}

static int fwdfn135( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn113( state, next_func );
  case 1:
    return fwdfn33( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn114( state, next_func );
  }
}

static int fwdfn137( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 17;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn138( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn137;
    return 7;
  } else {
    return fwdfn137( state, next_func );
  }
}

static int fwdfn136( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn138( state, next_func );
  } else {
    return fwdfn137( state, next_func );
  }
}

static int fwdfn131( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn132( state, next_func );
  case 1:
    return fwdfn135( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn136( state, next_func );
  }
}

static int fwdfn146( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 12;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn145( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 1 ) {
    return fwdfn146( state, next_func );
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn144( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn145;
    return 11;
  } else {
    return fwdfn145( state, next_func );
  }
}

static int fwdfn147( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn144;
    return 3;
  } else {
    return fwdfn144( state, next_func );
  }
}

static int fwdfn143( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn147( state, next_func );
  } else {
    return fwdfn144( state, next_func );
  }
}

static int fwdfn148( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn113( state, next_func );
  case 1:
    return fwdfn146( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn114( state, next_func );
  }
}

static int fwdfn151( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn137;
    return 12;
  } else {
    return fwdfn137( state, next_func );
  }
}

static int fwdfn150( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 1 ) {
    return fwdfn151( state, next_func );
  } else {
    return fwdfn137( state, next_func );
  }
}

static int fwdfn152( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn150;
    return 7;
  } else {
    return fwdfn150( state, next_func );
  }
}

static int fwdfn149( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn152( state, next_func );
  } else {
    return fwdfn150( state, next_func );
  }
}

static int fwdfn142( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn143( state, next_func );
  case 1:
    return fwdfn148( state, next_func );
  case 2:
    return fwdfn145( state, next_func );
  default:
    return fwdfn149( state, next_func );
  }
}

static int fwdfn141( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn142;
    return 14;
  } else {
    return fwdfn142( state, next_func );
  }
}

static int fwdfn140( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    return fwdfn141( state, next_func );
  } else {
    return fwdfn142( state, next_func );
  }
}

static int fwdfn139( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn140;
    return 4;
  } else {
    return fwdfn140( state, next_func );
  }
}

static int fwdfn105( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn106( state, next_func );
  case 1:
    return fwdfn119( state, next_func );
  case 2:
    return fwdfn131( state, next_func );
  default:
    return fwdfn139( state, next_func );
  }
}

static int fwdfn158( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 3;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn157( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn158( state, next_func );
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn160( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn33;
    return 7;
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn159( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn160( state, next_func );
  } else {
    return fwdfn33( state, next_func );
  }
}

static int fwdfn156( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn157( state, next_func );
  case 1:
    return fwdfn113( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn159( state, next_func );
  }
}

static int fwdfn162( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn157( state, next_func );
  case 1:
    return fwdfn33( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn159( state, next_func );
  }
}

static int fwdfn161( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn162;
    return 18;
  } else {
    return fwdfn162( state, next_func );
  }
}

static int fwdfn163( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn157( state, next_func );
  case 1:
    return fwdfn114( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn159( state, next_func );
  }
}

static int fwdfn155( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn156( state, next_func );
  case 1:
    return fwdfn161( state, next_func );
  case 2:
    return fwdfn162( state, next_func );
  default:
    return fwdfn163( state, next_func );
  }
}

static int fwdfn164( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn155;
    return 8;
  } else {
    return fwdfn155( state, next_func );
  }
}

static int fwdfn154( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return fwdfn164( state, next_func );
  } else {
    return fwdfn155( state, next_func );
  }
}

static int fwdfn166( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn156;
    return 10;
  } else {
    return fwdfn156( state, next_func );
  }
}

static int fwdfn167( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn163;
    return 16;
  } else {
    return fwdfn163( state, next_func );
  }
}

static int fwdfn165( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn166( state, next_func );
  case 1:
    return fwdfn162( state, next_func );
  case 2:
    return fwdfn162( state, next_func );
  default:
    return fwdfn167( state, next_func );
  }
}

static int fwdfn168( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn157( state, next_func );
  case 1:
    return fwdfn135( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    return fwdfn159( state, next_func );
  }
}

static int fwdfn172( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn162;
    return 12;
  } else {
    return fwdfn162( state, next_func );
  }
}

static int fwdfn171( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn156( state, next_func );
  case 1:
    return fwdfn172( state, next_func );
  case 2:
    return fwdfn162( state, next_func );
  default:
    return fwdfn163( state, next_func );
  }
}

static int fwdfn170( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn171;
    return 14;
  } else {
    return fwdfn171( state, next_func );
  }
}

static int fwdfn169( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    return fwdfn170( state, next_func );
  } else {
    return fwdfn171( state, next_func );
  }
}

static int fwdfn153( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn154( state, next_func );
  case 1:
    return fwdfn165( state, next_func );
  case 2:
    return fwdfn168( state, next_func );
  default:
    return fwdfn169( state, next_func );
  }
}

static int fwdfn177( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn63;
    return 15;
  } else {
    return fwdfn63( state, next_func );
  }
}

static int fwdfn176( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    return fwdfn177( state, next_func );
  } else {
    return fwdfn63( state, next_func );
  }
}

static int fwdfn178( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn176;
    return 3;
  } else {
    return fwdfn176( state, next_func );
  }
}

static int fwdfn175( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn178( state, next_func );
  } else {
    return fwdfn176( state, next_func );
  }
}

static int fwdfn183( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn81;
    return 13;
  } else {
    return fwdfn81( state, next_func );
  }
}

static int fwdfn182( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn183;
    return 2;
  } else {
    return fwdfn183( state, next_func );
  }
}

static int fwdfn184( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn88;
    return 13;
  } else {
    return fwdfn88( state, next_func );
  }
}

static int fwdfn185( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn93;
    return 13;
  } else {
    return fwdfn93( state, next_func );
  }
}

static int fwdfn187( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn99;
    return 13;
  } else {
    return fwdfn99( state, next_func );
  }
}

static int fwdfn186( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn187;
    return 6;
  } else {
    return fwdfn187( state, next_func );
  }
}

static int fwdfn181( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn182( state, next_func );
  case 1:
    return fwdfn184( state, next_func );
  case 2:
    return fwdfn185( state, next_func );
  default:
    return fwdfn186( state, next_func );
  }
}

static int fwdfn180( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn181;
    return 15;
  } else {
    return fwdfn181( state, next_func );
  }
}

static int fwdfn179( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    return fwdfn180( state, next_func );
  } else {
    return fwdfn181( state, next_func );
  }
}

static int fwdfn189( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn176;
    return 7;
  } else {
    return fwdfn176( state, next_func );
  }
}

static int fwdfn188( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn189( state, next_func );
  } else {
    return fwdfn176( state, next_func );
  }
}

static int fwdfn174( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn175( state, next_func );
  case 1:
    return fwdfn179( state, next_func );
  case 2:
    return fwdfn176( state, next_func );
  default:
    return fwdfn188( state, next_func );
  }
}

static int fwdfn190( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn174;
    return 5;
  } else {
    return fwdfn174( state, next_func );
  }
}

static int fwdfn173( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 1 ) {
    return fwdfn190( state, next_func );
  } else {
    return fwdfn174( state, next_func );
  }
}

static int fwdfn0( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn59( state, next_func );
  case 1:
    return fwdfn105( state, next_func );
  case 2:
    return fwdfn153( state, next_func );
  default:
    return fwdfn173( state, next_func );
  }
}

static void bwdrule1( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = 1;
  child_state->vars[ 24 ] = 3;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule2( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = 1;
  child_state->vars[ 25 ] = 3;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule3( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = 1;
  child_state->vars[ 31 ] = 3;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule4( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = 1;
  child_state->vars[ 32 ] = 3;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule5( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = 1;
  child_state->vars[ 24 ] = 0;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule6( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = 1;
  child_state->vars[ 25 ] = 0;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule7( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = 1;
  child_state->vars[ 31 ] = 0;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule8( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = 1;
  child_state->vars[ 32 ] = 0;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule9( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 3;
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 1;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule10( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = 3;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 1;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule11( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 3;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 1;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule12( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 3;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 1;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule13( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 1;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 0;
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule14( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 1;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 0;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule15( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 0;
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 1;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule16( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = 0;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 1;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule17( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 0;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 1;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule18( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 0;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 1;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule19( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 1;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 3;
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule20( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 1;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 3;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule21( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 0;
  child_state->vars[ 9 ] = 3;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule22( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 0;
  child_state->vars[ 16 ] = 3;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule23( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule24( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = 3;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule25( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = 0;
  child_state->vars[ 25 ] = 3;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule26( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule27( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = 3;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule28( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = 0;
  child_state->vars[ 32 ] = 3;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule29( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 0;
  child_state->vars[ 37 ] = 3;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule30( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 3;
  child_state->vars[ 9 ] = 0;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule31( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 3;
  child_state->vars[ 16 ] = 0;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule32( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule33( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = 0;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule34( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = 3;
  child_state->vars[ 25 ] = 0;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule35( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule36( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = 0;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule37( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = 3;
  child_state->vars[ 32 ] = 0;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule38( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 3;
  child_state->vars[ 37 ] = 0;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule39( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 3;
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 0;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule40( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = 3;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 0;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule41( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 3;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule42( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 3;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule43( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule44( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule45( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = 3;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = 0;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule46( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = 3;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = 0;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule47( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 0;
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule48( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 0;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule49( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = 0;
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 3;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule50( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = 0;
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 3;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule51( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = 0;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 3;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule52( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = 0;
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 3;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule53( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule54( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = 0;
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule55( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = 0;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = 3;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule56( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = 0;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = 3;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule57( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 3;
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static void bwdrule58( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 3;
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = state->vars[ 39 ];
  child_state->vars[ 40 ] = state->vars[ 40 ];
  child_state->vars[ 41 ] = state->vars[ 41 ];
  child_state->vars[ 42 ] = state->vars[ 42 ];
  child_state->vars[ 43 ] = state->vars[ 43 ];
  child_state->vars[ 44 ] = state->vars[ 44 ];
  child_state->vars[ 45 ] = state->vars[ 45 ];
  child_state->vars[ 46 ] = state->vars[ 46 ];
  child_state->vars[ 47 ] = state->vars[ 47 ];
  child_state->vars[ 48 ] = state->vars[ 48 ];
}

static actfuncptr bwd_rules[ 58 ] = { bwdrule1, bwdrule2, bwdrule3, bwdrule4, bwdrule5, bwdrule6, bwdrule7, bwdrule8, bwdrule9, bwdrule10, bwdrule11, bwdrule12, bwdrule13, bwdrule14, bwdrule15, bwdrule16, bwdrule17, bwdrule18, bwdrule19, bwdrule20, bwdrule21, bwdrule22, bwdrule23, bwdrule24, bwdrule25, bwdrule26, bwdrule27, bwdrule28, bwdrule29, bwdrule30, bwdrule31, bwdrule32, bwdrule33, bwdrule34, bwdrule35, bwdrule36, bwdrule37, bwdrule38, bwdrule39, bwdrule40, bwdrule41, bwdrule42, bwdrule43, bwdrule44, bwdrule45, bwdrule46, bwdrule47, bwdrule48, bwdrule49, bwdrule50, bwdrule51, bwdrule52, bwdrule53, bwdrule54, bwdrule55, bwdrule56, bwdrule57, bwdrule58 };

static int bwdfn14( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = 0;
    return 47;
  } else {
    return -1;
  }
}

static int bwdfn15( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = 0;
    return 57;
  } else {
    return -1;
  }
}

static int bwdfn13( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn14( state, next_func );
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    *((funcptr *)next_func) = bwdfn15;
    return 43;
  }
}

static int bwdfn16( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn14( state, next_func );
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    return bwdfn15( state, next_func );
  }
}

static int bwdfn17( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn14;
    return 53;
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    return bwdfn15( state, next_func );
  }
}

static int bwdfn12( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return bwdfn13( state, next_func );
  case 1:
    return bwdfn16( state, next_func );
  case 2:
    return bwdfn16( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn17;
    return 41;
  }
}

static int bwdfn11( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn12;
    return 49;
  } else {
    return bwdfn12( state, next_func );
  }
}

static int bwdfn20( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = 0;
    return 53;
  } else {
    return -1;
  }
}

static int bwdfn19( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn20;
    return 47;
  } else {
    return bwdfn20( state, next_func );
  }
}

static int bwdfn21( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn15;
    return 43;
  } else {
    return bwdfn15( state, next_func );
  }
}

static int bwdfn18( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn19( state, next_func );
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    return bwdfn21( state, next_func );
  }
}

static int bwdfn23( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn13;
    return 51;
  case 1:
    return bwdfn16( state, next_func );
  case 2:
    return bwdfn16( state, next_func );
  default:
    return bwdfn17( state, next_func );
  }
}

static int bwdfn22( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn23;
    return 39;
  } else {
    return bwdfn23( state, next_func );
  }
}

static int bwdfn10( const state_t *state, void *next_func )
{
  switch( state->vars[ 16 ] ) {
  case 0:
    return bwdfn11( state, next_func );
  case 1:
    return bwdfn18( state, next_func );
  case 2:
    return bwdfn18( state, next_func );
  default:
    return bwdfn22( state, next_func );
  }
}

static int bwdfn9( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn10;
    return 46;
  } else {
    return bwdfn10( state, next_func );
  }
}

static int bwdfn24( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn10;
    return 56;
  } else {
    return bwdfn10( state, next_func );
  }
}

static int bwdfn8( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn9( state, next_func );
  case 1:
    return bwdfn10( state, next_func );
  case 2:
    return bwdfn10( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn24;
    return 42;
  }
}

static int bwdfn7( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn8;
    return 48;
  } else {
    return bwdfn8( state, next_func );
  }
}

static int bwdfn6( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn7( state, next_func );
  case 1:
    return bwdfn8( state, next_func );
  case 2:
    return bwdfn8( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn8;
    return 50;
  }
}

static int bwdfn26( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn9( state, next_func );
  case 1:
    return bwdfn10( state, next_func );
  case 2:
    return bwdfn10( state, next_func );
  default:
    return bwdfn24( state, next_func );
  }
}

static int bwdfn27( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn26;
    return 48;
  } else {
    return bwdfn26( state, next_func );
  }
}

static int bwdfn25( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return bwdfn27( state, next_func );
  } else {
    return bwdfn26( state, next_func );
  }
}

static int bwdfn30( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn9;
    return 52;
  case 1:
    return bwdfn10( state, next_func );
  case 2:
    return bwdfn10( state, next_func );
  default:
    return bwdfn24( state, next_func );
  }
}

static int bwdfn29( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn30;
    return 48;
  } else {
    return bwdfn30( state, next_func );
  }
}

static int bwdfn28( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn29;
    return 40;
  } else {
    return bwdfn30( state, next_func );
  }
}

static int bwdfn5( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn6( state, next_func );
  case 1:
    return bwdfn25( state, next_func );
  case 2:
    return bwdfn25( state, next_func );
  default:
    return bwdfn28( state, next_func );
  }
}

static int bwdfn4( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn5;
    return 45;
  } else {
    return bwdfn5( state, next_func );
  }
}

static int bwdfn31( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn5;
    return 55;
  } else {
    return bwdfn5( state, next_func );
  }
}

static int bwdfn3( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return bwdfn4( state, next_func );
  case 1:
    return bwdfn5( state, next_func );
  case 2:
    return bwdfn5( state, next_func );
  default:
    return bwdfn31( state, next_func );
  }
}

static int bwdfn2( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn3;
    return 44;
  } else {
    return bwdfn3( state, next_func );
  }
}

static int bwdfn32( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn3;
    return 54;
  } else {
    return bwdfn3( state, next_func );
  }
}

static int bwdfn1( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return bwdfn2( state, next_func );
  case 1:
    return bwdfn3( state, next_func );
  case 2:
    return bwdfn3( state, next_func );
  default:
    return bwdfn32( state, next_func );
  }
}

static int bwdfn46( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 36;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn47( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 27;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn45( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn46( state, next_func );
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn47;
    return 35;
  }
}

static int bwdfn44( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn45;
    return 25;
  } else {
    return bwdfn45( state, next_func );
  }
}

static int bwdfn48( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn46( state, next_func );
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn47( state, next_func );
  }
}

static int bwdfn50( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn46;
    return 26;
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn47( state, next_func );
  }
}

static int bwdfn49( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn50;
    return 34;
  } else {
    return bwdfn50( state, next_func );
  }
}

static int bwdfn43( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn44( state, next_func );
  case 1:
    return bwdfn48( state, next_func );
  case 2:
    return bwdfn48( state, next_func );
  default:
    return bwdfn49( state, next_func );
  }
}

static int bwdfn42( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn43;
    return 33;
  } else {
    return bwdfn43( state, next_func );
  }
}

static int bwdfn51( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn43;
    return 24;
  } else {
    return bwdfn43( state, next_func );
  }
}

static int bwdfn41( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return bwdfn42( state, next_func );
  case 1:
    return bwdfn43( state, next_func );
  case 2:
    return bwdfn43( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn51;
    return 32;
  }
}

static int bwdfn40( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn41;
    return 22;
  } else {
    return bwdfn41( state, next_func );
  }
}

static int bwdfn52( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return bwdfn42( state, next_func );
  case 1:
    return bwdfn43( state, next_func );
  case 2:
    return bwdfn43( state, next_func );
  default:
    return bwdfn51( state, next_func );
  }
}

static int bwdfn54( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn42;
    return 23;
  case 1:
    return bwdfn43( state, next_func );
  case 2:
    return bwdfn43( state, next_func );
  default:
    return bwdfn51( state, next_func );
  }
}

static int bwdfn53( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn54;
    return 31;
  } else {
    return bwdfn54( state, next_func );
  }
}

static int bwdfn39( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return bwdfn40( state, next_func );
  case 1:
    return bwdfn52( state, next_func );
  case 2:
    return bwdfn52( state, next_func );
  default:
    return bwdfn53( state, next_func );
  }
}

static int bwdfn38( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn39;
    return 30;
  } else {
    return bwdfn39( state, next_func );
  }
}

static int bwdfn55( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn39;
    return 21;
  } else {
    return bwdfn39( state, next_func );
  }
}

static int bwdfn37( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn38( state, next_func );
  case 1:
    return bwdfn39( state, next_func );
  case 2:
    return bwdfn39( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn55;
    return 38;
  }
}

static int bwdfn36( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn37;
    return 29;
  } else {
    return bwdfn37( state, next_func );
  }
}

static int bwdfn56( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn38( state, next_func );
  case 1:
    return bwdfn39( state, next_func );
  case 2:
    return bwdfn39( state, next_func );
  default:
    return bwdfn55( state, next_func );
  }
}

static int bwdfn57( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn56;
    return 20;
  } else {
    return bwdfn56( state, next_func );
  }
}

static int bwdfn35( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return bwdfn36( state, next_func );
  case 1:
    return bwdfn56( state, next_func );
  case 2:
    return bwdfn56( state, next_func );
  default:
    return bwdfn57( state, next_func );
  }
}

static int bwdfn34( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn35;
    return 37;
  } else {
    return bwdfn35( state, next_func );
  }
}

static int bwdfn58( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn35;
    return 28;
  } else {
    return bwdfn35( state, next_func );
  }
}

static int bwdfn33( const state_t *state, void *next_func )
{
  switch( state->vars[ 36 ] ) {
  case 0:
    return bwdfn34( state, next_func );
  case 1:
    return bwdfn35( state, next_func );
  case 2:
    return bwdfn35( state, next_func );
  default:
    return bwdfn58( state, next_func );
  }
}

static int bwdfn63( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 16;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn62( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn63;
    return 6;
  } else {
    return bwdfn63( state, next_func );
  }
}

static int bwdfn65( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 10;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn64( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn65;
    return 2;
  } else {
    return bwdfn65( state, next_func );
  }
}

static int bwdfn61( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn33( state, next_func );
  case 1:
    return bwdfn62( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn64( state, next_func );
  }
}

static int bwdfn70( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 10;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn71( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 16;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn69( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn33( state, next_func );
  case 1:
    return bwdfn70( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn71( state, next_func );
  }
}

static int bwdfn68( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn69;
    return 17;
  } else {
    return bwdfn69( state, next_func );
  }
}

static int bwdfn67( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn68;
    return 7;
  } else {
    return bwdfn68( state, next_func );
  }
}

static int bwdfn66( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn67( state, next_func );
  } else {
    return bwdfn68( state, next_func );
  }
}

static int bwdfn74( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn69;
    return 11;
  } else {
    return bwdfn69( state, next_func );
  }
}

static int bwdfn73( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn74;
    return 3;
  } else {
    return bwdfn74( state, next_func );
  }
}

static int bwdfn72( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn73( state, next_func );
  } else {
    return bwdfn74( state, next_func );
  }
}

static int bwdfn60( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn61( state, next_func );
  case 1:
    return bwdfn66( state, next_func );
  case 2:
    return bwdfn69( state, next_func );
  default:
    return bwdfn72( state, next_func );
  }
}

static int bwdfn79( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 12;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn80( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 6;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn81( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 2;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn78( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn79( state, next_func );
  case 1:
    return bwdfn80( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn81( state, next_func );
  }
}

static int bwdfn86( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 17;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn85( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn86;
    return 12;
  } else {
    return bwdfn86( state, next_func );
  }
}

static int bwdfn84( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    return bwdfn85( state, next_func );
  } else {
    return bwdfn86( state, next_func );
  }
}

static int bwdfn83( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn84;
    return 7;
  } else {
    return bwdfn84( state, next_func );
  }
}

static int bwdfn82( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn83( state, next_func );
  } else {
    return bwdfn84( state, next_func );
  }
}

static int bwdfn87( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    return bwdfn79( state, next_func );
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn90( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn87;
    return 11;
  } else {
    return bwdfn87( state, next_func );
  }
}

static int bwdfn89( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn90;
    return 3;
  } else {
    return bwdfn90( state, next_func );
  }
}

static int bwdfn88( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn89( state, next_func );
  } else {
    return bwdfn90( state, next_func );
  }
}

static int bwdfn77( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn78( state, next_func );
  case 1:
    return bwdfn82( state, next_func );
  case 2:
    return bwdfn87( state, next_func );
  default:
    return bwdfn88( state, next_func );
  }
}

static int bwdfn91( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn77;
    return 14;
  } else {
    return bwdfn77( state, next_func );
  }
}

static int bwdfn76( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return bwdfn91( state, next_func );
  } else {
    return bwdfn77( state, next_func );
  }
}

static int bwdfn75( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn76;
    return 4;
  } else {
    return bwdfn76( state, next_func );
  }
}

static int bwdfn93( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn33( state, next_func );
  case 1:
    return bwdfn80( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn81( state, next_func );
  }
}

static int bwdfn95( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn86;
    return 7;
  } else {
    return bwdfn86( state, next_func );
  }
}

static int bwdfn94( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn95( state, next_func );
  } else {
    return bwdfn86( state, next_func );
  }
}

static int bwdfn98( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 11;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn97( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn98;
    return 3;
  } else {
    return bwdfn98( state, next_func );
  }
}

static int bwdfn96( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn97( state, next_func );
  } else {
    return bwdfn98( state, next_func );
  }
}

static int bwdfn92( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn93( state, next_func );
  case 1:
    return bwdfn94( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn96( state, next_func );
  }
}

static int bwdfn103( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 18;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn102( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn103( state, next_func );
  case 1:
    return bwdfn80( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn81( state, next_func );
  }
}

static int bwdfn107( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    return bwdfn103( state, next_func );
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn106( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn107;
    return 17;
  } else {
    return bwdfn107( state, next_func );
  }
}

static int bwdfn105( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn106;
    return 7;
  } else {
    return bwdfn106( state, next_func );
  }
}

static int bwdfn104( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn105( state, next_func );
  } else {
    return bwdfn106( state, next_func );
  }
}

static int bwdfn110( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn107;
    return 11;
  } else {
    return bwdfn107( state, next_func );
  }
}

static int bwdfn109( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn110;
    return 3;
  } else {
    return bwdfn110( state, next_func );
  }
}

static int bwdfn108( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn109( state, next_func );
  } else {
    return bwdfn110( state, next_func );
  }
}

static int bwdfn101( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn102( state, next_func );
  case 1:
    return bwdfn104( state, next_func );
  case 2:
    return bwdfn107( state, next_func );
  default:
    return bwdfn108( state, next_func );
  }
}

static int bwdfn111( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn101;
    return 8;
  } else {
    return bwdfn101( state, next_func );
  }
}

static int bwdfn100( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 1 ) {
    return bwdfn111( state, next_func );
  } else {
    return bwdfn101( state, next_func );
  }
}

static int bwdfn99( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn100;
    return 0;
  } else {
    return bwdfn100( state, next_func );
  }
}

static int bwdfn59( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn60( state, next_func );
  case 1:
    return bwdfn75( state, next_func );
  case 2:
    return bwdfn92( state, next_func );
  default:
    return bwdfn99( state, next_func );
  }
}

static int bwdfn121( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 14;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn120( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return bwdfn121( state, next_func );
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn119( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn120;
    return 12;
  } else {
    return bwdfn120( state, next_func );
  }
}

static int bwdfn123( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn103;
    return 8;
  } else {
    return bwdfn103( state, next_func );
  }
}

static int bwdfn122( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 1 ) {
    return bwdfn123( state, next_func );
  } else {
    return bwdfn103( state, next_func );
  }
}

static int bwdfn118( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn33( state, next_func );
  case 1:
    return bwdfn119( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn122( state, next_func );
  }
}

static int bwdfn117( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn118;
    return 13;
  } else {
    return bwdfn118( state, next_func );
  }
}

static int bwdfn128( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 8;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn129( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 14;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn127( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return bwdfn33( state, next_func );
  case 1:
    return bwdfn128( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn129( state, next_func );
  }
}

static int bwdfn130( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 16;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn126( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn127( state, next_func );
  case 1:
    return bwdfn33( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn130( state, next_func );
  }
}

static int bwdfn125( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn126;
    return 13;
  } else {
    return bwdfn126( state, next_func );
  }
}

static int bwdfn124( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn125;
    return 6;
  } else {
    return bwdfn125( state, next_func );
  }
}

static int bwdfn133( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    return bwdfn128( state, next_func );
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn134( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    return bwdfn129( state, next_func );
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn132( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return bwdfn33( state, next_func );
  case 1:
    return bwdfn133( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn134( state, next_func );
  }
}

static int bwdfn131( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn132;
    return 13;
  } else {
    return bwdfn132( state, next_func );
  }
}

static int bwdfn138( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 10;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn137( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn127( state, next_func );
  case 1:
    return bwdfn138( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn33( state, next_func );
  }
}

static int bwdfn136( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn137;
    return 13;
  } else {
    return bwdfn137( state, next_func );
  }
}

static int bwdfn135( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn136;
    return 2;
  } else {
    return bwdfn136( state, next_func );
  }
}

static int bwdfn116( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn117( state, next_func );
  case 1:
    return bwdfn124( state, next_func );
  case 2:
    return bwdfn131( state, next_func );
  default:
    return bwdfn135( state, next_func );
  }
}

static int bwdfn139( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn116;
    return 15;
  } else {
    return bwdfn116( state, next_func );
  }
}

static int bwdfn115( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    return bwdfn139( state, next_func );
  } else {
    return bwdfn116( state, next_func );
  }
}

static int bwdfn144( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    return bwdfn119( state, next_func );
  } else {
    return bwdfn120( state, next_func );
  }
}

static int bwdfn146( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn107;
    return 8;
  } else {
    return bwdfn107( state, next_func );
  }
}

static int bwdfn145( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 1 ) {
    return bwdfn146( state, next_func );
  } else {
    return bwdfn107( state, next_func );
  }
}

static int bwdfn143( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn69( state, next_func );
  case 1:
    return bwdfn144( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn145( state, next_func );
  }
}

static int bwdfn147( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn143;
    return 15;
  } else {
    return bwdfn143( state, next_func );
  }
}

static int bwdfn142( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    return bwdfn147( state, next_func );
  } else {
    return bwdfn143( state, next_func );
  }
}

static int bwdfn141( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn142;
    return 7;
  } else {
    return bwdfn142( state, next_func );
  }
}

static int bwdfn140( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn141( state, next_func );
  } else {
    return bwdfn142( state, next_func );
  }
}

static int bwdfn149( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn142;
    return 3;
  } else {
    return bwdfn142( state, next_func );
  }
}

static int bwdfn148( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn149( state, next_func );
  } else {
    return bwdfn142( state, next_func );
  }
}

static int bwdfn114( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn115( state, next_func );
  case 1:
    return bwdfn140( state, next_func );
  case 2:
    return bwdfn142( state, next_func );
  default:
    return bwdfn148( state, next_func );
  }
}

static int bwdfn113( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn114;
    return 5;
  } else {
    return bwdfn114( state, next_func );
  }
}

static int bwdfn112( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    return bwdfn113( state, next_func );
  } else {
    return bwdfn114( state, next_func );
  }
}

static int bwdfn154( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 7;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn153( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn154( state, next_func );
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn156( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn33;
    return 3;
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn155( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn156( state, next_func );
  } else {
    return bwdfn33( state, next_func );
  }
}

static int bwdfn152( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn33( state, next_func );
  case 1:
    return bwdfn153( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn155( state, next_func );
  }
}

static int bwdfn158( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn80( state, next_func );
  case 1:
    return bwdfn153( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn155( state, next_func );
  }
}

static int bwdfn157( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn158;
    return 16;
  } else {
    return bwdfn158( state, next_func );
  }
}

static int bwdfn160( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn81( state, next_func );
  case 1:
    return bwdfn153( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn155( state, next_func );
  }
}

static int bwdfn159( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn160;
    return 10;
  } else {
    return bwdfn160( state, next_func );
  }
}

static int bwdfn151( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn152( state, next_func );
  case 1:
    return bwdfn157( state, next_func );
  case 2:
    return bwdfn152( state, next_func );
  default:
    return bwdfn159( state, next_func );
  }
}

static int bwdfn163( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn152;
    return 12;
  } else {
    return bwdfn152( state, next_func );
  }
}

static int bwdfn162( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn163( state, next_func );
  case 1:
    return bwdfn158( state, next_func );
  case 2:
    return bwdfn152( state, next_func );
  default:
    return bwdfn160( state, next_func );
  }
}

static int bwdfn164( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn162;
    return 14;
  } else {
    return bwdfn162( state, next_func );
  }
}

static int bwdfn161( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return bwdfn164( state, next_func );
  } else {
    return bwdfn162( state, next_func );
  }
}

static int bwdfn165( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn93( state, next_func );
  case 1:
    return bwdfn153( state, next_func );
  case 2:
    return bwdfn33( state, next_func );
  default:
    return bwdfn155( state, next_func );
  }
}

static int bwdfn168( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn152;
    return 18;
  } else {
    return bwdfn152( state, next_func );
  }
}

static int bwdfn167( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn168( state, next_func );
  case 1:
    return bwdfn158( state, next_func );
  case 2:
    return bwdfn152( state, next_func );
  default:
    return bwdfn160( state, next_func );
  }
}

static int bwdfn169( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn167;
    return 8;
  } else {
    return bwdfn167( state, next_func );
  }
}

static int bwdfn166( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 1 ) {
    return bwdfn169( state, next_func );
  } else {
    return bwdfn167( state, next_func );
  }
}

static int bwdfn150( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn151( state, next_func );
  case 1:
    return bwdfn161( state, next_func );
  case 2:
    return bwdfn165( state, next_func );
  default:
    return bwdfn166( state, next_func );
  }
}

static int bwdfn176( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn118;
    return 9;
  } else {
    return bwdfn118( state, next_func );
  }
}

static int bwdfn175( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    return bwdfn176( state, next_func );
  } else {
    return bwdfn118( state, next_func );
  }
}

static int bwdfn179( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn126;
    return 9;
  } else {
    return bwdfn126( state, next_func );
  }
}

static int bwdfn178( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    return bwdfn179( state, next_func );
  } else {
    return bwdfn126( state, next_func );
  }
}

static int bwdfn177( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn178;
    return 6;
  } else {
    return bwdfn178( state, next_func );
  }
}

static int bwdfn181( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn132;
    return 9;
  } else {
    return bwdfn132( state, next_func );
  }
}

static int bwdfn180( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    return bwdfn181( state, next_func );
  } else {
    return bwdfn132( state, next_func );
  }
}

static int bwdfn184( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn137;
    return 9;
  } else {
    return bwdfn137( state, next_func );
  }
}

static int bwdfn183( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    return bwdfn184( state, next_func );
  } else {
    return bwdfn137( state, next_func );
  }
}

static int bwdfn182( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn183;
    return 2;
  } else {
    return bwdfn183( state, next_func );
  }
}

static int bwdfn174( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn175( state, next_func );
  case 1:
    return bwdfn177( state, next_func );
  case 2:
    return bwdfn180( state, next_func );
  default:
    return bwdfn182( state, next_func );
  }
}

static int bwdfn173( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn174;
    return 19;
  } else {
    return bwdfn174( state, next_func );
  }
}

static int bwdfn188( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn143;
    return 9;
  } else {
    return bwdfn143( state, next_func );
  }
}

static int bwdfn187( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    return bwdfn188( state, next_func );
  } else {
    return bwdfn143( state, next_func );
  }
}

static int bwdfn186( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn187;
    return 7;
  } else {
    return bwdfn187( state, next_func );
  }
}

static int bwdfn185( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn186( state, next_func );
  } else {
    return bwdfn187( state, next_func );
  }
}

static int bwdfn190( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn187;
    return 3;
  } else {
    return bwdfn187( state, next_func );
  }
}

static int bwdfn189( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn190( state, next_func );
  } else {
    return bwdfn187( state, next_func );
  }
}

static int bwdfn172( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn173( state, next_func );
  case 1:
    return bwdfn185( state, next_func );
  case 2:
    return bwdfn187( state, next_func );
  default:
    return bwdfn189( state, next_func );
  }
}

static int bwdfn171( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn172;
    return 1;
  } else {
    return bwdfn172( state, next_func );
  }
}

static int bwdfn170( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    return bwdfn171( state, next_func );
  } else {
    return bwdfn172( state, next_func );
  }
}

static int bwdfn0( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return bwdfn59( state, next_func );
  case 1:
    return bwdfn112( state, next_func );
  case 2:
    return bwdfn150( state, next_func );
  default:
    return bwdfn170( state, next_func );
  }
}


#define init_history 0

#define max_fwd_children 25

/* NOTE: FOR ALL OF THE MOVE ITERATOR DEFINITIONS funcptr
   MUST BE A VARIABLE. */

/* initialise a forward move iterator */
#define init_fwd_iter( ruleid_iter, state ) { \
  (*ruleid_iter).my_funcptr = fwdfn0 ; \
  (*ruleid_iter).my_state = state; \
}

/* use iterator to generate next applicable rule to apply 
   returns rule to use, -1 if there are no more rules to apply */
#define next_ruleid( ruleid_iter ) (((*ruleid_iter).my_funcptr)?((*ruleid_iter).my_funcptr)((*ruleid_iter).my_state,&((*ruleid_iter).my_funcptr)):-1)

/* apply a rule to a state */
#define apply_fwd_rule( rule, state, result ) fwd_rules[(rule)](state,result)
/* returns 0 if the rule is pruned, non-zero otherwise */
#define fwd_rule_valid_for_history( history, rule_used ) 1 
/* generate the next history from the current history and a rule */
#define next_fwd_history( history, rule_used ) 0 


static const int bw_max_children = 25;
#define max_bwd_children 25

/* initialise a backwards move iterator */
#define init_bwd_iter( ruleid_iter, state ) { \
  (*ruleid_iter).my_funcptr = bwdfn0 ; \
  (*ruleid_iter).my_state = state; \
}

/* apply a rule to a state */
#define apply_bwd_rule( rule, state, result ) bwd_rules[(rule)](state,result)
/* returns 0 if the rule is pruned, non-zero otherwise */
#define bwd_rule_valid_for_history( history, rule_used ) 1 
/* generate the next history from the current history and a rule */
#define next_bwd_history( history, rule_used ) 0 


/* returns 1 if state is a goal state, 0 otherwise */
static int is_goal( const state_t *state )
{
  if( state->vars[ 9 ] == 1 && state->vars[ 22 ] == 1 ) {
    return 1;
  }
  return 0;
}

static void init_goal_state( state_t *state, int goal_rule )
{
  switch( goal_rule ) {
  case 0:
    state->vars[ 0 ] = 0;
    state->vars[ 1 ] = 0;
    state->vars[ 2 ] = 0;
    state->vars[ 3 ] = 0;
    state->vars[ 4 ] = 0;
    state->vars[ 5 ] = 0;
    state->vars[ 6 ] = 0;
    state->vars[ 7 ] = 0;
    state->vars[ 8 ] = 0;
    state->vars[ 9 ] = 1;
    state->vars[ 10 ] = 0;
    state->vars[ 11 ] = 0;
    state->vars[ 12 ] = 0;
    state->vars[ 13 ] = 0;
    state->vars[ 14 ] = 0;
    state->vars[ 15 ] = 0;
    state->vars[ 16 ] = 0;
    state->vars[ 17 ] = 0;
    state->vars[ 18 ] = 0;
    state->vars[ 19 ] = 0;
    state->vars[ 20 ] = 0;
    state->vars[ 21 ] = 0;
    state->vars[ 22 ] = 1;
    state->vars[ 23 ] = 0;
    state->vars[ 24 ] = 0;
    state->vars[ 25 ] = 0;
    state->vars[ 26 ] = 0;
    state->vars[ 27 ] = 0;
    state->vars[ 28 ] = 0;
    state->vars[ 29 ] = 0;
    state->vars[ 30 ] = 0;
    state->vars[ 31 ] = 0;
    state->vars[ 32 ] = 0;
    state->vars[ 33 ] = 0;
    state->vars[ 34 ] = 0;
    state->vars[ 35 ] = 0;
    state->vars[ 36 ] = 0;
    state->vars[ 37 ] = 0;
    state->vars[ 38 ] = 0;
    state->vars[ 39 ] = 0;
    state->vars[ 40 ] = 0;
    state->vars[ 41 ] = 0;
    state->vars[ 42 ] = 0;
    state->vars[ 43 ] = 0;
    state->vars[ 44 ] = 0;
    state->vars[ 45 ] = 0;
    state->vars[ 46 ] = 0;
    state->vars[ 47 ] = 0;
    state->vars[ 48 ] = 0;
    break;
  }
}

/* get the first goal state and initialise iterator */
#define first_goal_state( state_ptr, int_ptr_goal_iter ) init_goal_state(state_ptr,*(int_ptr_goal_iter)=0)

/* get the next goal state
   returns 1 if there is another goal state, 0 otherwise */
static int8_t next_goal_state( state_t *state, int *goal_iter )
{
  switch( *goal_iter ) {
  case 0:
    if( state->vars[ 0 ] < 3 ) {
      ++state->vars[ 0 ];
      return 1;
    }
    state->vars[ 0 ] = 0;
    if( state->vars[ 1 ] < 3 ) {
      ++state->vars[ 1 ];
      return 1;
    }
    state->vars[ 1 ] = 0;
    if( state->vars[ 2 ] < 3 ) {
      ++state->vars[ 2 ];
      return 1;
    }
    state->vars[ 2 ] = 0;
    if( state->vars[ 3 ] < 3 ) {
      ++state->vars[ 3 ];
      return 1;
    }
    state->vars[ 3 ] = 0;
    if( state->vars[ 4 ] < 3 ) {
      ++state->vars[ 4 ];
      return 1;
    }
    state->vars[ 4 ] = 0;
    if( state->vars[ 5 ] < 3 ) {
      ++state->vars[ 5 ];
      return 1;
    }
    state->vars[ 5 ] = 0;
    if( state->vars[ 6 ] < 3 ) {
      ++state->vars[ 6 ];
      return 1;
    }
    state->vars[ 6 ] = 0;
    if( state->vars[ 7 ] < 3 ) {
      ++state->vars[ 7 ];
      return 1;
    }
    state->vars[ 7 ] = 0;
    if( state->vars[ 8 ] < 3 ) {
      ++state->vars[ 8 ];
      return 1;
    }
    state->vars[ 8 ] = 0;
    if( state->vars[ 10 ] < 3 ) {
      ++state->vars[ 10 ];
      return 1;
    }
    state->vars[ 10 ] = 0;
    if( state->vars[ 11 ] < 3 ) {
      ++state->vars[ 11 ];
      return 1;
    }
    state->vars[ 11 ] = 0;
    if( state->vars[ 12 ] < 3 ) {
      ++state->vars[ 12 ];
      return 1;
    }
    state->vars[ 12 ] = 0;
    if( state->vars[ 13 ] < 3 ) {
      ++state->vars[ 13 ];
      return 1;
    }
    state->vars[ 13 ] = 0;
    if( state->vars[ 14 ] < 3 ) {
      ++state->vars[ 14 ];
      return 1;
    }
    state->vars[ 14 ] = 0;
    if( state->vars[ 15 ] < 3 ) {
      ++state->vars[ 15 ];
      return 1;
    }
    state->vars[ 15 ] = 0;
    if( state->vars[ 16 ] < 3 ) {
      ++state->vars[ 16 ];
      return 1;
    }
    state->vars[ 16 ] = 0;
    if( state->vars[ 17 ] < 3 ) {
      ++state->vars[ 17 ];
      return 1;
    }
    state->vars[ 17 ] = 0;
    if( state->vars[ 18 ] < 3 ) {
      ++state->vars[ 18 ];
      return 1;
    }
    state->vars[ 18 ] = 0;
    if( state->vars[ 19 ] < 3 ) {
      ++state->vars[ 19 ];
      return 1;
    }
    state->vars[ 19 ] = 0;
    if( state->vars[ 20 ] < 3 ) {
      ++state->vars[ 20 ];
      return 1;
    }
    state->vars[ 20 ] = 0;
    if( state->vars[ 21 ] < 3 ) {
      ++state->vars[ 21 ];
      return 1;
    }
    state->vars[ 21 ] = 0;
    if( state->vars[ 23 ] < 3 ) {
      ++state->vars[ 23 ];
      return 1;
    }
    state->vars[ 23 ] = 0;
    if( state->vars[ 24 ] < 3 ) {
      ++state->vars[ 24 ];
      return 1;
    }
    state->vars[ 24 ] = 0;
    if( state->vars[ 25 ] < 3 ) {
      ++state->vars[ 25 ];
      return 1;
    }
    state->vars[ 25 ] = 0;
    if( state->vars[ 26 ] < 3 ) {
      ++state->vars[ 26 ];
      return 1;
    }
    state->vars[ 26 ] = 0;
    if( state->vars[ 27 ] < 3 ) {
      ++state->vars[ 27 ];
      return 1;
    }
    state->vars[ 27 ] = 0;
    if( state->vars[ 28 ] < 3 ) {
      ++state->vars[ 28 ];
      return 1;
    }
    state->vars[ 28 ] = 0;
    if( state->vars[ 29 ] < 3 ) {
      ++state->vars[ 29 ];
      return 1;
    }
    state->vars[ 29 ] = 0;
    if( state->vars[ 30 ] < 3 ) {
      ++state->vars[ 30 ];
      return 1;
    }
    state->vars[ 30 ] = 0;
    if( state->vars[ 31 ] < 3 ) {
      ++state->vars[ 31 ];
      return 1;
    }
    state->vars[ 31 ] = 0;
    if( state->vars[ 32 ] < 3 ) {
      ++state->vars[ 32 ];
      return 1;
    }
    state->vars[ 32 ] = 0;
    if( state->vars[ 33 ] < 3 ) {
      ++state->vars[ 33 ];
      return 1;
    }
    state->vars[ 33 ] = 0;
    if( state->vars[ 34 ] < 3 ) {
      ++state->vars[ 34 ];
      return 1;
    }
    state->vars[ 34 ] = 0;
    if( state->vars[ 35 ] < 3 ) {
      ++state->vars[ 35 ];
      return 1;
    }
    state->vars[ 35 ] = 0;
    if( state->vars[ 36 ] < 3 ) {
      ++state->vars[ 36 ];
      return 1;
    }
    state->vars[ 36 ] = 0;
    if( state->vars[ 37 ] < 3 ) {
      ++state->vars[ 37 ];
      return 1;
    }
    state->vars[ 37 ] = 0;
    if( state->vars[ 38 ] < 3 ) {
      ++state->vars[ 38 ];
      return 1;
    }
    state->vars[ 38 ] = 0;
    if( state->vars[ 39 ] < 3 ) {
      ++state->vars[ 39 ];
      return 1;
    }
    state->vars[ 39 ] = 0;
    if( state->vars[ 40 ] < 3 ) {
      ++state->vars[ 40 ];
      return 1;
    }
    state->vars[ 40 ] = 0;
    if( state->vars[ 41 ] < 3 ) {
      ++state->vars[ 41 ];
      return 1;
    }
    state->vars[ 41 ] = 0;
    if( state->vars[ 42 ] < 3 ) {
      ++state->vars[ 42 ];
      return 1;
    }
    state->vars[ 42 ] = 0;
    if( state->vars[ 43 ] < 3 ) {
      ++state->vars[ 43 ];
      return 1;
    }
    state->vars[ 43 ] = 0;
    if( state->vars[ 44 ] < 3 ) {
      ++state->vars[ 44 ];
      return 1;
    }
    state->vars[ 44 ] = 0;
    if( state->vars[ 45 ] < 3 ) {
      ++state->vars[ 45 ];
      return 1;
    }
    state->vars[ 45 ] = 0;
    if( state->vars[ 46 ] < 3 ) {
      ++state->vars[ 46 ];
      return 1;
    }
    state->vars[ 46 ] = 0;
    if( state->vars[ 47 ] < 3 ) {
      ++state->vars[ 47 ];
      return 1;
    }
    state->vars[ 47 ] = 0;
    if( state->vars[ 48 ] < 3 ) {
      ++state->vars[ 48 ];
      return 1;
    }
    return 0;
  }
  return 0;
}

/*
Copyright (C) 2011, 2014 by the PSVN Research Group, University of Alberta
*/

#include <string.h>

/* copy a state */
#define copy_state(dest_ptr,src_ptr) memcpy(dest_ptr,src_ptr,sizeof(var_t)*NUMVARS)

/* compare two state pointers
   returns 0 if equal, non-zero otherwise */
#define compare_states(a,b) memcmp(a,b,sizeof(var_t)*NUMVARS)


/* print a state to a file
   returns number of characters on success, -1 on failure */
static ssize_t print_state( FILE *file, const state_t *state )
{
  size_t len, t; int i;
  for( len = 0, i = 0; i < NUMVARS; ++i ) {
    t = fprintf( file, "%s ", var_domain_names[ i ][ state->vars[ i ] ] );
    if( t < 0 ) { return -1; }
    len += t;
  }
  return len;
}

/* print a state to a string
   returns number of characters on success, -1 on failure */
static ssize_t sprint_state( char *string,const size_t max_len,const state_t *state )
{
  size_t len, t; int i;
  for( len = 0, i = 0; i < NUMVARS; ++i ) {
    t = snprintf( &string[ len ], max_len - len, "%s ",
		  var_domain_names[ i ][ state->vars[ i ] ] );
    if( t < 0 ) { return -1; }
    len += t;
  }
  if( len >= max_len ) { return -1; } else { string[ len ] = 0; }
  return len;
}

/* read a state from a string
   returns number of characters consumed on success, -1 on failure
   NOTE: the part of the string representing the state must be
   followed either by whitespace (which will all be consumed) or
   the end of string marker */
static ssize_t read_state( const char *string, state_t *state )
{
  size_t len, t; int i; var_t j;
  len = 0;
  while( (string[len] !=0) && isspace(string[len]) ) { len++; } // skip leading white space
  for( i = 0; i < NUMVARS; ++i ) {
    for( j = 0; j < domain_sizes[ var_domains[ i ] ]; ++j ) {
      t = strlen( var_domain_names[ i ][ j ] );
      if( !strncasecmp( var_domain_names[ i ][ j ], &string[ len ], t ) ) {
          if( (string[len+t] ==0) || isspace(string[len+t]) ) { // require a terminator after the match
	      state->vars[ i ] = j;
	      len += t;
              while( (string[len] !=0) && isspace(string[len]) ) { len++; } // skip the following white space
              break;
          }
      }
    }
    if( j >= domain_sizes[ var_domains[ i ] ] ) { return -1; }
  }
  return len;
}

/* dump a raw state to a file
   returns 1 on success, 0 on failure */
#define dump_state( file, state_ptr ) fwrite(state_ptr,sizeof(var_t)*NUMVARS,1,file)

/* load a raw state from a file
   returns 1 on success, 0 on failure */
#define load_state( file, state_ptr ) fread(state_ptr,sizeof(var_t)*NUMVARS,1,file)




/*
-------------------------------------------------------------------------------
lookup3.c, by Bob Jenkins, May 2006, Public Domain.

These are functions for producing 32-bit hashes for hash table lookup.
hashword(), hashlittle(), hashlittle2(), hashbig(), mix(), and final() 
are externally useful functions.  Routines to test the hash are included 
if SELF_TEST is defined.  You can use this free for any purpose.  It's in
the public domain.  It has no warranty.

You probably want to use hashlittle().  hashlittle() and hashbig()
hash byte arrays.  hashlittle() is is faster than hashbig() on
little-endian machines.  Intel and AMD are little-endian machines.
On second thought, you probably want hashlittle2(), which is identical to
hashlittle() except it returns two 32-bit hashes for the price of one.  
You could implement hashbig2() if you wanted but I haven't bothered here.

If you want to find a hash of, say, exactly 7 integers, do
  a = i1;  b = i2;  c = i3;
  mix(a,b,c);
  a += i4; b += i5; c += i6;
  mix(a,b,c);
  a += i7;
  final(a,b,c);
then use c as the hash value.  If you have a variable length array of
4-byte integers to hash, use hashword().  If you have a byte array (like
a character string), use hashlittle().  If you have several byte arrays, or
a mix of things, see the comments above hashlittle().  

Why is this so big?  I read 12 bytes at a time into 3 4-byte integers, 
then mix those integers.  This is fast (you can do a lot more thorough
mixing with 12*3 instructions on 3 integers than you can with 3 instructions
on 1 byte), but shoehorning those bytes into integers efficiently is messy.
-------------------------------------------------------------------------------
*/
#include <sys/param.h>  /* attempt to define endianness */
#ifdef linux
# include <endian.h>    /* attempt to define endianness */
#endif

/*
 * My best guess at if you are big-endian or little-endian.  This may
 * need adjustment.
 */
#if (defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && \
     __BYTE_ORDER == __LITTLE_ENDIAN) || \
    (defined(i386) || defined(__i386__) || defined(__i486__) || \
     defined(__i586__) || defined(__i686__) || defined(vax) || defined(MIPSEL))
# define HASH_LITTLE_ENDIAN 1
# define HASH_BIG_ENDIAN 0
#elif (defined(__BYTE_ORDER) && defined(__BIG_ENDIAN) && \
       __BYTE_ORDER == __BIG_ENDIAN) || \
      (defined(sparc) || defined(POWERPC) || defined(mc68000) || defined(sel))
# define HASH_LITTLE_ENDIAN 0
# define HASH_BIG_ENDIAN 1
#else
# define HASH_LITTLE_ENDIAN 0
# define HASH_BIG_ENDIAN 0
#endif

#define rot(x,k) (((x)<<(k)) ^ ((x)>>(32-(k))))

/*
-------------------------------------------------------------------------------
mix -- mix 3 32-bit values reversibly.

This is reversible, so any information in (a,b,c) before mix() is
still in (a,b,c) after mix().

If four pairs of (a,b,c) inputs are run through mix(), or through
mix() in reverse, there are at least 32 bits of the output that
are sometimes the same for one pair and different for another pair.
This was tested for:
* pairs that differed by one bit, by two bits, in any combination
  of top bits of (a,b,c), or in any combination of bottom bits of
  (a,b,c).
* "differ" is defined as +, -, ^, or ~^.  For + and -, I transformed
  the output delta to a Gray code (a^(a>>1)) so a string of 1's (as
  is commonly produced by subtraction) look like a single 1-bit
  difference.
* the base values were pseudorandom, all zero but one bit set, or 
  all zero plus a counter that starts at zero.

Some k values for my "a-=c; a^=rot(c,k); c+=b;" arrangement that
satisfy this are
    4  6  8 16 19  4
    9 15  3 18 27 15
   14  9  3  7 17  3
Well, "9 15 3 18 27 15" didn't quite get 32 bits diffing
for "differ" defined as + with a one-bit base and a two-bit delta.  I
used http://burtleburtle.net/bob/hash/avalanche.html to choose 
the operations, constants, and arrangements of the variables.

This does not achieve avalanche.  There are input bits of (a,b,c)
that fail to affect some output bits of (a,b,c), especially of a.  The
most thoroughly mixed value is c, but it doesn't really even achieve
avalanche in c.

This allows some parallelism.  Read-after-writes are good at doubling
the number of bits affected, so the goal of mixing pulls in the opposite
direction as the goal of parallelism.  I did what I could.  Rotates
seem to cost as much as shifts on every machine I could lay my hands
on, and rotates are much kinder to the top and bottom bits, so I used
rotates.
-------------------------------------------------------------------------------
*/
#define mix(a,b,c) \
{ \
  a -= c;  a ^= rot(c, 4);  c += b; \
  b -= a;  b ^= rot(a, 6);  a += c; \
  c -= b;  c ^= rot(b, 8);  b += a; \
  a -= c;  a ^= rot(c,16);  c += b; \
  b -= a;  b ^= rot(a,19);  a += c; \
  c -= b;  c ^= rot(b, 4);  b += a; \
}

/*
-------------------------------------------------------------------------------
final -- final mixing of 3 32-bit values (a,b,c) into c

Pairs of (a,b,c) values differing in only a few bits will usually
produce values of c that look totally different.  This was tested for
* pairs that differed by one bit, by two bits, in any combination
  of top bits of (a,b,c), or in any combination of bottom bits of
  (a,b,c).
* "differ" is defined as +, -, ^, or ~^.  For + and -, I transformed
  the output delta to a Gray code (a^(a>>1)) so a string of 1's (as
  is commonly produced by subtraction) look like a single 1-bit
  difference.
* the base values were pseudorandom, all zero but one bit set, or 
  all zero plus a counter that starts at zero.

These constants passed:
 14 11 25 16 4 14 24
 12 14 25 16 4 14 24
and these came close:
  4  8 15 26 3 22 24
 10  8 15 26 3 22 24
 11  8 15 26 3 22 24
-------------------------------------------------------------------------------
*/
#define final(a,b,c) \
{ \
  c ^= b; c -= rot(b,14); \
  a ^= c; a -= rot(c,11); \
  b ^= a; b -= rot(a,25); \
  c ^= b; c -= rot(b,16); \
  a ^= c; a -= rot(c,4);  \
  b ^= a; b -= rot(a,14); \
  c ^= b; c -= rot(b,24); \
}

/*
 * hashlittle2: return 2 32-bit hash values
 *
 * This is identical to hashlittle(), except it returns two 32-bit hash
 * values instead of just one.  This is good enough for hash table
 * lookup with 2^^64 buckets, or if you want a second hash if you're not
 * happy with the first, or if you want a probably-unique 64-bit ID for
 * the key.  *pc is better mixed than *pb, so use *pc first.  If you want
 * a 64-bit value do something like "*pc + (((uint64_t)*pb)<<32)".
 */
static void hashlittle2( 
  const void *key,       /* the key to hash */
  size_t      length,    /* length of the key */
  uint32_t   *pc,        /* IN: primary initval, OUT: primary hash */
  uint32_t   *pb)        /* IN: secondary initval, OUT: secondary hash */
{
  uint32_t a,b,c;                                          /* internal state */
  union { const void *ptr; size_t i; } u;     /* needed for Mac Powerbook G4 */

  /* Set up the internal state */
  a = b = c = 0xdeadbeef + ((uint32_t)length) + *pc;
  c += *pb;

  u.ptr = key;
  if (HASH_LITTLE_ENDIAN && ((u.i & 0x3) == 0)) {
    const uint32_t *k = (const uint32_t *)key;         /* read 32-bit chunks */
#ifdef VALGRIND
    const uint8_t  *k8;
#endif

    /*------ all but last block: aligned reads and affect 32 bits of (a,b,c) */
    while (length > 12)
    {
      a += k[0];
      b += k[1];
      c += k[2];
      mix(a,b,c);
      length -= 12;
      k += 3;
    }

    /*----------------------------- handle the last (probably partial) block */
    /* 
     * "k[2]&0xffffff" actually reads beyond the end of the string, but
     * then masks off the part it's not allowed to read.  Because the
     * string is aligned, the masked-off tail is in the same word as the
     * rest of the string.  Every machine with memory protection I've seen
     * does it on word boundaries, so is OK with this.  But VALGRIND will
     * still catch it and complain.  The masking trick does make the hash
     * noticably faster for short strings (like English words).
     */
#ifndef VALGRIND

    switch(length)
    {
    case 12: c+=k[2]; b+=k[1]; a+=k[0]; break;
    case 11: c+=k[2]&0xffffff; b+=k[1]; a+=k[0]; break;
    case 10: c+=k[2]&0xffff; b+=k[1]; a+=k[0]; break;
    case 9 : c+=k[2]&0xff; b+=k[1]; a+=k[0]; break;
    case 8 : b+=k[1]; a+=k[0]; break;
    case 7 : b+=k[1]&0xffffff; a+=k[0]; break;
    case 6 : b+=k[1]&0xffff; a+=k[0]; break;
    case 5 : b+=k[1]&0xff; a+=k[0]; break;
    case 4 : a+=k[0]; break;
    case 3 : a+=k[0]&0xffffff; break;
    case 2 : a+=k[0]&0xffff; break;
    case 1 : a+=k[0]&0xff; break;
    case 0 : *pc=c; *pb=b; return;  /* zero length strings require no mixing */
    }

#else /* make valgrind happy */

    k8 = (const uint8_t *)k;
    switch(length)
    {
    case 12: c+=k[2]; b+=k[1]; a+=k[0]; break;
    case 11: c+=((uint32_t)k8[10])<<16;  /* fall through */
    case 10: c+=((uint32_t)k8[9])<<8;    /* fall through */
    case 9 : c+=k8[8];                   /* fall through */
    case 8 : b+=k[1]; a+=k[0]; break;
    case 7 : b+=((uint32_t)k8[6])<<16;   /* fall through */
    case 6 : b+=((uint32_t)k8[5])<<8;    /* fall through */
    case 5 : b+=k8[4];                   /* fall through */
    case 4 : a+=k[0]; break;
    case 3 : a+=((uint32_t)k8[2])<<16;   /* fall through */
    case 2 : a+=((uint32_t)k8[1])<<8;    /* fall through */
    case 1 : a+=k8[0]; break;
    case 0 : *pc=c; *pb=b; return;  /* zero length strings require no mixing */
    }

#endif /* !valgrind */

  } else if (HASH_LITTLE_ENDIAN && ((u.i & 0x1) == 0)) {
    const uint16_t *k = (const uint16_t *)key;         /* read 16-bit chunks */
    const uint8_t  *k8;

    /*--------------- all but last block: aligned reads and different mixing */
    while (length > 12)
    {
      a += k[0] + (((uint32_t)k[1])<<16);
      b += k[2] + (((uint32_t)k[3])<<16);
      c += k[4] + (((uint32_t)k[5])<<16);
      mix(a,b,c);
      length -= 12;
      k += 6;
    }

    /*----------------------------- handle the last (probably partial) block */
    k8 = (const uint8_t *)k;
    switch(length)
    {
    case 12: c+=k[4]+(((uint32_t)k[5])<<16);
             b+=k[2]+(((uint32_t)k[3])<<16);
             a+=k[0]+(((uint32_t)k[1])<<16);
             break;
    case 11: c+=((uint32_t)k8[10])<<16;     /* fall through */
    case 10: c+=k[4];
             b+=k[2]+(((uint32_t)k[3])<<16);
             a+=k[0]+(((uint32_t)k[1])<<16);
             break;
    case 9 : c+=k8[8];                      /* fall through */
    case 8 : b+=k[2]+(((uint32_t)k[3])<<16);
             a+=k[0]+(((uint32_t)k[1])<<16);
             break;
    case 7 : b+=((uint32_t)k8[6])<<16;      /* fall through */
    case 6 : b+=k[2];
             a+=k[0]+(((uint32_t)k[1])<<16);
             break;
    case 5 : b+=k8[4];                      /* fall through */
    case 4 : a+=k[0]+(((uint32_t)k[1])<<16);
             break;
    case 3 : a+=((uint32_t)k8[2])<<16;      /* fall through */
    case 2 : a+=k[0];
             break;
    case 1 : a+=k8[0];
             break;
    case 0 : *pc=c; *pb=b; return;  /* zero length strings require no mixing */
    }

  } else {                        /* need to read the key one byte at a time */
    const uint8_t *k = (const uint8_t *)key;

    /*--------------- all but the last block: affect some 32 bits of (a,b,c) */
    while (length > 12)
    {
      a += k[0];
      a += ((uint32_t)k[1])<<8;
      a += ((uint32_t)k[2])<<16;
      a += ((uint32_t)k[3])<<24;
      b += k[4];
      b += ((uint32_t)k[5])<<8;
      b += ((uint32_t)k[6])<<16;
      b += ((uint32_t)k[7])<<24;
      c += k[8];
      c += ((uint32_t)k[9])<<8;
      c += ((uint32_t)k[10])<<16;
      c += ((uint32_t)k[11])<<24;
      mix(a,b,c);
      length -= 12;
      k += 12;
    }

    /*-------------------------------- last block: affect all 32 bits of (c) */
    switch(length)                   /* all the case statements fall through */
    {
    case 12: c+=((uint32_t)k[11])<<24;
    case 11: c+=((uint32_t)k[10])<<16;
    case 10: c+=((uint32_t)k[9])<<8;
    case 9 : c+=k[8];
    case 8 : b+=((uint32_t)k[7])<<24;
    case 7 : b+=((uint32_t)k[6])<<16;
    case 6 : b+=((uint32_t)k[5])<<8;
    case 5 : b+=k[4];
    case 4 : a+=((uint32_t)k[3])<<24;
    case 3 : a+=((uint32_t)k[2])<<16;
    case 2 : a+=((uint32_t)k[1])<<8;
    case 1 : a+=k[0];
             break;
    case 0 : *pc=c; *pb=b; return;  /* zero length strings require no mixing */
    }
  }

  final(a,b,c);
  *pc=c; *pb=b; return;             /* zero length strings require no mixing */
}
/* ----------------------------------------------------------------------
   end lookup3
   ---------------------------------------------------------------------- */





static uint64_t hash_state( const state_t *state )
{
  uint32_t a, b;

  a = 0; b = 0; hashlittle2( state, sizeof( var_t ) * NUMVARS, &a, &b );
  return ( (uint64_t)a << 32 ) | b;
}




