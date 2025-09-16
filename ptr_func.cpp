#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "structures_consts.h"
#include "swap_string.h"
#include "info_about_file_.h"

char **read_to_ptr_array1(const char *name_of_file, file_info *info)
{
    assert(name_of_file != NULL);

    FILE *fptr = fopen(name_of_file, "r");
    char *buffer = (char *)calloc(info->max_len, sizeof(char));
    char **text = (char **)calloc(info->strings, sizeof(char *));
    int string = 0;

    while (fgets(buffer, info->max_len, fptr) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        text[string] = strdup(buffer);
        string++;
    }

    free(buffer);
    fclose(fptr);
    return text;
}

/*
неправильная реализация
void read_to_ptr_array1(const char *name_of_file)
{
    FILE *fptr = fopen(name_of_file, "r");
    file_info info = {};
    info = info_about_file(name_of_file);
    char *buffer = (char *)calloc(info.max_len, sizeof(char));
    char *text = (char *)calloc(info.strings, sizeof(char *));
    int string = 0;

    while (fgets(buffer, info.max_len, fptr) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        text[string] = buffer;
        string++;
    }

    fclose(fptr);
}
*/

int str_with_min_len(char *str1, char *str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    size_t len_str1_slash_0 = strlen(str1) + 1;
    size_t len_str2_slash_0 = strlen(str2) + 1;

    return len_str1_slash_0 < len_str2_slash_0 ? len_str1_slash_0 : len_str2_slash_0;
}

int find_idx_of_first_letter(char *string)
{
    for (int idx = 0; idx < strlen(string); idx++)
    {
        if (isalpha((string)[idx]))
        {
            return idx;
        }
    }
    return strlen(string);
}

void check_strings_elems(char **str1, char **str2, bool *is_elem_to_sort, int idx_str1, int idx_str2)
{
    for (int elem = 0; elem < str_with_min_len(*str1, *str2); elem++)
    {
        if (what_do_with_letters((*str1)[elem + idx_str1], (*str2)[elem + idx_str2]) == SWAP)
        {
            swap_pointers(str1, str2);
            *is_elem_to_sort = 1;
            return;
        }
        else if (what_do_with_letters((*str1)[elem + idx_str1], (*str2)[elem + idx_str2]) == BREAK)
        {
            return;
        }
    }
}

void sort_array_set_by_ptr1arr(char **array, file_info *info)
{
    assert(array != NULL);
    assert(*array != NULL);

    int left = 0, right = info->strings - 1;
    bool is_elem_to_sort = 1;

    while (left < right && is_elem_to_sort)
    {
        is_elem_to_sort = 0;

        for (int string = left; string < right; string++)
        {
            check_strings_elems(&array[string], &array[string + 1], &is_elem_to_sort, find_idx_of_first_letter(array[string]), find_idx_of_first_letter(array[string + 1]));
        }
        right--;

        for (int string = right; string > left; string--)
        {
            check_strings_elems(&array[string - 1], &array[string], &is_elem_to_sort, find_idx_of_first_letter(array[string - 1]), find_idx_of_first_letter(array[string]));
        }
        left++;
    }
}

void put_sorted_by_ptr1arr_onegin_to_file(const char *name_of_file, char **array, file_info *info)
{
    assert(array != NULL);
    assert(*array != NULL);
    assert(name_of_file != NULL);

    FILE *fptr = fopen(name_of_file, "w");
    assert(fptr != NULL);

    for (int string = 0; string < info->strings; string++)
    {
        if (array[string][0] != '\0')
        {
            fputs(array[string], fptr);
            fputs("\n", fptr);
        }
    }
    fclose(fptr);
}

void free_memory(char **array, file_info *info)
{
    for (int string = 0; string < info->strings; string++)
    {
        free(array[string]);
    }
    free(array);
}
// комнаратор - отвечает за параметр сортировки, а функция универсальная