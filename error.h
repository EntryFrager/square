/// @file error.h
#ifndef ERROR_H
#define ERROR_H

const int ERROR_CNT = 4;

// TODO caps
enum code_error {              ///< Error codes.
    NO_ERROR = 0,
    ERR_FOPEN = 1,             ///< Error opening file.
    ERR_FCLOSE = 2,            ///< Error closing file.
    ERR_FCOEF = 3
};

const char* error_str (unsigned code_error);    ///< Error return function.

#endif // ERROR_H
