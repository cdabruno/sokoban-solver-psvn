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



/* number of variables in a state */
#define NUMVARS 36


typedef int8_t var_t;
#define PRI_VAR PRId8
#define SCN_VAR SCNd8

#define NUMDOMAINS 1
static var_t domain_sizes[ NUMDOMAINS ] = { 4 };
static int var_domains[ NUMVARS ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const char *domain_0[ 4 ] = {"P", "R", "W", "N" };
static const char **var_domain_names[ NUMVARS ] = { domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0, domain_0 };

typedef struct {
 var_t vars[ NUMVARS ];
} state_t;

typedef int (*funcptr)( const state_t *, void * );
typedef void (*actfuncptr)( const state_t *, state_t * );

typedef struct {
 const state_t *my_state;
 funcptr my_funcptr;
} ruleid_iterator_t;

#define num_fwd_rules 216
static const char *fwd_rule_name[ 216 ] = { "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKRIGHT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKLEFT", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKUP", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "ROCKDOWN", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVERIGHT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVELEFT", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEUP", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN", "MOVEDOWN" };
#define get_fwd_rule_label( ruleid ) (fwd_rule_name[(ruleid)]) 
#define cost_of_cheapest_fwd_rule 1
#define cost_of_costliest_fwd_rule 1
#define get_fwd_rule_cost( ruleid ) 1

static void fwdrule1( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = 3;
  child_state->vars[ 1 ] = 0;
  child_state->vars[ 2 ] = 1;
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
}

static void fwdrule2( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = 3;
  child_state->vars[ 2 ] = 0;
  child_state->vars[ 3 ] = 1;
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
}

static void fwdrule3( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = 3;
  child_state->vars[ 3 ] = 0;
  child_state->vars[ 4 ] = 1;
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
}

static void fwdrule4( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = 3;
  child_state->vars[ 4 ] = 0;
  child_state->vars[ 5 ] = 1;
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
}

static void fwdrule5( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 3;
  child_state->vars[ 7 ] = 0;
  child_state->vars[ 8 ] = 1;
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
  child_state->vars[ 7 ] = 3;
  child_state->vars[ 8 ] = 0;
  child_state->vars[ 9 ] = 1;
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
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = 3;
  child_state->vars[ 13 ] = 0;
  child_state->vars[ 14 ] = 1;
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
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = 3;
  child_state->vars[ 14 ] = 0;
  child_state->vars[ 15 ] = 1;
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
  child_state->vars[ 14 ] = 3;
  child_state->vars[ 15 ] = 0;
  child_state->vars[ 16 ] = 1;
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
  child_state->vars[ 15 ] = 3;
  child_state->vars[ 16 ] = 0;
  child_state->vars[ 17 ] = 1;
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
  child_state->vars[ 18 ] = 3;
  child_state->vars[ 19 ] = 0;
  child_state->vars[ 20 ] = 1;
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
  child_state->vars[ 19 ] = 3;
  child_state->vars[ 20 ] = 0;
  child_state->vars[ 21 ] = 1;
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
  child_state->vars[ 20 ] = 3;
  child_state->vars[ 21 ] = 0;
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
  child_state->vars[ 21 ] = 3;
  child_state->vars[ 22 ] = 0;
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
  child_state->vars[ 26 ] = 1;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 26 ] = 0;
  child_state->vars[ 27 ] = 1;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = 3;
  child_state->vars[ 27 ] = 0;
  child_state->vars[ 28 ] = 1;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = 3;
  child_state->vars[ 28 ] = 0;
  child_state->vars[ 29 ] = 1;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 33 ] = 1;
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 33 ] = 0;
  child_state->vars[ 34 ] = 1;
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 33 ] = 3;
  child_state->vars[ 34 ] = 0;
  child_state->vars[ 35 ] = 1;
}

static void fwdrule25( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = 1;
  child_state->vars[ 1 ] = 0;
  child_state->vars[ 2 ] = 3;
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
}

static void fwdrule26( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = 1;
  child_state->vars[ 2 ] = 0;
  child_state->vars[ 3 ] = 3;
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
}

static void fwdrule27( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = 1;
  child_state->vars[ 3 ] = 0;
  child_state->vars[ 4 ] = 3;
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
}

static void fwdrule28( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = 1;
  child_state->vars[ 4 ] = 0;
  child_state->vars[ 5 ] = 3;
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
}

static void fwdrule29( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 1;
  child_state->vars[ 7 ] = 0;
  child_state->vars[ 8 ] = 3;
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
  child_state->vars[ 7 ] = 1;
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
  child_state->vars[ 12 ] = 1;
  child_state->vars[ 13 ] = 0;
  child_state->vars[ 14 ] = 3;
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
  child_state->vars[ 13 ] = 1;
  child_state->vars[ 14 ] = 0;
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
  child_state->vars[ 14 ] = 1;
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
  child_state->vars[ 15 ] = 1;
  child_state->vars[ 16 ] = 0;
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
  child_state->vars[ 18 ] = 1;
  child_state->vars[ 19 ] = 0;
  child_state->vars[ 20 ] = 3;
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
  child_state->vars[ 19 ] = 1;
  child_state->vars[ 20 ] = 0;
  child_state->vars[ 21 ] = 3;
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
  child_state->vars[ 20 ] = 1;
  child_state->vars[ 21 ] = 0;
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
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = 1;
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
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = 1;
  child_state->vars[ 25 ] = 0;
  child_state->vars[ 26 ] = 3;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = 1;
  child_state->vars[ 26 ] = 0;
  child_state->vars[ 27 ] = 3;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = 1;
  child_state->vars[ 27 ] = 0;
  child_state->vars[ 28 ] = 3;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 27 ] = 1;
  child_state->vars[ 28 ] = 0;
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 30 ] = 1;
  child_state->vars[ 31 ] = 0;
  child_state->vars[ 32 ] = 3;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 31 ] = 1;
  child_state->vars[ 32 ] = 0;
  child_state->vars[ 33 ] = 3;
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 32 ] = 1;
  child_state->vars[ 33 ] = 0;
  child_state->vars[ 34 ] = 3;
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 33 ] = 1;
  child_state->vars[ 34 ] = 0;
  child_state->vars[ 35 ] = 3;
}

static void fwdrule49( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = 1;
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 0;
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = 3;
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
}

static void fwdrule50( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = 1;
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = 0;
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = 3;
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
}

static void fwdrule51( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = 1;
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
  child_state->vars[ 14 ] = 3;
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
}

static void fwdrule52( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = 1;
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
}

static void fwdrule53( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = 1;
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
}

static void fwdrule54( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = 1;
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
}

static void fwdrule55( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 1;
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = 0;
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
  child_state->vars[ 7 ] = 1;
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = 0;
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = 3;
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
  child_state->vars[ 8 ] = 1;
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = 0;
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = 3;
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
  child_state->vars[ 9 ] = 1;
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
  child_state->vars[ 21 ] = 3;
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
  child_state->vars[ 10 ] = 1;
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
  child_state->vars[ 11 ] = 1;
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
  child_state->vars[ 12 ] = 1;
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
  child_state->vars[ 13 ] = 1;
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = 0;
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
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = 1;
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = 0;
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = 3;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 21 ] = 0;
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = 3;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 22 ] = 0;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = 3;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = 1;
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
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = 1;
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
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = 1;
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
  child_state->vars[ 31 ] = 3;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 20 ] = 1;
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = 0;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = 3;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 21 ] = 1;
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = 0;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = 3;
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 22 ] = 1;
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = 0;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = 3;
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 23 ] = 1;
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
  child_state->vars[ 35 ] = 3;
}

static void fwdrule73( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = 3;
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 0;
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = 1;
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
}

static void fwdrule74( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = 3;
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = 0;
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = 1;
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
}

static void fwdrule75( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = 3;
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
  child_state->vars[ 14 ] = 1;
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
}

static void fwdrule76( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = 3;
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
  child_state->vars[ 15 ] = 1;
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
}

static void fwdrule77( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = 3;
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
  child_state->vars[ 16 ] = 1;
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
}

static void fwdrule78( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = 3;
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
  child_state->vars[ 17 ] = 1;
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
}

static void fwdrule79( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 3;
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = 0;
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
  child_state->vars[ 7 ] = 3;
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = 0;
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = 1;
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
  child_state->vars[ 8 ] = 3;
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = state->vars[ 13 ];
  child_state->vars[ 14 ] = 0;
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = 1;
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
  child_state->vars[ 9 ] = 3;
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
  child_state->vars[ 21 ] = 1;
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
  child_state->vars[ 10 ] = 3;
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
  child_state->vars[ 11 ] = 3;
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
  child_state->vars[ 12 ] = 3;
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
  child_state->vars[ 13 ] = 3;
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = 0;
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
  child_state->vars[ 14 ] = 3;
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = 0;
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = 1;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 15 ] = 3;
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = state->vars[ 20 ];
  child_state->vars[ 21 ] = 0;
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = 1;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 16 ] = 3;
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
  child_state->vars[ 28 ] = 1;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
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
  child_state->vars[ 17 ] = 3;
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
  child_state->vars[ 29 ] = 1;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule91( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 24 ] = 0;
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
}

static void fwdrule92( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 19 ] = 3;
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
  child_state->vars[ 31 ] = 1;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule93( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 20 ] = 3;
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = 0;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = 1;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule94( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 21 ] = 3;
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = 0;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = 1;
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule95( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 28 ] = 0;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = 1;
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule96( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = 1;
}

static void fwdrule97( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = 3;
  child_state->vars[ 1 ] = 0;
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
}

static void fwdrule98( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = 3;
  child_state->vars[ 2 ] = 0;
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
}

static void fwdrule99( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = 3;
  child_state->vars[ 3 ] = 0;
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
}

static void fwdrule100( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = 3;
  child_state->vars[ 4 ] = 0;
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
}

static void fwdrule101( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = 3;
  child_state->vars[ 5 ] = 0;
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
}

static void fwdrule102( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 3;
  child_state->vars[ 7 ] = 0;
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
}

static void fwdrule103( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = 3;
  child_state->vars[ 8 ] = 0;
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
}

static void fwdrule104( const state_t *state, state_t *child_state )
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
}

static void fwdrule105( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule106( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule107( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 12 ] = 3;
  child_state->vars[ 13 ] = 0;
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
}

static void fwdrule108( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 13 ] = 3;
  child_state->vars[ 14 ] = 0;
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
}

static void fwdrule109( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 14 ] = 3;
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
}

static void fwdrule110( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule111( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule112( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 19 ] = 0;
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
}

static void fwdrule113( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 19 ] = 3;
  child_state->vars[ 20 ] = 0;
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
}

static void fwdrule114( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 20 ] = 3;
  child_state->vars[ 21 ] = 0;
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
}

static void fwdrule115( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 21 ] = 3;
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
}

static void fwdrule116( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule117( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule118( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 26 ] = 0;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule119( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 26 ] = 3;
  child_state->vars[ 27 ] = 0;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule120( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 27 ] = 3;
  child_state->vars[ 28 ] = 0;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule121( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 28 ] = 3;
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule122( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule123( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule124( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 33 ] = 0;
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule125( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 33 ] = 3;
  child_state->vars[ 34 ] = 0;
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule126( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 34 ] = 3;
  child_state->vars[ 35 ] = 0;
}

static void fwdrule127( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = 0;
  child_state->vars[ 1 ] = 3;
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
}

static void fwdrule128( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = 0;
  child_state->vars[ 2 ] = 3;
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
}

static void fwdrule129( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = 0;
  child_state->vars[ 3 ] = 3;
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
}

static void fwdrule130( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = 0;
  child_state->vars[ 4 ] = 3;
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
}

static void fwdrule131( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = 0;
  child_state->vars[ 5 ] = 3;
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
}

static void fwdrule132( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 0;
  child_state->vars[ 7 ] = 3;
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
}

static void fwdrule133( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = 0;
  child_state->vars[ 8 ] = 3;
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
}

static void fwdrule134( const state_t *state, state_t *child_state )
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
}

static void fwdrule135( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule136( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule137( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 12 ] = 0;
  child_state->vars[ 13 ] = 3;
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
}

static void fwdrule138( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 13 ] = 0;
  child_state->vars[ 14 ] = 3;
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
}

static void fwdrule139( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 14 ] = 0;
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
}

static void fwdrule140( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule141( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule142( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 19 ] = 3;
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
}

static void fwdrule143( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 19 ] = 0;
  child_state->vars[ 20 ] = 3;
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
}

static void fwdrule144( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 20 ] = 0;
  child_state->vars[ 21 ] = 3;
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
}

static void fwdrule145( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 21 ] = 0;
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
}

static void fwdrule146( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule147( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule148( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 26 ] = 3;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule149( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 26 ] = 0;
  child_state->vars[ 27 ] = 3;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule150( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 27 ] = 0;
  child_state->vars[ 28 ] = 3;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule151( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 28 ] = 0;
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule152( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule153( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule154( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 33 ] = 3;
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule155( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 33 ] = 0;
  child_state->vars[ 34 ] = 3;
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule156( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 34 ] = 0;
  child_state->vars[ 35 ] = 3;
}

static void fwdrule157( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = 0;
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 3;
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
}

static void fwdrule158( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = 0;
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = 3;
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
}

static void fwdrule159( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = 0;
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
}

static void fwdrule160( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = 0;
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
}

static void fwdrule161( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = 0;
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
}

static void fwdrule162( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = 0;
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
}

static void fwdrule163( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 0;
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = 3;
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
}

static void fwdrule164( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = 0;
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = 3;
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
}

static void fwdrule165( const state_t *state, state_t *child_state )
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
  child_state->vars[ 14 ] = 3;
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
}

static void fwdrule166( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule167( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule168( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule169( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 12 ] = 0;
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
}

static void fwdrule170( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 13 ] = 0;
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = 3;
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
}

static void fwdrule171( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 14 ] = 0;
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = 3;
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
}

static void fwdrule172( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 21 ] = 3;
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
}

static void fwdrule173( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule174( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule175( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule176( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 19 ] = 0;
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
}

static void fwdrule177( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 20 ] = 0;
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = 3;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule178( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 21 ] = 0;
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = 3;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule179( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 28 ] = 3;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule180( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 29 ] = 3;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule181( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 30 ] = 3;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule182( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 31 ] = 3;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule183( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 26 ] = 0;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = 3;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule184( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 27 ] = 0;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = 3;
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule185( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 28 ] = 0;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = 3;
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule186( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 35 ] = 3;
}

static void fwdrule187( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = 3;
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 0;
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
}

static void fwdrule188( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = 3;
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = 0;
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
}

static void fwdrule189( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = 3;
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
}

static void fwdrule190( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = 3;
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
}

static void fwdrule191( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = 3;
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
}

static void fwdrule192( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = 3;
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
}

static void fwdrule193( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = 3;
  child_state->vars[ 7 ] = state->vars[ 7 ];
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = 0;
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
}

static void fwdrule194( const state_t *state, state_t *child_state )
{
  child_state->vars[ 0 ] = state->vars[ 0 ];
  child_state->vars[ 1 ] = state->vars[ 1 ];
  child_state->vars[ 2 ] = state->vars[ 2 ];
  child_state->vars[ 3 ] = state->vars[ 3 ];
  child_state->vars[ 4 ] = state->vars[ 4 ];
  child_state->vars[ 5 ] = state->vars[ 5 ];
  child_state->vars[ 6 ] = state->vars[ 6 ];
  child_state->vars[ 7 ] = 3;
  child_state->vars[ 8 ] = state->vars[ 8 ];
  child_state->vars[ 9 ] = state->vars[ 9 ];
  child_state->vars[ 10 ] = state->vars[ 10 ];
  child_state->vars[ 11 ] = state->vars[ 11 ];
  child_state->vars[ 12 ] = state->vars[ 12 ];
  child_state->vars[ 13 ] = 0;
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
}

static void fwdrule195( const state_t *state, state_t *child_state )
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
  child_state->vars[ 14 ] = 0;
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
}

static void fwdrule196( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule197( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule198( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule199( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 12 ] = 3;
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
}

static void fwdrule200( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 13 ] = 3;
  child_state->vars[ 14 ] = state->vars[ 14 ];
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = 0;
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
}

static void fwdrule201( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 14 ] = 3;
  child_state->vars[ 15 ] = state->vars[ 15 ];
  child_state->vars[ 16 ] = state->vars[ 16 ];
  child_state->vars[ 17 ] = state->vars[ 17 ];
  child_state->vars[ 18 ] = state->vars[ 18 ];
  child_state->vars[ 19 ] = state->vars[ 19 ];
  child_state->vars[ 20 ] = 0;
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
}

static void fwdrule202( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 21 ] = 0;
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
}

