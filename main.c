#include <stdio.h>
#include <string.h>

#include "root_func/root.h"
#include "integral_func/integral.h"
#include "asm_func/functions.h"
#include "test_func/test.h"    // <-- теперь так

unsigned iter_cnt = 0;

static const char *help_message =
    "Usage: program [options]\n"
    "  -help    Show this help message\n"
    "  -r       Print coordinates of the roots\n"
    "  -i       Print iteration counts for each root\n"
    "  -test    Run all internal tests\n";

int main(int argc, char **argv) {
    int print_roots = 0;
    int print_iters = 0;
    unsigned i1 = 0, i2 = 0, i3 = 0;
    const double eps1 = 1e-5;
    const double eps2 = 1e-5;

    /* Разбор ключей */
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-help") == 0) {
            printf("%s", help_message);
            return 0;
        }
        else if (strcmp(argv[i], "-r") == 0) {
            print_roots = 1;
        }
        else if (strcmp(argv[i], "-i") == 0) {
            print_iters = 1;
        }
        else if (strcmp(argv[i], "-test") == 0) {
            test();      // <-- вызываем тесты из test_func/test.h
            return 0;
        }
        else {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            return 1;
        }
    }

    /* 1) Находим точки пересечения */
    const double left  = 0.0;
    const double right = 4.0;

    double x12 = root(f1, f2, left,  right, eps1); i1 = iter_cnt;
    double x13 = root(f1, f3, left,  right, eps1); i2 = iter_cnt;
    double x23 = root(f2, f3, left,  right, eps1); i3 = iter_cnt;

    /* При запросе выводим корни и/или счётчики */
    if (print_roots) {
        printf("Root f1=f2: %.6f\n", x12);
        printf("Root f1=f3: %.6f\n", x13);
        printf("Root f2=f3: %.6f\n", x23);
    }
    if (print_iters) {
        printf("Iterations for f1=f2: %u\n", i1);
        printf("Iterations for f1=f3: %u\n", i2);
        printf("Iterations for f2=f3: %u\n", i3);
    }
    if (print_roots || print_iters) {
        putchar('\n');
    }

    /* 2) Вычисляем площадь */
    double I1 = integral(f1, x13, x12, eps2);
    double I2 = integral(f2, x23, x12, eps2);
    double I3 = integral(f3, x13, x23, eps2);
    double area = I1 - I2 - I3;

    printf("Counted area = %.3f\n", area);
    return 0;
}
