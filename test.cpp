#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>
#include "kvadratka.h"
#include "test.h"

void data (Coefficients* var_coef, Test_data_roots* data_roots, FILE *fp) {
    while (fscanf (fp, "%lg %lg %lg, %lg, %lg, %d", &var_coef->a, &var_coef->b, &var_coef->c, &data_roots->x1Ref, &data_roots->x2Ref, &data_roots->nRootsRef) != 6)
    {
        clean_buffer ();
        printf ("В файле допущена ошибка при считываниии коэффициентов и правильных корней");
    }
}

// TODO only filename
int test (char **argv) {

    Test_data_roots data_roots = {};
    Roots var_roots = {};
    Coefficients var_coef = {};

    FILE *fp = fopen (argv[1], "r");

    if (fp == NULL)
    {
        printf ("Ошибка при открытии файла");
    }

    int test_success = 0;

    for (int i = 0; i < TESTS_CNT; i++)
    {
        data (&var_coef, &data_roots, fp);
        test_success += test_solve_square (&var_coef, &data_roots, &var_roots);
    }

    if (test_success == TESTS_CNT) {
        printf ("Тестирование прошло успешно\n");
    }
    else {
        printf ("Где-то допущена ошибка\n");
    }

    if (fclose (fp) != 0)
    {
        printf ("Ошибка при закрытии файла");
    }

    return test_success;
}

int test_solve_square (Coefficients* var_coef, Test_data_roots* data_roots, Roots* var_roots) {
    int nRoots = solve_dispetcher (var_coef, var_roots);

    if (compare_number(nRoots, data_roots->nRootsRef) || compare_number(var_roots->x1, data_roots->x1Ref) || compare_number(var_roots->x2, data_roots->x2Ref)) {
        printf ("ERROR: x1 = %lg, x2 = %lg, nRoots = %d, exected: x1Ref = %lg, x2Ref = %lg, nRootsRef = %d\n",
            var_roots->x1, var_roots->x2, nRoots, data_roots->x1Ref, data_roots->x2Ref, data_roots->nRootsRef);

        return 0;
    }
    else {
        printf ("Test-OK\n");

        return 1;
    }
}