static void fwdrule203( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule204( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule205( const state_t *state, state_t *child_state )
{
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
}

static void fwdrule206( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 19 ] = 3;
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
}

static void fwdrule207( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 20 ] = 3;
  child_state->vars[ 21 ] = state->vars[ 21 ];
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = 0;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule208( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 21 ] = 3;
  child_state->vars[ 22 ] = state->vars[ 22 ];
  child_state->vars[ 23 ] = state->vars[ 23 ];
  child_state->vars[ 24 ] = state->vars[ 24 ];
  child_state->vars[ 25 ] = state->vars[ 25 ];
  child_state->vars[ 26 ] = state->vars[ 26 ];
  child_state->vars[ 27 ] = 0;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule209( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 28 ] = 0;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule210( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 29 ] = 0;
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule211( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 30 ] = 0;
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule212( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 31 ] = 0;
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule213( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 26 ] = 3;
  child_state->vars[ 27 ] = state->vars[ 27 ];
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = 0;
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule214( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 27 ] = 3;
  child_state->vars[ 28 ] = state->vars[ 28 ];
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = 0;
  child_state->vars[ 34 ] = state->vars[ 34 ];
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule215( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 28 ] = 3;
  child_state->vars[ 29 ] = state->vars[ 29 ];
  child_state->vars[ 30 ] = state->vars[ 30 ];
  child_state->vars[ 31 ] = state->vars[ 31 ];
  child_state->vars[ 32 ] = state->vars[ 32 ];
  child_state->vars[ 33 ] = state->vars[ 33 ];
  child_state->vars[ 34 ] = 0;
  child_state->vars[ 35 ] = state->vars[ 35 ];
}

static void fwdrule216( const state_t *state, state_t *child_state )
{
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
  child_state->vars[ 35 ] = 0;
}

static actfuncptr fwd_rules[ 216 ] = { fwdrule1, fwdrule2, fwdrule3, fwdrule4, fwdrule5, fwdrule6, fwdrule7, fwdrule8, fwdrule9, fwdrule10, fwdrule11, fwdrule12, fwdrule13, fwdrule14, fwdrule15, fwdrule16, fwdrule17, fwdrule18, fwdrule19, fwdrule20, fwdrule21, fwdrule22, fwdrule23, fwdrule24, fwdrule25, fwdrule26, fwdrule27, fwdrule28, fwdrule29, fwdrule30, fwdrule31, fwdrule32, fwdrule33, fwdrule34, fwdrule35, fwdrule36, fwdrule37, fwdrule38, fwdrule39, fwdrule40, fwdrule41, fwdrule42, fwdrule43, fwdrule44, fwdrule45, fwdrule46, fwdrule47, fwdrule48, fwdrule49, fwdrule50, fwdrule51, fwdrule52, fwdrule53, fwdrule54, fwdrule55, fwdrule56, fwdrule57, fwdrule58, fwdrule59, fwdrule60, fwdrule61, fwdrule62, fwdrule63, fwdrule64, fwdrule65, fwdrule66, fwdrule67, fwdrule68, fwdrule69, fwdrule70, fwdrule71, fwdrule72, fwdrule73, fwdrule74, fwdrule75, fwdrule76, fwdrule77, fwdrule78, fwdrule79, fwdrule80, fwdrule81, fwdrule82, fwdrule83, fwdrule84, fwdrule85, fwdrule86, fwdrule87, fwdrule88, fwdrule89, fwdrule90, fwdrule91, fwdrule92, fwdrule93, fwdrule94, fwdrule95, fwdrule96, fwdrule97, fwdrule98, fwdrule99, fwdrule100, fwdrule101, fwdrule102, fwdrule103, fwdrule104, fwdrule105, fwdrule106, fwdrule107, fwdrule108, fwdrule109, fwdrule110, fwdrule111, fwdrule112, fwdrule113, fwdrule114, fwdrule115, fwdrule116, fwdrule117, fwdrule118, fwdrule119, fwdrule120, fwdrule121, fwdrule122, fwdrule123, fwdrule124, fwdrule125, fwdrule126, fwdrule127, fwdrule128, fwdrule129, fwdrule130, fwdrule131, fwdrule132, fwdrule133, fwdrule134, fwdrule135, fwdrule136, fwdrule137, fwdrule138, fwdrule139, fwdrule140, fwdrule141, fwdrule142, fwdrule143, fwdrule144, fwdrule145, fwdrule146, fwdrule147, fwdrule148, fwdrule149, fwdrule150, fwdrule151, fwdrule152, fwdrule153, fwdrule154, fwdrule155, fwdrule156, fwdrule157, fwdrule158, fwdrule159, fwdrule160, fwdrule161, fwdrule162, fwdrule163, fwdrule164, fwdrule165, fwdrule166, fwdrule167, fwdrule168, fwdrule169, fwdrule170, fwdrule171, fwdrule172, fwdrule173, fwdrule174, fwdrule175, fwdrule176, fwdrule177, fwdrule178, fwdrule179, fwdrule180, fwdrule181, fwdrule182, fwdrule183, fwdrule184, fwdrule185, fwdrule186, fwdrule187, fwdrule188, fwdrule189, fwdrule190, fwdrule191, fwdrule192, fwdrule193, fwdrule194, fwdrule195, fwdrule196, fwdrule197, fwdrule198, fwdrule199, fwdrule200, fwdrule201, fwdrule202, fwdrule203, fwdrule204, fwdrule205, fwdrule206, fwdrule207, fwdrule208, fwdrule209, fwdrule210, fwdrule211, fwdrule212, fwdrule213, fwdrule214, fwdrule215, fwdrule216 };

static int fwdfn24( const state_t *state, void *next_func )
{
  if( state->vars[ 35 ] == 3 ) {
    *((funcptr *)next_func) = 0;
    return 215;
  } else {
    return -1;
  }
}

static int fwdfn23( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn24( state, next_func );
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    *((funcptr *)next_func) = 0;
    return 209;
  }
}

static int fwdfn25( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    return fwdfn24( state, next_func );
  } else {
    return -1;
  }
}

static int fwdfn22( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn23( state, next_func );
  case 1:
    return fwdfn25( state, next_func );
  case 2:
    return fwdfn25( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn25;
    return 203;
  }
}

static int fwdfn27( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = 0;
    return 209;
  } else {
    return -1;
  }
}

static int fwdfn26( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    return fwdfn24( state, next_func );
  case 1:
    return -1;
  case 2:
    return -1;
  default:
    return fwdfn27( state, next_func );
  }
}

static int fwdfn28( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn26;
    return 197;
  } else {
    return fwdfn26( state, next_func );
  }
}

static int fwdfn21( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return fwdfn22( state, next_func );
  case 1:
    return fwdfn26( state, next_func );
  case 2:
    return fwdfn26( state, next_func );
  default:
    return fwdfn28( state, next_func );
  }
}

static int fwdfn20( const state_t *state, void *next_func )
{
  if( state->vars[ 34 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn21;
    return 214;
  } else {
    return fwdfn21( state, next_func );
  }
}

static int fwdfn19( const state_t *state, void *next_func )
{
  switch( state->vars[ 28 ] ) {
  case 0:
    return fwdfn20( state, next_func );
  case 1:
    return fwdfn21( state, next_func );
  case 2:
    return fwdfn21( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn21;
    return 208;
  }
}

static int fwdfn29( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 0 ) {
    return fwdfn20( state, next_func );
  } else {
    return fwdfn21( state, next_func );
  }
}

static int fwdfn18( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn19( state, next_func );
  case 1:
    return fwdfn29( state, next_func );
  case 2:
    return fwdfn29( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn29;
    return 202;
  }
}

static int fwdfn31( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn21;
    return 208;
  } else {
    return fwdfn21( state, next_func );
  }
}

static int fwdfn30( const state_t *state, void *next_func )
{
  switch( state->vars[ 28 ] ) {
  case 0:
    return fwdfn20( state, next_func );
  case 1:
    return fwdfn21( state, next_func );
  case 2:
    return fwdfn21( state, next_func );
  default:
    return fwdfn31( state, next_func );
  }
}

static int fwdfn32( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn30;
    return 196;
  } else {
    return fwdfn30( state, next_func );
  }
}

static int fwdfn17( const state_t *state, void *next_func )
{
  switch( state->vars[ 16 ] ) {
  case 0:
    return fwdfn18( state, next_func );
  case 1:
    return fwdfn30( state, next_func );
  case 2:
    return fwdfn30( state, next_func );
  default:
    return fwdfn32( state, next_func );
  }
}

static int fwdfn16( const state_t *state, void *next_func )
{
  if( state->vars[ 33 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn17;
    return 213;
  } else {
    return fwdfn17( state, next_func );
  }
}

static int fwdfn15( const state_t *state, void *next_func )
{
  switch( state->vars[ 27 ] ) {
  case 0:
    return fwdfn16( state, next_func );
  case 1:
    return fwdfn17( state, next_func );
  case 2:
    return fwdfn17( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn17;
    return 207;
  }
}

static int fwdfn33( const state_t *state, void *next_func )
{
  if( state->vars[ 27 ] == 0 ) {
    return fwdfn16( state, next_func );
  } else {
    return fwdfn17( state, next_func );
  }
}

static int fwdfn14( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn15( state, next_func );
  case 1:
    return fwdfn33( state, next_func );
  case 2:
    return fwdfn33( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn33;
    return 201;
  }
}

static int fwdfn35( const state_t *state, void *next_func )
{
  if( state->vars[ 21 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn17;
    return 207;
  } else {
    return fwdfn17( state, next_func );
  }
}

static int fwdfn34( const state_t *state, void *next_func )
{
  switch( state->vars[ 27 ] ) {
  case 0:
    return fwdfn16( state, next_func );
  case 1:
    return fwdfn17( state, next_func );
  case 2:
    return fwdfn17( state, next_func );
  default:
    return fwdfn35( state, next_func );
  }
}

static int fwdfn36( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn34;
    return 195;
  } else {
    return fwdfn34( state, next_func );
  }
}

static int fwdfn13( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn14( state, next_func );
  case 1:
    return fwdfn34( state, next_func );
  case 2:
    return fwdfn34( state, next_func );
  default:
    return fwdfn36( state, next_func );
  }
}

static int fwdfn12( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn13;
    return 212;
  } else {
    return fwdfn13( state, next_func );
  }
}

static int fwdfn11( const state_t *state, void *next_func )
{
  switch( state->vars[ 26 ] ) {
  case 0:
    return fwdfn12( state, next_func );
  case 1:
    return fwdfn13( state, next_func );
  case 2:
    return fwdfn13( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn13;
    return 206;
  }
}

static int fwdfn37( const state_t *state, void *next_func )
{
  if( state->vars[ 26 ] == 0 ) {
    return fwdfn12( state, next_func );
  } else {
    return fwdfn13( state, next_func );
  }
}

static int fwdfn10( const state_t *state, void *next_func )
{
  switch( state->vars[ 20 ] ) {
  case 0:
    return fwdfn11( state, next_func );
  case 1:
    return fwdfn37( state, next_func );
  case 2:
    return fwdfn37( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn37;
    return 200;
  }
}

static int fwdfn39( const state_t *state, void *next_func )
{
  if( state->vars[ 20 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn13;
    return 206;
  } else {
    return fwdfn13( state, next_func );
  }
}

static int fwdfn38( const state_t *state, void *next_func )
{
  switch( state->vars[ 26 ] ) {
  case 0:
    return fwdfn12( state, next_func );
  case 1:
    return fwdfn13( state, next_func );
  case 2:
    return fwdfn13( state, next_func );
  default:
    return fwdfn39( state, next_func );
  }
}

static int fwdfn40( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn38;
    return 194;
  } else {
    return fwdfn38( state, next_func );
  }
}

static int fwdfn9( const state_t *state, void *next_func )
{
  switch( state->vars[ 14 ] ) {
  case 0:
    return fwdfn10( state, next_func );
  case 1:
    return fwdfn38( state, next_func );
  case 2:
    return fwdfn38( state, next_func );
  default:
    return fwdfn40( state, next_func );
  }
}

static int fwdfn8( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn9;
    return 211;
  } else {
    return fwdfn9( state, next_func );
  }
}

static int fwdfn7( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return fwdfn8( state, next_func );
  case 1:
    return fwdfn9( state, next_func );
  case 2:
    return fwdfn9( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn9;
    return 205;
  }
}

static int fwdfn41( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    return fwdfn8( state, next_func );
  } else {
    return fwdfn9( state, next_func );
  }
}

static int fwdfn6( const state_t *state, void *next_func )
{
  switch( state->vars[ 19 ] ) {
  case 0:
    return fwdfn7( state, next_func );
  case 1:
    return fwdfn41( state, next_func );
  case 2:
    return fwdfn41( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn41;
    return 199;
  }
}

static int fwdfn43( const state_t *state, void *next_func )
{
  if( state->vars[ 19 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn9;
    return 205;
  } else {
    return fwdfn9( state, next_func );
  }
}

static int fwdfn42( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return fwdfn8( state, next_func );
  case 1:
    return fwdfn9( state, next_func );
  case 2:
    return fwdfn9( state, next_func );
  default:
    return fwdfn43( state, next_func );
  }
}

static int fwdfn44( const state_t *state, void *next_func )
{
  if( state->vars[ 7 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn42;
    return 193;
  } else {
    return fwdfn42( state, next_func );
  }
}

static int fwdfn5( const state_t *state, void *next_func )
{
  switch( state->vars[ 13 ] ) {
  case 0:
    return fwdfn6( state, next_func );
  case 1:
    return fwdfn42( state, next_func );
  case 2:
    return fwdfn42( state, next_func );
  default:
    return fwdfn44( state, next_func );
  }
}

static int fwdfn4( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn5;
    return 210;
  } else {
    return fwdfn5( state, next_func );
  }
}

static int fwdfn3( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return fwdfn4( state, next_func );
  case 1:
    return fwdfn5( state, next_func );
  case 2:
    return fwdfn5( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn5;
    return 204;
  }
}

static int fwdfn45( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    return fwdfn4( state, next_func );
  } else {
    return fwdfn5( state, next_func );
  }
}

