/*
 * newton_function.c
 *
 *  Created on: 21 Kas 2015
 *      Author: Gokhan Sahin
 */
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define diff (double)0.0000001

double differentiation (double x){

	  double R   = 1e3;
	  double IS  = 3e-15;
	  double VIN = 3.3;
	  double VT  = 25e-3;

      return VT*log((VIN - x)/(R*IS))-x;
}

double func_bias_diode_diff(double x,double(*f)(double)){
      return (double)((f(x+diff)-f(x))/diff);
}


