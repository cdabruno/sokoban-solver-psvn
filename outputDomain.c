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

#define num_fwd_rules 90
#define num_bwd_rules 90
static const char *fwd_rule_name[ 90 ] = { "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN" };
#define get_fwd_rule_label( ruleid ) (fwd_rule_name[(ruleid)]) 
static const char *bwd_rule_name[ 90 ] = { "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN" };
#define get_bwd_rule_label( ruleid ) (bwd_rule_name[(ruleid)]) 
#define cost_of_cheapest_fwd_rule 0
#define cost_of_costliest_fwd_rule 1
static const int fwd_rule_cost[ 90 ] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#define get_fwd_rule_cost( ruleid ) (fwd_rule_cost[(ruleid)]) 
#define cost_of_cheapest_bwd_rule 0
#define cost_of_costliest_bwd_rule 1
static const int bwd_rule_cost[ 90 ] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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
  child_state->vars[ 8 ] = 3;
  child_state->vars[ 9 ] = 0;
  child_state->vars[ 10 ] = 1;
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
  child_state->vars[ 9 ] = 3;
  child_state->vars[ 10 ] = 0;
  child_state->vars[ 11 ] = 1;
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
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 3;
  child_state->vars[ 37 ] = 0;
  child_state->vars[ 38 ] = 1;
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
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 3;
  child_state->vars[ 38 ] = 0;
  child_state->vars[ 39 ] = 1;
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
  child_state->vars[ 9 ] = 0;
  child_state->vars[ 10 ] = 3;
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
  child_state->vars[ 10 ] = 0;
  child_state->vars[ 11 ] = 3;
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
  child_state->vars[ 36 ] = 1;
  child_state->vars[ 37 ] = 0;
  child_state->vars[ 38 ] = 3;
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
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 1;
  child_state->vars[ 38 ] = 0;
  child_state->vars[ 39 ] = 3;
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
  child_state->vars[ 10 ] = 1;
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 0;
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
  child_state->vars[ 11 ] = 1;
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = 0;
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
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 1;
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
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = 1;
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
  child_state->vars[ 24 ] = 1;
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
  child_state->vars[ 38 ] = 3;
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
  child_state->vars[ 25 ] = 1;
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
  child_state->vars[ 39 ] = 3;
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
  child_state->vars[ 10 ] = 3;
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 0;
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
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
  child_state->vars[ 11 ] = 3;
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = 0;
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
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
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 3;
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
  child_state->vars[ 18 ] = 3;
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
  child_state->vars[ 38 ] = 1;
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
  child_state->vars[ 39 ] = 1;
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
  child_state->vars[ 9 ] = 3;
  child_state->vars[ 10 ] = 0;
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
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = 3;
  child_state->vars[ 11 ] = 0;
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
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 3;
  child_state->vars[ 18 ] = 0;
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
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 3;
  child_state->vars[ 38 ] = 0;
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
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = 3;
  child_state->vars[ 39 ] = 0;
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
  child_state->vars[ 9 ] = 0;
  child_state->vars[ 10 ] = 3;
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
  child_state->vars[ 10 ] = 0;
  child_state->vars[ 11 ] = 3;
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
  child_state->vars[ 17 ] = 0;
  child_state->vars[ 18 ] = 3;
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

static void fwdrule59( const state_t *state, state_t *child_state )
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

static void fwdrule60( const state_t *state, state_t *child_state )
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

static void fwdrule61( const state_t *state, state_t *child_state )
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
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 0;
  child_state->vars[ 38 ] = 3;
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

static void fwdrule62( const state_t *state, state_t *child_state )
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
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = 0;
  child_state->vars[ 39 ] = 3;
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

static void fwdrule63( const state_t *state, state_t *child_state )
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

static void fwdrule64( const state_t *state, state_t *child_state )
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
  child_state->vars[ 10 ] = 0;
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 3;
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

static void fwdrule65( const state_t *state, state_t *child_state )
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
  child_state->vars[ 11 ] = 0;
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = 3;
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

static void fwdrule66( const state_t *state, state_t *child_state )
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

static void fwdrule67( const state_t *state, state_t *child_state )
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
  child_state->vars[ 17 ] = 0;
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

static void fwdrule68( const state_t *state, state_t *child_state )
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
  child_state->vars[ 18 ] = 0;
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

static void fwdrule69( const state_t *state, state_t *child_state )
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

static void fwdrule70( const state_t *state, state_t *child_state )
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

static void fwdrule71( const state_t *state, state_t *child_state )
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

static void fwdrule72( const state_t *state, state_t *child_state )
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

static void fwdrule73( const state_t *state, state_t *child_state )
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

static void fwdrule74( const state_t *state, state_t *child_state )
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

static void fwdrule75( const state_t *state, state_t *child_state )
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
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = 3;
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

static void fwdrule76( const state_t *state, state_t *child_state )
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
  child_state->vars[ 32 ] = 0;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = 3;
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

static void fwdrule77( const state_t *state, state_t *child_state )
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

static void fwdrule78( const state_t *state, state_t *child_state )
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
  child_state->vars[ 10 ] = 3;
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 0;
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

static void fwdrule79( const state_t *state, state_t *child_state )
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
  child_state->vars[ 11 ] = 3;
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = 0;
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

static void fwdrule80( const state_t *state, state_t *child_state )
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

static void fwdrule81( const state_t *state, state_t *child_state )
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
  child_state->vars[ 17 ] = 3;
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

static void fwdrule82( const state_t *state, state_t *child_state )
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
  child_state->vars[ 18 ] = 3;
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

static void fwdrule83( const state_t *state, state_t *child_state )
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

static void fwdrule84( const state_t *state, state_t *child_state )
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

static void fwdrule85( const state_t *state, state_t *child_state )
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

static void fwdrule86( const state_t *state, state_t *child_state )
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

static void fwdrule87( const state_t *state, state_t *child_state )
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

static void fwdrule88( const state_t *state, state_t *child_state )
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

static void fwdrule89( const state_t *state, state_t *child_state )
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
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = 0;
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

static void fwdrule90( const state_t *state, state_t *child_state )
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
  child_state->vars[ 32 ] = 3;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = 0;
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

static actfuncptr fwd_rules[ 90 ] = { fwdrule1, fwdrule2, fwdrule3, fwdrule4, fwdrule5, fwdrule6, fwdrule7, fwdrule8, fwdrule9, fwdrule10, fwdrule11, fwdrule12, fwdrule13, fwdrule14, fwdrule15, fwdrule16, fwdrule17, fwdrule18, fwdrule19, fwdrule20, fwdrule21, fwdrule22, fwdrule23, fwdrule24, fwdrule25, fwdrule26, fwdrule27, fwdrule28, fwdrule29, fwdrule30, fwdrule31, fwdrule32, fwdrule33, fwdrule34, fwdrule35, fwdrule36, fwdrule37, fwdrule38, fwdrule39, fwdrule40, fwdrule41, fwdrule42, fwdrule43, fwdrule44, fwdrule45, fwdrule46, fwdrule47, fwdrule48, fwdrule49, fwdrule50, fwdrule51, fwdrule52, fwdrule53, fwdrule54, fwdrule55, fwdrule56, fwdrule57, fwdrule58, fwdrule59, fwdrule60, fwdrule61, fwdrule62, fwdrule63, fwdrule64, fwdrule65, fwdrule66, fwdrule67, fwdrule68, fwdrule69, fwdrule70, fwdrule71, fwdrule72, fwdrule73, fwdrule74, fwdrule75, fwdrule76, fwdrule77, fwdrule78, fwdrule79, fwdrule80, fwdrule81, fwdrule82, fwdrule83, fwdrule84, fwdrule85, fwdrule86, fwdrule87, fwdrule88, fwdrule89, fwdrule90 };

static int fwdfn14( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = 0;
    return 81;
  } else {
    return -1;
  }
}

static int fwdfn15( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = 0;
    return 78;
  } else {
    return -1;
  }
}

static int fwdfn13( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn14( state, next_func );
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    return fwdfn15( state, next_func );
  }
}

static int fwdfn12( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn13;
    return 89;
  } else {
    return fwdfn13( state, next_func );
  }
}

static int fwdfn19( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 3 ) {
    *((funcptr *)next_func) = 0;
    return 78;
  } else {
    return -1;
  }
}

static int fwdfn18( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    return fwdfn19( state, next_func );
  } else {
    return -1;
  }
}

static int fwdfn20( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    *((funcptr *)next_func) = 0;
    return 81;
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    return fwdfn15( state, next_func );
  }
}

static int fwdfn17( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn18;
    return 85;
  case 1:
    return fwdfn18( state, next_func );
  case 2:
    return fwdfn18( state, next_func );
  default:
    return fwdfn20( state, next_func );
  }
}

static int fwdfn16( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn17;
    return 75;
  } else {
    return fwdfn17( state, next_func );
  }
}

static int fwdfn11( const state_t *state, void *next_func )
{
  switch( state->vars[ 32 ] ) {
  case 0:
    return fwdfn12( state, next_func );
  case 1:
    return fwdfn13( state, next_func );
  case 2:
    return fwdfn13( state, next_func );
  default:
    return fwdfn16( state, next_func );
  }
}

static int fwdfn10( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn11;
    return 80;
  } else {
    return fwdfn11( state, next_func );
  }
}

static int fwdfn21( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn11;
    return 77;
  } else {
    return fwdfn11( state, next_func );
  }
}

static int fwdfn9( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return fwdfn10( state, next_func );
  case 1:
    return fwdfn11( state, next_func );
  case 2:
    return fwdfn11( state, next_func );
  default:
    return fwdfn21( state, next_func );
  }
}

static int fwdfn8( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn9;
    return 88;
  } else {
    return fwdfn9( state, next_func );
  }
}

static int fwdfn25( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn11;
    return 77;
  } else {
    return fwdfn11( state, next_func );
  }
}

static int fwdfn24( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    return fwdfn25( state, next_func );
  } else {
    return fwdfn11( state, next_func );
  }
}

static int fwdfn26( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn11;
    return 80;
  case 1:
    return fwdfn11( state, next_func );
  case 2:
    return fwdfn11( state, next_func );
  default:
    return fwdfn21( state, next_func );
  }
}

static int fwdfn23( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn24;
    return 84;
  case 1:
    return fwdfn24( state, next_func );
  case 2:
    return fwdfn24( state, next_func );
  default:
    return fwdfn26( state, next_func );
  }
}

static int fwdfn22( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn23;
    return 74;
  } else {
    return fwdfn23( state, next_func );
  }
}

static int fwdfn7( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return fwdfn8( state, next_func );
  case 1:
    return fwdfn9( state, next_func );
  case 2:
    return fwdfn9( state, next_func );
  default:
    return fwdfn22( state, next_func );
  }
}

static int fwdfn6( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn7;
    return 79;
  } else {
    return fwdfn7( state, next_func );
  }
}

static int fwdfn27( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn7;
    return 76;
  } else {
    return fwdfn7( state, next_func );
  }
}

static int fwdfn5( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn6( state, next_func );
  case 1:
    return fwdfn7( state, next_func );
  case 2:
    return fwdfn7( state, next_func );
  default:
    return fwdfn27( state, next_func );
  }
}

static int fwdfn4( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn5;
    return 86;
  } else {
    return fwdfn5( state, next_func );
  }
}

static int fwdfn31( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn7;
    return 76;
  } else {
    return fwdfn7( state, next_func );
  }
}

static int fwdfn30( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    return fwdfn31( state, next_func );
  } else {
    return fwdfn7( state, next_func );
  }
}

static int fwdfn32( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn7;
    return 79;
  case 1:
    return fwdfn7( state, next_func );
  case 2:
    return fwdfn7( state, next_func );
  default:
    return fwdfn27( state, next_func );
  }
}

static int fwdfn29( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn30;
    return 82;
  case 1:
    return fwdfn30( state, next_func );
  case 2:
    return fwdfn30( state, next_func );
  default:
    return fwdfn32( state, next_func );
  }
}

static int fwdfn28( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn29;
    return 72;
  } else {
    return fwdfn29( state, next_func );
  }
}

static int fwdfn3( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn4( state, next_func );
  case 1:
    return fwdfn5( state, next_func );
  case 2:
    return fwdfn5( state, next_func );
  default:
    return fwdfn28( state, next_func );
  }
}

static int fwdfn2( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn3;
    return 87;
  } else {
    return fwdfn3( state, next_func );
  }
}

static int fwdfn34( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn3;
    return 83;
  } else {
    return fwdfn3( state, next_func );
  }
}

static int fwdfn33( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn34;
    return 73;
  } else {
    return fwdfn34( state, next_func );
  }
}

static int fwdfn1( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn2( state, next_func );
  case 1:
    return fwdfn3( state, next_func );
  case 2:
    return fwdfn3( state, next_func );
  default:
    return fwdfn33( state, next_func );
  }
}

static int fwdfn51( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 71;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn50( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    return fwdfn51( state, next_func );
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn49( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn50;
    return 57;
  } else {
    return fwdfn50( state, next_func );
  }
}

static int fwdfn53( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 71;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn52( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn53;
    return 58;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn48( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return fwdfn49( state, next_func );
  case 1:
    return fwdfn50( state, next_func );
  case 2:
    return fwdfn50( state, next_func );
  default:
    return fwdfn52( state, next_func );
  }
}

static int fwdfn47( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn48;
    return 68;
  } else {
    return fwdfn48( state, next_func );
  }
}

static int fwdfn56( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn53;
    return 58;
  } else {
    return fwdfn53( state, next_func );
  }
}

static int fwdfn55( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    return fwdfn56( state, next_func );
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn57( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn50;
    return 57;
  case 1:
    return fwdfn50( state, next_func );
  case 2:
    return fwdfn50( state, next_func );
  default:
    return fwdfn52( state, next_func );
  }
}

static int fwdfn54( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn55;
    return 56;
  case 1:
    return fwdfn55( state, next_func );
  case 2:
    return fwdfn55( state, next_func );
  default:
    return fwdfn57( state, next_func );
  }
}

static int fwdfn46( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn47( state, next_func );
  case 1:
    return fwdfn48( state, next_func );
  case 2:
    return fwdfn48( state, next_func );
  default:
    return fwdfn54( state, next_func );
  }
}

static int fwdfn45( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn46;
    return 64;
  } else {
    return fwdfn46( state, next_func );
  }
}

