#include <stdio.h>
#include <string.h>
#include <TXLib.h>
#include "str_function.h"
#include "error.h"

int main ()
{
    char dest1[40] = "abbcdef";
    char dest2[40] = "abbcdef";

    test_msg (strlen(dest1) == my_strlen(dest2), "my_strlen");

    #if 1
    char dest_1[40] = "abbcdef", src_1[40] = "bb";
    char dest_2[40] = "abbcdef", src_2[40] = "bb";
    strcpy (dest_1, src_1);
    my_strcpy (dest_2, src_2);

    test_msg (strcmp (dest_1, dest_2) == 0, "my_strcpy");

    #endif

    #if 1

    char dest_3[40] = "abbcdef", src_3[] = "bbbb";
    char dest_4[40] = "abbcdef";
    strncpy (dest_3, src_3, 3);
    my_strncpy (dest_4, src_3, 3);

    test_msg (strcmp (dest_3, dest_4) == 0, "my_strncpy");
    #endif

    #if 1

    char dest_5[40] = "abbcdef", src_4[] = "bb";
    char dest_6[40] = "abbcdef";
    strcat (dest_5, src_4);
    my_strcat (dest_6, src_4);

    test_msg (strcmp (dest_5, dest_6) == 0, "my_strcat");
    #endif

    #if 1

    char dest_7[40] = "abbcdef", src_5[] = "bbbb";
    char dest_8[40] = "abbcdef", src_6[] = "bbbb";
    strncat (dest_7, src_5, 3);
    my_strncat (dest_8, src_6, 3);

    test_msg (strcmp (dest_7, dest_8) == 0, "my_strncat");
    #endif

    #if 1

    char dest_9[40] = "abbcdef";
    char dest_10[40] = "abbcdef";
    strdup (dest_9);
    my_strdup (dest_10);

    test_msg (strcmp (dest_9, dest_10) == 0, "my_strdup");
    #endif

    char dest_11[40] = "abbcdef";
    char dest_12[40] = "abbcdef";
    strchr (dest_11, 100);
    my_strchr (dest_12, 100);

    test_msg (*dest_11 == *dest_12, "my_strchr");

    char s1[] = "abcc", s2[] = "abcd";
    char s3[] = "abcc", s4[] = "abcd";
    strstr (s1, s2);
    my_strstr (s3, s4);

    test_msg (strcmp (s1, s2), "my_strstr");

    char str1[40] = "abcdef", str2[40] = "abcdef";
    char str3[40] = "abcdef", str4[40] = "abcdef";

    test_msg (strcmp (str1, str2) == my_strcmp (str3, str4), "my_strcmp");
}