static int fwdfn2( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn3( state, next_func );
  case 1:
    return fwdfn45( state, next_func );
  case 2:
    return fwdfn45( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn45;
    return 198;
  }
}

static int fwdfn47( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn5;
    return 204;
  } else {
    return fwdfn5( state, next_func );
  }
}

static int fwdfn46( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    return fwdfn4( state, next_func );
  case 1:
    return fwdfn5( state, next_func );
  case 2:
    return fwdfn5( state, next_func );
  default:
    return fwdfn47( state, next_func );
  }
}

static int fwdfn48( const state_t *state, void *next_func )
{
  if( state->vars[ 6 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn46;
    return 192;
  } else {
    return fwdfn46( state, next_func );
  }
}

static int fwdfn1( const state_t *state, void *next_func )
{
  switch( state->vars[ 12 ] ) {
  case 0:
    return fwdfn2( state, next_func );
  case 1:
    return fwdfn46( state, next_func );
  case 2:
    return fwdfn46( state, next_func );
  default:
    return fwdfn48( state, next_func );
  }
}

static int fwdfn79( const state_t *state, void *next_func )
{
  if( state->vars[ 35 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn1;
    return 185;
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn78( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    return fwdfn79( state, next_func );
  } else {
    return fwdfn1( state, next_func );
  }
}

static int fwdfn77( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn78;
    return 173;
  } else {
    return fwdfn78( state, next_func );
  }
}

static int fwdfn80( const state_t *state, void *next_func )
{
  switch( state->vars[ 29 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn1;
    return 179;
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
  switch( state->vars[ 23 ] ) {
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

static int fwdfn81( const state_t *state, void *next_func )
{
  if( state->vars[ 34 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn76;
    return 184;
  } else {
    return fwdfn76( state, next_func );
  }
}

static int fwdfn75( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 3 ) {
    return fwdfn81( state, next_func );
  } else {
    return fwdfn76( state, next_func );
  }
}

static int fwdfn74( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn75;
    return 172;
  } else {
    return fwdfn75( state, next_func );
  }
}

static int fwdfn82( const state_t *state, void *next_func )
{
  switch( state->vars[ 28 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn76;
    return 178;
  case 1:
    return fwdfn76( state, next_func );
  case 2:
    return fwdfn76( state, next_func );
  default:
    return fwdfn81( state, next_func );
  }
}

static int fwdfn73( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn74( state, next_func );
  case 1:
    return fwdfn75( state, next_func );
  case 2:
    return fwdfn75( state, next_func );
  default:
    return fwdfn82( state, next_func );
  }
}

static int fwdfn83( const state_t *state, void *next_func )
{
  if( state->vars[ 33 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn73;
    return 183;
  } else {
    return fwdfn73( state, next_func );
  }
}

static int fwdfn72( const state_t *state, void *next_func )
{
  if( state->vars[ 27 ] == 3 ) {
    return fwdfn83( state, next_func );
  } else {
    return fwdfn73( state, next_func );
  }
}

static int fwdfn71( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn72;
    return 171;
  } else {
    return fwdfn72( state, next_func );
  }
}

static int fwdfn84( const state_t *state, void *next_func )
{
  switch( state->vars[ 27 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn73;
    return 177;
  case 1:
    return fwdfn73( state, next_func );
  case 2:
    return fwdfn73( state, next_func );
  default:
    return fwdfn83( state, next_func );
  }
}

static int fwdfn70( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn71( state, next_func );
  case 1:
    return fwdfn72( state, next_func );
  case 2:
    return fwdfn72( state, next_func );
  default:
    return fwdfn84( state, next_func );
  }
}

static int fwdfn85( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn70;
    return 182;
  } else {
    return fwdfn70( state, next_func );
  }
}

static int fwdfn69( const state_t *state, void *next_func )
{
  if( state->vars[ 26 ] == 3 ) {
    return fwdfn85( state, next_func );
  } else {
    return fwdfn70( state, next_func );
  }
}

static int fwdfn68( const state_t *state, void *next_func )
{
  if( state->vars[ 14 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn69;
    return 170;
  } else {
    return fwdfn69( state, next_func );
  }
}

static int fwdfn86( const state_t *state, void *next_func )
{
  switch( state->vars[ 26 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn70;
    return 176;
  case 1:
    return fwdfn70( state, next_func );
  case 2:
    return fwdfn70( state, next_func );
  default:
    return fwdfn85( state, next_func );
  }
}

static int fwdfn67( const state_t *state, void *next_func )
{
  switch( state->vars[ 20 ] ) {
  case 0:
    return fwdfn68( state, next_func );
  case 1:
    return fwdfn69( state, next_func );
  case 2:
    return fwdfn69( state, next_func );
  default:
    return fwdfn86( state, next_func );
  }
}

static int fwdfn87( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn67;
    return 181;
  } else {
    return fwdfn67( state, next_func );
  }
}

static int fwdfn66( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    return fwdfn87( state, next_func );
  } else {
    return fwdfn67( state, next_func );
  }
}

static int fwdfn65( const state_t *state, void *next_func )
{
  if( state->vars[ 13 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn66;
    return 169;
  } else {
    return fwdfn66( state, next_func );
  }
}

static int fwdfn88( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn67;
    return 175;
  case 1:
    return fwdfn67( state, next_func );
  case 2:
    return fwdfn67( state, next_func );
  default:
    return fwdfn87( state, next_func );
  }
}

static int fwdfn64( const state_t *state, void *next_func )
{
  switch( state->vars[ 19 ] ) {
  case 0:
    return fwdfn65( state, next_func );
  case 1:
    return fwdfn66( state, next_func );
  case 2:
    return fwdfn66( state, next_func );
  default:
    return fwdfn88( state, next_func );
  }
}

static int fwdfn89( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn64;
    return 180;
  } else {
    return fwdfn64( state, next_func );
  }
}

static int fwdfn63( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 3 ) {
    return fwdfn89( state, next_func );
  } else {
    return fwdfn64( state, next_func );
  }
}

static int fwdfn62( const state_t *state, void *next_func )
{
  if( state->vars[ 12 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn63;
    return 168;
  } else {
    return fwdfn63( state, next_func );
  }
}

static int fwdfn90( const state_t *state, void *next_func )
{
  switch( state->vars[ 24 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn64;
    return 174;
  case 1:
    return fwdfn64( state, next_func );
  case 2:
    return fwdfn64( state, next_func );
  default:
    return fwdfn89( state, next_func );
  }
}

static int fwdfn61( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn62( state, next_func );
  case 1:
    return fwdfn63( state, next_func );
  case 2:
    return fwdfn63( state, next_func );
  default:
    return fwdfn90( state, next_func );
  }
}

static int fwdfn60( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn61;
    return 191;
  } else {
    return fwdfn61( state, next_func );
  }
}

static int fwdfn59( const state_t *state, void *next_func )
{
  if( state->vars[ 5 ] == 0 ) {
    return fwdfn60( state, next_func );
  } else {
    return fwdfn61( state, next_func );
  }
}

static int fwdfn58( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn59;
    return 190;
  } else {
    return fwdfn59( state, next_func );
  }
}

static int fwdfn57( const state_t *state, void *next_func )
{
  if( state->vars[ 4 ] == 0 ) {
    return fwdfn58( state, next_func );
  } else {
    return fwdfn59( state, next_func );
  }
}

static int fwdfn56( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn57;
    return 189;
  } else {
    return fwdfn57( state, next_func );
  }
}

static int fwdfn55( const state_t *state, void *next_func )
{
  if( state->vars[ 3 ] == 0 ) {
    return fwdfn56( state, next_func );
  } else {
    return fwdfn57( state, next_func );
  }
}

static int fwdfn54( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn55;
    return 188;
  } else {
    return fwdfn55( state, next_func );
  }
}

static int fwdfn53( const state_t *state, void *next_func )
{
  if( state->vars[ 2 ] == 0 ) {
    return fwdfn54( state, next_func );
  } else {
    return fwdfn55( state, next_func );
  }
}