static int fwdfn62( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 57;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn63( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 58;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn61( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return fwdfn62( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    return fwdfn63( state, next_func );
  }
}

static int fwdfn60( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn61;
    return 68;
  } else {
    return fwdfn61( state, next_func );
  }
}

static int fwdfn65( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    return fwdfn63( state, next_func );
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn66( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn1;
    return 57;
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    return fwdfn63( state, next_func );
  }
}

static int fwdfn64( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn65;
    return 56;
  case 1:
    return fwdfn65( state, next_func );
  case 2:
    return fwdfn65( state, next_func );
  default:
    return fwdfn66( state, next_func );
  }
}

static int fwdfn59( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn60( state, next_func );
  case 1:
    return fwdfn61( state, next_func );
  case 2:
    return fwdfn61( state, next_func );
  default:
    return fwdfn64( state, next_func );
  }
}

static int fwdfn71( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 68;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn70( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn71( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn1;
    return 56;
  }
}

static int fwdfn73( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 68;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn72( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    return fwdfn73( state, next_func );
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn69( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn70( state, next_func );
  case 1:
    return fwdfn72( state, next_func );
  case 2:
    return fwdfn72( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn72;
    return 57;
  }
}

static int fwdfn75( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 56;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn74( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn71( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    return fwdfn75( state, next_func );
  }
}

static int fwdfn68( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return fwdfn69( state, next_func );
  case 1:
    return fwdfn74( state, next_func );
  case 2:
    return fwdfn74( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn74;
    return 58;
  }
}

static int fwdfn79( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 57;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn78( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 3 ) {
    return fwdfn79( state, next_func );
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn77( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn78;
    return 68;
  } else {
    return fwdfn78( state, next_func );
  }
}

static int fwdfn80( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn1;
    return 56;
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    return fwdfn79( state, next_func );
  }
}

static int fwdfn76( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn77( state, next_func );
  case 1:
    return fwdfn78( state, next_func );
  case 2:
    return fwdfn78( state, next_func );
  default:
    return fwdfn80( state, next_func );
  }
}

static int fwdfn67( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn68;
    return 71;
  } else {
    return fwdfn76( state, next_func );
  }
}

static int fwdfn58( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn59;
    return 67;
  case 1:
    return fwdfn59( state, next_func );
  case 2:
    return fwdfn59( state, next_func );
  default:
    return fwdfn67( state, next_func );
  }
}

static int fwdfn44( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn45( state, next_func );
  case 1:
    return fwdfn46( state, next_func );
  case 2:
    return fwdfn46( state, next_func );
  default:
    return fwdfn58( state, next_func );
  }
}

static int fwdfn43( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn44;
    return 62;
  } else {
    return fwdfn44( state, next_func );
  }
}

static int fwdfn85( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn55;
    return 56;
  } else {
    return fwdfn55( state, next_func );
  }
}

static int fwdfn84( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn85( state, next_func );
  case 1:
    return fwdfn55( state, next_func );
  case 2:
    return fwdfn55( state, next_func );
  default:
    return fwdfn57( state, next_func );
  }
}

static int fwdfn83( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn84;
    return 64;
  } else {
    return fwdfn84( state, next_func );
  }
}

static int fwdfn88( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn65;
    return 56;
  } else {
    return fwdfn65( state, next_func );
  }
}

static int fwdfn87( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn88( state, next_func );
  case 1:
    return fwdfn65( state, next_func );
  case 2:
    return fwdfn65( state, next_func );
  default:
    return fwdfn66( state, next_func );
  }
}

static int fwdfn92( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 56;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn91( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn92( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn1;
    return 57;
  }
}

static int fwdfn93( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    return fwdfn75( state, next_func );
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn90( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return fwdfn91( state, next_func );
  case 1:
    return fwdfn93( state, next_func );
  case 2:
    return fwdfn93( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn93;
    return 58;
  }
}

static int fwdfn94( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn92( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    return fwdfn79( state, next_func );
  }
}

static int fwdfn89( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn90;
    return 71;
  } else {
    return fwdfn94( state, next_func );
  }
}

static int fwdfn86( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn87;
    return 67;
  case 1:
    return fwdfn87( state, next_func );
  case 2:
    return fwdfn87( state, next_func );
  default:
    return fwdfn89( state, next_func );
  }
}

static int fwdfn82( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn83( state, next_func );
  case 1:
    return fwdfn84( state, next_func );
  case 2:
    return fwdfn84( state, next_func );
  default:
    return fwdfn86( state, next_func );
  }
}

static int fwdfn97( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn48;
    return 64;
  } else {
    return fwdfn48( state, next_func );
  }
}

static int fwdfn100( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return fwdfn62( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn1;
    return 58;
  }
}

static int fwdfn99( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn100;
    return 71;
  } else {
    return fwdfn78( state, next_func );
  }
}

static int fwdfn98( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn61;
    return 67;
  case 1:
    return fwdfn61( state, next_func );
  case 2:
    return fwdfn61( state, next_func );
  default:
    return fwdfn99( state, next_func );
  }
}

static int fwdfn96( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn97( state, next_func );
  case 1:
    return fwdfn48( state, next_func );
  case 2:
    return fwdfn48( state, next_func );
  default:
    return fwdfn98( state, next_func );
  }
}

static int fwdfn103( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn55;
    return 64;
  } else {
    return fwdfn55( state, next_func );
  }
}

static int fwdfn106( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 58;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn105( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn106;
    return 71;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn104( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn65;
    return 67;
  case 1:
    return fwdfn65( state, next_func );
  case 2:
    return fwdfn65( state, next_func );
  default:
    return fwdfn105( state, next_func );
  }
}

static int fwdfn102( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn103( state, next_func );
  case 1:
    return fwdfn55( state, next_func );
  case 2:
    return fwdfn55( state, next_func );
  default:
    return fwdfn104( state, next_func );
  }
}

static int fwdfn109( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn50;
    return 64;
  } else {
    return fwdfn50( state, next_func );
  }
}

static int fwdfn110( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn1;
    return 67;
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    return fwdfn51( state, next_func );
  }
}

static int fwdfn108( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn109( state, next_func );
  case 1:
    return fwdfn50( state, next_func );
  case 2:
    return fwdfn50( state, next_func );
  default:
    return fwdfn110( state, next_func );
  }
}

static int fwdfn114( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 64;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn113( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn114( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn1;
    return 67;
  }
}

static int fwdfn116( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 64;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn115( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    return fwdfn116( state, next_func );
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn112( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return fwdfn113( state, next_func );
  case 1:
    return fwdfn115( state, next_func );
  case 2:
    return fwdfn115( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn115;
    return 71;
  }
}

static int fwdfn118( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 67;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn117( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn114( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    return fwdfn118( state, next_func );
  }
}

static int fwdfn111( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn112;
    return 58;
  } else {
    return fwdfn117( state, next_func );
  }
}

static int fwdfn107( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn108;
    return 57;
  case 1:
    return fwdfn108( state, next_func );
  case 2:
    return fwdfn108( state, next_func );
  default:
    return fwdfn111( state, next_func );
  }
}

static int fwdfn101( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn102;
    return 56;
  case 1:
    return fwdfn102( state, next_func );
  case 2:
    return fwdfn102( state, next_func );
  default:
    return fwdfn107( state, next_func );
  }
}

static int fwdfn95( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn96;
    return 68;
  case 1:
    return fwdfn96( state, next_func );
  case 2:
    return fwdfn96( state, next_func );
  default:
    return fwdfn101( state, next_func );
  }
}

static int fwdfn81( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn82;
    return 65;
  case 1:
    return fwdfn82( state, next_func );
  case 2:
    return fwdfn82( state, next_func );
  default:
    return fwdfn95( state, next_func );
  }
}

static int fwdfn42( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn43( state, next_func );
  case 1:
    return fwdfn44( state, next_func );
  case 2:
    return fwdfn44( state, next_func );
  default:
    return fwdfn81( state, next_func );
  }
}

static int fwdfn41( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn42;
    return 63;
  } else {
    return fwdfn42( state, next_func );
  }
}

static int fwdfn40( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return fwdfn41( state, next_func );
  case 1:
    return fwdfn42( state, next_func );
  case 2:
    return fwdfn42( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn42;
    return 66;
  }
}

static int fwdfn125( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn102;
    return 62;
  } else {
    return fwdfn102( state, next_func );
  }
}

static int fwdfn124( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn125( state, next_func );
  case 1:
    return fwdfn102( state, next_func );
  case 2:
    return fwdfn102( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn102;
    return 65;
  }
}

static int fwdfn127( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn102;
    return 62;
  } else {
    return fwdfn102( state, next_func );
  }
}

static int fwdfn126( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return fwdfn127( state, next_func );
  } else {
    return fwdfn102( state, next_func );
  }
}

static int fwdfn123( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn124( state, next_func );
  case 1:
    return fwdfn126( state, next_func );
  case 2:
    return fwdfn126( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn126;
    return 68;
  }
}

static int fwdfn122( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn123;
    return 63;
  } else {
    return fwdfn123( state, next_func );
  }
}

static int fwdfn121( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return fwdfn122( state, next_func );
  case 1:
    return fwdfn123( state, next_func );
  case 2:
    return fwdfn123( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn123;
    return 66;
  }
}

static int fwdfn131( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn102;
    return 65;
  } else {
    return fwdfn102( state, next_func );
  }
}

static int fwdfn130( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn125( state, next_func );
  case 1:
    return fwdfn102( state, next_func );
  case 2:
    return fwdfn102( state, next_func );
  default:
    return fwdfn131( state, next_func );
  }
}

static int fwdfn129( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn130;
    return 63;
  } else {
    return fwdfn130( state, next_func );
  }
}

static int fwdfn128( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return fwdfn129( state, next_func );
  case 1:
    return fwdfn130( state, next_func );
  case 2:
    return fwdfn130( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn130;
    return 66;
  }
}

static int fwdfn120( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn121( state, next_func );
  case 1:
    return fwdfn128( state, next_func );
  case 2:
    return fwdfn128( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn128;
    return 56;
  }
}

static int fwdfn137( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn102;
    return 68;
  } else {
    return fwdfn102( state, next_func );
  }
}

static int fwdfn136( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    return fwdfn137( state, next_func );
  } else {
    return fwdfn102( state, next_func );
  }
}

static int fwdfn135( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn136;
    return 62;
  } else {
    return fwdfn136( state, next_func );
  }
}

static int fwdfn138( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn102;
    return 65;
  case 1:
    return fwdfn102( state, next_func );
  case 2:
    return fwdfn102( state, next_func );
  default:
    return fwdfn137( state, next_func );
  }
}

static int fwdfn134( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn135( state, next_func );
  case 1:
    return fwdfn136( state, next_func );
  case 2:
    return fwdfn136( state, next_func );
  default:
    return fwdfn138( state, next_func );
  }
}

static int fwdfn133( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn134;
    return 63;
  } else {
    return fwdfn134( state, next_func );
  }
}

static int fwdfn132( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return fwdfn133( state, next_func );
  case 1:
    return fwdfn134( state, next_func );
  case 2:
    return fwdfn134( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn134;
    return 66;
  }
}

static int fwdfn145( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn108;
    return 68;
  } else {
    return fwdfn108( state, next_func );
  }
}

static int fwdfn144( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    return fwdfn145( state, next_func );
  } else {
    return fwdfn108( state, next_func );
  }
}

static int fwdfn143( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn144;
    return 62;
  } else {
    return fwdfn144( state, next_func );
  }
}

static int fwdfn146( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn108;
    return 65;
  case 1:
    return fwdfn108( state, next_func );
  case 2:
    return fwdfn108( state, next_func );
  default:
    return fwdfn145( state, next_func );
  }
}

static int fwdfn142( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn143( state, next_func );
  case 1:
    return fwdfn144( state, next_func );
  case 2:
    return fwdfn144( state, next_func );
  default:
    return fwdfn146( state, next_func );
  }
}

static int fwdfn152( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn72;
    return 62;
  } else {
    return fwdfn72( state, next_func );
  }
}

static int fwdfn153( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn1;
    return 65;
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    return fwdfn73( state, next_func );
  }
}

static int fwdfn151( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn152( state, next_func );
  case 1:
    return fwdfn72( state, next_func );
  case 2:
    return fwdfn72( state, next_func );
  default:
    return fwdfn153( state, next_func );
  }
}

static int fwdfn150( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn151;
    return 64;
  } else {
    return fwdfn151( state, next_func );
  }
}

static int fwdfn149( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn150( state, next_func );
  case 1:
    return fwdfn151( state, next_func );
  case 2:
    return fwdfn151( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn151;
    return 67;
  }
}

static int fwdfn155( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn151;
    return 64;
  } else {
    return fwdfn151( state, next_func );
  }
}

static int fwdfn154( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    return fwdfn155( state, next_func );
  } else {
    return fwdfn151( state, next_func );
  }
}

static int fwdfn148( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return fwdfn149( state, next_func );
  case 1:
    return fwdfn154( state, next_func );
  case 2:
    return fwdfn154( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn154;
    return 71;
  }
}

static int fwdfn157( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn151;
    return 67;
  } else {
    return fwdfn151( state, next_func );
  }
}

static int fwdfn156( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn150( state, next_func );
  case 1:
    return fwdfn151( state, next_func );
  case 2:
    return fwdfn151( state, next_func );
  default:
    return fwdfn157( state, next_func );
  }
}

static int fwdfn147( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn148;
    return 58;
  } else {
    return fwdfn156( state, next_func );
  }
}

static int fwdfn141( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn142;
    return 57;
  case 1:
    return fwdfn142( state, next_func );
  case 2:
    return fwdfn142( state, next_func );
  default:
    return fwdfn147( state, next_func );
  }
}

static int fwdfn140( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn141;
    return 63;
  } else {
    return fwdfn141( state, next_func );
  }
}

static int fwdfn139( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return fwdfn140( state, next_func );
  case 1:
    return fwdfn141( state, next_func );
  case 2:
    return fwdfn141( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn141;
    return 66;
  }
}

static int fwdfn119( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn120;
    return 69;
  case 1:
    return fwdfn132( state, next_func );
  case 2:
    return fwdfn132( state, next_func );
  default:
    return fwdfn139( state, next_func );
  }
}

static int fwdfn39( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn119;
    return 54;
  } else {
    return fwdfn40( state, next_func );
  }
}

static int fwdfn164( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn102;
    return 69;
  } else {
    return fwdfn102( state, next_func );
  }
}

static int fwdfn163( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn164;
    return 62;
  } else {
    return fwdfn164( state, next_func );
  }
}

static int fwdfn162( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn163( state, next_func );
  case 1:
    return fwdfn164( state, next_func );
  case 2:
    return fwdfn164( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn164;
    return 65;
  }
}

static int fwdfn166( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn164;
    return 62;
  } else {
    return fwdfn164( state, next_func );
  }
}

static int fwdfn165( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return fwdfn166( state, next_func );
  } else {
    return fwdfn164( state, next_func );
  }
}

