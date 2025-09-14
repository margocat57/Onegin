#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "structures_consts.h"

file_info_fstat file_information(const char *name_of_file)
{
    assert(name_of_file != NULL);
    file_info_fstat fptr_info = {};
    FILE *fptr = fopen(name_of_file, "r");
    assert(fptr != NULL);

    struct stat file_info;
    stat(name_of_file, &file_info);

    char *all_strings_in_file = (char *)calloc(file_info.st_size, sizeof(char));
    assert(all_strings_in_file != NULL);
    fread(all_strings_in_file, sizeof(char), file_info.st_size, fptr);

    int nmb_of_str = 0;
    int nmb_of_elem = 0;
    int max = 0;

    for (int i = 0; i < file_info.st_size; i++)
    {
        if (all_strings_in_file[i] == '\n' || i == file_info.st_size - 1)
        {
            if (i == file_info.st_size - 1 && all_strings_in_file[i] != '\n')
            {
                nmb_of_elem++;
            }
            if (nmb_of_elem > max)
            {
                max = nmb_of_elem + 1;
            }
            nmb_of_elem = 0;
            nmb_of_str++;
        }
        else
        {
            nmb_of_elem++;
        }
    }

    fptr_info.amount_str = nmb_of_str;
    fptr_info.maximum_len = max;
    printf("max_size = %lu\n", fptr_info.maximum_len);
    printf("how_many_strings = %lu\n", fptr_info.amount_str);

    fclose(fptr);
    free(all_strings_in_file);
    return fptr_info;
}