#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>
#include "kvadratka.h"
#include "test.h"


int main (int argc, char *argv[]) {
    Roots var_roots = {};
    Coefficients var_coef = {};

    printf ("Ёто программа решающа€ квадратные уравнени€ (ax^2 + bx + c = 0).\n");

    int type_mode = test_mode();

    int nRoots = 0;

    if (type_mode == SQUARE)
    {
        input_square (&var_coef);
        nRoots = solve_dispetcher (&var_coef, &var_roots);
        print_roots (nRoots, &var_roots);
    }
    else
    {
        test(argv);
    }

    return 0;
}
