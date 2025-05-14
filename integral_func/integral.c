#include <stdio.h>
#include <math.h>

/* Метод прямоугольников для интеграла ∫_a^b f(x) dx с точностью esp2 */
double integral(
    double (*f)(double),
    double a,
    double b,
    double esp2
) {
    int n = 1;
    double h = b - a;
    double I_old = f(a) * h;
    double I_new;

    for (;;) {
        n <<= 1;
        h = (b - a) / n;
        I_new = 0.0;
        for (int i = 0; i < n; ++i) {
            I_new += f(a + i * h) * h;
        }
        if (fabs(I_new - I_old) < esp2) break;
        I_old = I_new;
    }
    return I_new;
}