static int fwdfn161( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn162( state, next_func );
  case 1:
    return fwdfn165( state, next_func );
  case 2:
    return fwdfn165( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn165;
    return 68;
  }
}

static int fwdfn167( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn130;
    return 69;
  } else {
    return fwdfn130( state, next_func );
  }
}

static int fwdfn160( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn161( state, next_func );
  case 1:
    return fwdfn167( state, next_func );
  case 2:
    return fwdfn167( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn167;
    return 56;
  }
}

static int fwdfn159( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn160( state, next_func );
  case 1:
    return fwdfn134( state, next_func );
  case 2:
    return fwdfn134( state, next_func );
  default:
    return fwdfn141( state, next_func );
  }
}

static int fwdfn168( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn159;
    return 63;
  } else {
    return fwdfn159( state, next_func );
  }
}

static int fwdfn158( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    return fwdfn168( state, next_func );
  } else {
    return fwdfn159( state, next_func );
  }
}

static int fwdfn179( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 62;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn178( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn179( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn1;
    return 65;
  }
}

static int fwdfn181( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 62;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn180( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return fwdfn181( state, next_func );
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn177( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn178( state, next_func );
  case 1:
    return fwdfn180( state, next_func );
  case 2:
    return fwdfn180( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn180;
    return 68;
  }
}

static int fwdfn176( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn177;
    return 64;
  } else {
    return fwdfn177( state, next_func );
  }
}

static int fwdfn175( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn176( state, next_func );
  case 1:
    return fwdfn177( state, next_func );
  case 2:
    return fwdfn177( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn177;
    return 67;
  }
}

static int fwdfn185( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 65;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn184( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn179( state, next_func );
  case 1:
    return fwdfn1( state, next_func );
  case 2:
    return fwdfn1( state, next_func );
  default:
    return fwdfn185( state, next_func );
  }
}

static int fwdfn183( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn184;
    return 64;
  } else {
    return fwdfn184( state, next_func );
  }
}

static int fwdfn182( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn183( state, next_func );
  case 1:
    return fwdfn184( state, next_func );
  case 2:
    return fwdfn184( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn184;
    return 67;
  }
}

static int fwdfn174( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn175( state, next_func );
  case 1:
    return fwdfn182( state, next_func );
  case 2:
    return fwdfn182( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn182;
    return 56;
  }
}

static int fwdfn173( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn174;
    return 69;
  } else {
    return fwdfn174( state, next_func );
  }
}

static int fwdfn172( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn173( state, next_func );
  case 1:
    return fwdfn149( state, next_func );
  case 2:
    return fwdfn149( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn149;
    return 57;
  }
}

static int fwdfn193( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 69;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn192( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    return fwdfn193( state, next_func );
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn191( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn192;
    return 68;
  } else {
    return fwdfn192( state, next_func );
  }
}

static int fwdfn195( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 69;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn194( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn195;
    return 56;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn190( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn191( state, next_func );
  case 1:
    return fwdfn192( state, next_func );
  case 2:
    return fwdfn192( state, next_func );
  default:
    return fwdfn194( state, next_func );
  }
}

static int fwdfn189( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn190;
    return 62;
  } else {
    return fwdfn190( state, next_func );
  }
}

static int fwdfn198( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn195;
    return 56;
  } else {
    return fwdfn195( state, next_func );
  }
}

static int fwdfn197( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    return fwdfn198( state, next_func );
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn199( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn192;
    return 68;
  case 1:
    return fwdfn192( state, next_func );
  case 2:
    return fwdfn192( state, next_func );
  default:
    return fwdfn194( state, next_func );
  }
}

static int fwdfn196( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn197;
    return 65;
  case 1:
    return fwdfn197( state, next_func );
  case 2:
    return fwdfn197( state, next_func );
  default:
    return fwdfn199( state, next_func );
  }
}

static int fwdfn188( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn189( state, next_func );
  case 1:
    return fwdfn190( state, next_func );
  case 2:
    return fwdfn190( state, next_func );
  default:
    return fwdfn196( state, next_func );
  }
}

static int fwdfn187( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn188;
    return 64;
  } else {
    return fwdfn188( state, next_func );
  }
}

static int fwdfn186( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn187( state, next_func );
  case 1:
    return fwdfn188( state, next_func );
  case 2:
    return fwdfn188( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn188;
    return 67;
  }
}

static int fwdfn200( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn186;
    return 58;
  } else {
    return fwdfn186( state, next_func );
  }
}

static int fwdfn171( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn172;
    return 70;
  case 1:
    return fwdfn186( state, next_func );
  case 2:
    return fwdfn186( state, next_func );
  default:
    return fwdfn200( state, next_func );
  }
}

static int fwdfn207( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn115;
    return 62;
  } else {
    return fwdfn115( state, next_func );
  }
}

static int fwdfn206( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn207( state, next_func );
  case 1:
    return fwdfn115( state, next_func );
  case 2:
    return fwdfn115( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn115;
    return 65;
  }
}

static int fwdfn209( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn115;
    return 62;
  } else {
    return fwdfn115( state, next_func );
  }
}

static int fwdfn208( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return fwdfn209( state, next_func );
  } else {
    return fwdfn115( state, next_func );
  }
}

static int fwdfn205( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn206( state, next_func );
  case 1:
    return fwdfn208( state, next_func );
  case 2:
    return fwdfn208( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn208;
    return 68;
  }
}

static int fwdfn204( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn205;
    return 69;
  } else {
    return fwdfn205( state, next_func );
  }
}

static int fwdfn212( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn184;
    return 64;
  } else {
    return fwdfn184( state, next_func );
  }
}

static int fwdfn211( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    return fwdfn212( state, next_func );
  } else {
    return fwdfn184( state, next_func );
  }
}

static int fwdfn210( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn211;
    return 69;
  } else {
    return fwdfn211( state, next_func );
  }
}

static int fwdfn203( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn204( state, next_func );
  case 1:
    return fwdfn210( state, next_func );
  case 2:
    return fwdfn210( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn210;
    return 56;
  }
}

static int fwdfn202( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn203( state, next_func );
  case 1:
    return fwdfn154( state, next_func );
  case 2:
    return fwdfn154( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn154;
    return 57;
  }
}

static int fwdfn214( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn188;
    return 64;
  } else {
    return fwdfn188( state, next_func );
  }
}

static int fwdfn213( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    return fwdfn214( state, next_func );
  } else {
    return fwdfn188( state, next_func );
  }
}

static int fwdfn215( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn213;
    return 58;
  } else {
    return fwdfn213( state, next_func );
  }
}

static int fwdfn201( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn202;
    return 70;
  case 1:
    return fwdfn213( state, next_func );
  case 2:
    return fwdfn213( state, next_func );
  default:
    return fwdfn215( state, next_func );
  }
}

static int fwdfn218( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn203;
    return 71;
  } else {
    return fwdfn203( state, next_func );
  }
}

static int fwdfn219( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn154;
    return 71;
  } else {
    return fwdfn154( state, next_func );
  }
}

static int fwdfn217( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn218( state, next_func );
  case 1:
    return fwdfn219( state, next_func );
  case 2:
    return fwdfn219( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn219;
    return 57;
  }
}

static int fwdfn221( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn188;
    return 71;
  } else {
    return fwdfn188( state, next_func );
  }
}

static int fwdfn222( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn214;
    return 71;
  } else {
    return fwdfn214( state, next_func );
  }
}

static int fwdfn220( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    return fwdfn222( state, next_func );
  } else {
    return fwdfn221( state, next_func );
  }
}

static int fwdfn223_a0_1( const state_t *state, void *next_func )
{
  *((funcptr *)next_func) = fwdfn213;
  return 71;
}

static int fwdfn223( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn223_a0_1;
    return 58;
  } else {
    return fwdfn213( state, next_func );
  }
}

static int fwdfn216( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn217;
    return 70;
  case 1:
    return fwdfn220( state, next_func );
  case 2:
    return fwdfn220( state, next_func );
  default:
    return fwdfn223( state, next_func );
  }
}

static int fwdfn170( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn171;
    return 55;
  case 1:
    return fwdfn201( state, next_func );
  case 2:
    return fwdfn201( state, next_func );
  default:
    return fwdfn216( state, next_func );
  }
}

static int fwdfn224( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn170;
    return 63;
  } else {
    return fwdfn170( state, next_func );
  }
}

static int fwdfn169( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    return fwdfn224( state, next_func );
  } else {
    return fwdfn170( state, next_func );
  }
}

static int fwdfn38( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return fwdfn39( state, next_func );
  case 1:
    return fwdfn158( state, next_func );
  case 2:
    return fwdfn158( state, next_func );
  default:
    return fwdfn169( state, next_func );
  }
}

static int fwdfn225( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn38;
    return 61;
  } else {
    return fwdfn38( state, next_func );
  }
}

static int fwdfn37( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 3 ) {
    return fwdfn225( state, next_func );
  } else {
    return fwdfn38( state, next_func );
  }
}

static int fwdfn36( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn37;
    return 59;
  } else {
    return fwdfn37( state, next_func );
  }
}

static int fwdfn226( const state_t *state, void *next_func )
{
  switch( state->vars[ 38 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn38;
    return 60;
  case 1:
    return fwdfn38( state, next_func );
  case 2:
    return fwdfn38( state, next_func );
  default:
    return fwdfn225( state, next_func );
  }
}

static int fwdfn35( const state_t *state, void *next_func )
{
  switch( state->vars[ 37 ] ) {
  case 0:
    return fwdfn36( state, next_func );
  case 1:
    return fwdfn37( state, next_func );
  case 2:
    return fwdfn37( state, next_func );
  default:
    return fwdfn226( state, next_func );
  }
}

static int fwdfn242( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn35;
    return 38;
  } else {
    return fwdfn35( state, next_func );
  }
}

static int fwdfn243( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn35;
    return 51;
  } else {
    return fwdfn35( state, next_func );
  }
}

static int fwdfn241( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    return fwdfn242( state, next_func );
  case 1:
    return fwdfn35( state, next_func );
  case 2:
    return fwdfn35( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn243;
    return 37;
  }
}

static int fwdfn240( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn241;
    return 49;
  } else {
    return fwdfn241( state, next_func );
  }
}

static int fwdfn244( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    return fwdfn242( state, next_func );
  case 1:
    return fwdfn35( state, next_func );
  case 2:
    return fwdfn35( state, next_func );
  default:
    return fwdfn243( state, next_func );
  }
}

static int fwdfn246( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn242;
    return 50;
  case 1:
    return fwdfn35( state, next_func );
  case 2:
    return fwdfn35( state, next_func );
  default:
    return fwdfn243( state, next_func );
  }
}

static int fwdfn245( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn246;
    return 36;
  } else {
    return fwdfn246( state, next_func );
  }
}

static int fwdfn239( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return fwdfn240( state, next_func );
  case 1:
    return fwdfn244( state, next_func );
  case 2:
    return fwdfn244( state, next_func );
  default:
    return fwdfn245( state, next_func );
  }
}

static int fwdfn238( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn239;
    return 42;
  } else {
    return fwdfn239( state, next_func );
  }
}

static int fwdfn237( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return fwdfn238( state, next_func );
  case 1:
    return fwdfn239( state, next_func );
  case 2:
    return fwdfn239( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn239;
    return 41;
  }
}

static int fwdfn236( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn237;
    return 53;
  } else {
    return fwdfn237( state, next_func );
  }
}

static int fwdfn247( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    return fwdfn238( state, next_func );
  } else {
    return fwdfn239( state, next_func );
  }
}

static int fwdfn248( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn247;
    return 40;
  } else {
    return fwdfn247( state, next_func );
  }
}

static int fwdfn235( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn236( state, next_func );
  case 1:
    return fwdfn247( state, next_func );
  case 2:
    return fwdfn247( state, next_func );
  default:
    return fwdfn248( state, next_func );
  }
}

static int fwdfn234( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn235;
    return 48;
  } else {
    return fwdfn235( state, next_func );
  }
}

static int fwdfn233( const state_t *state, void *next_func )
{
  switch( state->vars[ 38 ] ) {
  case 0:
    return fwdfn234( state, next_func );
  case 1:
    return fwdfn235( state, next_func );
  case 2:
    return fwdfn235( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn235;
    return 47;
  }
}

static int fwdfn249( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 0 ) {
    return fwdfn234( state, next_func );
  } else {
    return fwdfn235( state, next_func );
  }
}

static int fwdfn250( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn249;
    return 46;
  } else {
    return fwdfn249( state, next_func );
  }
}

static int fwdfn232( const state_t *state, void *next_func )
{
  switch( state->vars[ 37 ] ) {
  case 0:
    return fwdfn233( state, next_func );
  case 1:
    return fwdfn249( state, next_func );
  case 2:
    return fwdfn249( state, next_func );
  default:
    return fwdfn250( state, next_func );
  }
}

static int fwdfn231( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn232;
    return 45;
  } else {
    return fwdfn232( state, next_func );
  }
}

static int fwdfn230( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return fwdfn231( state, next_func );
  case 1:
    return fwdfn232( state, next_func );
  case 2:
    return fwdfn232( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn232;
    return 44;
  }
}

static int fwdfn251( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return fwdfn231( state, next_func );
  } else {
    return fwdfn232( state, next_func );
  }
}

static int fwdfn252( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn251;
    return 43;
  } else {
    return fwdfn251( state, next_func );
  }
}

static int fwdfn229( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn230( state, next_func );
  case 1:
    return fwdfn251( state, next_func );
  case 2:
    return fwdfn251( state, next_func );
  default:
    return fwdfn252( state, next_func );
  }
}

static int fwdfn228( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn229;
    return 39;
  } else {
    return fwdfn229( state, next_func );
  }
}

static int fwdfn253( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn229;
    return 52;
  } else {
    return fwdfn229( state, next_func );
  }
}

static int fwdfn227( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return fwdfn228( state, next_func );
  case 1:
    return fwdfn229( state, next_func );
  case 2:
    return fwdfn229( state, next_func );
  default:
    return fwdfn253( state, next_func );
  }
}

static int fwdfn263( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn227;
    return 35;
  } else {
    return fwdfn227( state, next_func );
  }
}

static int fwdfn262( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 1 ) {
    return fwdfn263( state, next_func );
  } else {
    return fwdfn227( state, next_func );
  }
}

static int fwdfn264( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn262;
    return 18;
  } else {
    return fwdfn262( state, next_func );
  }
}

static int fwdfn261( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    return fwdfn264( state, next_func );
  } else {
    return fwdfn262( state, next_func );
  }
}

static int fwdfn266( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn227;
    return 31;
  } else {
    return fwdfn227( state, next_func );
  }
}

