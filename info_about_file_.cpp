#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "structures_consts.h"
#include "swap_string.h"

file_info info_about_file(const char *name_of_file)
{
    assert(name_of_file != NULL);
    file_info fptr_info = {};
    FILE *fptr = fopen(name_of_file, "r");
    assert(fptr != NULL);

    size_t max = 0;
    char ch = '.';
    size_t num_of_symbols = 0;
    size_t num_of_strings = 0;
    while ((ch = (char)fgetc(fptr)) != EOF)
    {
        if (ch != '\n')
        {
            num_of_symbols++;
        }
        else
        {
            if (num_of_symbols >= max)
            {
                max = num_of_symbols + 1;
            }
            num_of_symbols = 0;
            num_of_strings++;
        }
    }
    // почему нужен +1, потому что когда последняя строка не заканчивается /n,
    // то должны добавить еще одну строку в прямоугольный массив, иначе не будет места
    // для записи последней строки
    fptr_info.strings = num_of_strings + 1;
    fptr_info.max_len = max;

    fclose(fptr);
    printf("max_len = %lu, strings = %lu\n", max, num_of_strings);
    return fptr_info;
}