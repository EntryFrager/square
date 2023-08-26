/// @file kvadratka.h

#ifndef KVADRATKA_H
#define KVADRATKA_H

#include "kvadratka.h"
#include "error.h"
#include "str_function.h"

const double EPSILON = 1e-10;               ///< Constant needed to compare numbers of type double.

enum mode {                                 ///< Arguments specifying the program's behavior.
    TEST = 't',                             ///< Test argument.
    HELP = 'h'                              ///< Argument for options.
};

enum roots {                                ///< Arguments specifying the number of roots.
    NO_ROOTS = 0,                           ///< No roots.
    ONE_ROOTS = 1,                          ///< One roots.
    TWO_ROOTS = 2,                          ///< Two roots.
    INFINITY_ROOTS = 1000                   ///< Infinity roots.
};

typedef struct {                            ///< A structure containing the coefficients of a quadratic equation.
    double a;                               ///< Coefficient at the second degree.
    double b;                               ///< Coefficient at the first degree.
    double c;                               ///< Free member.
} Coefficients;

typedef struct {                            ///< A structure containing the roots of a quadratic equation.
    double x1;                              ///< Smaller root.
    double x2;                              ///< Bigger root.
} Roots;

void printf_help ();                                                                 ///< Displaying information about a file.

int test_mode ();                                                                   ///< Mode selection.

void input_square (Coefficients* var_coef);                                         ///< Entering the coefficients of a quadratic equation.

int solve_dispetcher (const Coefficients* var_coef, Roots* var_roots);              ///< Quadratic Equation Manager.

int solve_linear (const double a, const double b, Roots* var_roots);                 ///< Function for solving a linear equation.

int solve_square (const double a, double b, const double c, Roots* var_roots);       ///< Function for solving a quadratic equation.

bool is_zero (const double value);                                                   ///< Checking numbers for zero.

bool compare_number (const double value_1, const double value_2);                    ///< Number Comparison.

void clean_buffer ();                                                                ///< Buffer cleaning function.

void print_roots (const int nRoots, const Roots* var_roots);                         ///< Derivation of solutions.

#endif // KVADRATKA_H