static int fwdfn267( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn227;
    return 21;
  } else {
    return fwdfn227( state, next_func );
  }
}

static int fwdfn265( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn266( state, next_func );
  case 1:
    return fwdfn227( state, next_func );
  case 2:
    return fwdfn227( state, next_func );
  default:
    return fwdfn267( state, next_func );
  }
}

static int fwdfn270( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn227;
    return 28;
  } else {
    return fwdfn227( state, next_func );
  }
}

static int fwdfn269( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    return fwdfn270( state, next_func );
  } else {
    return fwdfn227( state, next_func );
  }
}

static int fwdfn271( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn269;
    return 25;
  } else {
    return fwdfn269( state, next_func );
  }
}

static int fwdfn268( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 1 ) {
    return fwdfn271( state, next_func );
  } else {
    return fwdfn269( state, next_func );
  }
}

static int fwdfn260( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return fwdfn261( state, next_func );
  case 1:
    return fwdfn265( state, next_func );
  case 2:
    return fwdfn227( state, next_func );
  default:
    return fwdfn268( state, next_func );
  }
}

static int fwdfn272( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn260;
    return 34;
  } else {
    return fwdfn260( state, next_func );
  }
}

static int fwdfn259( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn272( state, next_func );
  } else {
    return fwdfn260( state, next_func );
  }
}

static int fwdfn274( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn260;
    return 30;
  } else {
    return fwdfn260( state, next_func );
  }
}

static int fwdfn275( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn260;
    return 20;
  } else {
    return fwdfn260( state, next_func );
  }
}

static int fwdfn273( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return fwdfn274( state, next_func );
  case 1:
    return fwdfn260( state, next_func );
  case 2:
    return fwdfn260( state, next_func );
  default:
    return fwdfn275( state, next_func );
  }
}

static int fwdfn278( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn260;
    return 27;
  } else {
    return fwdfn260( state, next_func );
  }
}

static int fwdfn277( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    return fwdfn278( state, next_func );
  } else {
    return fwdfn260( state, next_func );
  }
}

static int fwdfn279( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn277;
    return 24;
  } else {
    return fwdfn277( state, next_func );
  }
}

static int fwdfn276( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn279( state, next_func );
  } else {
    return fwdfn277( state, next_func );
  }
}

static int fwdfn258( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return fwdfn259( state, next_func );
  case 1:
    return fwdfn273( state, next_func );
  case 2:
    return fwdfn260( state, next_func );
  default:
    return fwdfn276( state, next_func );
  }
}

static int fwdfn280( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn258;
    return 32;
  } else {
    return fwdfn258( state, next_func );
  }
}

static int fwdfn257( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 1 ) {
    return fwdfn280( state, next_func );
  } else {
    return fwdfn258( state, next_func );
  }
}

static int fwdfn282( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn258;
    return 29;
  } else {
    return fwdfn258( state, next_func );
  }
}

static int fwdfn283( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn258;
    return 19;
  } else {
    return fwdfn258( state, next_func );
  }
}

static int fwdfn281( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn282( state, next_func );
  case 1:
    return fwdfn258( state, next_func );
  case 2:
    return fwdfn258( state, next_func );
  default:
    return fwdfn283( state, next_func );
  }
}

static int fwdfn286( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn258;
    return 26;
  } else {
    return fwdfn258( state, next_func );
  }
}

static int fwdfn285( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    return fwdfn286( state, next_func );
  } else {
    return fwdfn258( state, next_func );
  }
}

static int fwdfn287( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn285;
    return 22;
  } else {
    return fwdfn285( state, next_func );
  }
}

static int fwdfn284( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 1 ) {
    return fwdfn287( state, next_func );
  } else {
    return fwdfn285( state, next_func );
  }
}

static int fwdfn256( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn257( state, next_func );
  case 1:
    return fwdfn281( state, next_func );
  case 2:
    return fwdfn258( state, next_func );
  default:
    return fwdfn284( state, next_func );
  }
}

static int fwdfn288( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn256;
    return 33;
  } else {
    return fwdfn256( state, next_func );
  }
}

static int fwdfn255( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 1 ) {
    return fwdfn288( state, next_func );
  } else {
    return fwdfn256( state, next_func );
  }
}

static int fwdfn290( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn256;
    return 23;
  } else {
    return fwdfn256( state, next_func );
  }
}

static int fwdfn289( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 1 ) {
    return fwdfn290( state, next_func );
  } else {
    return fwdfn256( state, next_func );
  }
}

static int fwdfn254( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn255( state, next_func );
  case 1:
    return fwdfn256( state, next_func );
  case 2:
    return fwdfn256( state, next_func );
  default:
    return fwdfn289( state, next_func );
  }
}

static int fwdfn298( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn254;
    return 3;
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn297( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 1 ) {
    return fwdfn298( state, next_func );
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn300( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn254;
    return 2;
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn301( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn254;
    return 10;
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn299( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn300( state, next_func );
  case 1:
    return fwdfn254( state, next_func );
  case 2:
    return fwdfn254( state, next_func );
  default:
    return fwdfn301( state, next_func );
  }
}

static int fwdfn303( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn254;
    return 11;
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn302( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 1 ) {
    return fwdfn303( state, next_func );
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn296( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn297( state, next_func );
  case 1:
    return fwdfn299( state, next_func );
  case 2:
    return fwdfn254( state, next_func );
  default:
    return fwdfn302( state, next_func );
  }
}

static int fwdfn307( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn297( state, next_func );
  case 1:
    return fwdfn300( state, next_func );
  case 2:
    return fwdfn254( state, next_func );
  default:
    return fwdfn302( state, next_func );
  }
}

static int fwdfn306( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn307;
    return 16;
  } else {
    return fwdfn307( state, next_func );
  }
}

static int fwdfn308( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn297( state, next_func );
  case 1:
    return fwdfn254( state, next_func );
  case 2:
    return fwdfn254( state, next_func );
  default:
    return fwdfn302( state, next_func );
  }
}

static int fwdfn309( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn297( state, next_func );
  case 1:
    return fwdfn301( state, next_func );
  case 2:
    return fwdfn254( state, next_func );
  default:
    return fwdfn302( state, next_func );
  }
}

static int fwdfn305( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn306( state, next_func );
  case 1:
    return fwdfn308( state, next_func );
  case 2:
    return fwdfn308( state, next_func );
  default:
    return fwdfn309( state, next_func );
  }
}

static int fwdfn304( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn305;
    return 8;
  } else {
    return fwdfn305( state, next_func );
  }
}

static int fwdfn295( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return fwdfn304( state, next_func );
  } else {
    return fwdfn296( state, next_func );
  }
}

static int fwdfn316( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn254;
    return 16;
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn315( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    return fwdfn316( state, next_func );
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn314( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return fwdfn315( state, next_func );
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn317( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn314;
    return 3;
  } else {
    return fwdfn314( state, next_func );
  }
}

static int fwdfn313( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 1 ) {
    return fwdfn317( state, next_func );
  } else {
    return fwdfn314( state, next_func );
  }
}

static int fwdfn321( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn254;
    return 16;
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn320( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return fwdfn321( state, next_func );
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn319( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn320;
    return 2;
  } else {
    return fwdfn320( state, next_func );
  }
}

static int fwdfn318( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn319( state, next_func );
  case 1:
    return fwdfn254( state, next_func );
  case 2:
    return fwdfn254( state, next_func );
  default:
    return fwdfn301( state, next_func );
  }
}

static int fwdfn323( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn314;
    return 11;
  } else {
    return fwdfn314( state, next_func );
  }
}

static int fwdfn322( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 1 ) {
    return fwdfn323( state, next_func );
  } else {
    return fwdfn314( state, next_func );
  }
}

static int fwdfn312( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn313( state, next_func );
  case 1:
    return fwdfn318( state, next_func );
  case 2:
    return fwdfn314( state, next_func );
  default:
    return fwdfn322( state, next_func );
  }
}

static int fwdfn311( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn312;
    return 1;
  } else {
    return fwdfn312( state, next_func );
  }
}

static int fwdfn324( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn312;
    return 9;
  } else {
    return fwdfn312( state, next_func );
  }
}

static int fwdfn310( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return fwdfn311( state, next_func );
  case 1:
    return fwdfn312( state, next_func );
  case 2:
    return fwdfn312( state, next_func );
  default:
    return fwdfn324( state, next_func );
  }
}

static int fwdfn330( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn254;
    return 10;
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn329( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    return fwdfn330( state, next_func );
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn328( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn329;
    return 0;
  } else {
    return fwdfn329( state, next_func );
  }
}

static int fwdfn331( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn321( state, next_func );
  case 1:
    return fwdfn254( state, next_func );
  case 2:
    return fwdfn254( state, next_func );
  default:
    return fwdfn330( state, next_func );
  }
}

static int fwdfn327( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return fwdfn328( state, next_func );
  case 1:
    return fwdfn329( state, next_func );
  case 2:
    return fwdfn329( state, next_func );
  default:
    return fwdfn331( state, next_func );
  }
}

static int fwdfn326( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn327;
    return 17;
  } else {
    return fwdfn327( state, next_func );
  }
}

static int fwdfn334( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn298( state, next_func );
  case 1:
    return fwdfn254( state, next_func );
  case 2:
    return fwdfn254( state, next_func );
  default:
    return fwdfn303( state, next_func );
  }
}

static int fwdfn333( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn334;
    return 0;
  } else {
    return fwdfn334( state, next_func );
  }
}

static int fwdfn336( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn334;
    return 16;
  } else {
    return fwdfn334( state, next_func );
  }
}

static int fwdfn335( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 1 ) {
    return fwdfn336( state, next_func );
  } else {
    return fwdfn334( state, next_func );
  }
}

static int fwdfn332( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return fwdfn333( state, next_func );
  case 1:
    return fwdfn334( state, next_func );
  case 2:
    return fwdfn334( state, next_func );
  default:
    return fwdfn335( state, next_func );
  }
}

static int fwdfn338( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn254;
    return 0;
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn337( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return fwdfn338( state, next_func );
  case 1:
    return fwdfn254( state, next_func );
  case 2:
    return fwdfn254( state, next_func );
  default:
    return fwdfn315( state, next_func );
  }
}

static int fwdfn342( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn254;
    return 2;
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn341( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    return fwdfn342( state, next_func );
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn340( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn341;
    return 0;
  } else {
    return fwdfn341( state, next_func );
  }
}

static int fwdfn344( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn321;
    return 2;
  } else {
    return fwdfn321( state, next_func );
  }
}

static int fwdfn343( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    return fwdfn344( state, next_func );
  } else {
    return fwdfn254( state, next_func );
  }
}

static int fwdfn339( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return fwdfn340( state, next_func );
  case 1:
    return fwdfn341( state, next_func );
  case 2:
    return fwdfn341( state, next_func );
  default:
    return fwdfn343( state, next_func );
  }
}

static int fwdfn325( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return fwdfn326( state, next_func );
  case 1:
    return fwdfn332( state, next_func );
  case 2:
    return fwdfn337( state, next_func );
  default:
    return fwdfn339( state, next_func );
  }
}

static int fwdfn294( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    return fwdfn295( state, next_func );
  case 1:
    return fwdfn310( state, next_func );
  case 2:
    return fwdfn312( state, next_func );
  default:
    return fwdfn325( state, next_func );
  }
}

static int fwdfn345( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn294;
    return 5;
  } else {
    return fwdfn294( state, next_func );
  }
}

static int fwdfn293( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn345( state, next_func );
  } else {
    return fwdfn294( state, next_func );
  }
}

static int fwdfn347( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn294;
    return 4;
  } else {
    return fwdfn294( state, next_func );
  }
}

static int fwdfn348( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn294;
    return 12;
  } else {
    return fwdfn294( state, next_func );
  }
}

static int fwdfn346( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn347( state, next_func );
  case 1:
    return fwdfn294( state, next_func );
  case 2:
    return fwdfn294( state, next_func );
  default:
    return fwdfn348( state, next_func );
  }
}

static int fwdfn350( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn294;
    return 13;
  } else {
    return fwdfn294( state, next_func );
  }
}

static int fwdfn349( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    return fwdfn350( state, next_func );
  } else {
    return fwdfn294( state, next_func );
  }
}

static int fwdfn292( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return fwdfn293( state, next_func );
  case 1:
    return fwdfn346( state, next_func );
  case 2:
    return fwdfn294( state, next_func );
  default:
    return fwdfn349( state, next_func );
  }
}

static int fwdfn351( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn292;
    return 7;
  } else {
    return fwdfn292( state, next_func );
  }
}

static int fwdfn291( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 1 ) {
    return fwdfn351( state, next_func );
  } else {
    return fwdfn292( state, next_func );
  }
}

static int fwdfn353( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn292;
    return 6;
  } else {
    return fwdfn292( state, next_func );
  }
}

static int fwdfn354( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn292;
    return 14;
  } else {
    return fwdfn292( state, next_func );
  }
}

static int fwdfn352( const state_t *state, void *next_func )
{
  switch( state->vars[ 36 ] ) {
  case 0:
    return fwdfn353( state, next_func );
  case 1:
    return fwdfn292( state, next_func );
  case 2:
    return fwdfn292( state, next_func );
  default:
    return fwdfn354( state, next_func );
  }
}

static int fwdfn356( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn292;
    return 15;
  } else {
    return fwdfn292( state, next_func );
  }
}

static int fwdfn355( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 1 ) {
    return fwdfn356( state, next_func );
  } else {
    return fwdfn292( state, next_func );
  }
}

