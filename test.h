#ifndef TEST_H
#define TEST_H
#include "kvadratka.h"

enum test {
    TESTS_CNT = 5
};

typedef struct {
    double x1Ref;
    double x2Ref;
    int nRootsRef;
} Test_data_roots;

void data_coef (Coefficients* var_coef, FILE *fp);
void data_roots_test (Test_data_roots* data_roots, FILE *fp);
int test (char *argv[]);
int test_solve_square (Coefficients* var_coef, Test_data_roots* data_roots, Roots* var_roots);

#endif // TEST_H
