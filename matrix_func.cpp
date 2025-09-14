#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "structures_consts.h"
#include "swap_string.h"

void fill_matrix(const char *name_of_file, char array[][MAXIMUM_LENGTH])
{
    assert(name_of_file != NULL);
    char buffer[MAXIMUM_LENGTH] = {};

    FILE *fp = fopen(name_of_file, "r");
    assert(fp != NULL);

    int string = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(array[string], buffer);
        string++;
    }
}

void sort_array_set_by_matrix(char array[][MAXIMUM_LENGTH])
{
    int left = 0, right = NUMBER_OF_STRINGS - 1;
    bool is_elem_to_sort = 1;

    while (left < right && is_elem_to_sort)
    {
        is_elem_to_sort = 0;

        for (int string = left; string < right; string++)
        {
            for (int elem = 0; elem < MAXIMUM_LENGTH; elem++)
            {
                // return enum
                if (what_do_with_letters(array[string][elem], array[string + 1][elem]) == SWAP)
                {
                    strswap_strcpy(array[string], array[string + 1]);
                    is_elem_to_sort = 1;
                    break;
                }
                else if (what_do_with_letters(array[string][elem], array[string + 1][elem]) == BREAK)
                {
                    break;
                }
            }
        }
        right--;

        for (int string = right; string > left; string--)
        {
            for (int elem = 0; elem < MAXIMUM_LENGTH; elem++)
            {
                if (what_do_with_letters(array[string - 1][elem], array[string][elem]) == SWAP)
                {
                    strswap_strcpy(array[string - 1], array[string]);
                    is_elem_to_sort = 1;
                    break;
                }
                else if (what_do_with_letters(array[string - 1][elem], array[string][elem]) == BREAK)
                {
                    break;
                }
            }
        }
        left++;
    }
}

void put_sorted_by_mtrx_onegin_to_file(const char *name_of_file, char array[][MAXIMUM_LENGTH])
{
    assert(name_of_file != NULL);

    FILE *fptr = fopen(name_of_file, "w");
    assert(fptr != NULL);

    for (int string = 0; string < NUMBER_OF_STRINGS; string++)
    {
        if (array[string][0] != '\0')
        {
            fputs(array[string], fptr);
            fputs("\n", fptr);
        }
    }
    fclose(fptr);
}