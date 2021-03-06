/*
 * File: USART_IT_F302R8_00.c
 *
 * Generated by STM32 Coder for Xcos with scilab-5.5.2
 * C/C++ source code generated on  :05-Oct-2020
 *
 * Model version      : 1.0
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

/* ---- Headers ---- */
#include <string.h> // memcpy
#include "STM32_Config.h"

#include "scicos_block4.h"

#include "USART_IT_F302R8_00.h"

double get_scicos_time(void);
void set_scicos_time(double t);
int get_phase_simulation(void);
void assert_sci_failed(const char* e, const char* file, int line){}

 
#define max(a,b) ((a) >= (b) ? (a) : (b))
#define min(a,b) ((a) <= (b) ? (a) : (b))
 
/* Table of constant values passed by ref */
static const int nrd_0 = 0;
static const int nrd_1 = 1;
static const int nrd_10 = 10;
static const int nrd_11 = 11;
static const int nrd_81 = 81;
static const int nrd_82 = 82;
static const int nrd_84 = 84;
static const int nrd_811 = 811;
static const int nrd_812 = 812;
static const int nrd_814 = 814;

/* Some general static variables passed by ref */
static int aaa=0, bbb=0;

/* data shared ptr declaration */
void **work;
void **USART_IT_F302R8_00_block_outtbptr;
scicos_block block_USART_IT_F302R8_00;
/* Dumy variable not used in embedded word but necessary for current version based on PC scicos C functions */
int local_flag=4; //Set to initialization
double t; //Simulation time (not used)

double sci_time;

const int size_SCSREAL_N_1x1[] = {1, 1, SCSREAL_N};

const double RPAR1[1] = {0.0};
const int IPAR1[1] = {0};
/* def object parameters */
/*
 * Routine name of block: cstblk4_m
 * UID of block: -5f95c7d:1566ea22c33:-7ecc
 * Compiled structure index: 1
 */
static float OPAR_1[] = {4};

/* Initial values */

/* Note that z[]=[z_initial_condition;outtbptr;work]
    z_initial_condition={};
    outtbptr={0};
    work= {0,0};
  */

   double z[]={0,0,0};

  int evoutptr[1];
  void* outptr[1];
  int outszptr[3*1];


  /* outtb declaration */
  float outtb_1[1]={0};

