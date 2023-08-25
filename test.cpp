#include "kvadratka.h"
#include "test.h"
#include "Error.h"
#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>


void data (Coefficients* var_coef, Test_data_roots* data_roots, FILE *fp) {

    assert (var_coef != NULL);
    assert (data_roots != NULL);
    assert (fp != NULL);

    while (fscanf (fp, "%lg %lg %lg, %lg, %lg, %d", &var_coef->a, &var_coef->b, &var_coef->c, &data_roots->x1Ref, &data_roots->x2Ref, &data_roots->nRootsRef) != 6)
    {
        clean_buffer ();
        printf ("В файле допущена ошибка при считываниии коэффициентов и правильных корней");
    }
    printf("%lg", var_coef->a);
}

int test (const char *filename) {

    assert (filename != NULL);

    Test_data_roots data_roots = {};
    Roots var_roots = {};
    Coefficients var_coef = {};

    FILE *fp = fopen (filename, "r");

    if (fp == NULL)
    {
        printf("fopen");
        return error_fopen;
    }

    int test_success = 0;

    for (int i = 0; i < TESTS_CNT; i++)
    {
        printf("1");
        data (&var_coef, &data_roots, fp);
        printf("2");
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
        printf("fclose");
        return error_fclose;
    }

    return 0;
}

int test_solve_square (Coefficients* var_coef, Test_data_roots* data_roots, Roots* var_roots) {

    assert (var_coef != NULL);
    assert (data_roots != NULL);
    assert (var_roots != NULL);

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
