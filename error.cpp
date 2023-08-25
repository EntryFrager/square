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
    "������ ���.\n",
    "ERROR: ��������� ������ ��� �������� �����.\n",
    "ERROR: ��������� ������ ��� �������� �����.\n",
    "ERROR: ��������� ������ ��� ���������� ������������� � ���������� ������ �� ��������� �����.\n",
    "ERROR: ��������� ������, ��� ��� ���� �� ������������� == NAN ��� �������������.\n",
    "ERROR: ��������� ������, ��� ��� ������� ������� ���������"
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
        return "����������� ������.\n";
    }
}
