#include<stdio.h>

#include "functions_objective.h"
#include "bisection_options.h"
#include "bisection_internals.h"
#include "bisection_core.h"
#include "newton_function.h"

int main (void)
{
  BisectionOptions  opt_log ;
  SolnIterates      soln;
  SolnLList        *cptr;
  unsigned int flag;
  unsigned int cnt;

  opt_log.fptr = func_bias_diode;
  opt_log.diffptr = func_bias_diode_diff;
  opt_log.diffx0  = 0;
  opt_log.fx0 = 0;
  opt_log.x0 = 2.8;
  opt_log.x1 = 0;
  opt_log.maxIter = 50;

  // initialize soln
  initialize(&soln);

  // run
  flag = newton_method( &opt_log , &soln );
  printf("\nNo of iterations (length of soln array) : %d\n",size(&soln));

  if ( (flag == 0) || (flag == -2) )
    {
      if (size(&soln) > 0)
      {
        printf("\nValues and Function Values\n\n");
        cnt = 0;
        cptr = soln.llist;
        while ( cptr != NULL )
        {
          cnt++;
          printf
          ( "Iter %d : %.16e %.16e\n" , cnt ,
            cptr->point.x0, cptr->point.x1
          );
          cptr = cptr->next;
        }

        printf("\nErrors in Values and Function Values\n\n");
        cnt = 0;
        cptr = soln.llist;
        while ( cptr != NULL )
        {
          cnt++;
          printf
          ( "Iter %d : %.16e %.16e\n" , cnt ,
            cptr->err_x , cptr->err_f
          );
          cptr = cptr->next;
        }
      }
    }

  destroy(&soln);

  return 0;
}
