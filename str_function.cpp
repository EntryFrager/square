/// @file str_function.cpp

#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>
#include "kvadratka.h"
#include "test.h"
#include "error.h"

void puts_function (const char * string)
{
    while (*string)
    {
        putchar (*string++);
    }
}
