/// @file error.cpp

#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>
#include "kvadratka.h"
#include "test.h"
#include "error.h"

/**
 * types of errors
*/

static const char* err_msgs_arr[] = {
    "Ошибок нет.\n",
    "ERROR: произошла ошибка при открытии файла.\n",
    "ERROR: произошла ошибка при закрытии файла.\n",
    "ERROR: произошла ошибка при считывании коэффициентов и правильных корней из тестового файла.\n",
    "ERROR: произошла ошибка, так как один из коэффициентов == NAN или бесконечность.\n",
    "ERROR: произошла ошибка, так как получен нулевой указатель"
};

/**
 * Error return function.
 * @param[in] code_error
*/

const char* error_str (unsigned code_error)
{
    if (code_error < ERROR_CNT)
    {
        return err_msgs_arr[code_error];
    }
    else
    {
        return "Неизвестная ошибка.\n";
    }
}
