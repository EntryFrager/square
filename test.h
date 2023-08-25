/// @file test.h
#ifndef TEST_H
#define TEST_H

#include "kvadratka.h"
#include "Error.h"
#include <stdio.h>

const int TESTS_CNT = 5;                        ///< Constant containing the number of tests

typedef struct {                                ///< Structure containing regular roots and their number.
    double x1Ref;                               ///< True root 1.
    double x2Ref;                               ///< True root 2.
    int nRootsRef;                              ///< Number of roots.
} Test_data_roots;

int data (Coefficients* var_coef,  Test_data_roots* data_roots, FILE *fp);                      ///< Function for reading test data.

int test (const char *filename);                                                                ///< Main test management function.

int test_solve_square (Coefficients* var_coef, Test_data_roots* data_roots, Roots* var_roots);  ///< Function testing our program.

#endif // TEST_H
