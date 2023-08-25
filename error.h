#ifndef ERROR_H
#define ERROR_H

enum error {
    error_fopen = 1,
    error_fclose
};

void error (int code_error);

#endif // ERROR_H
