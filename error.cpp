#include "kvadratka.h"
#include "test.h"
#include "Error.h"
#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>

void error (int code_error) {
    if (code_error == error_fopen)
    {
        printf("ERROR: ��������� ������ ��� �������� ����� � test.cpp --> int test(...)");
    }
    if (code_error == error_fclose)
    {
        printf("ERROR: ��������� ������ ��� �������� ����� � test.cpp --> int test(...)");
    }
}
