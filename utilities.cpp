/// @fail utilities.cpp

#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <assert.h>
#include "kvadratka.h"
#include "test.h"
#include "error.h"

/**
 * Function to check for zero.
 * @param[in] value
 * @param[out] True or False(1 or 0)
*/

bool is_zero (const double value)
{
    if (my_assert (isfinite(value)))
    {
        return ERR_ISFINITE;
    }

    return (fabs (value) < EPSILON);
}

/**
 * Function for comparing numbers.
 * @param[in] value_1
 * @param[in] value_2
 * @param[out] True or False(1 or 0)
*/

bool compare_number (const double value_1, const double value_2)
{
    if (my_assert (isfinite(value_1)))
    {
        return ERR_ISFINITE;
    }
    if (my_assert (isfinite(value_2)))
    {
        return ERR_ISFINITE;
    }

    return ((value_1 - value_2) > EPSILON);
}

/**
 * Buffer cleaning function.
 * @param[in] value_1
 * @param[in] value_2
 * @param[out] True or False(1 or 0)
*/

void clean_buffer ()
{
    int ch = 0;

    while ((ch = getchar () != '\n') && (ch != EOF)) {}
}
