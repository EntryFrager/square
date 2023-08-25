#include "kvadratka.h"
#include "test.h"
#include "Error.h"
#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>
#include <string.h>

const char default_tests_src[] = "Test.txt";

int main (int argc, char *argv[]) {
    Roots var_roots = {};
    Coefficients var_coef = {};

    printf ("Это программа решающая квадратные уравнения (ax^2 + bx + c = 0).\n");

    char *str = argv[1];

    switch(argc)
        {
        case exe:
        {
            //if (type_mode == SQUARE)
            int type_mode = test_mode ();
            input_square (&var_coef);

            int nRoots = solve_dispetcher (&var_coef, &var_roots);

            print_roots (nRoots, &var_roots);
        }
            break;
        case exe_h_t:
            if (strstr("-h", str) != NULL)
            {
                printf_help ();
            }
            else if (strstr("-t", str) != NULL)
            {
                printf ("Будет использоваться дефолтный файл для тестов");

                int code_error = test (default_tests_src);
            }
            break;
        case exe_h_t_filename:
            if (strstr("-t", str) != NULL)
            {
                char *tests_src_filename = argv[2];
                int code_error = test (tests_src_filename);
            }
            break;
        default:
            printf("ERROR: ты ввел неверный код...");
        }

    return 0;
}
