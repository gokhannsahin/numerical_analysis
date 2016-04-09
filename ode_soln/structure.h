#ifndef STRUCTURE_H_
#define STRUCTURE_H_

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct ode_equation__
{
	FILE *ptr_file;
	int a;
	int B;
	int C;
	int D;
	float w;
	int q;
	float T;
	float N;
	double initValue;
	double dt;
	double *t;
	double *ut;
	double *ptr;
	double *solve;
} ode_equation_;

#ifdef __cplusplus
}
#endif
#endif /* STRUCTURE_H_ */
