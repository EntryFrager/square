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
    printf ("Опции:\n");

    printf ("\t" "-h"              "\t\t" "отображение информации\n");
    printf ("\t" "-t"              "\t\t" "тестирование программы с дефолтным файлом\n");
    printf ("\t" "-t filename.txt" "\t"   "тестирование программы со своим файлом\n");
    printf ("Дополнительные сведения о программе смотри в документации.\n");
}

/**
 * Function for entering the coefficients of a quadratic equation.
 * @param[in] var_coef
 * @param[out] var_coef
*/

void input_square (Coefficients* var_coef)
{
    my_assert (var_coef != NULL);

    printf ("Введи коэффициенты для квадратного уравнения (ax^2 + bx + c = 0): ");

    while (scanf ("%lg %lg %lg", &var_coef->a, &var_coef->b, &var_coef->c) != 3)
    {
        clean_buffer();

        printf ("Ты ввел неверное значение, давай заново (иначе будешь убит) ");
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

    printf ("Сейчас решим! Это же вам не ЕГЭ!..\n");

    Sleep (1000);

    switch(nRoots)
        {
        case NO_ROOTS:
            printf ("Уравнение не имеет решений. А вы их хотели да?..\n");
            break;

        case ONE_ROOTS:
            printf ("Уравнение имеет одно решение: x = %lg, радуйтесь, что есть хоть это.\n", var_roots->x1);
            break;

        case TWO_ROOTS:
            printf ("Уравнение имеет два решения: x1 = %lg, x2 = %lg. С вас %lg долларов\n",
                    var_roots->x1, var_roots->x2, fabs (var_roots->x1 * var_roots->x2));
            break;

        case INFINITY_ROOTS:
            printf ("Уравнение имеет бесконечно много решений.\n");
            break;

        default:
            fprintf (stderr, "ERROR где-то ошибка... не скажу где.\n");
        }
}
