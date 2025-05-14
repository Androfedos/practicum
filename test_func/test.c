// test_func/test.c
#include <stdio.h>
#include <math.h>

#include "root_func/root.h"
#include "integral_func/integral.h"
#include "test_func/test.h"

// НЕ подцепляем здесь "asm_func/functions.h"

static double f1(double x) { return x*x - 2.0; }
static double f2(double x) { return sin(x); }
static double f3(double x) { return exp(x) - x*x; }

void test(void) {
    double a = 0.5, b = 3.0, cross;

    cross = root(f1, f2, a, b, 1e-3);
    printf("f1=f2: x = %.6f\n", cross);

    cross = root(f1, f3, a, b, 1e-3);
    printf("f1=f3: x = %.6f\n", cross);

    cross = root(f2, f3, a, b, 1e-3);
    printf("f2=f3: x = %.6f\n", cross);

    double I1 = integral(f1, a, b, 1e-3);
    printf("∫f1 = %.6f\n", I1);
    double I2 = integral(f2, a, b, 1e-3);
    printf("∫f2 = %.6f\n", I2);
    double I3 = integral(f3, a, b, 1e-3);
    printf("∫f3 = %.6f\n", I3);
}