static int fwdfn0( const state_t *state, void *next_func )
{
  switch( state->vars[ 37 ] ) {
  case 0:
    return fwdfn291( state, next_func );
  case 1:
    return fwdfn352( state, next_func );
  case 2:
    return fwdfn292( state, next_func );
  default:
    return fwdfn355( state, next_func );
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
  child_state->vars[ 8 ] = 0;
  child_state->vars[ 9 ] = 1;
  child_state->vars[ 10 ] = 3;
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
  child_state->vars[ 9 ] = 0;
  child_state->vars[ 10 ] = 1;
  child_state->vars[ 11 ] = 3;
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
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = 0;
  child_state->vars[ 37 ] = 1;
  child_state->vars[ 38 ] = 3;
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
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 0;
  child_state->vars[ 38 ] = 1;
  child_state->vars[ 39 ] = 3;
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
  child_state->vars[ 9 ] = 1;
  child_state->vars[ 10 ] = 0;
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
  child_state->vars[ 10 ] = 1;
  child_state->vars[ 11 ] = 0;
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
  child_state->vars[ 37 ] = 1;
  child_state->vars[ 38 ] = 0;
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
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 3;
  child_state->vars[ 38 ] = 1;
  child_state->vars[ 39 ] = 0;
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
  child_state->vars[ 10 ] = 3;
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 1;
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
  child_state->vars[ 11 ] = 3;
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = 1;
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
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 3;
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = 1;
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
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = 3;
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = 1;
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
  child_state->vars[ 24 ] = 3;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = 1;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = 0;
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
  child_state->vars[ 25 ] = 3;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = 1;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = 0;
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
  child_state->vars[ 10 ] = 0;
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 1;
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
  child_state->vars[ 11 ] = 0;
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = 1;
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
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 0;
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = 1;
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
  child_state->vars[ 18 ] = 0;
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = 1;
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
  child_state->vars[ 24 ] = 0;
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = 1;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = 3;
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
  child_state->vars[ 25 ] = 0;
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = 1;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = 3;
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
  child_state->vars[ 9 ] = 0;
  child_state->vars[ 10 ] = 3;
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
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = 0;
  child_state->vars[ 11 ] = 3;
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
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 0;
  child_state->vars[ 18 ] = 3;
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
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 0;
  child_state->vars[ 38 ] = 3;
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
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = 0;
  child_state->vars[ 39 ] = 3;
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
  child_state->vars[ 9 ] = 3;
  child_state->vars[ 10 ] = 0;
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
  child_state->vars[ 10 ] = 3;
  child_state->vars[ 11 ] = 0;
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
  child_state->vars[ 17 ] = 3;
  child_state->vars[ 18 ] = 0;
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

static void bwdrule59( const state_t *state, state_t *child_state )
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

static void bwdrule60( const state_t *state, state_t *child_state )
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

static void bwdrule61( const state_t *state, state_t *child_state )
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
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = 3;
  child_state->vars[ 38 ] = 0;
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

static void bwdrule62( const state_t *state, state_t *child_state )
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
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = 3;
  child_state->vars[ 39 ] = 0;
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

static void bwdrule63( const state_t *state, state_t *child_state )
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

static void bwdrule64( const state_t *state, state_t *child_state )
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
  child_state->vars[ 10 ] = 3;
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 0;
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

static void bwdrule65( const state_t *state, state_t *child_state )
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
  child_state->vars[ 11 ] = 3;
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = 0;
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

static void bwdrule66( const state_t *state, state_t *child_state )
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

static void bwdrule67( const state_t *state, state_t *child_state )
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
  child_state->vars[ 17 ] = 3;
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

static void bwdrule68( const state_t *state, state_t *child_state )
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
  child_state->vars[ 18 ] = 3;
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

static void bwdrule69( const state_t *state, state_t *child_state )
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

static void bwdrule70( const state_t *state, state_t *child_state )
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

static void bwdrule71( const state_t *state, state_t *child_state )
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

static void bwdrule72( const state_t *state, state_t *child_state )
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

static void bwdrule73( const state_t *state, state_t *child_state )
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

static void bwdrule74( const state_t *state, state_t *child_state )
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

static void bwdrule75( const state_t *state, state_t *child_state )
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
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = 0;
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

static void bwdrule76( const state_t *state, state_t *child_state )
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
  child_state->vars[ 32 ] = 3;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = 0;
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

static void bwdrule77( const state_t *state, state_t *child_state )
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

static void bwdrule78( const state_t *state, state_t *child_state )
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
  child_state->vars[ 10 ] = 0;
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 3;
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

static void bwdrule79( const state_t *state, state_t *child_state )
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
  child_state->vars[ 11 ] = 0;
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = 3;
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

static void bwdrule80( const state_t *state, state_t *child_state )
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

static void bwdrule81( const state_t *state, state_t *child_state )
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
  child_state->vars[ 17 ] = 0;
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

static void bwdrule82( const state_t *state, state_t *child_state )
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
  child_state->vars[ 18 ] = 0;
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

static void bwdrule83( const state_t *state, state_t *child_state )
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

static void bwdrule84( const state_t *state, state_t *child_state )
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

static void bwdrule85( const state_t *state, state_t *child_state )
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

static void bwdrule86( const state_t *state, state_t *child_state )
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

static void bwdrule87( const state_t *state, state_t *child_state )
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

static void bwdrule88( const state_t *state, state_t *child_state )
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

static void bwdrule89( const state_t *state, state_t *child_state )
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
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = 3;
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

static void bwdrule90( const state_t *state, state_t *child_state )
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
  child_state->vars[ 32 ] = 0;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
  child_state->vars[ 36 ] = state->vars[ 36 ];
  child_state->vars[ 37 ] = state->vars[ 37 ];
  child_state->vars[ 38 ] = state->vars[ 38 ];
  child_state->vars[ 39 ] = 3;
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

static actfuncptr bwd_rules[ 90 ] = { bwdrule1, bwdrule2, bwdrule3, bwdrule4, bwdrule5, bwdrule6, bwdrule7, bwdrule8, bwdrule9, bwdrule10, bwdrule11, bwdrule12, bwdrule13, bwdrule14, bwdrule15, bwdrule16, bwdrule17, bwdrule18, bwdrule19, bwdrule20, bwdrule21, bwdrule22, bwdrule23, bwdrule24, bwdrule25, bwdrule26, bwdrule27, bwdrule28, bwdrule29, bwdrule30, bwdrule31, bwdrule32, bwdrule33, bwdrule34, bwdrule35, bwdrule36, bwdrule37, bwdrule38, bwdrule39, bwdrule40, bwdrule41, bwdrule42, bwdrule43, bwdrule44, bwdrule45, bwdrule46, bwdrule47, bwdrule48, bwdrule49, bwdrule50, bwdrule51, bwdrule52, bwdrule53, bwdrule54, bwdrule55, bwdrule56, bwdrule57, bwdrule58, bwdrule59, bwdrule60, bwdrule61, bwdrule62, bwdrule63, bwdrule64, bwdrule65, bwdrule66, bwdrule67, bwdrule68, bwdrule69, bwdrule70, bwdrule71, bwdrule72, bwdrule73, bwdrule74, bwdrule75, bwdrule76, bwdrule77, bwdrule78, bwdrule79, bwdrule80, bwdrule81, bwdrule82, bwdrule83, bwdrule84, bwdrule85, bwdrule86, bwdrule87, bwdrule88, bwdrule89, bwdrule90 };

static int bwdfn18( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = 0;
    return 78;
  } else {
    return -1;
  }
}

static int bwdfn17( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return bwdfn18( state, next_func );
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    *((funcptr *)next_func) = 0;
    return 81;
  }
}

static int bwdfn20( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    *((funcptr *)next_func) = 0;
    return 78;
  } else {
    return -1;
  }
}

static int bwdfn19( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    return bwdfn20( state, next_func );
  } else {
    return -1;
  }
}

static int bwdfn16( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return bwdfn17( state, next_func );
  case 1:
    return bwdfn19( state, next_func );
  case 2:
    return bwdfn19( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn19;
    return 85;
  }
}

static int bwdfn15( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn16;
    return 75;
  } else {
    return bwdfn16( state, next_func );
  }
}

static int bwdfn22( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = 0;
    return 81;
  } else {
    return -1;
  }
}

static int bwdfn21( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return bwdfn18( state, next_func );
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    return bwdfn22( state, next_func );
  }
}

static int bwdfn23( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn21;
    return 89;
  } else {
    return bwdfn21( state, next_func );
  }
}

static int bwdfn14( const state_t *state, void *next_func )
{
  switch( state->vars[ 32 ] ) {
  case 0:
    return bwdfn15( state, next_func );
  case 1:
    return bwdfn21( state, next_func );
  case 2:
    return bwdfn21( state, next_func );
  default:
    return bwdfn23( state, next_func );
  }
}

static int bwdfn13( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn14;
    return 77;
  } else {
    return bwdfn14( state, next_func );
  }
}

static int bwdfn12( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return bwdfn13( state, next_func );
  case 1:
    return bwdfn14( state, next_func );
  case 2:
    return bwdfn14( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn14;
    return 80;
  }
}

static int bwdfn25( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn14;
    return 77;
  } else {
    return bwdfn14( state, next_func );
  }
}

static int bwdfn24( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    return bwdfn25( state, next_func );
  } else {
    return bwdfn14( state, next_func );
  }
}

static int bwdfn11( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return bwdfn12( state, next_func );
  case 1:
    return bwdfn24( state, next_func );
  case 2:
    return bwdfn24( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn24;
    return 84;
  }
}

static int bwdfn10( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn11;
    return 74;
  } else {
    return bwdfn11( state, next_func );
  }
}

static int bwdfn27( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn14;
    return 80;
  } else {
    return bwdfn14( state, next_func );
  }
}

static int bwdfn26( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return bwdfn13( state, next_func );
  case 1:
    return bwdfn14( state, next_func );
  case 2:
    return bwdfn14( state, next_func );
  default:
    return bwdfn27( state, next_func );
  }
}

static int bwdfn28( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn26;
    return 88;
  } else {
    return bwdfn26( state, next_func );
  }
}

static int bwdfn9( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn10( state, next_func );
  case 1:
    return bwdfn26( state, next_func );
  case 2:
    return bwdfn26( state, next_func );
  default:
    return bwdfn28( state, next_func );
  }
}

static int bwdfn8( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn9;
    return 76;
  } else {
    return bwdfn9( state, next_func );
  }
}

static int bwdfn7( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn8( state, next_func );
  case 1:
    return bwdfn9( state, next_func );
  case 2:
    return bwdfn9( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn9;
    return 79;
  }
}

static int bwdfn30( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn9;
    return 76;
  } else {
    return bwdfn9( state, next_func );
  }
}

static int bwdfn29( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return bwdfn30( state, next_func );
  } else {
    return bwdfn9( state, next_func );
  }
}

static int bwdfn6( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn7( state, next_func );
  case 1:
    return bwdfn29( state, next_func );
  case 2:
    return bwdfn29( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn29;
    return 82;
  }
}

static int bwdfn5( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn6;
    return 72;
  } else {
    return bwdfn6( state, next_func );
  }
}

static int bwdfn32( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn9;
    return 79;
  } else {
    return bwdfn9( state, next_func );
  }
}

static int bwdfn31( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn8( state, next_func );
  case 1:
    return bwdfn9( state, next_func );
  case 2:
    return bwdfn9( state, next_func );
  default:
    return bwdfn32( state, next_func );
  }
}

static int bwdfn33( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn31;
    return 86;
  } else {
    return bwdfn31( state, next_func );
  }
}

static int bwdfn4( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn5( state, next_func );
  case 1:
    return bwdfn31( state, next_func );
  case 2:
    return bwdfn31( state, next_func );
  default:
    return bwdfn33( state, next_func );
  }
}

static int bwdfn3( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn4;
    return 83;
  } else {
    return bwdfn4( state, next_func );
  }
}

static int bwdfn2( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn3;
    return 73;
  } else {
    return bwdfn3( state, next_func );
  }
}

static int bwdfn34( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn4;
    return 87;
  } else {
    return bwdfn4( state, next_func );
  }
}

static int bwdfn1( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn2( state, next_func );
  case 1:
    return bwdfn4( state, next_func );
  case 2:
    return bwdfn4( state, next_func );
  default:
    return bwdfn34( state, next_func );
  }
}

static int bwdfn50( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 69;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn49( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn50;
    return 56;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn52( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 69;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn51( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    return bwdfn52( state, next_func );
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn48( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn49( state, next_func );
  case 1:
    return bwdfn51( state, next_func );
  case 2:
    return bwdfn51( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn51;
    return 68;
  }
}

static int bwdfn54( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn50;
    return 56;
  } else {
    return bwdfn50( state, next_func );
  }
}

static int bwdfn53( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 3 ) {
    return bwdfn54( state, next_func );
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn47( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn48( state, next_func );
  case 1:
    return bwdfn53( state, next_func );
  case 2:
    return bwdfn53( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn53;
    return 65;
  }
}

static int bwdfn56( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn51;
    return 68;
  } else {
    return bwdfn51( state, next_func );
  }
}

static int bwdfn55( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn49( state, next_func );
  case 1:
    return bwdfn51( state, next_func );
  case 2:
    return bwdfn51( state, next_func );
  default:
    return bwdfn56( state, next_func );
  }
}

static int bwdfn57( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn55;
    return 62;
  } else {
    return bwdfn55( state, next_func );
  }
}

static int bwdfn46( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn47( state, next_func );
  case 1:
    return bwdfn55( state, next_func );
  case 2:
    return bwdfn55( state, next_func );
  default:
    return bwdfn57( state, next_func );
  }
}

static int bwdfn45( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn46;
    return 64;
  } else {
    return bwdfn46( state, next_func );
  }
}

static int bwdfn44( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    return bwdfn45( state, next_func );
  } else {
    return bwdfn46( state, next_func );
  }
}

static int bwdfn43_a3_1( const state_t *state, void *next_func )
{
  *((funcptr *)next_func) = bwdfn44;
  return 71;
}

static int bwdfn43( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn43_a3_1;
    return 58;
  } else {
    return bwdfn44( state, next_func );
  }
}

static int bwdfn59( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn45;
    return 71;
  } else {
    return bwdfn45( state, next_func );
  }
}

static int bwdfn60( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn46;
    return 71;
  } else {
    return bwdfn46( state, next_func );
  }
}

static int bwdfn58( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    return bwdfn59( state, next_func );
  } else {
    return bwdfn60( state, next_func );
  }
}

static int bwdfn67( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 68;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn66( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn67( state, next_func );
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn1;
    return 65;
  }
}

static int bwdfn68( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    return bwdfn67( state, next_func );
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn69( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn68;
    return 62;
  } else {
    return bwdfn68( state, next_func );
  }
}

static int bwdfn65( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn66( state, next_func );
  case 1:
    return bwdfn68( state, next_func );
  case 2:
    return bwdfn68( state, next_func );
  default:
    return bwdfn69( state, next_func );
  }
}

static int bwdfn64( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn65;
    return 64;
  } else {
    return bwdfn65( state, next_func );
  }
}

static int bwdfn63( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    return bwdfn64( state, next_func );
  } else {
    return bwdfn65( state, next_func );
  }
}

static int bwdfn62( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn63;
    return 71;
  } else {
    return bwdfn63( state, next_func );
  }
}

static int bwdfn76( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 65;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn77( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 62;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn75( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn76( state, next_func );
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn77( state, next_func );
  }
}

static int bwdfn74( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn75;
    return 64;
  } else {
    return bwdfn75( state, next_func );
  }
}

static int bwdfn73( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    return bwdfn74( state, next_func );
  } else {
    return bwdfn75( state, next_func );
  }
}

