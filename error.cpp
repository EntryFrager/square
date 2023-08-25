/// @file error.cpp
#include "kvadratka.h"
#include "test.h"
#include "Error.h"
#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>

/**
 * Error return function.
 * @param[in] code_error
*/
static const char* err_msgs_arr[] = {
    "Ошибок нет\n",
    "ERROR: произошла ошибка при открытии файла\n",
    "ERROR: произошла ошибка при закрытии файла\n",
    "ERROR: произошла ошибка при считывании коэффициентов и правильных корней из тестового файла."
};

const char* error_str (unsigned code_error) {
    if (code_error < ERROR_CNT)
    {
        return err_msgs_arr[code_error];
    }
    else
    {
        return "Неизвестная ошибка\n";
    }
}
