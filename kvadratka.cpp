/// @file kvadratka.cpp

#include "kvadratka.h"
#include "test.h"
#include "Error.h"
#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>

/// Function for displaying information about the program.

void printf_help () {
    printf("�����:\n");

    printf("\t-h\t\t����������� ����������\n");

    printf("\t-t\t\t������������ ��������� � ��������� ������\n");

    printf("\t-t filename.txt\t������������ ��������� �� ����� ������");

}

/**
 * Function prompting the user to solve a quadratic equation or start testing.
 * @param[out] type_mode
*/

#if 0
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
 * Function for entering the coefficients of a quadratic equation.
 * @param[in] var_coef
 * @param[out] var_coef
*/

void input_square (Coefficients* var_coef) {
    assert (var_coef != NULL);

    printf ("����� ������������ ��� ����������� ��������� (ax^2 + bx + c = 0): ");

    while (scanf ("%lg %lg %lg", &var_coef->a, &var_coef->b, &var_coef->c) != 3)
    {
        clean_buffer();

        printf ("�� ���� �������� ��������, ����� ������ (����� ������ ����) ");
    }
}

/**
 * Function for solving a linear equation.
 * Formula: x = -b / a
 * @param[in] a
 * @param[in] b
 * @param[out] var_roots
*/

int solve_linear (double a, double b, Roots* var_roots) {
    assert (isfinite (a));
    assert (isfinite (b));
    assert (!isnan (a));
    assert (!isnan (b));
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

int solve_dispetcher (Coefficients* var_coef, Roots* var_roots) {
    assert (isfinite (var_coef->a));
    assert (isfinite (var_coef->b));
    assert (isfinite (var_coef->c));
    assert (!isnan (var_coef->a));
    assert (!isnan (var_coef->b));
    assert (!isnan (var_coef->c));
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
            printf ("��� ��������� ����� �������� ���.\n");

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

int solve_square (double a, double b, double c, Roots* var_roots) {
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (!isnan (a));
    assert (!isnan (b));
    assert (!isnan (c));
    assert (var_roots != NULL);

    double disc = b * b - 4 * a * c;

    if (compare_number(disc, 0))
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

/**
 * Function to check for zero.
 * @param[in] value
 * @param[out] True or False(1 or 0)
*/

bool is_zero (double value) {
    assert (!isnan (value));
    assert (isfinite (value));

    return (fabs (value) < EPSILON);
}

/**
 * Function for comparing numbers.
 * @param[in] value_1
 * @param[in] value_2
 * @param[out] True or False(1 or 0)
*/

bool compare_number (double value_1, double value_2) {
    assert (!isnan (value_1));
    assert (isfinite (value_1));
    assert (!isnan (value_2));
    assert (isfinite (value_2));

    return ((value_1 - value_2) > EPSILON);
}

/**
 * Buffer cleaning function.
 * @param[in] value_1
 * @param[in] value_2
 * @param[out] True or False(1 or 0)
*/

void clean_buffer () {
    int ch = 0;

    while ((ch = getchar () != '\n') && (ch != EOF)) {}
}

/**
 * Function for displaying roots.
 * @param[in] nROots
 * @param[in] var_roots
 * @param[out] roots
*/

void print_roots (int nRoots, const Roots* var_roots) {
    assert (var_roots != NULL);

    printf ("������ �����! ��� �� ��� �� ���!..\n");

    Sleep (1000);

    switch(nRoots)
        {
        case NO_ROOTS:
            printf ("��������� �� ����� �������. � �� �� ������ ��?..\n");
            break;

        case ONE_ROOTS:
            printf ("��������� ����� ���� �������: x = %lg, ���������, ��� ���� ���� ���.\n", var_roots->x1);
            break;

        case TWO_ROOTS:
            printf ("��������� ����� ��� �������: x1 = %lg, x2 = %lg. � ��� %lg ��������\n",
                    var_roots->x1, var_roots->x2, fabs (var_roots->x1 * var_roots->x2));
            break;

        case INFINITY_ROOTS:
            printf ("��������� ����� ���������� ����� �������.\n");
            break;

        default:
            printf ("ERROR ���-�� ������... �� ����� ���.\n");
        }
}