static int fwdfn52( const state_t *state, void *next_func )
{
  if( state->vars[ 7 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn53;
    return 187;
  } else {
    return fwdfn53( state, next_func );
  }
}

static int fwdfn51( const state_t *state, void *next_func )
{
  if( state->vars[ 1 ] == 0 ) {
    return fwdfn52( state, next_func );
  } else {
    return fwdfn53( state, next_func );
  }
}

static int fwdfn50( const state_t *state, void *next_func )
{
  if( state->vars[ 6 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn51;
    return 186;
  } else {
    return fwdfn51( state, next_func );
  }
}

static int fwdfn49( const state_t *state, void *next_func )
{
  if( state->vars[ 0 ] == 0 ) {
    return fwdfn50( state, next_func );
  } else {
    return fwdfn51( state, next_func );
  }
}

static int fwdfn115( const state_t *state, void *next_func )
{
  if( state->vars[ 35 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn49;
    return 155;
  } else {
    return fwdfn49( state, next_func );
  }
}

static int fwdfn114( const state_t *state, void *next_func )
{
  if( state->vars[ 34 ] == 3 ) {
    return fwdfn115( state, next_func );
  } else {
    return fwdfn49( state, next_func );
  }
}

static int fwdfn113( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn114;
    return 153;
  } else {
    return fwdfn114( state, next_func );
  }
}

static int fwdfn116( const state_t *state, void *next_func )
{
  switch( state->vars[ 34 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn49;
    return 154;
  case 1:
    return fwdfn49( state, next_func );
  case 2:
    return fwdfn49( state, next_func );
  default:
    return fwdfn115( state, next_func );
  }
}

static int fwdfn112( const state_t *state, void *next_func )
{
  switch( state->vars[ 33 ] ) {
  case 0:
    return fwdfn113( state, next_func );
  case 1:
    return fwdfn114( state, next_func );
  case 2:
    return fwdfn114( state, next_func );
  default:
    return fwdfn116( state, next_func );
  }
}

static int fwdfn111( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn112;
    return 151;
  } else {
    return fwdfn112( state, next_func );
  }
}

static int fwdfn119( const state_t *state, void *next_func )
{
  if( state->vars[ 33 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn49;
    return 154;
  } else {
    return fwdfn49( state, next_func );
  }
}

static int fwdfn118( const state_t *state, void *next_func )
{
  switch( state->vars[ 34 ] ) {
  case 0:
    return fwdfn119( state, next_func );
  case 1:
    return fwdfn49( state, next_func );
  case 2:
    return fwdfn49( state, next_func );
  default:
    return fwdfn115( state, next_func );
  }
}

static int fwdfn120( const state_t *state, void *next_func )
{
  switch( state->vars[ 33 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn114;
    return 153;
  case 1:
    return fwdfn114( state, next_func );
  case 2:
    return fwdfn114( state, next_func );
  default:
    return fwdfn116( state, next_func );
  }
}

static int fwdfn117( const state_t *state, void *next_func )
{
  switch( state->vars[ 32 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn118;
    return 152;
  case 1:
    return fwdfn118( state, next_func );
  case 2:
    return fwdfn118( state, next_func );
  default:
    return fwdfn120( state, next_func );
  }
}

static int fwdfn110( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return fwdfn111( state, next_func );
  case 1:
    return fwdfn112( state, next_func );
  case 2:
    return fwdfn112( state, next_func );
  default:
    return fwdfn117( state, next_func );
  }
}

static int fwdfn121( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn110;
    return 150;
  } else {
    return fwdfn110( state, next_func );
  }
}

static int fwdfn109( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 3 ) {
    return fwdfn121( state, next_func );
  } else {
    return fwdfn110( state, next_func );
  }
}

static int fwdfn108( const state_t *state, void *next_func )
{
  if( state->vars[ 26 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn109;
    return 148;
  } else {
    return fwdfn109( state, next_func );
  }
}

static int fwdfn122( const state_t *state, void *next_func )
{
  switch( state->vars[ 28 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn110;
    return 149;
  case 1:
    return fwdfn110( state, next_func );
  case 2:
    return fwdfn110( state, next_func );
  default:
    return fwdfn121( state, next_func );
  }
}

static int fwdfn107( const state_t *state, void *next_func )
{
  switch( state->vars[ 27 ] ) {
  case 0:
    return fwdfn108( state, next_func );
  case 1:
    return fwdfn109( state, next_func );
  case 2:
    return fwdfn109( state, next_func );
  default:
    return fwdfn122( state, next_func );
  }
}

static int fwdfn106( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn107;
    return 146;
  } else {
    return fwdfn107( state, next_func );
  }
}

static int fwdfn125( const state_t *state, void *next_func )
{
  if( state->vars[ 27 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn110;
    return 149;
  } else {
    return fwdfn110( state, next_func );
  }
}

static int fwdfn124( const state_t *state, void *next_func )
{
  switch( state->vars[ 28 ] ) {
  case 0:
    return fwdfn125( state, next_func );
  case 1:
    return fwdfn110( state, next_func );
  case 2:
    return fwdfn110( state, next_func );
  default:
    return fwdfn121( state, next_func );
  }
}

static int fwdfn126( const state_t *state, void *next_func )
{
  switch( state->vars[ 27 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn109;
    return 148;
  case 1:
    return fwdfn109( state, next_func );
  case 2:
    return fwdfn109( state, next_func );
  default:
    return fwdfn122( state, next_func );
  }
}

static int fwdfn123( const state_t *state, void *next_func )
{
  switch( state->vars[ 26 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn124;
    return 147;
  case 1:
    return fwdfn124( state, next_func );
  case 2:
    return fwdfn124( state, next_func );
  default:
    return fwdfn126( state, next_func );
  }
}

static int fwdfn105( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return fwdfn106( state, next_func );
  case 1:
    return fwdfn107( state, next_func );
  case 2:
    return fwdfn107( state, next_func );
  default:
    return fwdfn123( state, next_func );
  }
}

static int fwdfn104( const state_t *state, void *next_func )
{
  if( state->vars[ 5 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn105;
    return 161;
  } else {
    return fwdfn105( state, next_func );
  }
}

static int fwdfn127( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn105;
    return 167;
  } else {
    return fwdfn105( state, next_func );
  }
}

static int fwdfn103( const state_t *state, void *next_func )
{
  switch( state->vars[ 11 ] ) {
  case 0:
    return fwdfn104( state, next_func );
  case 1:
    return fwdfn105( state, next_func );
  case 2:
    return fwdfn105( state, next_func );
  default:
    return fwdfn127( state, next_func );
  }
}

static int fwdfn102( const state_t *state, void *next_func )
{
  if( state->vars[ 4 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn103;
    return 160;
  } else {
    return fwdfn103( state, next_func );
  }
}

static int fwdfn128( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn103;
    return 166;
  } else {
    return fwdfn103( state, next_func );
  }
}

static int fwdfn101( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    return fwdfn102( state, next_func );
  case 1:
    return fwdfn103( state, next_func );
  case 2:
    return fwdfn103( state, next_func );
  default:
    return fwdfn128( state, next_func );
  }
}

static int fwdfn100( const state_t *state, void *next_func )
{
  if( state->vars[ 3 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn101;
    return 159;
  } else {
    return fwdfn101( state, next_func );
  }
}

static int fwdfn129( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn101;
    return 165;
  } else {
    return fwdfn101( state, next_func );
  }
}

static int fwdfn99( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return fwdfn100( state, next_func );
  case 1:
    return fwdfn101( state, next_func );
  case 2:
    return fwdfn101( state, next_func );
  default:
    return fwdfn129( state, next_func );
  }
}

static int fwdfn98( const state_t *state, void *next_func )
{
  if( state->vars[ 2 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn99;
    return 158;
  } else {
    return fwdfn99( state, next_func );
  }
}

static int fwdfn130( const state_t *state, void *next_func )
{
  if( state->vars[ 14 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn99;
    return 164;
  } else {
    return fwdfn99( state, next_func );
  }
}

static int fwdfn97( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return fwdfn98( state, next_func );
  case 1:
    return fwdfn99( state, next_func );
  case 2:
    return fwdfn99( state, next_func );
  default:
    return fwdfn130( state, next_func );
  }
}

static int fwdfn96( const state_t *state, void *next_func )
{
  if( state->vars[ 1 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn97;
    return 157;
  } else {
    return fwdfn97( state, next_func );
  }
}

static int fwdfn131( const state_t *state, void *next_func )
{
  if( state->vars[ 13 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn97;
    return 163;
  } else {
    return fwdfn97( state, next_func );
  }
}

static int fwdfn95( const state_t *state, void *next_func )
{
  switch( state->vars[ 7 ] ) {
  case 0:
    return fwdfn96( state, next_func );
  case 1:
    return fwdfn97( state, next_func );
  case 2:
    return fwdfn97( state, next_func );
  default:
    return fwdfn131( state, next_func );
  }
}

static int fwdfn94( const state_t *state, void *next_func )
{
  if( state->vars[ 0 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn95;
    return 156;
  } else {
    return fwdfn95( state, next_func );
  }
}

static int fwdfn132( const state_t *state, void *next_func )
{
  if( state->vars[ 12 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn95;
    return 162;
  } else {
    return fwdfn95( state, next_func );
  }
}

static int fwdfn93( const state_t *state, void *next_func )
{
  switch( state->vars[ 6 ] ) {
  case 0:
    return fwdfn94( state, next_func );
  case 1:
    return fwdfn95( state, next_func );
  case 2:
    return fwdfn95( state, next_func );
  default:
    return fwdfn132( state, next_func );
  }
}

static int fwdfn92( const state_t *state, void *next_func )
{
  if( state->vars[ 21 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn93;
    return 144;
  } else {
    return fwdfn93( state, next_func );
  }
}

static int fwdfn133( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn93;
    return 145;
  } else {
    return fwdfn93( state, next_func );
  }
}

static int fwdfn91( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn92( state, next_func );
  case 1:
    return fwdfn93( state, next_func );
  case 2:
    return fwdfn93( state, next_func );
  default:
    return fwdfn133( state, next_func );
  }
}

static int fwdfn159( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn91;
    return 140;
  } else {
    return fwdfn91( state, next_func );
  }
}

static int fwdfn158( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    return fwdfn159( state, next_func );
  } else {
    return fwdfn91( state, next_func );
  }
}

static int fwdfn157( const state_t *state, void *next_func )
{
  if( state->vars[ 14 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn158;
    return 138;
  } else {
    return fwdfn158( state, next_func );
  }
}

static int fwdfn160( const state_t *state, void *next_func )
{
  switch( state->vars[ 16 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn91;
    return 139;
  case 1:
    return fwdfn91( state, next_func );
  case 2:
    return fwdfn91( state, next_func );
  default:
    return fwdfn159( state, next_func );
  }
}

static int fwdfn156( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn157( state, next_func );
  case 1:
    return fwdfn158( state, next_func );
  case 2:
    return fwdfn158( state, next_func );
  default:
    return fwdfn160( state, next_func );
  }
}

static int fwdfn155( const state_t *state, void *next_func )
{
  if( state->vars[ 12 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn156;
    return 136;
  } else {
    return fwdfn156( state, next_func );
  }
}

static int fwdfn163( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn91;
    return 139;
  } else {
    return fwdfn91( state, next_func );
  }
}

static int fwdfn162( const state_t *state, void *next_func )
{
  switch( state->vars[ 16 ] ) {
  case 0:
    return fwdfn163( state, next_func );
  case 1:
    return fwdfn91( state, next_func );
  case 2:
    return fwdfn91( state, next_func );
  default:
    return fwdfn159( state, next_func );
  }
}

static int fwdfn164( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn158;
    return 138;
  case 1:
    return fwdfn158( state, next_func );
  case 2:
    return fwdfn158( state, next_func );
  default:
    return fwdfn160( state, next_func );
  }
}

static int fwdfn161( const state_t *state, void *next_func )
{
  switch( state->vars[ 14 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn162;
    return 137;
  case 1:
    return fwdfn162( state, next_func );
  case 2:
    return fwdfn162( state, next_func );
  default:
    return fwdfn164( state, next_func );
  }
}

static int fwdfn154( const state_t *state, void *next_func )
{
  switch( state->vars[ 13 ] ) {
  case 0:
    return fwdfn155( state, next_func );
  case 1:
    return fwdfn156( state, next_func );
  case 2:
    return fwdfn156( state, next_func );
  default:
    return fwdfn161( state, next_func );
  }
}

static int fwdfn165( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn154;
    return 135;
  } else {
    return fwdfn154( state, next_func );
  }
}

static int fwdfn153( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    return fwdfn165( state, next_func );
  } else {
    return fwdfn154( state, next_func );
  }
}

static int fwdfn152( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn153;
    return 133;
  } else {
    return fwdfn153( state, next_func );
  }
}

static int fwdfn166( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn154;
    return 134;
  case 1:
    return fwdfn154( state, next_func );
  case 2:
    return fwdfn154( state, next_func );
  default:
    return fwdfn165( state, next_func );
  }
}

static int fwdfn151( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return fwdfn152( state, next_func );
  case 1:
    return fwdfn153( state, next_func );
  case 2:
    return fwdfn153( state, next_func );
  default:
    return fwdfn166( state, next_func );
  }
}

static int fwdfn150( const state_t *state, void *next_func )
{
  if( state->vars[ 6 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn151;
    return 131;
  } else {
    return fwdfn151( state, next_func );
  }
}

static int fwdfn169( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn154;
    return 134;
  } else {
    return fwdfn154( state, next_func );
  }
}

static int fwdfn168( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    return fwdfn169( state, next_func );
  case 1:
    return fwdfn154( state, next_func );
  case 2:
    return fwdfn154( state, next_func );
  default:
    return fwdfn165( state, next_func );
  }
}

static int fwdfn170( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn153;
    return 133;
  case 1:
    return fwdfn153( state, next_func );
  case 2:
    return fwdfn153( state, next_func );
  default:
    return fwdfn166( state, next_func );
  }
}

static int fwdfn167( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn168;
    return 132;
  case 1:
    return fwdfn168( state, next_func );
  case 2:
    return fwdfn168( state, next_func );
  default:
    return fwdfn170( state, next_func );
  }
}

static int fwdfn149( const state_t *state, void *next_func )
{
  switch( state->vars[ 7 ] ) {
  case 0:
    return fwdfn150( state, next_func );
  case 1:
    return fwdfn151( state, next_func );
  case 2:
    return fwdfn151( state, next_func );
  default:
    return fwdfn167( state, next_func );
  }
}