static int bwdfn72( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn73;
    return 69;
  } else {
    return bwdfn73( state, next_func );
  }
}

static int bwdfn83( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 64;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn82( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    return bwdfn83( state, next_func );
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn81( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn82;
    return 62;
  } else {
    return bwdfn82( state, next_func );
  }
}

static int bwdfn80( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    return bwdfn81( state, next_func );
  } else {
    return bwdfn82( state, next_func );
  }
}

static int bwdfn85( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn82;
    return 62;
  } else {
    return bwdfn82( state, next_func );
  }
}

static int bwdfn84( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn82;
    return 65;
  case 1:
    return bwdfn82( state, next_func );
  case 2:
    return bwdfn82( state, next_func );
  default:
    return bwdfn85( state, next_func );
  }
}

static int bwdfn79( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn80;
    return 68;
  case 1:
    return bwdfn80( state, next_func );
  case 2:
    return bwdfn80( state, next_func );
  default:
    return bwdfn84( state, next_func );
  }
}

static int bwdfn78( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn79;
    return 69;
  } else {
    return bwdfn79( state, next_func );
  }
}

static int bwdfn71( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn72;
    return 56;
  case 1:
    return bwdfn72( state, next_func );
  case 2:
    return bwdfn72( state, next_func );
  default:
    return bwdfn78( state, next_func );
  }
}

static int bwdfn70( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn71;
    return 71;
  } else {
    return bwdfn71( state, next_func );
  }
}

static int bwdfn61( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn62;
    return 57;
  case 1:
    return bwdfn62( state, next_func );
  case 2:
    return bwdfn62( state, next_func );
  default:
    return bwdfn70( state, next_func );
  }
}

static int bwdfn42( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn43( state, next_func );
  case 1:
    return bwdfn58( state, next_func );
  case 2:
    return bwdfn58( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn61;
    return 70;
  }
}

static int bwdfn87( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn44;
    return 58;
  } else {
    return bwdfn44( state, next_func );
  }
}

static int bwdfn88( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn63;
    return 57;
  case 1:
    return bwdfn63( state, next_func );
  case 2:
    return bwdfn63( state, next_func );
  default:
    return bwdfn71( state, next_func );
  }
}

static int bwdfn86( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn87( state, next_func );
  case 1:
    return bwdfn44( state, next_func );
  case 2:
    return bwdfn44( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn88;
    return 70;
  }
}

static int bwdfn92( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn46;
    return 64;
  } else {
    return bwdfn46( state, next_func );
  }
}

static int bwdfn91( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn46;
    return 67;
  case 1:
    return bwdfn46( state, next_func );
  case 2:
    return bwdfn46( state, next_func );
  default:
    return bwdfn92( state, next_func );
  }
}

static int bwdfn90( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn91;
    return 58;
  } else {
    return bwdfn91( state, next_func );
  }
}

static int bwdfn95( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn65;
    return 64;
  } else {
    return bwdfn65( state, next_func );
  }
}

static int bwdfn94( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn65;
    return 67;
  case 1:
    return bwdfn65( state, next_func );
  case 2:
    return bwdfn65( state, next_func );
  default:
    return bwdfn95( state, next_func );
  }
}

static int bwdfn99( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn75;
    return 64;
  } else {
    return bwdfn75( state, next_func );
  }
}

static int bwdfn98( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn75;
    return 67;
  case 1:
    return bwdfn75( state, next_func );
  case 2:
    return bwdfn75( state, next_func );
  default:
    return bwdfn99( state, next_func );
  }
}

static int bwdfn103( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 62;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn102( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    return bwdfn103( state, next_func );
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn104( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn1;
    return 65;
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn77( state, next_func );
  }
}

static int bwdfn101( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn102;
    return 68;
  case 1:
    return bwdfn102( state, next_func );
  case 2:
    return bwdfn102( state, next_func );
  default:
    return bwdfn104( state, next_func );
  }
}

static int bwdfn105( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn101;
    return 64;
  } else {
    return bwdfn101( state, next_func );
  }
}

static int bwdfn100( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn101;
    return 67;
  case 1:
    return bwdfn101( state, next_func );
  case 2:
    return bwdfn101( state, next_func );
  default:
    return bwdfn105( state, next_func );
  }
}

static int bwdfn97( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn98;
    return 56;
  case 1:
    return bwdfn98( state, next_func );
  case 2:
    return bwdfn98( state, next_func );
  default:
    return bwdfn100( state, next_func );
  }
}

static int bwdfn96( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn97;
    return 69;
  } else {
    return bwdfn97( state, next_func );
  }
}

static int bwdfn93( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn94;
    return 57;
  case 1:
    return bwdfn94( state, next_func );
  case 2:
    return bwdfn94( state, next_func );
  default:
    return bwdfn96( state, next_func );
  }
}

static int bwdfn89( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn90( state, next_func );
  case 1:
    return bwdfn91( state, next_func );
  case 2:
    return bwdfn91( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn93;
    return 70;
  }
}

static int bwdfn41( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return bwdfn42( state, next_func );
  case 1:
    return bwdfn86( state, next_func );
  case 2:
    return bwdfn86( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn89;
    return 55;
  }
}

static int bwdfn40( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn41;
    return 63;
  } else {
    return bwdfn41( state, next_func );
  }
}

static int bwdfn39( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    return bwdfn40( state, next_func );
  } else {
    return bwdfn41( state, next_func );
  }
}

static int bwdfn112( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn65;
    return 67;
  } else {
    return bwdfn65( state, next_func );
  }
}

static int bwdfn111( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return bwdfn112( state, next_func );
  case 1:
    return bwdfn65( state, next_func );
  case 2:
    return bwdfn65( state, next_func );
  default:
    return bwdfn95( state, next_func );
  }
}

static int bwdfn113( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn63;
    return 71;
  case 1:
    return bwdfn63( state, next_func );
  case 2:
    return bwdfn63( state, next_func );
  default:
    return bwdfn94( state, next_func );
  }
}

static int bwdfn110( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn113;
    return 58;
  } else {
    return bwdfn111( state, next_func );
  }
}

static int bwdfn119( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 71;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn118( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return bwdfn119( state, next_func );
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn1;
    return 67;
  }
}

static int bwdfn120( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    return bwdfn119( state, next_func );
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn121( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn120;
    return 64;
  } else {
    return bwdfn120( state, next_func );
  }
}

static int bwdfn117( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return bwdfn118( state, next_func );
  case 1:
    return bwdfn120( state, next_func );
  case 2:
    return bwdfn120( state, next_func );
  default:
    return bwdfn121( state, next_func );
  }
}

static int bwdfn116( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn117;
    return 68;
  } else {
    return bwdfn117( state, next_func );
  }
}

static int bwdfn115( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn116( state, next_func );
  case 1:
    return bwdfn117( state, next_func );
  case 2:
    return bwdfn117( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn117;
    return 65;
  }
}

static int bwdfn122( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    return bwdfn116( state, next_func );
  } else {
    return bwdfn117( state, next_func );
  }
}

static int bwdfn123( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn122;
    return 62;
  } else {
    return bwdfn122( state, next_func );
  }
}

static int bwdfn114( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn115( state, next_func );
  case 1:
    return bwdfn122( state, next_func );
  case 2:
    return bwdfn122( state, next_func );
  default:
    return bwdfn123( state, next_func );
  }
}

static int bwdfn109( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn110( state, next_func );
  case 1:
    return bwdfn114( state, next_func );
  case 2:
    return bwdfn114( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn114;
    return 57;
  }
}

static int bwdfn130( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 58;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn129( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn130;
    return 71;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn132( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 58;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn131( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn132( state, next_func );
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn128( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return bwdfn129( state, next_func );
  case 1:
    return bwdfn131( state, next_func );
  case 2:
    return bwdfn131( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn131;
    return 67;
  }
}

static int bwdfn135( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 71;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn134( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn135;
    return 58;
  } else {
    return bwdfn135( state, next_func );
  }
}

static int bwdfn133( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    return bwdfn134( state, next_func );
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn136( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn133;
    return 64;
  } else {
    return bwdfn133( state, next_func );
  }
}

static int bwdfn127( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return bwdfn128( state, next_func );
  case 1:
    return bwdfn133( state, next_func );
  case 2:
    return bwdfn133( state, next_func );
  default:
    return bwdfn136( state, next_func );
  }
}

static int bwdfn126( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn127;
    return 68;
  } else {
    return bwdfn127( state, next_func );
  }
}

static int bwdfn125( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn126( state, next_func );
  case 1:
    return bwdfn127( state, next_func );
  case 2:
    return bwdfn127( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn127;
    return 65;
  }
}

static int bwdfn137( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    return bwdfn126( state, next_func );
  } else {
    return bwdfn127( state, next_func );
  }
}

static int bwdfn138( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn137;
    return 62;
  } else {
    return bwdfn137( state, next_func );
  }
}

static int bwdfn124( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn125( state, next_func );
  case 1:
    return bwdfn137( state, next_func );
  case 2:
    return bwdfn137( state, next_func );
  default:
    return bwdfn138( state, next_func );
  }
}

static int bwdfn142( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn127;
    return 65;
  } else {
    return bwdfn127( state, next_func );
  }
}

static int bwdfn143( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn127;
    return 62;
  } else {
    return bwdfn127( state, next_func );
  }
}

static int bwdfn141( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn142( state, next_func );
  case 1:
    return bwdfn127( state, next_func );
  case 2:
    return bwdfn127( state, next_func );
  default:
    return bwdfn143( state, next_func );
  }
}

static int bwdfn140( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn141;
    return 69;
  } else {
    return bwdfn141( state, next_func );
  }
}

static int bwdfn147( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn127;
    return 69;
  } else {
    return bwdfn127( state, next_func );
  }
}

static int bwdfn146( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn147;
    return 62;
  } else {
    return bwdfn147( state, next_func );
  }
}

static int bwdfn145( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    return bwdfn146( state, next_func );
  } else {
    return bwdfn147( state, next_func );
  }
}

static int bwdfn149( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn147;
    return 62;
  } else {
    return bwdfn147( state, next_func );
  }
}

static int bwdfn148( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn147;
    return 65;
  case 1:
    return bwdfn147( state, next_func );
  case 2:
    return bwdfn147( state, next_func );
  default:
    return bwdfn149( state, next_func );
  }
}

static int bwdfn144( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn145;
    return 68;
  case 1:
    return bwdfn145( state, next_func );
  case 2:
    return bwdfn145( state, next_func );
  default:
    return bwdfn148( state, next_func );
  }
}

static int bwdfn139( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn140;
    return 56;
  case 1:
    return bwdfn140( state, next_func );
  case 2:
    return bwdfn140( state, next_func );
  default:
    return bwdfn144( state, next_func );
  }
}

static int bwdfn108( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn109( state, next_func );
  case 1:
    return bwdfn124( state, next_func );
  case 2:
    return bwdfn124( state, next_func );
  default:
    return bwdfn139( state, next_func );
  }
}

static int bwdfn107( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn108;
    return 63;
  } else {
    return bwdfn108( state, next_func );
  }
}

static int bwdfn106( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    return bwdfn107( state, next_func );
  } else {
    return bwdfn108( state, next_func );
  }
}

static int bwdfn153( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn109;
    return 63;
  } else {
    return bwdfn109( state, next_func );
  }
}

static int bwdfn152( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn109;
    return 66;
  case 1:
    return bwdfn109( state, next_func );
  case 2:
    return bwdfn109( state, next_func );
  default:
    return bwdfn153( state, next_func );
  }
}

static int bwdfn155( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn124;
    return 63;
  } else {
    return bwdfn124( state, next_func );
  }
}

static int bwdfn154( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn124;
    return 66;
  case 1:
    return bwdfn124( state, next_func );
  case 2:
    return bwdfn124( state, next_func );
  default:
    return bwdfn155( state, next_func );
  }
}

static int bwdfn158( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn141;
    return 63;
  } else {
    return bwdfn141( state, next_func );
  }
}

static int bwdfn157( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn141;
    return 66;
  case 1:
    return bwdfn141( state, next_func );
  case 2:
    return bwdfn141( state, next_func );
  default:
    return bwdfn158( state, next_func );
  }
}

static int bwdfn162( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn127;
    return 62;
  } else {
    return bwdfn127( state, next_func );
  }
}

static int bwdfn161( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    return bwdfn162( state, next_func );
  } else {
    return bwdfn127( state, next_func );
  }
}

static int bwdfn163( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn127;
    return 65;
  case 1:
    return bwdfn127( state, next_func );
  case 2:
    return bwdfn127( state, next_func );
  default:
    return bwdfn143( state, next_func );
  }
}

static int bwdfn160( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn161;
    return 68;
  case 1:
    return bwdfn161( state, next_func );
  case 2:
    return bwdfn161( state, next_func );
  default:
    return bwdfn163( state, next_func );
  }
}

static int bwdfn164( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn160;
    return 63;
  } else {
    return bwdfn160( state, next_func );
  }
}

static int bwdfn159( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn160;
    return 66;
  case 1:
    return bwdfn160( state, next_func );
  case 2:
    return bwdfn160( state, next_func );
  default:
    return bwdfn164( state, next_func );
  }
}

static int bwdfn156( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn157;
    return 56;
  case 1:
    return bwdfn157( state, next_func );
  case 2:
    return bwdfn157( state, next_func );
  default:
    return bwdfn159( state, next_func );
  }
}

static int bwdfn151( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn152( state, next_func );
  case 1:
    return bwdfn154( state, next_func );
  case 2:
    return bwdfn154( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn156;
    return 69;
  }
}

static int bwdfn173( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 67;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn174( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 64;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn172( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return bwdfn173( state, next_func );
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn174( state, next_func );
  }
}

static int bwdfn176( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn1;
    return 67;
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn174( state, next_func );
  }
}

static int bwdfn175( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn82;
    return 71;
  case 1:
    return bwdfn82( state, next_func );
  case 2:
    return bwdfn82( state, next_func );
  default:
    return bwdfn176( state, next_func );
  }
}

static int bwdfn171( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn175;
    return 58;
  } else {
    return bwdfn172( state, next_func );
  }
}

static int bwdfn170( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn171( state, next_func );
  case 1:
    return bwdfn117( state, next_func );
  case 2:
    return bwdfn117( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn117;
    return 57;
  }
}

static int bwdfn169( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn170( state, next_func );
  case 1:
    return bwdfn127( state, next_func );
  case 2:
    return bwdfn127( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn127;
    return 56;
  }
}

