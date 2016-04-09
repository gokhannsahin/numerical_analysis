#include "bisection_core.h" 
#include "functions_objective.h"
#include "newton_function.h"

// 
// newton_method
// 
// returns:
//  0 : normal return (no warnings)
// -1 : initial interval not valid
// -2 : maximum no of iterations reached (not converged)
// 
int newton_method(const BisectionOptions * ptr_opt, SolnIterates * soln)
{
	int flag = -99; // invalid value
	BisectionOptions opt = *ptr_opt;
	IntervalInfo interval;
	double result;
	const SolnLList *last;

	// initialize interval and check validity of end-points
	interval.mid.x0 = opt.x0;
	interval.mid.diffx0 = opt.diffx0;
	interval.mid.fx0 = opt.fx0;
	interval.mid.x1 = opt.x1;
	// now iterate
	while (size(soln) < opt.maxIter)
	{
		interval.mid.fx0 = func_bias_diode(interval.mid.x0);
		interval.mid.diffx0 = func_bias_diode_diff(interval.mid.x0,differentiation);
		interval.mid.x1 = interval.mid.x0 - (interval.mid.fx0 / interval.mid.diffx0);

		if (size(soln) <= 0)
		{
			// there is no data yet, initialize the linked list with the first arriving data
			append(soln, interval.mid, 0.0, 0.0);
		}
		else
		{
			last = getLast(soln);
			result = fabs(last->point.x1 - interval.mid.x1);
			printf("  |Ea| degeri   %.20e\n0",result/last->point.x1 );
			if (result < 1e-25)
			{
				printf("Soln found in %d iterations.\n", size(soln));
				flag = 0;
				break;
			}
			append(soln, interval.mid, interval.mid.x1, result);
		}
		printf("Iteration %d\n", size(soln));
		printf("  The soln is   %.20e\n", interval.mid.x1);
		interval.mid.x0 = interval.mid.x1;
	}
	// check if soln found and issue warning
	if (flag != 0)
	{
		printf(
				"A satisfactory soln could not be computed. Maximum number of iterations reached...\n");
		flag = -2;
	}

	return flag;
}