static int fwdfn171( const state_t *state, void *next_func )
{
  if( state->vars[ 5 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn149;
    return 130;
  } else {
    return fwdfn149( state, next_func );
  }
}

static int fwdfn148( const state_t *state, void *next_func )
{
  if( state->vars[ 4 ] == 3 ) {
    return fwdfn171( state, next_func );
  } else {
    return fwdfn149( state, next_func );
  }
}

static int fwdfn147( const state_t *state, void *next_func )
{
  if( state->vars[ 2 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn148;
    return 128;
  } else {
    return fwdfn148( state, next_func );
  }
}

static int fwdfn172( const state_t *state, void *next_func )
{
  switch( state->vars[ 4 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn149;
    return 129;
  case 1:
    return fwdfn149( state, next_func );
  case 2:
    return fwdfn149( state, next_func );
  default:
    return fwdfn171( state, next_func );
  }
}

static int fwdfn146( const state_t *state, void *next_func )
{
  switch( state->vars[ 3 ] ) {
  case 0:
    return fwdfn147( state, next_func );
  case 1:
    return fwdfn148( state, next_func );
  case 2:
    return fwdfn148( state, next_func );
  default:
    return fwdfn172( state, next_func );
  }
}

static int fwdfn145( const state_t *state, void *next_func )
{
  if( state->vars[ 0 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn146;
    return 126;
  } else {
    return fwdfn146( state, next_func );
  }
}

static int fwdfn175( const state_t *state, void *next_func )
{
  if( state->vars[ 3 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn149;
    return 129;
  } else {
    return fwdfn149( state, next_func );
  }
}

static int fwdfn174( const state_t *state, void *next_func )
{
  switch( state->vars[ 4 ] ) {
  case 0:
    return fwdfn175( state, next_func );
  case 1:
    return fwdfn149( state, next_func );
  case 2:
    return fwdfn149( state, next_func );
  default:
    return fwdfn171( state, next_func );
  }
}

static int fwdfn176( const state_t *state, void *next_func )
{
  switch( state->vars[ 3 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn148;
    return 128;
  case 1:
    return fwdfn148( state, next_func );
  case 2:
    return fwdfn148( state, next_func );
  default:
    return fwdfn172( state, next_func );
  }
}

static int fwdfn173( const state_t *state, void *next_func )
{
  switch( state->vars[ 2 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn174;
    return 127;
  case 1:
    return fwdfn174( state, next_func );
  case 2:
    return fwdfn174( state, next_func );
  default:
    return fwdfn176( state, next_func );
  }
}

static int fwdfn144( const state_t *state, void *next_func )
{
  switch( state->vars[ 1 ] ) {
  case 0:
    return fwdfn145( state, next_func );
  case 1:
    return fwdfn146( state, next_func );
  case 2:
    return fwdfn146( state, next_func );
  default:
    return fwdfn173( state, next_func );
  }
}

static int fwdfn143( const state_t *state, void *next_func )
{
  if( state->vars[ 35 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn144;
    return 125;
  } else {
    return fwdfn144( state, next_func );
  }
}

static int fwdfn142( const state_t *state, void *next_func )
{
  switch( state->vars[ 34 ] ) {
  case 0:
    return fwdfn143( state, next_func );
  case 1:
    return fwdfn144( state, next_func );
  case 2:
    return fwdfn144( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn144;
    return 124;
  }
}

static int fwdfn177( const state_t *state, void *next_func )
{
  if( state->vars[ 34 ] == 0 ) {
    return fwdfn143( state, next_func );
  } else {
    return fwdfn144( state, next_func );
  }
}

static int fwdfn141( const state_t *state, void *next_func )
{
  switch( state->vars[ 33 ] ) {
  case 0:
    return fwdfn142( state, next_func );
  case 1:
    return fwdfn177( state, next_func );
  case 2:
    return fwdfn177( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn177;
    return 123;
  }
}

static int fwdfn179( const state_t *state, void *next_func )
{
  if( state->vars[ 33 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn144;
    return 124;
  } else {
    return fwdfn144( state, next_func );
  }
}

static int fwdfn178( const state_t *state, void *next_func )
{
  switch( state->vars[ 34 ] ) {
  case 0:
    return fwdfn143( state, next_func );
  case 1:
    return fwdfn144( state, next_func );
  case 2:
    return fwdfn144( state, next_func );
  default:
    return fwdfn179( state, next_func );
  }
}

static int fwdfn140( const state_t *state, void *next_func )
{
  switch( state->vars[ 32 ] ) {
  case 0:
    return fwdfn141( state, next_func );
  case 1:
    return fwdfn178( state, next_func );
  case 2:
    return fwdfn178( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn178;
    return 122;
  }
}

static int fwdfn181( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn177;
    return 123;
  } else {
    return fwdfn177( state, next_func );
  }
}

static int fwdfn180( const state_t *state, void *next_func )
{
  switch( state->vars[ 33 ] ) {
  case 0:
    return fwdfn142( state, next_func );
  case 1:
    return fwdfn177( state, next_func );
  case 2:
    return fwdfn177( state, next_func );
  default:
    return fwdfn181( state, next_func );
  }
}

static int fwdfn182( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn180;
    return 121;
  } else {
    return fwdfn180( state, next_func );
  }
}

static int fwdfn139( const state_t *state, void *next_func )
{
  switch( state->vars[ 31 ] ) {
  case 0:
    return fwdfn140( state, next_func );
  case 1:
    return fwdfn180( state, next_func );
  case 2:
    return fwdfn180( state, next_func );
  default:
    return fwdfn182( state, next_func );
  }
}

static int fwdfn183( const state_t *state, void *next_func )
{
  if( state->vars[ 21 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn139;
    return 143;
  } else {
    return fwdfn139( state, next_func );
  }
}

static int fwdfn138( const state_t *state, void *next_func )
{
  if( state->vars[ 20 ] == 3 ) {
    return fwdfn183( state, next_func );
  } else {
    return fwdfn139( state, next_func );
  }
}

static int fwdfn137( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn138;
    return 141;
  } else {
    return fwdfn138( state, next_func );
  }
}

static int fwdfn184( const state_t *state, void *next_func )
{
  switch( state->vars[ 20 ] ) {
  case 0:
    *((funcptr *)next_func) = fwdfn139;
    return 142;
  case 1:
    return fwdfn139( state, next_func );
  case 2:
    return fwdfn139( state, next_func );
  default:
    return fwdfn183( state, next_func );
  }
}

static int fwdfn136( const state_t *state, void *next_func )
{
  switch( state->vars[ 19 ] ) {
  case 0:
    return fwdfn137( state, next_func );
  case 1:
    return fwdfn138( state, next_func );
  case 2:
    return fwdfn138( state, next_func );
  default:
    return fwdfn184( state, next_func );
  }
}

static int fwdfn135( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn136;
    return 120;
  } else {
    return fwdfn136( state, next_func );
  }
}

static int fwdfn134( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 0 ) {
    return fwdfn135( state, next_func );
  } else {
    return fwdfn136( state, next_func );
  }
}

static int fwdfn208( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn134;
    return 115;
  } else {
    return fwdfn134( state, next_func );
  }
}

static int fwdfn207( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn208( state, next_func );
  case 1:
    return fwdfn134( state, next_func );
  case 2:
    return fwdfn134( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn134;
    return 114;
  }
}

static int fwdfn209( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    return fwdfn208( state, next_func );
  } else {
    return fwdfn134( state, next_func );
  }
}

static int fwdfn206( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn207( state, next_func );
  case 1:
    return fwdfn209( state, next_func );
  case 2:
    return fwdfn209( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn209;
    return 113;
  }
}

static int fwdfn211( const state_t *state, void *next_func )
{
  if( state->vars[ 21 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn134;
    return 114;
  } else {
    return fwdfn134( state, next_func );
  }
}

static int fwdfn210( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn208( state, next_func );
  case 1:
    return fwdfn134( state, next_func );
  case 2:
    return fwdfn134( state, next_func );
  default:
    return fwdfn211( state, next_func );
  }
}

static int fwdfn205( const state_t *state, void *next_func )
{
  switch( state->vars[ 20 ] ) {
  case 0:
    return fwdfn206( state, next_func );
  case 1:
    return fwdfn210( state, next_func );
  case 2:
    return fwdfn210( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn210;
    return 112;
  }
}

static int fwdfn213( const state_t *state, void *next_func )
{
  if( state->vars[ 20 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn209;
    return 113;
  } else {
    return fwdfn209( state, next_func );
  }
}

static int fwdfn212( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn207( state, next_func );
  case 1:
    return fwdfn209( state, next_func );
  case 2:
    return fwdfn209( state, next_func );
  default:
    return fwdfn213( state, next_func );
  }
}

static int fwdfn214( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn212;
    return 111;
  } else {
    return fwdfn212( state, next_func );
  }
}

static int fwdfn204( const state_t *state, void *next_func )
{
  switch( state->vars[ 19 ] ) {
  case 0:
    return fwdfn205( state, next_func );
  case 1:
    return fwdfn212( state, next_func );
  case 2:
    return fwdfn212( state, next_func );
  default:
    return fwdfn214( state, next_func );
  }
}

static int fwdfn203( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn204;
    return 110;
  } else {
    return fwdfn204( state, next_func );
  }
}

static int fwdfn202( const state_t *state, void *next_func )
{
  switch( state->vars[ 16 ] ) {
  case 0:
    return fwdfn203( state, next_func );
  case 1:
    return fwdfn204( state, next_func );
  case 2:
    return fwdfn204( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn204;
    return 109;
  }
}

static int fwdfn215( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    return fwdfn203( state, next_func );
  } else {
    return fwdfn204( state, next_func );
  }
}

static int fwdfn201( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn202( state, next_func );
  case 1:
    return fwdfn215( state, next_func );
  case 2:
    return fwdfn215( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn215;
    return 108;
  }
}

static int fwdfn217( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn204;
    return 109;
  } else {
    return fwdfn204( state, next_func );
  }
}

static int fwdfn216( const state_t *state, void *next_func )
{
  switch( state->vars[ 16 ] ) {
  case 0:
    return fwdfn203( state, next_func );
  case 1:
    return fwdfn204( state, next_func );
  case 2:
    return fwdfn204( state, next_func );
  default:
    return fwdfn217( state, next_func );
  }
}

static int fwdfn200( const state_t *state, void *next_func )
{
  switch( state->vars[ 14 ] ) {
  case 0:
    return fwdfn201( state, next_func );
  case 1:
    return fwdfn216( state, next_func );
  case 2:
    return fwdfn216( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn216;
    return 107;
  }
}

static int fwdfn219( const state_t *state, void *next_func )
{
  if( state->vars[ 14 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn215;
    return 108;
  } else {
    return fwdfn215( state, next_func );
  }
}

static int fwdfn218( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn202( state, next_func );
  case 1:
    return fwdfn215( state, next_func );
  case 2:
    return fwdfn215( state, next_func );
  default:
    return fwdfn219( state, next_func );
  }
}

static int fwdfn220( const state_t *state, void *next_func )
{
  if( state->vars[ 12 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn218;
    return 106;
  } else {
    return fwdfn218( state, next_func );
  }
}

static int fwdfn199( const state_t *state, void *next_func )
{
  switch( state->vars[ 13 ] ) {
  case 0:
    return fwdfn200( state, next_func );
  case 1:
    return fwdfn218( state, next_func );
  case 2:
    return fwdfn218( state, next_func );
  default:
    return fwdfn220( state, next_func );
  }
}

static int fwdfn198( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn199;
    return 105;
  } else {
    return fwdfn199( state, next_func );
  }
}

static int fwdfn197( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    return fwdfn198( state, next_func );
  case 1:
    return fwdfn199( state, next_func );
  case 2:
    return fwdfn199( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn199;
    return 104;
  }
}

static int fwdfn221( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    return fwdfn198( state, next_func );
  } else {
    return fwdfn199( state, next_func );
  }
}

static int fwdfn196( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return fwdfn197( state, next_func );
  case 1:
    return fwdfn221( state, next_func );
  case 2:
    return fwdfn221( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn221;
    return 103;
  }
}

static int fwdfn223( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn199;
    return 104;
  } else {
    return fwdfn199( state, next_func );
  }
}

static int fwdfn222( const state_t *state, void *next_func )
{
  switch( state->vars[ 10 ] ) {
  case 0:
    return fwdfn198( state, next_func );
  case 1:
    return fwdfn199( state, next_func );
  case 2:
    return fwdfn199( state, next_func );
  default:
    return fwdfn223( state, next_func );
  }
}

static int fwdfn195( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return fwdfn196( state, next_func );
  case 1:
    return fwdfn222( state, next_func );
  case 2:
    return fwdfn222( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn222;
    return 102;
  }
}

static int fwdfn225( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn221;
    return 103;
  } else {
    return fwdfn221( state, next_func );
  }
}

static int fwdfn224( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return fwdfn197( state, next_func );
  case 1:
    return fwdfn221( state, next_func );
  case 2:
    return fwdfn221( state, next_func );
  default:
    return fwdfn225( state, next_func );
  }
}

static int fwdfn226( const state_t *state, void *next_func )
{
  if( state->vars[ 6 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn224;
    return 101;
  } else {
    return fwdfn224( state, next_func );
  }
}

static int fwdfn194( const state_t *state, void *next_func )
{
  switch( state->vars[ 7 ] ) {
  case 0:
    return fwdfn195( state, next_func );
  case 1:
    return fwdfn224( state, next_func );
  case 2:
    return fwdfn224( state, next_func );
  default:
    return fwdfn226( state, next_func );
  }
}

static int fwdfn193( const state_t *state, void *next_func )
{
  if( state->vars[ 5 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn194;
    return 100;
  } else {
    return fwdfn194( state, next_func );
  }
}

static int fwdfn192( const state_t *state, void *next_func )
{
  switch( state->vars[ 4 ] ) {
  case 0:
    return fwdfn193( state, next_func );
  case 1:
    return fwdfn194( state, next_func );
  case 2:
    return fwdfn194( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn194;
    return 99;
  }
}

static int fwdfn227( const state_t *state, void *next_func )
{
  if( state->vars[ 4 ] == 0 ) {
    return fwdfn193( state, next_func );
  } else {
    return fwdfn194( state, next_func );
  }
}

static int fwdfn191( const state_t *state, void *next_func )
{
  switch( state->vars[ 3 ] ) {
  case 0:
    return fwdfn192( state, next_func );
  case 1:
    return fwdfn227( state, next_func );
  case 2:
    return fwdfn227( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn227;
    return 98;
  }
}

static int fwdfn229( const state_t *state, void *next_func )
{
  if( state->vars[ 3 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn194;
    return 99;
  } else {
    return fwdfn194( state, next_func );
  }
}

static int fwdfn228( const state_t *state, void *next_func )
{
  switch( state->vars[ 4 ] ) {
  case 0:
    return fwdfn193( state, next_func );
  case 1:
    return fwdfn194( state, next_func );
  case 2:
    return fwdfn194( state, next_func );
  default:
    return fwdfn229( state, next_func );
  }
}

static int fwdfn190( const state_t *state, void *next_func )
{
  switch( state->vars[ 2 ] ) {
  case 0:
    return fwdfn191( state, next_func );
  case 1:
    return fwdfn228( state, next_func );
  case 2:
    return fwdfn228( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn228;
    return 97;
  }
}

static int fwdfn231( const state_t *state, void *next_func )
{
  if( state->vars[ 2 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn227;
    return 98;
  } else {
    return fwdfn227( state, next_func );
  }
}

static int fwdfn230( const state_t *state, void *next_func )
{
  switch( state->vars[ 3 ] ) {
  case 0:
    return fwdfn192( state, next_func );
  case 1:
    return fwdfn227( state, next_func );
  case 2:
    return fwdfn227( state, next_func );
  default:
    return fwdfn231( state, next_func );
  }
}

static int fwdfn232( const state_t *state, void *next_func )
{
  if( state->vars[ 0 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn230;
    return 96;
  } else {
    return fwdfn230( state, next_func );
  }
}

static int fwdfn189( const state_t *state, void *next_func )
{
  switch( state->vars[ 1 ] ) {
  case 0:
    return fwdfn190( state, next_func );
  case 1:
    return fwdfn230( state, next_func );
  case 2:
    return fwdfn230( state, next_func );
  default:
    return fwdfn232( state, next_func );
  }
}

static int fwdfn188( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn189;
    return 119;
  } else {
    return fwdfn189( state, next_func );
  }
}

static int fwdfn187( const state_t *state, void *next_func )
{
  switch( state->vars[ 27 ] ) {
  case 0:
    return fwdfn188( state, next_func );
  case 1:
    return fwdfn189( state, next_func );
  case 2:
    return fwdfn189( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn189;
    return 118;
  }
}

static int fwdfn233( const state_t *state, void *next_func )
{
  if( state->vars[ 27 ] == 0 ) {
    return fwdfn188( state, next_func );
  } else {
    return fwdfn189( state, next_func );
  }
}

static int fwdfn186( const state_t *state, void *next_func )
{
  switch( state->vars[ 26 ] ) {
  case 0:
    return fwdfn187( state, next_func );
  case 1:
    return fwdfn233( state, next_func );
  case 2:
    return fwdfn233( state, next_func );
  default:
    *((funcptr *)next_func) = fwdfn233;
    return 117;
  }
}

static int fwdfn235( const state_t *state, void *next_func )
{
  if( state->vars[ 26 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn189;
    return 118;
  } else {
    return fwdfn189( state, next_func );
  }
}

static int fwdfn234( const state_t *state, void *next_func )
{
  switch( state->vars[ 27 ] ) {
  case 0:
    return fwdfn188( state, next_func );
  case 1:
    return fwdfn189( state, next_func );
  case 2:
    return fwdfn189( state, next_func );
  default:
    return fwdfn235( state, next_func );
  }
}

static int fwdfn236( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn234;
    return 116;
  } else {
    return fwdfn234( state, next_func );
  }
}

static int fwdfn185( const state_t *state, void *next_func )
{
  switch( state->vars[ 25 ] ) {
  case 0:
    return fwdfn186( state, next_func );
  case 1:
    return fwdfn234( state, next_func );
  case 2:
    return fwdfn234( state, next_func );
  default:
    return fwdfn236( state, next_func );
  }
}

static int fwdfn255( const state_t *state, void *next_func )
{
  if( state->vars[ 35 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn185;
    return 95;
  } else {
    return fwdfn185( state, next_func );
  }
}

static int fwdfn254( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 1 ) {
    return fwdfn255( state, next_func );
  } else {
    return fwdfn185( state, next_func );
  }
}

static int fwdfn256( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn185;
    return 89;
  } else {
    return fwdfn185( state, next_func );
  }
}

static int fwdfn253( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn254( state, next_func );
  case 1:
    return fwdfn256( state, next_func );
  case 2:
    return fwdfn185( state, next_func );
  default:
    return fwdfn185( state, next_func );
  }
}

static int fwdfn258( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn185;
    return 83;
  } else {
    return fwdfn185( state, next_func );
  }
}

static int fwdfn257( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn254( state, next_func );
  case 1:
    return fwdfn185( state, next_func );
  case 2:
    return fwdfn185( state, next_func );
  default:
    return fwdfn258( state, next_func );
  }
}

static int fwdfn259( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    return fwdfn254( state, next_func );
  } else {
    return fwdfn185( state, next_func );
  }
}

static int fwdfn261( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn259;
    return 77;
  } else {
    return fwdfn259( state, next_func );
  }
}

static int fwdfn260( const state_t *state, void *next_func )
{
  if( state->vars[ 5 ] == 0 ) {
    return fwdfn261( state, next_func );
  } else {
    return fwdfn259( state, next_func );
  }
}

static int fwdfn252( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return fwdfn253( state, next_func );
  case 1:
    return fwdfn257( state, next_func );
  case 2:
    return fwdfn259( state, next_func );
  default:
    return fwdfn260( state, next_func );
  }
}

static int fwdfn262( const state_t *state, void *next_func )
{
  if( state->vars[ 34 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn252;
    return 94;
  } else {
    return fwdfn252( state, next_func );
  }
}

static int fwdfn251( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 1 ) {
    return fwdfn262( state, next_func );
  } else {
    return fwdfn252( state, next_func );
  }
}

static int fwdfn263( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn252;
    return 88;
  } else {
    return fwdfn252( state, next_func );
  }
}

static int fwdfn250( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn251( state, next_func );
  case 1:
    return fwdfn263( state, next_func );
  case 2:
    return fwdfn252( state, next_func );
  default:
    return fwdfn252( state, next_func );
  }
}

static int fwdfn265( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn252;
    return 82;
  } else {
    return fwdfn252( state, next_func );
  }
}

static int fwdfn264( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn251( state, next_func );
  case 1:
    return fwdfn252( state, next_func );
  case 2:
    return fwdfn252( state, next_func );
  default:
    return fwdfn265( state, next_func );
  }
}

static int fwdfn266( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    return fwdfn251( state, next_func );
  } else {
    return fwdfn252( state, next_func );
  }
}

static int fwdfn268( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn266;
    return 76;
  } else {
    return fwdfn266( state, next_func );
  }
}

static int fwdfn267( const state_t *state, void *next_func )
{
  if( state->vars[ 4 ] == 0 ) {
    return fwdfn268( state, next_func );
  } else {
    return fwdfn266( state, next_func );
  }
}

static int fwdfn249( const state_t *state, void *next_func )
{
  switch( state->vars[ 16 ] ) {
  case 0:
    return fwdfn250( state, next_func );
  case 1:
    return fwdfn264( state, next_func );
  case 2:
    return fwdfn266( state, next_func );
  default:
    return fwdfn267( state, next_func );
  }
}

static int fwdfn269( const state_t *state, void *next_func )
{
  if( state->vars[ 33 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn249;
    return 93;
  } else {
    return fwdfn249( state, next_func );
  }
}

static int fwdfn248( const state_t *state, void *next_func )
{
  if( state->vars[ 27 ] == 1 ) {
    return fwdfn269( state, next_func );
  } else {
    return fwdfn249( state, next_func );
  }
}

static int fwdfn270( const state_t *state, void *next_func )
{
  if( state->vars[ 27 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn249;
    return 87;
  } else {
    return fwdfn249( state, next_func );
  }
}

static int fwdfn247( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn248( state, next_func );
  case 1:
    return fwdfn270( state, next_func );
  case 2:
    return fwdfn249( state, next_func );
  default:
    return fwdfn249( state, next_func );
  }
}

static int fwdfn272( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn249;
    return 81;
  } else {
    return fwdfn249( state, next_func );
  }
}

