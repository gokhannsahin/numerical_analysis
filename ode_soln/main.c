/*
 * main.c
 *
 * Created on: 14 Ara 2015
 * Author: Gokhan Sahin
 */
#include <stdio.h>
#include "structure.h"
#include "math.h"

#define M_PI 3.14159265358979323846
#define ut1 0 // u(t) = B
#define ut2 1 // u(t) = C*exp(q*t)
#define ut3 0 // u(t) = D*sin(w*t)
int guejkfd;
void forward_eular (struct ode_equation__ *ode_eq);
void backward_eular (struct ode_equation__ *ode_eq);
void trapezoidal (struct ode_equation__ *ode_eq);
int main(void)
{
	int i;
	int j;
	struct ode_equation__ *ode_equation = malloc(sizeof(struct ode_equation__));
	ode_equation->ptr_file = fopen("output.txt", "w");
	if (!ode_equation->ptr_file)
		printf("txt is not created...");
	ode_equation->T = 10;
	ode_equation->N = 51;
	ode_equation->initValue = 5.0;
	ode_equation->a = -1e0;
	ode_equation->B = 2.0;
	ode_equation->C = 2;
	ode_equation->D = 2;
	ode_equation->w = 2 * M_PI * 1;
	ode_equation->q = -2;
	ode_equation->t = malloc(ode_equation->N * sizeof(double));
	ode_equation->ptr = malloc(ode_equation->N * sizeof(double));
	ode_equation->ut = malloc(ode_equation->N * sizeof(double));
	ode_equation->dt = (ode_equation->T / (ode_equation->N - 1));
	printf("dt zamaný = %.5e\n", ode_equation->dt);
	*ode_equation->t = 0;
	printf("t[0] zaman domaini = %.5e\n", ode_equation->t);
	fprintf(ode_equation->ptr_file, "%.5e\n", *ode_equation->t);
	for (i = 1; i < ode_equation->N; i++)
	{
		*(ode_equation->t + i) = *(ode_equation->t + i - 1) + ode_equation->dt;
		printf("t[%d] zaman domaini = %.5e\n", i, *(ode_equation->t + i));
		fprintf(ode_equation->ptr_file, "%.5e\n", *(ode_equation->t + i));
	}
	*ode_equation->ptr = ode_equation->initValue;
#if ut1
	for (i=0;i<ode_equation->N;i++)
	Page 1
	main.c
	*(ode_equation->ut+i) = ode_equation->B;
	printf("Forward Eular Sonucu y[0] = %.5e\n",*ode_equation->ptr);
	forward_eular(ode_equation);
	printf("Backward Eular Sonucu y[0] = %.5e\n",*ode_equation->ptr);
	backward_eular(ode_equation);
	printf("Trapezoidal Sonucu y[0] = %.5e\n",*ode_equation->ptr);
	trapezoidal(ode_equation);
#endif
#if ut2
	for (i=0;i<ode_equation->N;i++)
	*(ode_equation->ut+i) = ode_equation->C * exp(ode_equation->q*(*
					(ode_equation->t+i)));
	printf("Forward Eular Sonucu y[0] = %.5e\n",*ode_equation->ptr);
	forward_eular(ode_equation);
	printf("Backward Eular Sonucu y[0] = %.5e\n",*ode_equation->ptr);
	backward_eular(ode_equation);
	printf("Trapezoidal Sonucu y[0] = %.5e\n",*ode_equation->ptr);
	trapezoidal(ode_equation);
#endif
#if ut3
	ode_equation->a = -1e-5;
	for (i=0;i<ode_equation->N;i++)
	*(ode_equation->ut+i) = ode_equation->D * sin(ode_equation->w*(*
					(ode_equation->t+i)));
	printf("Forward Eular Sonucu y[0] = %.5e\n",*ode_equation->ptr);
	forward_eular(ode_equation);
	printf("Backward Eular Sonucu y[0] = %.5e\n",*ode_equation->ptr);
	backward_eular(ode_equation);
	printf("Trapezoidal Sonucu y[0] = %.5e\n",*ode_equation->ptr);
	trapezoidal(ode_equation);
#endif
	fclose(ode_equation->ptr_file);
	free(ode_equation);
	free(ode_equation->t);
	free(ode_equation->ut);
	free(ode_equation->ptr);
	return 0;
}
