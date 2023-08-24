#ifndef KVADRATKA_H
#define KVADRATKA_H

const double EPSILON = 1e-10;

enum mode {
    SQUARE = 1,
    TEST = 2
};

enum error {
    ZERO = 0
};

enum roots {
    NO_ROOTS = 0,
    ONE_ROOTS = 1,
    TWO_ROOTS = 2,
    INFINITY_ROOTS = 1000
};

typedef struct {
    double a;
    double b;
    double c;
} Coefficients;

typedef struct {
    double x1;
    double x2;
} Roots;

int test_mode ();
void input_square (Coefficients* var_coef);                             // ввод для квадратного уравнения
int solve_dispetcher (Coefficients* var_coef, Roots* var_roots);        // диспетчер для квадратного(вдруг оно преобразуется к линейному)
int solve_linear (double a, double b, Roots* var_roots);                // решение линейного уравнения
int solve_square (double a, double b, double c, Roots* var_roots);      // решение квадратного
bool is_zero (double value);                                             // проверка на ноль
bool compair_number (double value_1, double value_2);
bool compair_number_reverse (double value_1, double value_2);
void clean_buffer ();
void print_roots (int nRoots, Roots* var_roots);                        // вывод решений                                                  // чистка буфера
#endif // KVADRATKA_H