static int bwdfn181( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 57;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn180( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    return bwdfn181( state, next_func );
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn183( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 57;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn182( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn1;
    return 58;
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn183( state, next_func );
  }
}

static int bwdfn179( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn182;
    return 71;
  } else {
    return bwdfn180( state, next_func );
  }
}

static int bwdfn184( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn132( state, next_func );
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn183( state, next_func );
  }
}

static int bwdfn178( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return bwdfn179( state, next_func );
  case 1:
    return bwdfn184( state, next_func );
  case 2:
    return bwdfn184( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn184;
    return 67;
  }
}

static int bwdfn186( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn135;
    return 58;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn187( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn120;
    return 57;
  } else {
    return bwdfn120( state, next_func );
  }
}

static int bwdfn185( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn186( state, next_func );
  case 1:
    return bwdfn120( state, next_func );
  case 2:
    return bwdfn120( state, next_func );
  default:
    return bwdfn187( state, next_func );
  }
}

static int bwdfn188( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn185;
    return 64;
  } else {
    return bwdfn185( state, next_func );
  }
}

static int bwdfn177( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return bwdfn178( state, next_func );
  case 1:
    return bwdfn185( state, next_func );
  case 2:
    return bwdfn185( state, next_func );
  default:
    return bwdfn188( state, next_func );
  }
}

static int bwdfn168( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn169( state, next_func );
  case 1:
    return bwdfn177( state, next_func );
  case 2:
    return bwdfn177( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn177;
    return 68;
  }
}

static int bwdfn193( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 56;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn192( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn181( state, next_func );
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn193( state, next_func );
  }
}

static int bwdfn196( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 56;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn195( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    return bwdfn196( state, next_func );
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn197( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn1;
    return 57;
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn193( state, next_func );
  }
}

static int bwdfn194( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn195;
    return 58;
  case 1:
    return bwdfn195( state, next_func );
  case 2:
    return bwdfn195( state, next_func );
  default:
    return bwdfn197( state, next_func );
  }
}

static int bwdfn191( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn194;
    return 71;
  } else {
    return bwdfn192( state, next_func );
  }
}

static int bwdfn199( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn132( state, next_func );
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn1;
    return 57;
  }
}

static int bwdfn200( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn131;
    return 56;
  } else {
    return bwdfn131( state, next_func );
  }
}

static int bwdfn198( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn199( state, next_func );
  case 1:
    return bwdfn131( state, next_func );
  case 2:
    return bwdfn131( state, next_func );
  default:
    return bwdfn200( state, next_func );
  }
}

static int bwdfn190( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return bwdfn191( state, next_func );
  case 1:
    return bwdfn198( state, next_func );
  case 2:
    return bwdfn198( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn198;
    return 67;
  }
}

static int bwdfn202( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return bwdfn186( state, next_func );
  case 1:
    return bwdfn120( state, next_func );
  case 2:
    return bwdfn120( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn120;
    return 57;
  }
}

static int bwdfn203( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn133;
    return 56;
  } else {
    return bwdfn133( state, next_func );
  }
}

static int bwdfn201( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn202( state, next_func );
  case 1:
    return bwdfn133( state, next_func );
  case 2:
    return bwdfn133( state, next_func );
  default:
    return bwdfn203( state, next_func );
  }
}

static int bwdfn204( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn201;
    return 64;
  } else {
    return bwdfn201( state, next_func );
  }
}

static int bwdfn189( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return bwdfn190( state, next_func );
  case 1:
    return bwdfn201( state, next_func );
  case 2:
    return bwdfn201( state, next_func );
  default:
    return bwdfn204( state, next_func );
  }
}

static int bwdfn167( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn168( state, next_func );
  case 1:
    return bwdfn189( state, next_func );
  case 2:
    return bwdfn189( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn189;
    return 65;
  }
}

static int bwdfn209( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn181( state, next_func );
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn1;
    return 56;
  }
}

static int bwdfn210( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn180;
    return 68;
  } else {
    return bwdfn180( state, next_func );
  }
}

static int bwdfn208( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn209( state, next_func );
  case 1:
    return bwdfn180( state, next_func );
  case 2:
    return bwdfn180( state, next_func );
  default:
    return bwdfn210( state, next_func );
  }
}

static int bwdfn213( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn1;
    return 68;
  } else {
    return bwdfn1( state, next_func );
  }
}

static int bwdfn212( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn196( state, next_func );
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn213( state, next_func );
  }
}

static int bwdfn215( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn1;
    return 56;
  case 1:
    return bwdfn1( state, next_func );
  case 2:
    return bwdfn1( state, next_func );
  default:
    return bwdfn213( state, next_func );
  }
}

static int bwdfn214( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn68;
    return 57;
  case 1:
    return bwdfn68( state, next_func );
  case 2:
    return bwdfn68( state, next_func );
  default:
    return bwdfn215( state, next_func );
  }
}

static int bwdfn211( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn212;
    return 58;
  case 1:
    return bwdfn212( state, next_func );
  case 2:
    return bwdfn212( state, next_func );
  default:
    return bwdfn214( state, next_func );
  }
}

static int bwdfn207( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn211;
    return 71;
  } else {
    return bwdfn208( state, next_func );
  }
}

static int bwdfn217( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn199( state, next_func );
  case 1:
    return bwdfn131( state, next_func );
  case 2:
    return bwdfn131( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn131;
    return 56;
  }
}

static int bwdfn218( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn184;
    return 68;
  } else {
    return bwdfn184( state, next_func );
  }
}

static int bwdfn216( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn217( state, next_func );
  case 1:
    return bwdfn184( state, next_func );
  case 2:
    return bwdfn184( state, next_func );
  default:
    return bwdfn218( state, next_func );
  }
}

static int bwdfn206( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return bwdfn207( state, next_func );
  case 1:
    return bwdfn216( state, next_func );
  case 2:
    return bwdfn216( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn216;
    return 67;
  }
}

static int bwdfn220( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn202( state, next_func );
  case 1:
    return bwdfn133( state, next_func );
  case 2:
    return bwdfn133( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn133;
    return 56;
  }
}

static int bwdfn221( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn185;
    return 68;
  } else {
    return bwdfn185( state, next_func );
  }
}

static int bwdfn219( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn220( state, next_func );
  case 1:
    return bwdfn185( state, next_func );
  case 2:
    return bwdfn185( state, next_func );
  default:
    return bwdfn221( state, next_func );
  }
}

static int bwdfn222( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn219;
    return 64;
  } else {
    return bwdfn219( state, next_func );
  }
}

static int bwdfn205( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return bwdfn206( state, next_func );
  case 1:
    return bwdfn219( state, next_func );
  case 2:
    return bwdfn219( state, next_func );
  default:
    return bwdfn222( state, next_func );
  }
}

static int bwdfn223( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn205;
    return 62;
  } else {
    return bwdfn205( state, next_func );
  }
}

static int bwdfn166( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn167( state, next_func );
  case 1:
    return bwdfn205( state, next_func );
  case 2:
    return bwdfn205( state, next_func );
  default:
    return bwdfn223( state, next_func );
  }
}

static int bwdfn224( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn166;
    return 63;
  } else {
    return bwdfn166( state, next_func );
  }
}

static int bwdfn165( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn166;
    return 66;
  case 1:
    return bwdfn166( state, next_func );
  case 2:
    return bwdfn166( state, next_func );
  default:
    return bwdfn224( state, next_func );
  }
}

static int bwdfn150( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn151;
    return 54;
  } else {
    return bwdfn165( state, next_func );
  }
}

static int bwdfn38( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return bwdfn39( state, next_func );
  case 1:
    return bwdfn106( state, next_func );
  case 2:
    return bwdfn106( state, next_func );
  default:
    return bwdfn150( state, next_func );
  }
}

static int bwdfn37( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn38;
    return 61;
  } else {
    return bwdfn38( state, next_func );
  }
}

static int bwdfn36( const state_t *state, void *next_func )
{
  switch( state->vars[ 38 ] ) {
  case 0:
    return bwdfn37( state, next_func );
  case 1:
    return bwdfn38( state, next_func );
  case 2:
    return bwdfn38( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn38;
    return 60;
  }
}

static int bwdfn225( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 0 ) {
    return bwdfn37( state, next_func );
  } else {
    return bwdfn38( state, next_func );
  }
}

static int bwdfn226( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn225;
    return 59;
  } else {
    return bwdfn225( state, next_func );
  }
}

static int bwdfn35( const state_t *state, void *next_func )
{
  switch( state->vars[ 37 ] ) {
  case 0:
    return bwdfn36( state, next_func );
  case 1:
    return bwdfn225( state, next_func );
  case 2:
    return bwdfn225( state, next_func );
  default:
    return bwdfn226( state, next_func );
  }
}

static int bwdfn241( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn35;
    return 51;
  } else {
    return bwdfn35( state, next_func );
  }
}

static int bwdfn242( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn35;
    return 38;
  } else {
    return bwdfn35( state, next_func );
  }
}

static int bwdfn240( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    return bwdfn241( state, next_func );
  case 1:
    return bwdfn35( state, next_func );
  case 2:
    return bwdfn35( state, next_func );
  default:
    *((funcptr *)next_func) = bwdfn242;
    return 50;
  }
}

static int bwdfn239( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn240;
    return 36;
  } else {
    return bwdfn240( state, next_func );
  }
}

static int bwdfn243( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    return bwdfn241( state, next_func );
  case 1:
    return bwdfn35( state, next_func );
  case 2:
    return bwdfn35( state, next_func );
  default:
    return bwdfn242( state, next_func );
  }
}

static int bwdfn245( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn241;
    return 37;
  case 1:
    return bwdfn35( state, next_func );
  case 2:
    return bwdfn35( state, next_func );
  default:
    return bwdfn242( state, next_func );
  }
}

static int bwdfn244( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn245;
    return 49;
  } else {
    return bwdfn245( state, next_func );
  }
}

static int bwdfn238( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return bwdfn239( state, next_func );
  case 1:
    return bwdfn243( state, next_func );
  case 2:
    return bwdfn243( state, next_func );
  default:
    return bwdfn244( state, next_func );
  }
}

static int bwdfn246( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn238;
    return 42;
  } else {
    return bwdfn238( state, next_func );
  }
}

static int bwdfn237( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 3 ) {
    return bwdfn246( state, next_func );
  } else {
    return bwdfn238( state, next_func );
  }
}

static int bwdfn236( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn237;
    return 40;
  } else {
    return bwdfn237( state, next_func );
  }
}

static int bwdfn248( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn238;
    return 41;
  case 1:
    return bwdfn238( state, next_func );
  case 2:
    return bwdfn238( state, next_func );
  default:
    return bwdfn246( state, next_func );
  }
}

static int bwdfn247( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn248;
    return 53;
  } else {
    return bwdfn248( state, next_func );
  }
}

static int bwdfn235( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return bwdfn236( state, next_func );
  case 1:
    return bwdfn237( state, next_func );
  case 2:
    return bwdfn237( state, next_func );
  default:
    return bwdfn247( state, next_func );
  }
}

static int bwdfn249( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn235;
    return 48;
  } else {
    return bwdfn235( state, next_func );
  }
}

static int bwdfn234( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 3 ) {
    return bwdfn249( state, next_func );
  } else {
    return bwdfn235( state, next_func );
  }
}

static int bwdfn233( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn234;
    return 46;
  } else {
    return bwdfn234( state, next_func );
  }
}

static int bwdfn250( const state_t *state, void *next_func )
{
  switch( state->vars[ 38 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn235;
    return 47;
  case 1:
    return bwdfn235( state, next_func );
  case 2:
    return bwdfn235( state, next_func );
  default:
    return bwdfn249( state, next_func );
  }
}

static int bwdfn232( const state_t *state, void *next_func )
{
  switch( state->vars[ 37 ] ) {
  case 0:
    return bwdfn233( state, next_func );
  case 1:
    return bwdfn234( state, next_func );
  case 2:
    return bwdfn234( state, next_func );
  default:
    return bwdfn250( state, next_func );
  }
}

static int bwdfn251( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn232;
    return 45;
  } else {
    return bwdfn232( state, next_func );
  }
}

static int bwdfn231( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    return bwdfn251( state, next_func );
  } else {
    return bwdfn232( state, next_func );
  }
}

static int bwdfn230( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn231;
    return 43;
  } else {
    return bwdfn231( state, next_func );
  }
}

static int bwdfn252( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    *((funcptr *)next_func) = bwdfn232;
    return 44;
  case 1:
    return bwdfn232( state, next_func );
  case 2:
    return bwdfn232( state, next_func );
  default:
    return bwdfn251( state, next_func );
  }
}

static int bwdfn229( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn230( state, next_func );
  case 1:
    return bwdfn231( state, next_func );
  case 2:
    return bwdfn231( state, next_func );
  default:
    return bwdfn252( state, next_func );
  }
}

static int bwdfn228( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn229;
    return 52;
  } else {
    return bwdfn229( state, next_func );
  }
}

static int bwdfn253( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn229;
    return 39;
  } else {
    return bwdfn229( state, next_func );
  }
}

static int bwdfn227( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return bwdfn228( state, next_func );
  case 1:
    return bwdfn229( state, next_func );
  case 2:
    return bwdfn229( state, next_func );
  default:
    return bwdfn253( state, next_func );
  }
}

static int bwdfn261( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn227;
    return 21;
  } else {
    return bwdfn227( state, next_func );
  }
}

static int bwdfn262( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn227;
    return 31;
  } else {
    return bwdfn227( state, next_func );
  }
}

static int bwdfn260( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return bwdfn227( state, next_func );
  case 1:
    return bwdfn261( state, next_func );
  case 2:
    return bwdfn227( state, next_func );
  default:
    return bwdfn262( state, next_func );
  }
}

static int bwdfn266( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn227;
    return 28;
  } else {
    return bwdfn227( state, next_func );
  }
}

static int bwdfn265( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    return bwdfn266( state, next_func );
  } else {
    return bwdfn227( state, next_func );
  }
}

static int bwdfn264( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn265;
    return 25;
  } else {
    return bwdfn265( state, next_func );
  }
}

static int bwdfn263( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    return bwdfn264( state, next_func );
  } else {
    return bwdfn265( state, next_func );
  }
}

static int bwdfn269( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn227;
    return 35;
  } else {
    return bwdfn227( state, next_func );
  }
}

static int bwdfn268( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    return bwdfn269( state, next_func );
  } else {
    return bwdfn227( state, next_func );
  }
}

static int bwdfn270( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn268;
    return 18;
  } else {
    return bwdfn268( state, next_func );
  }
}

static int bwdfn267( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 1 ) {
    return bwdfn270( state, next_func );
  } else {
    return bwdfn268( state, next_func );
  }
}

static int bwdfn259( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return bwdfn260( state, next_func );
  case 1:
    return bwdfn263( state, next_func );
  case 2:
    return bwdfn227( state, next_func );
  default:
    return bwdfn267( state, next_func );
  }
}

