/*
 * functions.c
 *
 * Created on: 15 Ara 2015
 * Author: Gokhan Sahin
 */
#include <stdio.h>
#include "structure.h"

void forward_eular(struct ode_equation__ *ode_eq)
{
	static int i;
	fprintf(ode_eq->ptr_file, "%.5e\n", *(ode_eq->ptr));
	for (i = 1; i < ode_eq->N; i++)
	{
		*(ode_eq->ptr + i) = (1 + ode_eq->a * ode_eq->dt)
				* (*(ode_eq->ptr + i - 1))
				+ (ode_eq->dt * (*(ode_eq->ut + i - 1)));
		printf("Forward Eular Sonucu y[%d] = %.5e\n", i, *(ode_eq->ptr + i));
		fprintf(ode_eq->ptr_file, "%.5e\n", *(ode_eq->ptr + i));
	}
}
void backward_eular(struct ode_equation__ *ode_eq)
{
	static int i;
	fprintf(ode_eq->ptr_file, "%.5e\n", *(ode_eq->ptr));
	for (i = 1; i < ode_eq->N; i++)
	{
		*(ode_eq->ptr + i) = (1 / (1 - (ode_eq->a * ode_eq->dt)))
				* (*(ode_eq->ptr + i - 1))
				+ (ode_eq->dt / (1 - (ode_eq->a * ode_eq->dt))
						* (*(ode_eq->ut + i)));
		printf("Backward Eular Sonucu y[%d] = %.5e\n", i, *(ode_eq->ptr + i));
		fprintf(ode_eq->ptr_file, "%.5e\n", *(ode_eq->ptr + i));
	}
}
void trapezoidal(struct ode_equation__ *ode_eq)
{
	static int i;
	fprintf(ode_eq->ptr_file, "%.5e\n", *(ode_eq->ptr));
	for (i = 1; i < ode_eq->N; i++)
	{
		*(ode_eq->ptr + i) = (1 + ode_eq->a * ode_eq->dt / 2)
				/ (1 - ode_eq->a * ode_eq->dt / 2) * (*(ode_eq->ptr + i - 1))
				+ (ode_eq->dt / (2 * (1 - ode_eq->a * ode_eq->dt / 2)))
						* (*(ode_eq->ut + i) + *(ode_eq->ut + i - 1));
		printf("Trapezoidal Sonucu y[%d] = %.5e\n", i, *(ode_eq->ptr + i));
		fprintf(ode_eq->ptr_file, "%.5e\n", *(ode_eq->ptr + i));
	}
}
