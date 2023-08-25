/// @file main.cpp

#include "kvadratka.h"
#include "test.h"
#include "Error.h"
#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>
#include <string.h>

const char default_tests_src[] = "Test.txt";            ///< Default test file for testing the program.

/** Main entry point of the program.
 *  @param[in] argc
 *  @param[in] argv
*/

int main (int argc, char *argv[]) {
    Roots var_roots = {};
    Coefficients var_coef = {};

    printf ("��� ��������� �������� ���������� ��������� (ax^2 + bx + c = 0).\n");

    char *test_filename = NULL;

    int test_mode = 0;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if (strlen(argv[i]) != 2)
            {
                printf("ERROR: �� ���� ������������� ������ ���������...\n");
                return 0;
            }
            switch (*(argv[i] + 1))
            {
                case 't':
                {
                    test_mode = 1;
                }
                break;
                case 'h':
                {
                    printf_help ();
                    return 0;
                }
                break;
                default:
                    printf("ERROR: �� ���� �������� ��������...\n");
                    return 0;
            }
        }
        else
        {
            test_filename = argv[i];
        }
    }

    if (test_mode)
    {
        if (test_filename == NULL)
        {
            printf ("����� �������������� ��������� ���� ��� ������\n");
            test_filename = (char *) default_tests_src;
        }

        int code_error = test (test_filename);

        if (code_error != 0)
        {
            printf("%s", error_str (code_error));
        }
    }
    else
    {
        input_square (&var_coef);

        int nRoots = solve_dispetcher (&var_coef, &var_roots);

        print_roots (nRoots, &var_roots);
    }

    return 0;
}
