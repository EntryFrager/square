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
        puts ("Функция strlen работает верно");
    }
    else
    {
        fprintf(stderr, "ERROR функция my_strlen допустила ошибку\n");
    }

    if (strcpy(dest, src) == my_strcpy(dest, src))
    {
        puts ("Функция strcpy работает верно");
    }
    else
    {
        fprintf(stderr, "ERROR функция strcpy допустила ошибку\n");
    }

    if (strncpy(dest, src, 3) == my_strncpy(dest, src, 3))
    {
        puts ("Функция strncpy работает верно");
    }
    else
    {
        fprintf(stderr, "ERROR функция my_strncpy допустила ошибку\n");
    }

    if (strcat(dest, src) == my_strcat(dest, src))
    {
        puts ("Функция strcat работает верно");
    }
    else
    {
        fprintf(stderr, "ERROR функция my_strcat допустила ошибку\n");
    }

    if (strncat(dest, src, 3) == my_strncat(dest, src, 3))
    {
        puts ("Функция strncat работает верно");
    }
    else
    {
        fprintf(stderr, "ERROR функция my_strncat допустила ошибку\n");
    }

    if (*strdup(dest) == *my_strdup(dest))
    {
        puts ("Функция strdup работает верно");
    }
    else
    {
        fprintf(stderr, "ERROR функция my_strdup допустила ошибку\n");
    }

    if (strchr(dest, 100) == my_strchr(dest, 100))
    {
        puts ("Функция strchr работает верно");
    }
    else
    {
        fprintf(stderr, "ERROR функция my_strchr допустила ошибку\n");
    }

    if (strstr(str_str, src_123)  == my_strstr(str_str, src_123))
    {
        puts ("Функция strstr работает верно");
    }
    else
    {
        fprintf(stderr, "ERROR функция my_strstr допустила ошибку\n");
    }
}
