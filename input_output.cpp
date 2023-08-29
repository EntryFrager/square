/// @file input_output

#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>
#include "kvadratka.h"
#include "test.h"
#include "error.h"

/// Function for displaying information about the program.

void printf_help ()
{
    printf ("�����:\n");

    printf ("\t" "-h"              "\t\t" "����������� ����������\n");
    printf ("\t" "-t"              "\t\t" "������������ ��������� � ��������� ������\n");
    printf ("\t" "-t filename.txt" "\t"   "������������ ��������� �� ����� ������\n");
    printf ("�������������� �������� � ��������� ������ � ������������.\n");
}

/**
 * Function for entering the coefficients of a quadratic equation.
 * @param[in] var_coef
 * @param[out] var_coef
*/

void input_square (Coefficients* var_coef)
{
    my_assert (var_coef != NULL);

    printf ("����� ������������ ��� ����������� ��������� (ax^2 + bx + c = 0): ");

    while (scanf ("%lg %lg %lg", &var_coef->a, &var_coef->b, &var_coef->c) != 3)
    {
        clean_buffer();

        printf ("�� ���� �������� ��������, ����� ������ (����� ������ ����) ");
    }
}

/**
 * Function for displaying roots.
 * @param[in] nRoots
 * @param[in] var_roots
 * @param[out] roots
*/

void print_roots (const int nRoots, const Roots* var_roots)
{
    my_assert (var_roots != NULL);

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
            fprintf (stderr, "ERROR ���-�� ������... �� ����� ���.\n");
        }
}