static int bwdfn271( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn259;
    return 20;
  } else {
    return bwdfn259( state, next_func );
  }
}

static int bwdfn272( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn259;
    return 30;
  } else {
    return bwdfn259( state, next_func );
  }
}

static int bwdfn258( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return bwdfn259( state, next_func );
  case 1:
    return bwdfn271( state, next_func );
  case 2:
    return bwdfn259( state, next_func );
  default:
    return bwdfn272( state, next_func );
  }
}

static int bwdfn276( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn259;
    return 27;
  } else {
    return bwdfn259( state, next_func );
  }
}

static int bwdfn275( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    return bwdfn276( state, next_func );
  } else {
    return bwdfn259( state, next_func );
  }
}

static int bwdfn274( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn275;
    return 24;
  } else {
    return bwdfn275( state, next_func );
  }
}

static int bwdfn273( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn274( state, next_func );
  } else {
    return bwdfn275( state, next_func );
  }
}

static int bwdfn278( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn259;
    return 34;
  } else {
    return bwdfn259( state, next_func );
  }
}

static int bwdfn277( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn278( state, next_func );
  } else {
    return bwdfn259( state, next_func );
  }
}

static int bwdfn257( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return bwdfn258( state, next_func );
  case 1:
    return bwdfn273( state, next_func );
  case 2:
    return bwdfn259( state, next_func );
  default:
    return bwdfn277( state, next_func );
  }
}

static int bwdfn279( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn257;
    return 19;
  } else {
    return bwdfn257( state, next_func );
  }
}

static int bwdfn280( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn257;
    return 29;
  } else {
    return bwdfn257( state, next_func );
  }
}

static int bwdfn256( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return bwdfn257( state, next_func );
  case 1:
    return bwdfn279( state, next_func );
  case 2:
    return bwdfn257( state, next_func );
  default:
    return bwdfn280( state, next_func );
  }
}

static int bwdfn284( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn257;
    return 26;
  } else {
    return bwdfn257( state, next_func );
  }
}

static int bwdfn283( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    return bwdfn284( state, next_func );
  } else {
    return bwdfn257( state, next_func );
  }
}

static int bwdfn282( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn283;
    return 22;
  } else {
    return bwdfn283( state, next_func );
  }
}

static int bwdfn281( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    return bwdfn282( state, next_func );
  } else {
    return bwdfn283( state, next_func );
  }
}

static int bwdfn286( const state_t *state, void *next_func )
{
  if( state->vars[ 36 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn257;
    return 32;
  } else {
    return bwdfn257( state, next_func );
  }
}

static int bwdfn285( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    return bwdfn286( state, next_func );
  } else {
    return bwdfn257( state, next_func );
  }
}

static int bwdfn255( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn256( state, next_func );
  case 1:
    return bwdfn281( state, next_func );
  case 2:
    return bwdfn257( state, next_func );
  default:
    return bwdfn285( state, next_func );
  }
}

static int bwdfn288( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn255;
    return 23;
  } else {
    return bwdfn255( state, next_func );
  }
}

static int bwdfn287( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    return bwdfn288( state, next_func );
  } else {
    return bwdfn255( state, next_func );
  }
}

static int bwdfn290( const state_t *state, void *next_func )
{
  if( state->vars[ 37 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn255;
    return 33;
  } else {
    return bwdfn255( state, next_func );
  }
}

static int bwdfn289( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    return bwdfn290( state, next_func );
  } else {
    return bwdfn255( state, next_func );
  }
}

static int bwdfn254( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return bwdfn255( state, next_func );
  case 1:
    return bwdfn287( state, next_func );
  case 2:
    return bwdfn255( state, next_func );
  default:
    return bwdfn289( state, next_func );
  }
}

static int bwdfn298( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn254;
    return 10;
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn301( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn254;
    return 16;
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn300( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 1 ) {
    return bwdfn301( state, next_func );
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn299( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn300;
    return 2;
  } else {
    return bwdfn300( state, next_func );
  }
}

static int bwdfn297( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn254( state, next_func );
  case 1:
    return bwdfn298( state, next_func );
  case 2:
    return bwdfn254( state, next_func );
  default:
    return bwdfn299( state, next_func );
  }
}

static int bwdfn306( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn254;
    return 16;
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn305( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    return bwdfn306( state, next_func );
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn304( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 1 ) {
    return bwdfn305( state, next_func );
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn303( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn304;
    return 11;
  } else {
    return bwdfn304( state, next_func );
  }
}

static int bwdfn302( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    return bwdfn303( state, next_func );
  } else {
    return bwdfn304( state, next_func );
  }
}

static int bwdfn308( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn304;
    return 3;
  } else {
    return bwdfn304( state, next_func );
  }
}

static int bwdfn307( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    return bwdfn308( state, next_func );
  } else {
    return bwdfn304( state, next_func );
  }
}

static int bwdfn296( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return bwdfn297( state, next_func );
  case 1:
    return bwdfn302( state, next_func );
  case 2:
    return bwdfn304( state, next_func );
  default:
    return bwdfn307( state, next_func );
  }
}

static int bwdfn309( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn296;
    return 9;
  } else {
    return bwdfn296( state, next_func );
  }
}

static int bwdfn310( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn296;
    return 1;
  } else {
    return bwdfn296( state, next_func );
  }
}

static int bwdfn295( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return bwdfn296( state, next_func );
  case 1:
    return bwdfn309( state, next_func );
  case 2:
    return bwdfn296( state, next_func );
  default:
    return bwdfn310( state, next_func );
  }
}

static int bwdfn314( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn254;
    return 11;
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn315( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn254;
    return 3;
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn313( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return bwdfn254( state, next_func );
  case 1:
    return bwdfn314( state, next_func );
  case 2:
    return bwdfn254( state, next_func );
  default:
    return bwdfn315( state, next_func );
  }
}

static int bwdfn317( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn313;
    return 16;
  } else {
    return bwdfn313( state, next_func );
  }
}

static int bwdfn316( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    return bwdfn317( state, next_func );
  } else {
    return bwdfn313( state, next_func );
  }
}

static int bwdfn318( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn313;
    return 0;
  } else {
    return bwdfn313( state, next_func );
  }
}

static int bwdfn312( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return bwdfn313( state, next_func );
  case 1:
    return bwdfn316( state, next_func );
  case 2:
    return bwdfn313( state, next_func );
  default:
    return bwdfn318( state, next_func );
  }
}

static int bwdfn321( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn254;
    return 2;
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn320( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    return bwdfn321( state, next_func );
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn323( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn301;
    return 2;
  } else {
    return bwdfn301( state, next_func );
  }
}

static int bwdfn322( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    return bwdfn323( state, next_func );
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn324( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn320;
    return 0;
  } else {
    return bwdfn320( state, next_func );
  }
}

static int bwdfn319( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return bwdfn320( state, next_func );
  case 1:
    return bwdfn322( state, next_func );
  case 2:
    return bwdfn320( state, next_func );
  default:
    return bwdfn324( state, next_func );
  }
}

static int bwdfn326( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn254;
    return 0;
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn325( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return bwdfn254( state, next_func );
  case 1:
    return bwdfn305( state, next_func );
  case 2:
    return bwdfn254( state, next_func );
  default:
    return bwdfn326( state, next_func );
  }
}

static int bwdfn330( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn254;
    return 10;
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn329( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 1 ) {
    return bwdfn330( state, next_func );
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn331( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn254( state, next_func );
  case 1:
    return bwdfn330( state, next_func );
  case 2:
    return bwdfn254( state, next_func );
  default:
    return bwdfn301( state, next_func );
  }
}

static int bwdfn332( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn329;
    return 0;
  } else {
    return bwdfn329( state, next_func );
  }
}

static int bwdfn328( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return bwdfn329( state, next_func );
  case 1:
    return bwdfn331( state, next_func );
  case 2:
    return bwdfn329( state, next_func );
  default:
    return bwdfn332( state, next_func );
  }
}

static int bwdfn327( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn328;
    return 17;
  } else {
    return bwdfn328( state, next_func );
  }
}

static int bwdfn311( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return bwdfn312( state, next_func );
  case 1:
    return bwdfn319( state, next_func );
  case 2:
    return bwdfn325( state, next_func );
  default:
    return bwdfn327( state, next_func );
  }
}

static int bwdfn336( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn254;
    return 2;
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn335( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn254( state, next_func );
  case 1:
    return bwdfn298( state, next_func );
  case 2:
    return bwdfn254( state, next_func );
  default:
    return bwdfn336( state, next_func );
  }
}

static int bwdfn337( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    return bwdfn314( state, next_func );
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn338( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    return bwdfn315( state, next_func );
  } else {
    return bwdfn254( state, next_func );
  }
}

static int bwdfn334( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return bwdfn335( state, next_func );
  case 1:
    return bwdfn337( state, next_func );
  case 2:
    return bwdfn254( state, next_func );
  default:
    return bwdfn338( state, next_func );
  }
}

static int bwdfn341( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return bwdfn254( state, next_func );
  case 1:
    return bwdfn337( state, next_func );
  case 2:
    return bwdfn254( state, next_func );
  default:
    return bwdfn338( state, next_func );
  }
}

static int bwdfn342( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return bwdfn298( state, next_func );
  case 1:
    return bwdfn337( state, next_func );
  case 2:
    return bwdfn254( state, next_func );
  default:
    return bwdfn338( state, next_func );
  }
}

static int bwdfn344( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return bwdfn336( state, next_func );
  case 1:
    return bwdfn337( state, next_func );
  case 2:
    return bwdfn254( state, next_func );
  default:
    return bwdfn338( state, next_func );
  }
}

static int bwdfn343( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn344;
    return 16;
  } else {
    return bwdfn344( state, next_func );
  }
}

static int bwdfn340( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return bwdfn341( state, next_func );
  case 1:
    return bwdfn342( state, next_func );
  case 2:
    return bwdfn341( state, next_func );
  default:
    return bwdfn343( state, next_func );
  }
}

static int bwdfn339( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = bwdfn340;
    return 8;
  } else {
    return bwdfn340( state, next_func );
  }
}

static int bwdfn333( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 1 ) {
    return bwdfn339( state, next_func );
  } else {
    return bwdfn334( state, next_func );
  }
}

static int bwdfn294( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    return bwdfn295( state, next_func );
  case 1:
    return bwdfn311( state, next_func );
  case 2:
    return bwdfn296( state, next_func );
  default:
    return bwdfn333( state, next_func );
  }
}

static int bwdfn345( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn294;
    return 12;
  } else {
    return bwdfn294( state, next_func );
  }
}

static int bwdfn346( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn294;
    return 4;
  } else {
    return bwdfn294( state, next_func );
  }
}

static int bwdfn293( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return bwdfn294( state, next_func );
  case 1:
    return bwdfn345( state, next_func );
  case 2:
    return bwdfn294( state, next_func );
  default:
    return bwdfn346( state, next_func );
  }
}

static int bwdfn348( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn294;
    return 13;
  } else {
    return bwdfn294( state, next_func );
  }
}

static int bwdfn347( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn348( state, next_func );
  } else {
    return bwdfn294( state, next_func );
  }
}

static int bwdfn350( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn294;
    return 5;
  } else {
    return bwdfn294( state, next_func );
  }
}

static int bwdfn349( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    return bwdfn350( state, next_func );
  } else {
    return bwdfn294( state, next_func );
  }
}

static int bwdfn292( const state_t *state, void *next_func )
{
  switch( state->vars[ 30 ] ) {
  case 0:
    return bwdfn293( state, next_func );
  case 1:
    return bwdfn347( state, next_func );
  case 2:
    return bwdfn294( state, next_func );
  default:
    return bwdfn349( state, next_func );
  }
}

static int bwdfn351( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn292;
    return 14;
  } else {
    return bwdfn292( state, next_func );
  }
}

static int bwdfn352( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn292;
    return 6;
  } else {
    return bwdfn292( state, next_func );
  }
}

static int bwdfn291( const state_t *state, void *next_func )
{
  switch( state->vars[ 36 ] ) {
  case 0:
    return bwdfn292( state, next_func );
  case 1:
    return bwdfn351( state, next_func );
  case 2:
    return bwdfn292( state, next_func );
  default:
    return bwdfn352( state, next_func );
  }
}

static int bwdfn354( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 3 ) {
    *((funcptr *)next_func) = bwdfn292;
    return 15;
  } else {
    return bwdfn292( state, next_func );
  }
}

static int bwdfn353( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 0 ) {
    return bwdfn354( state, next_func );
  } else {
    return bwdfn292( state, next_func );
  }
}

static int bwdfn356( const state_t *state, void *next_func )
{
  if( state->vars[ 39 ] == 1 ) {
    *((funcptr *)next_func) = bwdfn292;
    return 7;
  } else {
    return bwdfn292( state, next_func );
  }
}

static int bwdfn355( const state_t *state, void *next_func )
{
  if( state->vars[ 38 ] == 0 ) {
    return bwdfn356( state, next_func );
  } else {
    return bwdfn292( state, next_func );
  }
}

static int bwdfn0( const state_t *state, void *next_func )
{
  switch( state->vars[ 37 ] ) {
  case 0:
    return bwdfn291( state, next_func );
  case 1:
    return bwdfn353( state, next_func );
  case 2:
    return bwdfn292( state, next_func );
  default:
    return bwdfn355( state, next_func );
  }
}


#define init_history 0

#define max_fwd_children 43

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


static const int bw_max_children = 43;
#define max_bwd_children 43

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
  if( state->vars[ 24 ] == 1 && state->vars[ 30 ] == 1 && state->vars[ 31 ] == 1 ) {
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
    state->vars[ 9 ] = 0;
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
    state->vars[ 22 ] = 0;
    state->vars[ 23 ] = 0;
    state->vars[ 24 ] = 1;
    state->vars[ 25 ] = 0;
    state->vars[ 26 ] = 0;
    state->vars[ 27 ] = 0;
    state->vars[ 28 ] = 0;
    state->vars[ 29 ] = 0;
    state->vars[ 30 ] = 1;
    state->vars[ 31 ] = 1;
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
    if( state->vars[ 9 ] < 3 ) {
      ++state->vars[ 9 ];
      return 1;
    }
    state->vars[ 9 ] = 0;
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
    if( state->vars[ 22 ] < 3 ) {
      ++state->vars[ 22 ];
      return 1;
    }
    state->vars[ 22 ] = 0;
    if( state->vars[ 23 ] < 3 ) {
      ++state->vars[ 23 ];
      return 1;
    }
    state->vars[ 23 ] = 0;
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




