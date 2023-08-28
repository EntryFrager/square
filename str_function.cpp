/// @file str_function.cpp

#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>
//#include "kvadratka.h"
//#include "test.h"
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

    return my_strcpt (dest, src, 0);
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

    return my_strcpt(dest, src, dest_len);
}

char* my_strncat (char* dest, const char* src, size_t n)
{
    my_assert (dest != NULL);
    my_assert (src != NULL);

    size_t dest_len = my_strlen (dest);

    for (size_t i = 0; i < n; i++)
    {
        dest[dest_len + i] = src[i];
    }

    return dest;
}

char* my_strcpt (char* dest, const char* src, size_t start_dest) // TODO
{
    my_assert (dest != NULL);
    my_assert (src != NULL);

    while (*src++ != '\0')
    {
        dest[start_dest++] = *src;
    }

    dest[start_dest] = '\0';

    return dest;
}

char* my_strdup (const char* s)
{
    size_t s_len = my_strlen (s);

    char* s_copy = (char *) malloc (sizeof(s));

    for (size_t i = 0; i <= s_len; i++)
    {
        s_copy[i] = s[i];
    }

    return s_copy;
}

char* my_strchr (const char* s, int c)
{
    size_t s_len = my_strlen (s);

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

    for (size_t i = 0; i <= s1_len; i++)
    {
        if (t == s2_len)
        {
            return (char *) s1 + i - s2_len;
        }
        if (s1[i] == s2[t])
        {
            t++;
        }
        else
        {
            t = 0;
        }
    }
    return NULL;
}
