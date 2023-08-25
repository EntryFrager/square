/// @file test.cpp
#include "kvadratka.h"
#include "test.h"
#include "Error.h"
#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>

/**
 * Function for reading test data.
 * @param[in] var_coef
 * @param[in] data_roots
 * @param[in] fp
*/

int data (Coefficients* var_coef, Test_data_roots* data_roots, FILE *fp) {

    assert (var_coef != NULL);
    assert (data_roots != NULL);
    assert (fp != NULL);

    if (fscanf (fp, "%lg %lg %lg %lg %lg %d", &var_coef->a, &var_coef->b, &var_coef->c, &data_roots->x1Ref, &data_roots->x2Ref, &data_roots->nRootsRef) != 6)
    {
        return ERR_FCOEF;
    }
    else
    {
        return NO_ERROR;
    }
    return 0;
}

/**
 * Main test management function.
 * @param[in] filename
 * @param[out] code_error
*/

int test (const char *filename) {

    assert (filename != NULL);

    Test_data_roots data_roots = {};
    Roots var_roots = {};
    Coefficients var_coef = {};

    FILE *fp = fopen (filename, "r");

    if (fp == NULL)
    {
        return ERR_FOPEN;
    }

    int test_success = 0;

    for (int i = 0; i < TESTS_CNT; i++)
    {
        if (data (&var_coef, &data_roots, fp) == ERR_FCOEF)
        {
            return ERR_FCOEF;
        }
        else
        {
            test_success += test_solve_square (&var_coef, &data_roots, &var_roots);
        }
    }

    if (test_success == TESTS_CNT) {
        printf ("������������ ������ �������\n");
    }
    else {
        printf ("���-�� �������� ������\n");
    }

    if (fclose (fp) != 0)
    {
        return ERR_FCLOSE;
    }

    return 0;
}

/**
 * Function testing our program.
 * @param[in] var_coef
 * @param[in] data_roots
 * @param[in] var_roots
 * @param[out] test_result
*/

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
