/// @file error.h

#ifndef ERROR_H
#define ERROR_H

#define my_assert (value) (value)? 0: 1

const int ERROR_CNT = 6;

enum code_error {                               ///< Error codes.
    NO_ERROR = 0,                               ///< No error.
    ERR_FOPEN = 1,                              ///< Error opening file.
    ERR_FCLOSE = 2,                             ///< Error closing file.
    ERR_FCOEF = 3,                              ///< Error when reading coefficients and correct roots from a file.
    ERR_ISFINITE = 4,
    ERR_NULL = 5
};

const char* error_str (unsigned code_error);    ///< Error return function.

#endif // ERROR_H
