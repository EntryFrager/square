/// @file error.h

#ifndef ERROR_H
#define ERROR_H

#define my_assert(expr) if (!(expr)) {  \
        fprintf(stderr, "%s:%d: My assertion failed: \"" #expr " on line \n", __func__, __LINE__); \
        exit(1); \
    }

const int ERROR_CNT = 6;

enum code_error {                               ///< Error codes.
    ERR_NO = 0,                                 ///< No error.
    ERR_FOPEN = 1,                              ///< Error opening file.
    ERR_FCLOSE = 2,                             ///< Error closing file.
    ERR_FCOEF = 3                               ///< Error when reading coefficients and correct roots from a file.
};

const char* error_str (unsigned code_error);    ///< Error return function.

#endif // ERROR_H
