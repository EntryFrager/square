/// @file str_function.cpp

#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>
#include "str_function.h"
#include "error.h"

int my_puts (const char* str)
{
    my_assert (str != NULL);

    while (*str != '\0')
    {
        if (putchar (*str++) == EOF)
        {
            return EOF;
        }
    }
    if (putchar ('\n') == EOF)
    {
        return EOF;
    }

    return 0;
}

void test_msg (bool expr, const char* name_func)
{
    if (expr)
    {
        printf("Функция %s выполнена корректно\n", name_func);
    }
    else
    {
        fprintf(stderr, "ERROR: %s выполнена с ошибкой\n", name_func);
    }
}

size_t my_strlen (const char* str)
{
    my_assert (str != NULL);

    size_t len = 0;

    while (*str++ != '\0')
    {
        len++;
    }

    return len;
}

char* my_strcpy (char* dest, const char* src)
{
    my_assert (dest != NULL);
    my_assert (src  != NULL);

    int i = 0;

    while (src[0] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return dest;
}

char* my_strncpy (char* dest, const char* src, size_t n)
{
    my_assert (dest != NULL);
    my_assert (src  != NULL);

    size_t src_len = my_strlen (src);

    for (size_t i = 0; i < n; i++)
    {
        if (i <= src_len)
        {
            dest[i] = src[i];
        }
        else
        {
            dest[i] = '0';
        }
    }

    return dest;
}

char* my_strcat (char* dest, const char* src)
{
    my_assert (dest != NULL);
    my_assert (src != NULL);

    size_t dest_len = my_strlen (dest);
    int i = 0;

    while (src[i] != '\0')
    {
        dest[dest_len + i] = src[i];
        i++;
    }

    dest[dest_len  + i] = '\0';

    return dest;
}

char* my_strncat (char* dest, const char* src, size_t n)
{
    my_assert (dest != NULL);
    my_assert (src != NULL);

    size_t dest_len = my_strlen (dest);

    for (size_t i = 0; i < n; i++)
    {
        /*if (src[i - 1] == '\0')
        {
            break;
        }*/
        dest[dest_len + i] = src[i];
    }

    return dest;
}

char* my_strdup (const char* s)
{
    size_t s_len = my_strlen (s);

    char* s_copy = (char *) malloc (sizeof(s));  // TODO  NULL

    strncpy (s_copy, s, s_len);

    return s_copy;
}

char* my_strchr (const char* s, int c)
{
    size_t s_len = my_strlen (s); // TODO

    for (size_t i = 0; i <= s_len; i++)
    {
        if (s[i] == c)
        {
            return (char *) s + i;
        }
    }
    return NULL;
}

char* my_strstr (const char* s1, const char* s2)
{
    size_t s1_len = my_strlen (s1), s2_len = my_strlen (s2);

    size_t t = 0;

    for (size_t len_1 = 0; len_1 < s1_len; len_1++)
    {
        for (size_t len_2 = 0; len_2 < s2_len; len_2++)
        {
            if (t == s2_len)
            {
                return (char *) s1  + len_1 - 1;
            }
            if (s1[len_1 + len_2] == s2[len_2])
            {
                t++;
            }
            else
            {
                t = 0;
                break;
            }
        }
    }
    return NULL;
}

int my_strcmp (const char* s1, const char* s2)
{
    size_t s1_len = my_strlen (s1), s2_len = my_strlen (s2);

    while ((*s1++ == *s2++) && (*s1 != '\0'))
    {
        s1_len--;
        s2_len--;
    }
    if (s1_len == s2_len)
    {
        return 0;
    }
    else if (*s1 > *s2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

#if 0
ssize_t getline (char ** lineptr, size_t *n, FILE *stream)
{
    for (size_t i = 0, i; i++)
    {
        fgets (*lineptr, 1, stream);
        if i
    }

    int i = 0;

    while (fgets(*lineptr, 1, stream) != EOF)
    {
        i++
        if (i == n)
    }

    do
    {

    } while (fgets;)
}
#endif
