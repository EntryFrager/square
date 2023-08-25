#include "kvadratka.h"
#include "test.h"
#include "Error.h"
#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>

void printf_help () {
    printf("�����:\n");

    printf("\t-h\t\t����������� ����������\n");

    printf("\t-t\t\t������������ ��������� � ��������� ������\n");

    printf("\t-t filename.txt\t������������ ��������� �� ����� ������");

}

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

void input_square (Coefficients* var_coef) {
    assert (var_coef != NULL);

    printf ("����� ������������ ��� ����������� ��������� (ax^2 + bx + c = 0): ");

    while (scanf ("%lg %lg %lg", &var_coef->a, &var_coef->b, &var_coef->c) != 3)
    {
        clean_buffer();

        printf ("�� ���� �������� ��������, ����� ������ (����� ������ ����) ");
    }
}

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

bool is_zero (double value) {
    assert (!isnan (value));
    assert (isfinite (value));

    return (fabs (value) < EPSILON);
}

bool compare_number (double value_1, double value_2) {
    assert (!isnan (value_1));
    assert (isfinite (value_1));
    assert (!isnan (value_2));
    assert (isfinite (value_2));

    return ((value_1 - value_2) > EPSILON);
}

void clean_buffer () {
    int ch = 0;

    while ((ch = getchar () != '\n') && (ch != EOF)) {}
}

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
