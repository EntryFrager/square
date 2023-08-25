#ifndef TEST_H
#define TEST_H

#include "kvadratka.h"
#include "Error.h"
#include <stdio.h>

const int TESTS_CNT = 5;

typedef struct {
    double x1Ref;
    double x2Ref;
    int nRootsRef;
} Test_data_roots;

void data (Coefficients* var_coef,  Test_data_roots* data_roots, FILE *fp);

int test (const char *filename);

int test_solve_square (Coefficients* var_coef, Test_data_roots* data_roots, Roots* var_roots);

#endif // TEST_H