/*----------------------------------------  Initialization function */
int USART_IT_F302R8_00_Initialize()
{
  int nevprt=1;
  int nport;


  /* Get work ptr of blocks */
  work = (void **)(z+1);

  /* Get outtbptr ptr of blocks */
  USART_IT_F302R8_00_block_outtbptr = (void **)(z+0);

  USART_IT_F302R8_00_block_outtbptr[0] = (void *) outtb_1;

  /* Initialization */

  /* Call of 'cstblk4_m' (type 4 - blk nb 1 - uid ) */
  { 
    /* set blk struc. of 'cstblk4_m' (type 4 - blk nb 1 - uid ) */
    block_USART_IT_F302R8_00.type   = 4;
    block_USART_IT_F302R8_00.ztyp   = 0;
    block_USART_IT_F302R8_00.ng     = 0;
    block_USART_IT_F302R8_00.nz     = 0;
    block_USART_IT_F302R8_00.noz    = 0;
    block_USART_IT_F302R8_00.nrpar  = 0;
    block_USART_IT_F302R8_00.nopar  = 1;
    block_USART_IT_F302R8_00.nipar  = 0;
    block_USART_IT_F302R8_00.nin    = 0;
    block_USART_IT_F302R8_00.nout   = 1;
    block_USART_IT_F302R8_00.nevout = 0;
    block_USART_IT_F302R8_00.nmode  = 0;
    block_USART_IT_F302R8_00.evout = NULL;
    block_USART_IT_F302R8_00.inptr  = inptr;
    block_USART_IT_F302R8_00.insz = NULL;
    block_USART_IT_F302R8_00.outptr = outptr;
    block_USART_IT_F302R8_00.outptr[0] = USART_IT_F302R8_00_block_outtbptr[0];
    block_USART_IT_F302R8_00.outsz = outszptr;
    block_USART_IT_F302R8_00.outsz[0]  = 1;
    block_USART_IT_F302R8_00.outsz[1]  = 1;
    block_USART_IT_F302R8_00.outsz[2]  = SCSREAL_N;
    block_USART_IT_F302R8_00.z = &(z[0]);
    if ((block_USART_IT_F302R8_00.oparptr = malloc(sizeof(void *)*block_USART_IT_F302R8_00.nopar))== NULL ) return 0;
    if ((block_USART_IT_F302R8_00.oparsz  = malloc(2*sizeof(int)*block_USART_IT_F302R8_00.nopar))== NULL ) return 0;
    if ((block_USART_IT_F302R8_00.opartyp = malloc(sizeof(int)*block_USART_IT_F302R8_00.nopar))== NULL ) return 0;
    block_USART_IT_F302R8_00.oparptr[0]   = (void *) OPAR_1;
    block_USART_IT_F302R8_00.oparsz[0]    = 1;
    block_USART_IT_F302R8_00.oparsz[1]    = 1;
    block_USART_IT_F302R8_00.opartyp[0]   = SCSREAL_N;
    block_USART_IT_F302R8_00.work = (void **)(((double *)work)+0);
  }
  cstblk4_m(&block_USART_IT_F302R8_00,4);
  {
    free(block_USART_IT_F302R8_00.oparptr);
    free(block_USART_IT_F302R8_00.oparsz);
    free(block_USART_IT_F302R8_00.opartyp);
  }

    /* Initial blocks must be called with flag 1 */
    /* Call of 'cstblk4_m' (type 4 - blk nb 1 - uid ) */
    { 
      /* set blk struc. of 'cstblk4_m' (type 4 - blk nb 1 - uid ) */
      block_USART_IT_F302R8_00.type   = 4;
      block_USART_IT_F302R8_00.ztyp   = 0;
      block_USART_IT_F302R8_00.ng     = 0;
      block_USART_IT_F302R8_00.nz     = 0;
      block_USART_IT_F302R8_00.noz    = 0;
      block_USART_IT_F302R8_00.nrpar  = 0;
      block_USART_IT_F302R8_00.nopar  = 1;
      block_USART_IT_F302R8_00.nipar  = 0;
      block_USART_IT_F302R8_00.nin    = 0;
      block_USART_IT_F302R8_00.nout   = 1;
      block_USART_IT_F302R8_00.nevout = 0;
      block_USART_IT_F302R8_00.nmode  = 0;
      block_USART_IT_F302R8_00.evout = NULL;
      block_USART_IT_F302R8_00.inptr  = inptr;
      block_USART_IT_F302R8_00.insz = NULL;
      block_USART_IT_F302R8_00.outptr = outptr;
      block_USART_IT_F302R8_00.outptr[0] = USART_IT_F302R8_00_block_outtbptr[0];
      block_USART_IT_F302R8_00.outsz = outszptr;
      block_USART_IT_F302R8_00.outsz[0]  = 1;
      block_USART_IT_F302R8_00.outsz[1]  = 1;
      block_USART_IT_F302R8_00.outsz[2]  = SCSREAL_N;
      block_USART_IT_F302R8_00.z = &(z[0]);
      if ((block_USART_IT_F302R8_00.oparptr = malloc(sizeof(void *)*block_USART_IT_F302R8_00.nopar))== NULL ) return 0;
      if ((block_USART_IT_F302R8_00.oparsz  = malloc(2*sizeof(int)*block_USART_IT_F302R8_00.nopar))== NULL ) return 0;
      if ((block_USART_IT_F302R8_00.opartyp = malloc(sizeof(int)*block_USART_IT_F302R8_00.nopar))== NULL ) return 0;
      block_USART_IT_F302R8_00.oparptr[0]   = (void *) OPAR_1;
      block_USART_IT_F302R8_00.oparsz[0]    = 1;
      block_USART_IT_F302R8_00.oparsz[1]    = 1;
      block_USART_IT_F302R8_00.opartyp[0]   = SCSREAL_N;
      block_USART_IT_F302R8_00.work = (void **)(((double *)work)+0);
    }
    cstblk4_m(&block_USART_IT_F302R8_00,1);
    cstblk4_m(&block_USART_IT_F302R8_00,2);
    {
      free(block_USART_IT_F302R8_00.oparptr);
      free(block_USART_IT_F302R8_00.oparsz);
      free(block_USART_IT_F302R8_00.opartyp);
    }


    /* Dumy variable not used in embedded word but necessary for current version based on PC scicos C functions*/
    /* local_flag set to output update */
    local_flag = 1;
    double t; //Simulation time (not used)
return(1);
} //End of function USART_IT_F302R8_00_Initialize()
/*----------------------------------------  Step function */
void USART_IT_F302R8_00_Step()
{
  // double t;
  int nevprt=1;
  // int local_flag = 1; //Output update
  int nport;

/*---------------continuous activation state */
/*---------------STM32 block(s) without activation state  */
/*---------------STM32 solver step: NoEvt NoIn NoOut*/
/*---------------STM32 solver step: NoEvt NoIn Out*/
/*---------------STM32 solver step: NoEvt In Out*/
/*---------------STM32 solver step: NoEvt In NoOut*/
/*---------------FLAG: 1  */

  } //End of USART_IT_F302R8_00_Step1 function


double get_scicos_time()
{
  return sci_time;
}

void set_scicos_time(double t)
{
 sci_time = t;
}

int get_phase_simulation()
{
  return 1;
}



void set_block_error(int err)
{
  return;
}

void * scicos_malloc(size_t size)
{
  return malloc(size);
}

void scicos_free(void *p)
{
  free(p);
}

void do_cold_restart()
{
  return;
}

void sciprint (char *fmt)
{
  return;
}

