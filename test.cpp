#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>
#include "kvadratka.h"
#include "test.h"

#if 1

void data_coef (Coefficients* var_coef, FILE *fp) {
    fscanf (fp, "%lg %lg %lg", &var_coef->a, &var_coef->b, &var_coef->c);
    /*while (fscanf (stdin, "%lg %lg %lg", &var_coef->a, &var_coef->b, &var_coef->c) != 3)
    {
        clean_buffer();
        printf ("В файле допущена ошибка при считываниии коэффициентов");
    }*/
}

void data_roots_test (Test_data_roots* data_roots, FILE *fp) {
    fscanf (fp, "%lg %lg %d", &data_roots->x1Ref, &data_roots->x2Ref, &data_roots->nRootsRef);
    /*while (fscanf (stdin, "%lg %lg %d", &data_roots->x1Ref, &data_roots->x2Ref, &data_roots->nRootsRef) != 3)
    {
        clean_buffer();
        printf ("В файле допущена ошибка при считывании правильных корней");
    }*/
}

int test (char *argv[]) {

    Test_data_roots data_roots = {};
    Roots var_roots = {};
    Coefficients var_coef = {};

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Ошибка при открытии файла");
    }

    int test_success = 0;

    for (int i = 0; i < TESTS_CNT; i++)
    {
        data_coef (&var_coef, fp);
        data_roots_test (&data_roots, fp);
        test_success += test_solve_square(&var_coef, &data_roots, &var_roots);
    }

    if (test_success == TESTS_CNT) {
        printf("Тестирование прошло успешно\n");
    }
    else {
        printf("Где-то допущена ошибка\n");
    }

    if (fclose(fp) != 0)
    {
        printf("Ошибка при закрытии файла");
    }

    return test_success;
}

int test_solve_square (Coefficients* var_coef, Test_data_roots* data_roots, Roots* var_roots) {
    int nRoots = solve_dispetcher (var_coef, var_roots);

    if (compair_number(nRoots, data_roots->nRootsRef) || compair_number(var_roots->x1, data_roots->x1Ref) || compair_number(var_roots->x2, data_roots->x2Ref)) {
        printf ("ERROR: x1 = %lg, x2 = %lg, nRoots = %d, exected: x1Ref = %lg, x2Ref = %lg, nRootsRef = %d\n",
            var_roots->x1, var_roots->x2, nRoots, data_roots->x1Ref, data_roots->x2Ref, data_roots->nRootsRef);

        return 0;
    }
    else {
        printf ("Test-OK\n");

        return 1;
    }
}
#endif
