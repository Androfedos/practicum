#ifndef INTEGRAL_H_INCLUDED
#define INTEGRAL_H_INCLUDED

/**  
 * Вычисляет интеграл функции f на [a,b] с точностью eps  
 */ 
double integral(double (*f)(double), double a, double b, double eps);

#endif // INTEGRAL_H_INCLUDED
