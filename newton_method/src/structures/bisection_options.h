#ifndef BISECTION_OPTIONS_H_
#define BISECTION_OPTIONS_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BisectionOptions_
{
  double (*fptr)(double);
  double (*diffptr) (double);
  
  double x0 , fx0 , diffx0, x1;
  
  unsigned 
  int maxIter;
}BisectionOptions;

#ifdef __cplusplus
}
#endif

#endif
