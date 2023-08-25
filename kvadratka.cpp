/// @file kvadratka.cpp

#include "kvadratka.h"
#include "test.h"
#include "Error.h"
#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>

/**
 * Function prompting the user to solve a quadratic equation or start testing.
 * @param[out] type_mode
*/

#if 0
int test_mode () {
    printf ("Ты хочешь решить квадратное уравнение (напиши 1) или запустить тестирование (напиши 2)?\n"
            "Твой выбор: ");

    int type_mode = 0;

    do {
        scanf ("%d", &type_mode);
        if (type_mode != SQUARE && type_mode != TEST)
            printf ("Ты ошибся, давай снова ");

        clean_buffer();
    } while (type_mode != SQUARE && type_mode != TEST);

    return type_mode;
}
#endif

/**
 * Function for solving a linear equation.
 * Formula: x = -b / a
 * @param[in] a
 * @param[in] b
 * @param[out] var_roots
*/

int solve_linear (const double a, const double b, Roots* var_roots) {
    assert (isfinite (a));
    assert (isfinite (b));
    assert (var_roots != NULL);

    if (is_zero (a))
    {
        if (is_zero (b))
            return INFINITY_ROOTS;
        else
            return NO_ROOTS;
    }
    else
    {
        var_roots->x1 = var_roots->x2 = - b / a;

        return ONE_ROOTS;
    };
}

/**
 * Dispatcher function to track if a quadratic equation takes a linear form.
 * @param[in] var_coef
 * @param[in] var_roots
 * @param[out] nRoots
*/

int solve_dispetcher (const Coefficients* var_coef, Roots* var_roots) {
    assert (isfinite (var_coef->a));
    assert (isfinite (var_coef->b));
    assert (isfinite (var_coef->c));
    assert (var_coef != NULL);
    assert (var_roots != NULL);

    if (is_zero (var_coef->a))
    {
        if (is_zero (var_coef->b))
        {
            if (is_zero (var_coef->c))
            {
                return INFINITY_ROOTS;
            }

            return NO_ROOTS;
        }
        else
        {
            printf ("Твоё уравнение имеет линейный вид.\n");

            return solve_linear (var_coef->b, var_coef->c, var_roots);
        }
    }
    else
    {
        return solve_square (var_coef->a, var_coef->b, var_coef->c, var_roots);
    }
}

/**
 * Function for solving a quadratic equation.
 * Formula: disc = b * b - 4 * a *c
 * Formula: x1 = (- b - sqrt (disc)) / (2 * a)
 * Formula: x2 = (- b + sqrt (disc)) / (2 * a)
 * @param[in] a
 * @param[in] b
 * @param[in] c
 * @param[in] var_roots
 * @param[out] nRoots
*/

int solve_square (const double a, const double b, const double c, Roots* var_roots) {
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (var_roots != NULL);

    double disc = b * b - 4 * a * c;

    if (compare_number (disc, 0))
    {
        double sqrt_disc = sqrt (disc);

        var_roots->x1 = (- b - sqrt_disc) / (2 * a);
        var_roots->x2 = (- b + sqrt_disc) / (2 * a);

        return TWO_ROOTS;
    }
    else if (is_zero(disc))
    {
        var_roots->x1 = var_roots->x2 = - b / (2 * a);

        return ONE_ROOTS;
    }
    else
        return NO_ROOTS;
}
