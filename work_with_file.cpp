#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "structures_consts.h"

file_in_array file_information(const char *name_of_file)
{
    assert(name_of_file != NULL);
    file_in_array fptr_in_array = {};
    FILE *fptr = fopen(name_of_file, "r");
    assert(fptr != NULL);

    struct stat file_info;
    stat(name_of_file, &file_info);

    char *all_strings_in_file = (char *)calloc(file_info.st_size + 1, sizeof(char));
    assert(all_strings_in_file != NULL);
    fread(all_strings_in_file, sizeof(char), file_info.st_size, fptr);

    int nmb_of_str = 0;

    for (int i = 0; i < file_info.st_size; i++)
    {
        if (all_strings_in_file[i] == '\n' || i == file_info.st_size - 1)
        {
            nmb_of_str++;
        }
    }

    fptr_in_array.amount_of_symb = file_info.st_size + 1;
    fptr_in_array.amount_str = nmb_of_str;
    fptr_in_array.all_strings_in_file = all_strings_in_file;
    printf("how_many_strings = %lu\n", fptr_in_array.amount_str);

    fclose(fptr);
    return fptr_in_array;
}