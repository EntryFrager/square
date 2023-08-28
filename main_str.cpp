#include <stdio.h>
#include <string.h>
#include <TXLib.h>
#include "str_function.h"
#include "error.h"

int main ()
{
    char dest[] = "abbcdef", src[] = "bb";

    if (strlen(dest) == my_strlen(dest))
    {
        puts ("������� strlen �������� �����");
    }
    else
    {
        fprintf(stderr, "ERROR ������� my_strlen ��������� ������\n");
    }

    if (strcpy(dest, src) == my_strcpy(dest, src))
    {
        puts ("������� strcpy �������� �����");
    }
    else
    {
        fprintf(stderr, "ERROR ������� strcpy ��������� ������\n");
    }

    if (strncpy(dest, src, 3) == my_strncpy(dest, src, 3))
    {
        puts ("������� strncpy �������� �����");
    }
    else
    {
        fprintf(stderr, "ERROR ������� my_strncpy ��������� ������\n");
    }

    if (strcat(dest, src) == my_strcat(dest, src))
    {
        puts ("������� strcat �������� �����");
    }
    else
    {
        fprintf(stderr, "ERROR ������� my_strcat ��������� ������\n");
    }

    if (strncat(dest, src, 3) == my_strncat(dest, src, 3))
    {
        puts ("������� strncat �������� �����");
    }
    else
    {
        fprintf(stderr, "ERROR ������� my_strncat ��������� ������\n");
    }

    if (*strdup(dest) == *my_strdup(dest))
    {
        puts ("������� strdup �������� �����");
    }
    else
    {
        fprintf(stderr, "ERROR ������� my_strdup ��������� ������\n");
    }

    if (strchr(dest, 100) == my_strchr(dest, 100))
    {
        puts ("������� strchr �������� �����");
    }
    else
    {
        fprintf(stderr, "ERROR ������� my_strchr ��������� ������\n");
    }

    if (strstr(str_str, src_123)  == my_strstr(str_str, src_123))
    {
        puts ("������� strstr �������� �����");
    }
    else
    {
        fprintf(stderr, "ERROR ������� my_strstr ��������� ������\n");
    }
}