static int fwdfn271( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn248( state, next_func );
  case 1:
    return fwdfn249( state, next_func );
  case 2:
    return fwdfn249( state, next_func );
  default:
    return fwdfn272( state, next_func );
  }
}

static int fwdfn273( const state_t *state, void *next_func )
{
  if( state->vars[ 21 ] == 0 ) {
    return fwdfn248( state, next_func );
  } else {
    return fwdfn249( state, next_func );
  }
}

static int fwdfn275( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn273;
    return 75;
  } else {
    return fwdfn273( state, next_func );
  }
}

static int fwdfn274( const state_t *state, void *next_func )
{
  if( state->vars[ 3 ] == 0 ) {
    return fwdfn275( state, next_func );
  } else {
    return fwdfn273( state, next_func );
  }
}

static int fwdfn246( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn247( state, next_func );
  case 1:
    return fwdfn271( state, next_func );
  case 2:
    return fwdfn273( state, next_func );
  default:
    return fwdfn274( state, next_func );
  }
}

static int fwdfn276( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn246;
    return 92;
  } else {
    return fwdfn246( state, next_func );
  }
}

static int fwdfn245( const state_t *state, void *next_func )
{
  if( state->vars[ 26 ] == 1 ) {
    return fwdfn276( state, next_func );
  } else {
    return fwdfn246( state, next_func );
  }
}

static int fwdfn277( const state_t *state, void *next_func )
{
  if( state->vars[ 26 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn246;
    return 86;
  } else {
    return fwdfn246( state, next_func );
  }
}

static int fwdfn244( const state_t *state, void *next_func )
{
  switch( state->vars[ 20 ] ) {
  case 0:
    return fwdfn245( state, next_func );
  case 1:
    return fwdfn277( state, next_func );
  case 2:
    return fwdfn246( state, next_func );
  default:
    return fwdfn246( state, next_func );
  }
}

static int fwdfn279( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn246;
    return 80;
  } else {
    return fwdfn246( state, next_func );
  }
}

static int fwdfn278( const state_t *state, void *next_func )
{
  switch( state->vars[ 20 ] ) {
  case 0:
    return fwdfn245( state, next_func );
  case 1:
    return fwdfn246( state, next_func );
  case 2:
    return fwdfn246( state, next_func );
  default:
    return fwdfn279( state, next_func );
  }
}

static int fwdfn280( const state_t *state, void *next_func )
{
  if( state->vars[ 20 ] == 0 ) {
    return fwdfn245( state, next_func );
  } else {
    return fwdfn246( state, next_func );
  }
}

static int fwdfn282( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn280;
    return 74;
  } else {
    return fwdfn280( state, next_func );
  }
}

static int fwdfn281( const state_t *state, void *next_func )
{
  if( state->vars[ 2 ] == 0 ) {
    return fwdfn282( state, next_func );
  } else {
    return fwdfn280( state, next_func );
  }
}

static int fwdfn243( const state_t *state, void *next_func )
{
  switch( state->vars[ 14 ] ) {
  case 0:
    return fwdfn244( state, next_func );
  case 1:
    return fwdfn278( state, next_func );
  case 2:
    return fwdfn280( state, next_func );
  default:
    return fwdfn281( state, next_func );
  }
}

static int fwdfn283( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn243;
    return 91;
  } else {
    return fwdfn243( state, next_func );
  }
}

static int fwdfn242( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 1 ) {
    return fwdfn283( state, next_func );
  } else {
    return fwdfn243( state, next_func );
  }
}

static int fwdfn284( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn243;
    return 85;
  } else {
    return fwdfn243( state, next_func );
  }
}

static int fwdfn241( const state_t *state, void *next_func )
{
  switch( state->vars[ 19 ] ) {
  case 0:
    return fwdfn242( state, next_func );
  case 1:
    return fwdfn284( state, next_func );
  case 2:
    return fwdfn243( state, next_func );
  default:
    return fwdfn243( state, next_func );
  }
}

static int fwdfn286( const state_t *state, void *next_func )
{
  if( state->vars[ 7 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn243;
    return 79;
  } else {
    return fwdfn243( state, next_func );
  }
}

static int fwdfn285( const state_t *state, void *next_func )
{
  switch( state->vars[ 19 ] ) {
  case 0:
    return fwdfn242( state, next_func );
  case 1:
    return fwdfn243( state, next_func );
  case 2:
    return fwdfn243( state, next_func );
  default:
    return fwdfn286( state, next_func );
  }
}

static int fwdfn287( const state_t *state, void *next_func )
{
  if( state->vars[ 19 ] == 0 ) {
    return fwdfn242( state, next_func );
  } else {
    return fwdfn243( state, next_func );
  }
}

static int fwdfn289( const state_t *state, void *next_func )
{
  if( state->vars[ 7 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn287;
    return 73;
  } else {
    return fwdfn287( state, next_func );
  }
}

static int fwdfn288( const state_t *state, void *next_func )
{
  if( state->vars[ 1 ] == 0 ) {
    return fwdfn289( state, next_func );
  } else {
    return fwdfn287( state, next_func );
  }
}

static int fwdfn240( const state_t *state, void *next_func )
{
  switch( state->vars[ 13 ] ) {
  case 0:
    return fwdfn241( state, next_func );
  case 1:
    return fwdfn285( state, next_func );
  case 2:
    return fwdfn287( state, next_func );
  default:
    return fwdfn288( state, next_func );
  }
}

static int fwdfn290( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn240;
    return 90;
  } else {
    return fwdfn240( state, next_func );
  }
}

static int fwdfn239( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 1 ) {
    return fwdfn290( state, next_func );
  } else {
    return fwdfn240( state, next_func );
  }
}

static int fwdfn291( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn240;
    return 84;
  } else {
    return fwdfn240( state, next_func );
  }
}

static int fwdfn238( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn239( state, next_func );
  case 1:
    return fwdfn291( state, next_func );
  case 2:
    return fwdfn240( state, next_func );
  default:
    return fwdfn240( state, next_func );
  }
}

static int fwdfn293( const state_t *state, void *next_func )
{
  if( state->vars[ 6 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn240;
    return 78;
  } else {
    return fwdfn240( state, next_func );
  }
}

static int fwdfn292( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn239( state, next_func );
  case 1:
    return fwdfn240( state, next_func );
  case 2:
    return fwdfn240( state, next_func );
  default:
    return fwdfn293( state, next_func );
  }
}

static int fwdfn294( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    return fwdfn239( state, next_func );
  } else {
    return fwdfn240( state, next_func );
  }
}

static int fwdfn296( const state_t *state, void *next_func )
{
  if( state->vars[ 6 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn294;
    return 72;
  } else {
    return fwdfn294( state, next_func );
  }
}

static int fwdfn295( const state_t *state, void *next_func )
{
  if( state->vars[ 0 ] == 0 ) {
    return fwdfn296( state, next_func );
  } else {
    return fwdfn294( state, next_func );
  }
}

static int fwdfn237( const state_t *state, void *next_func )
{
  switch( state->vars[ 12 ] ) {
  case 0:
    return fwdfn238( state, next_func );
  case 1:
    return fwdfn292( state, next_func );
  case 2:
    return fwdfn294( state, next_func );
  default:
    return fwdfn295( state, next_func );
  }
}

static int fwdfn316( const state_t *state, void *next_func )
{
  if( state->vars[ 35 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn237;
    return 71;
  } else {
    return fwdfn237( state, next_func );
  }
}

static int fwdfn315( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 1 ) {
    return fwdfn316( state, next_func );
  } else {
    return fwdfn237( state, next_func );
  }
}

static int fwdfn314( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    return fwdfn315( state, next_func );
  } else {
    return fwdfn237( state, next_func );
  }
}

static int fwdfn317( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn314;
    return 53;
  } else {
    return fwdfn314( state, next_func );
  }
}

static int fwdfn313( const state_t *state, void *next_func )
{
  if( state->vars[ 5 ] == 3 ) {
    return fwdfn317( state, next_func );
  } else {
    return fwdfn314( state, next_func );
  }
}

static int fwdfn319( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn237;
    return 59;
  } else {
    return fwdfn237( state, next_func );
  }
}

static int fwdfn318( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn319( state, next_func );
  case 1:
    return fwdfn237( state, next_func );
  case 2:
    return fwdfn237( state, next_func );
  default:
    return fwdfn315( state, next_func );
  }
}

static int fwdfn321( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn237;
    return 65;
  } else {
    return fwdfn237( state, next_func );
  }
}

static int fwdfn320( const state_t *state, void *next_func )
{
  switch( state->vars[ 23 ] ) {
  case 0:
    return fwdfn237( state, next_func );
  case 1:
    return fwdfn321( state, next_func );
  case 2:
    return fwdfn237( state, next_func );
  default:
    return fwdfn315( state, next_func );
  }
}

static int fwdfn312( const state_t *state, void *next_func )
{
  switch( state->vars[ 17 ] ) {
  case 0:
    return fwdfn313( state, next_func );
  case 1:
    return fwdfn318( state, next_func );
  case 2:
    return fwdfn314( state, next_func );
  default:
    return fwdfn320( state, next_func );
  }
}

static int fwdfn323( const state_t *state, void *next_func )
{
  if( state->vars[ 34 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn312;
    return 70;
  } else {
    return fwdfn312( state, next_func );
  }
}

static int fwdfn322( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 1 ) {
    return fwdfn323( state, next_func );
  } else {
    return fwdfn312( state, next_func );
  }
}

static int fwdfn311( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    return fwdfn322( state, next_func );
  } else {
    return fwdfn312( state, next_func );
  }
}

static int fwdfn324( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn311;
    return 52;
  } else {
    return fwdfn311( state, next_func );
  }
}

static int fwdfn310( const state_t *state, void *next_func )
{
  if( state->vars[ 4 ] == 3 ) {
    return fwdfn324( state, next_func );
  } else {
    return fwdfn311( state, next_func );
  }
}

static int fwdfn326( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn312;
    return 58;
  } else {
    return fwdfn312( state, next_func );
  }
}

static int fwdfn325( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn326( state, next_func );
  case 1:
    return fwdfn312( state, next_func );
  case 2:
    return fwdfn312( state, next_func );
  default:
    return fwdfn322( state, next_func );
  }
}

static int fwdfn328( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn312;
    return 64;
  } else {
    return fwdfn312( state, next_func );
  }
}

static int fwdfn327( const state_t *state, void *next_func )
{
  switch( state->vars[ 22 ] ) {
  case 0:
    return fwdfn312( state, next_func );
  case 1:
    return fwdfn328( state, next_func );
  case 2:
    return fwdfn312( state, next_func );
  default:
    return fwdfn322( state, next_func );
  }
}

static int fwdfn309( const state_t *state, void *next_func )
{
  switch( state->vars[ 16 ] ) {
  case 0:
    return fwdfn310( state, next_func );
  case 1:
    return fwdfn325( state, next_func );
  case 2:
    return fwdfn311( state, next_func );
  default:
    return fwdfn327( state, next_func );
  }
}

static int fwdfn330( const state_t *state, void *next_func )
{
  if( state->vars[ 33 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn309;
    return 69;
  } else {
    return fwdfn309( state, next_func );
  }
}

static int fwdfn329( const state_t *state, void *next_func )
{
  if( state->vars[ 27 ] == 1 ) {
    return fwdfn330( state, next_func );
  } else {
    return fwdfn309( state, next_func );
  }
}

static int fwdfn308( const state_t *state, void *next_func )
{
  if( state->vars[ 21 ] == 3 ) {
    return fwdfn329( state, next_func );
  } else {
    return fwdfn309( state, next_func );
  }
}

static int fwdfn331( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn308;
    return 51;
  } else {
    return fwdfn308( state, next_func );
  }
}

static int fwdfn307( const state_t *state, void *next_func )
{
  if( state->vars[ 3 ] == 3 ) {
    return fwdfn331( state, next_func );
  } else {
    return fwdfn308( state, next_func );
  }
}

static int fwdfn333( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn309;
    return 57;
  } else {
    return fwdfn309( state, next_func );
  }
}

static int fwdfn332( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn333( state, next_func );
  case 1:
    return fwdfn309( state, next_func );
  case 2:
    return fwdfn309( state, next_func );
  default:
    return fwdfn329( state, next_func );
  }
}

static int fwdfn335( const state_t *state, void *next_func )
{
  if( state->vars[ 27 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn309;
    return 63;
  } else {
    return fwdfn309( state, next_func );
  }
}

static int fwdfn334( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn309( state, next_func );
  case 1:
    return fwdfn335( state, next_func );
  case 2:
    return fwdfn309( state, next_func );
  default:
    return fwdfn329( state, next_func );
  }
}

static int fwdfn306( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn307( state, next_func );
  case 1:
    return fwdfn332( state, next_func );
  case 2:
    return fwdfn308( state, next_func );
  default:
    return fwdfn334( state, next_func );
  }
}

static int fwdfn337( const state_t *state, void *next_func )
{
  if( state->vars[ 32 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn306;
    return 68;
  } else {
    return fwdfn306( state, next_func );
  }
}

static int fwdfn336( const state_t *state, void *next_func )
{
  if( state->vars[ 26 ] == 1 ) {
    return fwdfn337( state, next_func );
  } else {
    return fwdfn306( state, next_func );
  }
}

static int fwdfn305( const state_t *state, void *next_func )
{
  if( state->vars[ 20 ] == 3 ) {
    return fwdfn336( state, next_func );
  } else {
    return fwdfn306( state, next_func );
  }
}

static int fwdfn338( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn305;
    return 50;
  } else {
    return fwdfn305( state, next_func );
  }
}

static int fwdfn304( const state_t *state, void *next_func )
{
  if( state->vars[ 2 ] == 3 ) {
    return fwdfn338( state, next_func );
  } else {
    return fwdfn305( state, next_func );
  }
}

static int fwdfn340( const state_t *state, void *next_func )
{
  if( state->vars[ 8 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn306;
    return 56;
  } else {
    return fwdfn306( state, next_func );
  }
}

static int fwdfn339( const state_t *state, void *next_func )
{
  switch( state->vars[ 20 ] ) {
  case 0:
    return fwdfn340( state, next_func );
  case 1:
    return fwdfn306( state, next_func );
  case 2:
    return fwdfn306( state, next_func );
  default:
    return fwdfn336( state, next_func );
  }
}

static int fwdfn342( const state_t *state, void *next_func )
{
  if( state->vars[ 26 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn306;
    return 62;
  } else {
    return fwdfn306( state, next_func );
  }
}

static int fwdfn341( const state_t *state, void *next_func )
{
  switch( state->vars[ 20 ] ) {
  case 0:
    return fwdfn306( state, next_func );
  case 1:
    return fwdfn342( state, next_func );
  case 2:
    return fwdfn306( state, next_func );
  default:
    return fwdfn336( state, next_func );
  }
}

static int fwdfn303( const state_t *state, void *next_func )
{
  switch( state->vars[ 14 ] ) {
  case 0:
    return fwdfn304( state, next_func );
  case 1:
    return fwdfn339( state, next_func );
  case 2:
    return fwdfn305( state, next_func );
  default:
    return fwdfn341( state, next_func );
  }
}

static int fwdfn344( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn303;
    return 67;
  } else {
    return fwdfn303( state, next_func );
  }
}

static int fwdfn343( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 1 ) {
    return fwdfn344( state, next_func );
  } else {
    return fwdfn303( state, next_func );
  }
}

