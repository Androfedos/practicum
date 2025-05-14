#include <stdio.h>
#include <math.h>


extern unsigned iter_cnt;  

/* �������� ��� ������ ����� f1(x) - f2(x) = 0 �� [a,b] */
double root(
    double (*f1)(double),
    double (*f2)(double),
    double a,
    double b,
    double eps1
) {
    iter_cnt = 0;
    double fa = f1(a) - f2(a);
    double fb = f1(b) - f2(b);
    if (fa * fb > 0.0) return NAN;  /* ��� �������� ����� */

    while ((b - a) / 2.0 > eps1) {
        ++iter_cnt;
        double m  = 0.5 * (a + b);
        double fm = f1(m) - f2(m);
        if (fabs(fm) < eps1) return m;
        if (fa * fm <= 0.0) {
            b  = m;  fb = fm;
        } else {
            a  = m;  fa = fm;
        }
    }
    return 0.5 * (a + b);
}

