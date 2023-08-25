/// @file kvadratka.cpp

#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>
#include "kvadratka.h"
#include "test.h"
#include "error.h"

#if 0
/**
 * Function prompting the user to solve a quadratic equation or start testing.
 * @param[out] type_mode
*/


int test_mode () {
    printf ("�� ������ ������ ���������� ��������� (������ 1) ��� ��������� ������������ (������ 2)?\n"
            "���� �����: ");

    int type_mode = 0;

    do {
        scanf ("%d", &type_mode);
        if (type_mode != SQUARE && type_mode != TEST)
            printf ("�� ������, ����� ����� ");

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

int solve_linear (const double a, const double b, Roots* var_roots)
{
    if (my_assert (isfinite (a)))
    {
        return ERR_ISFINITE;
    }

    if (my_assert (isfinite (b)))
    {
        return ERR_ISFINITE;
    }

    if (my_assert (var_roots != NULL))
    {
        return ERR_NULL;
    }

    if (is_zero (a))
    {
        if (is_zero (b))
        {
            return INFINITY_ROOTS;
        }
        else
        {
            return NO_ROOTS;
        }
    }
    else
    {
        var_roots->x1 = var_roots->x2 = - b / a;

        return ONE_ROOTS;
    }
}

/**
 * Dispatcher function to track if a quadratic equation takes a linear form.
 * @param[in] var_coef
 * @param[in] var_roots
 * @param[out] nRoots
*/

int solve_dispetcher (const Coefficients* var_coef, Roots* var_roots)
{
    if (my_assert (isfinite (var_coef->a)))
    {
        return ERR_ISFINITE;
    }

    if (my_assert (isfinite (var_coef->b)))
    {
        return ERR_ISFINITE;
    }

    if (my_assert (isfinite (var_coef->c)))
    {
        return ERR_ISFINITE;
    }

    if (my_assert (var_coef != NULL))
    {
        return ERR_NULL;
    }

    if (my_assert (var_roots != NULL))
    {
        return ERR_NULL;
    }

    if (is_zero (var_coef->a))
    {
        printf ("��� ��������� ����� �������� ���.\n");

        return solve_linear (var_coef->b, var_coef->c, var_roots);
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

int solve_square (const double a, const double b, const double c, Roots* var_roots)
{
    if (my_assert (isfinite (a)))
    {
        return ERR_ISFINITE;
    }

    if (my_assert (isfinite (b)))
    {
        return ERR_ISFINITE;
    }

    if (my_assert (isfinite (c)))
    {
        return ERR_ISFINITE;
    }

    if (my_assert (var_roots != NULL))
    {
        return ERR_NULL;
    }

    if (is_zero (c))
    {
        var_roots->x1 = 0;

        var_roots->x2 = -b / a;

        return TWO_ROOTS
    }

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