static int fwdfn302( const state_t *state, void *next_func )
{
  if( state->vars[ 19 ] == 3 ) {
    return fwdfn343( state, next_func );
  } else {
    return fwdfn303( state, next_func );
  }
}

static int fwdfn345( const state_t *state, void *next_func )
{
  if( state->vars[ 7 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn302;
    return 49;
  } else {
    return fwdfn302( state, next_func );
  }
}

static int fwdfn301( const state_t *state, void *next_func )
{
  if( state->vars[ 1 ] == 3 ) {
    return fwdfn345( state, next_func );
  } else {
    return fwdfn302( state, next_func );
  }
}

static int fwdfn347( const state_t *state, void *next_func )
{
  if( state->vars[ 7 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn303;
    return 55;
  } else {
    return fwdfn303( state, next_func );
  }
}

static int fwdfn346( const state_t *state, void *next_func )
{
  switch( state->vars[ 19 ] ) {
  case 0:
    return fwdfn347( state, next_func );
  case 1:
    return fwdfn303( state, next_func );
  case 2:
    return fwdfn303( state, next_func );
  default:
    return fwdfn343( state, next_func );
  }
}

static int fwdfn349( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn303;
    return 61;
  } else {
    return fwdfn303( state, next_func );
  }
}

static int fwdfn348( const state_t *state, void *next_func )
{
  switch( state->vars[ 19 ] ) {
  case 0:
    return fwdfn303( state, next_func );
  case 1:
    return fwdfn349( state, next_func );
  case 2:
    return fwdfn303( state, next_func );
  default:
    return fwdfn343( state, next_func );
  }
}

static int fwdfn300( const state_t *state, void *next_func )
{
  switch( state->vars[ 13 ] ) {
  case 0:
    return fwdfn301( state, next_func );
  case 1:
    return fwdfn346( state, next_func );
  case 2:
    return fwdfn302( state, next_func );
  default:
    return fwdfn348( state, next_func );
  }
}

static int fwdfn351( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn300;
    return 66;
  } else {
    return fwdfn300( state, next_func );
  }
}

static int fwdfn350( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 1 ) {
    return fwdfn351( state, next_func );
  } else {
    return fwdfn300( state, next_func );
  }
}

static int fwdfn299( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 3 ) {
    return fwdfn350( state, next_func );
  } else {
    return fwdfn300( state, next_func );
  }
}

static int fwdfn352( const state_t *state, void *next_func )
{
  if( state->vars[ 6 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn299;
    return 48;
  } else {
    return fwdfn299( state, next_func );
  }
}

static int fwdfn298( const state_t *state, void *next_func )
{
  if( state->vars[ 0 ] == 3 ) {
    return fwdfn352( state, next_func );
  } else {
    return fwdfn299( state, next_func );
  }
}

static int fwdfn354( const state_t *state, void *next_func )
{
  if( state->vars[ 6 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn300;
    return 54;
  } else {
    return fwdfn300( state, next_func );
  }
}

static int fwdfn353( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn354( state, next_func );
  case 1:
    return fwdfn300( state, next_func );
  case 2:
    return fwdfn300( state, next_func );
  default:
    return fwdfn350( state, next_func );
  }
}

static int fwdfn356( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn300;
    return 60;
  } else {
    return fwdfn300( state, next_func );
  }
}

static int fwdfn355( const state_t *state, void *next_func )
{
  switch( state->vars[ 18 ] ) {
  case 0:
    return fwdfn300( state, next_func );
  case 1:
    return fwdfn356( state, next_func );
  case 2:
    return fwdfn300( state, next_func );
  default:
    return fwdfn350( state, next_func );
  }
}

static int fwdfn297( const state_t *state, void *next_func )
{
  switch( state->vars[ 12 ] ) {
  case 0:
    return fwdfn298( state, next_func );
  case 1:
    return fwdfn353( state, next_func );
  case 2:
    return fwdfn299( state, next_func );
  default:
    return fwdfn355( state, next_func );
  }
}

static int fwdfn376( const state_t *state, void *next_func )
{
  if( state->vars[ 35 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn297;
    return 47;
  } else {
    return fwdfn297( state, next_func );
  }
}

static int fwdfn375( const state_t *state, void *next_func )
{
  if( state->vars[ 34 ] == 1 ) {
    return fwdfn376( state, next_func );
  } else {
    return fwdfn297( state, next_func );
  }
}

static int fwdfn374( const state_t *state, void *next_func )
{
  if( state->vars[ 33 ] == 3 ) {
    return fwdfn375( state, next_func );
  } else {
    return fwdfn297( state, next_func );
  }
}

static int fwdfn377( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn374;
    return 44;
  } else {
    return fwdfn374( state, next_func );
  }
}

static int fwdfn373( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 3 ) {
    return fwdfn377( state, next_func );
  } else {
    return fwdfn374( state, next_func );
  }
}

static int fwdfn379( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn297;
    return 45;
  } else {
    return fwdfn297( state, next_func );
  }
}

static int fwdfn378( const state_t *state, void *next_func )
{
  switch( state->vars[ 33 ] ) {
  case 0:
    return fwdfn379( state, next_func );
  case 1:
    return fwdfn297( state, next_func );
  case 2:
    return fwdfn297( state, next_func );
  default:
    return fwdfn375( state, next_func );
  }
}

static int fwdfn381( const state_t *state, void *next_func )
{
  if( state->vars[ 34 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn297;
    return 46;
  } else {
    return fwdfn297( state, next_func );
  }
}

static int fwdfn380( const state_t *state, void *next_func )
{
  switch( state->vars[ 33 ] ) {
  case 0:
    return fwdfn297( state, next_func );
  case 1:
    return fwdfn381( state, next_func );
  case 2:
    return fwdfn297( state, next_func );
  default:
    return fwdfn375( state, next_func );
  }
}

static int fwdfn372( const state_t *state, void *next_func )
{
  switch( state->vars[ 32 ] ) {
  case 0:
    return fwdfn373( state, next_func );
  case 1:
    return fwdfn378( state, next_func );
  case 2:
    return fwdfn374( state, next_func );
  default:
    return fwdfn380( state, next_func );
  }
}

static int fwdfn383( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn372;
    return 43;
  } else {
    return fwdfn372( state, next_func );
  }
}

static int fwdfn382( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 1 ) {
    return fwdfn383( state, next_func );
  } else {
    return fwdfn372( state, next_func );
  }
}

static int fwdfn371( const state_t *state, void *next_func )
{
  if( state->vars[ 27 ] == 3 ) {
    return fwdfn382( state, next_func );
  } else {
    return fwdfn372( state, next_func );
  }
}

static int fwdfn384( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn371;
    return 40;
  } else {
    return fwdfn371( state, next_func );
  }
}

static int fwdfn370( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 3 ) {
    return fwdfn384( state, next_func );
  } else {
    return fwdfn371( state, next_func );
  }
}

static int fwdfn386( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn372;
    return 41;
  } else {
    return fwdfn372( state, next_func );
  }
}

static int fwdfn385( const state_t *state, void *next_func )
{
  switch( state->vars[ 27 ] ) {
  case 0:
    return fwdfn386( state, next_func );
  case 1:
    return fwdfn372( state, next_func );
  case 2:
    return fwdfn372( state, next_func );
  default:
    return fwdfn382( state, next_func );
  }
}

static int fwdfn388( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn372;
    return 42;
  } else {
    return fwdfn372( state, next_func );
  }
}

static int fwdfn387( const state_t *state, void *next_func )
{
  switch( state->vars[ 27 ] ) {
  case 0:
    return fwdfn372( state, next_func );
  case 1:
    return fwdfn388( state, next_func );
  case 2:
    return fwdfn372( state, next_func );
  default:
    return fwdfn382( state, next_func );
  }
}

static int fwdfn369( const state_t *state, void *next_func )
{
  switch( state->vars[ 26 ] ) {
  case 0:
    return fwdfn370( state, next_func );
  case 1:
    return fwdfn385( state, next_func );
  case 2:
    return fwdfn371( state, next_func );
  default:
    return fwdfn387( state, next_func );
  }
}

static int fwdfn390( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn369;
    return 39;
  } else {
    return fwdfn369( state, next_func );
  }
}

static int fwdfn389( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 1 ) {
    return fwdfn390( state, next_func );
  } else {
    return fwdfn369( state, next_func );
  }
}

static int fwdfn368( const state_t *state, void *next_func )
{
  if( state->vars[ 21 ] == 3 ) {
    return fwdfn389( state, next_func );
  } else {
    return fwdfn369( state, next_func );
  }
}

static int fwdfn391( const state_t *state, void *next_func )
{
  if( state->vars[ 19 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn368;
    return 36;
  } else {
    return fwdfn368( state, next_func );
  }
}

static int fwdfn367( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 3 ) {
    return fwdfn391( state, next_func );
  } else {
    return fwdfn368( state, next_func );
  }
}

static int fwdfn393( const state_t *state, void *next_func )
{
  if( state->vars[ 19 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn369;
    return 37;
  } else {
    return fwdfn369( state, next_func );
  }
}

static int fwdfn392( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn393( state, next_func );
  case 1:
    return fwdfn369( state, next_func );
  case 2:
    return fwdfn369( state, next_func );
  default:
    return fwdfn389( state, next_func );
  }
}

static int fwdfn395( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn369;
    return 38;
  } else {
    return fwdfn369( state, next_func );
  }
}

static int fwdfn394( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn369( state, next_func );
  case 1:
    return fwdfn395( state, next_func );
  case 2:
    return fwdfn369( state, next_func );
  default:
    return fwdfn389( state, next_func );
  }
}

static int fwdfn366( const state_t *state, void *next_func )
{
  switch( state->vars[ 20 ] ) {
  case 0:
    return fwdfn367( state, next_func );
  case 1:
    return fwdfn392( state, next_func );
  case 2:
    return fwdfn368( state, next_func );
  default:
    return fwdfn394( state, next_func );
  }
}

static int fwdfn397( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn366;
    return 35;
  } else {
    return fwdfn366( state, next_func );
  }
}

static int fwdfn396( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    return fwdfn397( state, next_func );
  } else {
    return fwdfn366( state, next_func );
  }
}

static int fwdfn365( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 3 ) {
    return fwdfn396( state, next_func );
  } else {
    return fwdfn366( state, next_func );
  }
}

static int fwdfn398( const state_t *state, void *next_func )
{
  if( state->vars[ 13 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn365;
    return 32;
  } else {
    return fwdfn365( state, next_func );
  }
}

static int fwdfn364( const state_t *state, void *next_func )
{
  if( state->vars[ 12 ] == 3 ) {
    return fwdfn398( state, next_func );
  } else {
    return fwdfn365( state, next_func );
  }
}

static int fwdfn400( const state_t *state, void *next_func )
{
  if( state->vars[ 13 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn366;
    return 33;
  } else {
    return fwdfn366( state, next_func );
  }
}

static int fwdfn399( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn400( state, next_func );
  case 1:
    return fwdfn366( state, next_func );
  case 2:
    return fwdfn366( state, next_func );
  default:
    return fwdfn396( state, next_func );
  }
}

static int fwdfn402( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn366;
    return 34;
  } else {
    return fwdfn366( state, next_func );
  }
}

static int fwdfn401( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn366( state, next_func );
  case 1:
    return fwdfn402( state, next_func );
  case 2:
    return fwdfn366( state, next_func );
  default:
    return fwdfn396( state, next_func );
  }
}

static int fwdfn363( const state_t *state, void *next_func )
{
  switch( state->vars[ 14 ] ) {
  case 0:
    return fwdfn364( state, next_func );
  case 1:
    return fwdfn399( state, next_func );
  case 2:
    return fwdfn365( state, next_func );
  default:
    return fwdfn401( state, next_func );
  }
}

static int fwdfn404( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn363;
    return 31;
  } else {
    return fwdfn363( state, next_func );
  }
}

static int fwdfn403( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 1 ) {
    return fwdfn404( state, next_func );
  } else {
    return fwdfn363( state, next_func );
  }
}

static int fwdfn362( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 3 ) {
    return fwdfn403( state, next_func );
  } else {
    return fwdfn363( state, next_func );
  }
}

static int fwdfn405( const state_t *state, void *next_func )
{
  if( state->vars[ 7 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn362;
    return 28;
  } else {
    return fwdfn362( state, next_func );
  }
}

static int fwdfn361( const state_t *state, void *next_func )
{
  if( state->vars[ 6 ] == 3 ) {
    return fwdfn405( state, next_func );
  } else {
    return fwdfn362( state, next_func );
  }
}

static int fwdfn407( const state_t *state, void *next_func )
{
  if( state->vars[ 7 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn363;
    return 29;
  } else {
    return fwdfn363( state, next_func );
  }
}

static int fwdfn406( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return fwdfn407( state, next_func );
  case 1:
    return fwdfn363( state, next_func );
  case 2:
    return fwdfn363( state, next_func );
  default:
    return fwdfn403( state, next_func );
  }
}

static int fwdfn409( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn363;
    return 30;
  } else {
    return fwdfn363( state, next_func );
  }
}

static int fwdfn408( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return fwdfn363( state, next_func );
  case 1:
    return fwdfn409( state, next_func );
  case 2:
    return fwdfn363( state, next_func );
  default:
    return fwdfn403( state, next_func );
  }
}

static int fwdfn360( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return fwdfn361( state, next_func );
  case 1:
    return fwdfn406( state, next_func );
  case 2:
    return fwdfn362( state, next_func );
  default:
    return fwdfn408( state, next_func );
  }
}

static int fwdfn411( const state_t *state, void *next_func )
{
  if( state->vars[ 5 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn360;
    return 27;
  } else {
    return fwdfn360( state, next_func );
  }
}

static int fwdfn410( const state_t *state, void *next_func )
{
  if( state->vars[ 4 ] == 1 ) {
    return fwdfn411( state, next_func );
  } else {
    return fwdfn360( state, next_func );
  }
}

static int fwdfn359( const state_t *state, void *next_func )
{
  if( state->vars[ 3 ] == 3 ) {
    return fwdfn410( state, next_func );
  } else {
    return fwdfn360( state, next_func );
  }
}

static int fwdfn412( const state_t *state, void *next_func )
{
  if( state->vars[ 1 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn359;
    return 24;
  } else {
    return fwdfn359( state, next_func );
  }
}

static int fwdfn358( const state_t *state, void *next_func )
{
  if( state->vars[ 0 ] == 3 ) {
    return fwdfn412( state, next_func );
  } else {
    return fwdfn359( state, next_func );
  }
}

static int fwdfn414( const state_t *state, void *next_func )
{
  if( state->vars[ 1 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn360;
    return 25;
  } else {
    return fwdfn360( state, next_func );
  }
}

static int fwdfn413( const state_t *state, void *next_func )
{
  switch( state->vars[ 3 ] ) {
  case 0:
    return fwdfn414( state, next_func );
  case 1:
    return fwdfn360( state, next_func );
  case 2:
    return fwdfn360( state, next_func );
  default:
    return fwdfn410( state, next_func );
  }
}

static int fwdfn416( const state_t *state, void *next_func )
{
  if( state->vars[ 4 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn360;
    return 26;
  } else {
    return fwdfn360( state, next_func );
  }
}

static int fwdfn415( const state_t *state, void *next_func )
{
  switch( state->vars[ 3 ] ) {
  case 0:
    return fwdfn360( state, next_func );
  case 1:
    return fwdfn416( state, next_func );
  case 2:
    return fwdfn360( state, next_func );
  default:
    return fwdfn410( state, next_func );
  }
}

static int fwdfn357( const state_t *state, void *next_func )
{
  switch( state->vars[ 2 ] ) {
  case 0:
    return fwdfn358( state, next_func );
  case 1:
    return fwdfn413( state, next_func );
  case 2:
    return fwdfn359( state, next_func );
  default:
    return fwdfn415( state, next_func );
  }
}

static int fwdfn434( const state_t *state, void *next_func )
{
  if( state->vars[ 35 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn357;
    return 23;
  } else {
    return fwdfn357( state, next_func );
  }
}

static int fwdfn433( const state_t *state, void *next_func )
{
  if( state->vars[ 34 ] == 1 ) {
    return fwdfn434( state, next_func );
  } else {
    return fwdfn357( state, next_func );
  }
}

static int fwdfn435( const state_t *state, void *next_func )
{
  if( state->vars[ 34 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn357;
    return 22;
  } else {
    return fwdfn357( state, next_func );
  }
}

static int fwdfn432( const state_t *state, void *next_func )
{
  switch( state->vars[ 33 ] ) {
  case 0:
    return fwdfn433( state, next_func );
  case 1:
    return fwdfn435( state, next_func );
  case 2:
    return fwdfn357( state, next_func );
  default:
    return fwdfn357( state, next_func );
  }
}

static int fwdfn437( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn357;
    return 21;
  } else {
    return fwdfn357( state, next_func );
  }
}

static int fwdfn436( const state_t *state, void *next_func )
{
  switch( state->vars[ 33 ] ) {
  case 0:
    return fwdfn433( state, next_func );
  case 1:
    return fwdfn357( state, next_func );
  case 2:
    return fwdfn357( state, next_func );
  default:
    return fwdfn437( state, next_func );
  }
}

static int fwdfn438( const state_t *state, void *next_func )
{
  if( state->vars[ 33 ] == 0 ) {
    return fwdfn433( state, next_func );
  } else {
    return fwdfn357( state, next_func );
  }
}

static int fwdfn440( const state_t *state, void *next_func )
{
  if( state->vars[ 31 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn438;
    return 20;
  } else {
    return fwdfn438( state, next_func );
  }
}

static int fwdfn439( const state_t *state, void *next_func )
{
  if( state->vars[ 30 ] == 0 ) {
    return fwdfn440( state, next_func );
  } else {
    return fwdfn438( state, next_func );
  }
}

static int fwdfn431( const state_t *state, void *next_func )
{
  switch( state->vars[ 32 ] ) {
  case 0:
    return fwdfn432( state, next_func );
  case 1:
    return fwdfn436( state, next_func );
  case 2:
    return fwdfn438( state, next_func );
  default:
    return fwdfn439( state, next_func );
  }
}

static int fwdfn441( const state_t *state, void *next_func )
{
  if( state->vars[ 29 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn431;
    return 19;
  } else {
    return fwdfn431( state, next_func );
  }
}

static int fwdfn430( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 1 ) {
    return fwdfn441( state, next_func );
  } else {
    return fwdfn431( state, next_func );
  }
}

static int fwdfn442( const state_t *state, void *next_func )
{
  if( state->vars[ 28 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn431;
    return 18;
  } else {
    return fwdfn431( state, next_func );
  }
}

static int fwdfn429( const state_t *state, void *next_func )
{
  switch( state->vars[ 27 ] ) {
  case 0:
    return fwdfn430( state, next_func );
  case 1:
    return fwdfn442( state, next_func );
  case 2:
    return fwdfn431( state, next_func );
  default:
    return fwdfn431( state, next_func );
  }
}

static int fwdfn444( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn431;
    return 17;
  } else {
    return fwdfn431( state, next_func );
  }
}

static int fwdfn443( const state_t *state, void *next_func )
{
  switch( state->vars[ 27 ] ) {
  case 0:
    return fwdfn430( state, next_func );
  case 1:
    return fwdfn431( state, next_func );
  case 2:
    return fwdfn431( state, next_func );
  default:
    return fwdfn444( state, next_func );
  }
}

static int fwdfn445( const state_t *state, void *next_func )
{
  if( state->vars[ 27 ] == 0 ) {
    return fwdfn430( state, next_func );
  } else {
    return fwdfn431( state, next_func );
  }
}

static int fwdfn447( const state_t *state, void *next_func )
{
  if( state->vars[ 25 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn445;
    return 16;
  } else {
    return fwdfn445( state, next_func );
  }
}

static int fwdfn446( const state_t *state, void *next_func )
{
  if( state->vars[ 24 ] == 0 ) {
    return fwdfn447( state, next_func );
  } else {
    return fwdfn445( state, next_func );
  }
}

static int fwdfn428( const state_t *state, void *next_func )
{
  switch( state->vars[ 26 ] ) {
  case 0:
    return fwdfn429( state, next_func );
  case 1:
    return fwdfn443( state, next_func );
  case 2:
    return fwdfn445( state, next_func );
  default:
    return fwdfn446( state, next_func );
  }
}

static int fwdfn448( const state_t *state, void *next_func )
{
  if( state->vars[ 23 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn428;
    return 15;
  } else {
    return fwdfn428( state, next_func );
  }
}

static int fwdfn427( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 1 ) {
    return fwdfn448( state, next_func );
  } else {
    return fwdfn428( state, next_func );
  }
}

static int fwdfn449( const state_t *state, void *next_func )
{
  if( state->vars[ 22 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn428;
    return 14;
  } else {
    return fwdfn428( state, next_func );
  }
}

static int fwdfn426( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn427( state, next_func );
  case 1:
    return fwdfn449( state, next_func );
  case 2:
    return fwdfn428( state, next_func );
  default:
    return fwdfn428( state, next_func );
  }
}

static int fwdfn451( const state_t *state, void *next_func )
{
  if( state->vars[ 19 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn428;
    return 13;
  } else {
    return fwdfn428( state, next_func );
  }
}

static int fwdfn450( const state_t *state, void *next_func )
{
  switch( state->vars[ 21 ] ) {
  case 0:
    return fwdfn427( state, next_func );
  case 1:
    return fwdfn428( state, next_func );
  case 2:
    return fwdfn428( state, next_func );
  default:
    return fwdfn451( state, next_func );
  }
}

static int fwdfn452( const state_t *state, void *next_func )
{
  if( state->vars[ 21 ] == 0 ) {
    return fwdfn427( state, next_func );
  } else {
    return fwdfn428( state, next_func );
  }
}

static int fwdfn454( const state_t *state, void *next_func )
{
  if( state->vars[ 19 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn452;
    return 12;
  } else {
    return fwdfn452( state, next_func );
  }
}

static int fwdfn453( const state_t *state, void *next_func )
{
  if( state->vars[ 18 ] == 0 ) {
    return fwdfn454( state, next_func );
  } else {
    return fwdfn452( state, next_func );
  }
}

static int fwdfn425( const state_t *state, void *next_func )
{
  switch( state->vars[ 20 ] ) {
  case 0:
    return fwdfn426( state, next_func );
  case 1:
    return fwdfn450( state, next_func );
  case 2:
    return fwdfn452( state, next_func );
  default:
    return fwdfn453( state, next_func );
  }
}

static int fwdfn455( const state_t *state, void *next_func )
{
  if( state->vars[ 17 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn425;
    return 11;
  } else {
    return fwdfn425( state, next_func );
  }
}

static int fwdfn424( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 1 ) {
    return fwdfn455( state, next_func );
  } else {
    return fwdfn425( state, next_func );
  }
}

static int fwdfn456( const state_t *state, void *next_func )
{
  if( state->vars[ 16 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn425;
    return 10;
  } else {
    return fwdfn425( state, next_func );
  }
}

static int fwdfn423( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn424( state, next_func );
  case 1:
    return fwdfn456( state, next_func );
  case 2:
    return fwdfn425( state, next_func );
  default:
    return fwdfn425( state, next_func );
  }
}

static int fwdfn458( const state_t *state, void *next_func )
{
  if( state->vars[ 13 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn425;
    return 9;
  } else {
    return fwdfn425( state, next_func );
  }
}

static int fwdfn457( const state_t *state, void *next_func )
{
  switch( state->vars[ 15 ] ) {
  case 0:
    return fwdfn424( state, next_func );
  case 1:
    return fwdfn425( state, next_func );
  case 2:
    return fwdfn425( state, next_func );
  default:
    return fwdfn458( state, next_func );
  }
}

static int fwdfn459( const state_t *state, void *next_func )
{
  if( state->vars[ 15 ] == 0 ) {
    return fwdfn424( state, next_func );
  } else {
    return fwdfn425( state, next_func );
  }
}

static int fwdfn461( const state_t *state, void *next_func )
{
  if( state->vars[ 13 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn459;
    return 8;
  } else {
    return fwdfn459( state, next_func );
  }
}

static int fwdfn460( const state_t *state, void *next_func )
{
  if( state->vars[ 12 ] == 0 ) {
    return fwdfn461( state, next_func );
  } else {
    return fwdfn459( state, next_func );
  }
}

static int fwdfn422( const state_t *state, void *next_func )
{
  switch( state->vars[ 14 ] ) {
  case 0:
    return fwdfn423( state, next_func );
  case 1:
    return fwdfn457( state, next_func );
  case 2:
    return fwdfn459( state, next_func );
  default:
    return fwdfn460( state, next_func );
  }
}

static int fwdfn462( const state_t *state, void *next_func )
{
  if( state->vars[ 11 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn422;
    return 7;
  } else {
    return fwdfn422( state, next_func );
  }
}

static int fwdfn421( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 1 ) {
    return fwdfn462( state, next_func );
  } else {
    return fwdfn422( state, next_func );
  }
}

static int fwdfn463( const state_t *state, void *next_func )
{
  if( state->vars[ 10 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn422;
    return 6;
  } else {
    return fwdfn422( state, next_func );
  }
}

static int fwdfn420( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return fwdfn421( state, next_func );
  case 1:
    return fwdfn463( state, next_func );
  case 2:
    return fwdfn422( state, next_func );
  default:
    return fwdfn422( state, next_func );
  }
}

static int fwdfn465( const state_t *state, void *next_func )
{
  if( state->vars[ 7 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn422;
    return 5;
  } else {
    return fwdfn422( state, next_func );
  }
}

static int fwdfn464( const state_t *state, void *next_func )
{
  switch( state->vars[ 9 ] ) {
  case 0:
    return fwdfn421( state, next_func );
  case 1:
    return fwdfn422( state, next_func );
  case 2:
    return fwdfn422( state, next_func );
  default:
    return fwdfn465( state, next_func );
  }
}

static int fwdfn466( const state_t *state, void *next_func )
{
  if( state->vars[ 9 ] == 0 ) {
    return fwdfn421( state, next_func );
  } else {
    return fwdfn422( state, next_func );
  }
}

static int fwdfn468( const state_t *state, void *next_func )
{
  if( state->vars[ 7 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn466;
    return 4;
  } else {
    return fwdfn466( state, next_func );
  }
}

static int fwdfn467( const state_t *state, void *next_func )
{
  if( state->vars[ 6 ] == 0 ) {
    return fwdfn468( state, next_func );
  } else {
    return fwdfn466( state, next_func );
  }
}

static int fwdfn419( const state_t *state, void *next_func )
{
  switch( state->vars[ 8 ] ) {
  case 0:
    return fwdfn420( state, next_func );
  case 1:
    return fwdfn464( state, next_func );
  case 2:
    return fwdfn466( state, next_func );
  default:
    return fwdfn467( state, next_func );
  }
}

static int fwdfn469( const state_t *state, void *next_func )
{
  if( state->vars[ 5 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn419;
    return 3;
  } else {
    return fwdfn419( state, next_func );
  }
}

static int fwdfn418( const state_t *state, void *next_func )
{
  if( state->vars[ 4 ] == 1 ) {
    return fwdfn469( state, next_func );
  } else {
    return fwdfn419( state, next_func );
  }
}

static int fwdfn470( const state_t *state, void *next_func )
{
  if( state->vars[ 4 ] == 3 ) {
    *((funcptr *)next_func) = fwdfn419;
    return 2;
  } else {
    return fwdfn419( state, next_func );
  }
}

static int fwdfn417( const state_t *state, void *next_func )
{
  switch( state->vars[ 3 ] ) {
  case 0:
    return fwdfn418( state, next_func );
  case 1:
    return fwdfn470( state, next_func );
  case 2:
    return fwdfn419( state, next_func );
  default:
    return fwdfn419( state, next_func );
  }
}

static int fwdfn472( const state_t *state, void *next_func )
{
  if( state->vars[ 1 ] == 0 ) {
    *((funcptr *)next_func) = fwdfn419;
    return 1;
  } else {
    return fwdfn419( state, next_func );
  }
}

static int fwdfn471( const state_t *state, void *next_func )
{
  switch( state->vars[ 3 ] ) {
  case 0:
    return fwdfn418( state, next_func );
  case 1:
    return fwdfn419( state, next_func );
  case 2:
    return fwdfn419( state, next_func );
  default:
    return fwdfn472( state, next_func );
  }
}

static int fwdfn473( const state_t *state, void *next_func )
{
  if( state->vars[ 3 ] == 0 ) {
    return fwdfn418( state, next_func );
  } else {
    return fwdfn419( state, next_func );
  }
}

static int fwdfn475( const state_t *state, void *next_func )
{
  if( state->vars[ 1 ] == 1 ) {
    *((funcptr *)next_func) = fwdfn473;
    return 0;
  } else {
    return fwdfn473( state, next_func );
  }
}

static int fwdfn474( const state_t *state, void *next_func )
{
  if( state->vars[ 0 ] == 0 ) {
    return fwdfn475( state, next_func );
  } else {
    return fwdfn473( state, next_func );
  }
}

static int fwdfn0( const state_t *state, void *next_func )
{
  switch( state->vars[ 2 ] ) {
  case 0:
    return fwdfn417( state, next_func );
  case 1:
    return fwdfn471( state, next_func );
  case 2:
    return fwdfn473( state, next_func );
  default:
    return fwdfn474( state, next_func );
  }
}


#define init_history 0

#define max_fwd_children 120

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


/* returns 1 if state is a goal state, 0 otherwise */
static int is_goal( const state_t *state )
{
  if( state->vars[ 25 ] == 1 && state->vars[ 26 ] == 1 ) {
    return 1;
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




