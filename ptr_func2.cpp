#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include "structures_consts.h"

char **create_ptr_array(file_in_array *arr)
{
    assert(arr != NULL);
    char **array_with_ptrs = (char **)calloc(arr->amount_str, sizeof(char *));
    assert(array_with_ptrs != NULL);

    size_t num_of_elem = 0;
    array_with_ptrs[num_of_elem] = &((arr->all_strings_in_file)[0]);
    num_of_elem = 1;

    for (int i = 1; i < arr->amount_of_symb; i++)
    {
        if ((arr->all_strings_in_file)[i] == '\n' && i != arr->amount_of_symb - 1)
        {
            (arr->all_strings_in_file)[i] = '\0';
            array_with_ptrs[num_of_elem] = &((arr->all_strings_in_file)[i + 1]);
            num_of_elem++;
        }
    }
    //(arr->all_strings_in_file)[arr->amount_of_symb - 1] = '\0';
    // почему когда я закомментила этот код то оно стало работать, а если его оставить,
    // то у нас бесконечное число итераций
    // дополнительный символ нужно добавлять, иначе strlen на последней строке будет искать \0 и не найдя его выйдет за границы массива
    return array_with_ptrs;
}

void strswap_strcpy(char *string1, char *string2)
{
    assert(string1 != NULL);
    assert(string2 != NULL);

    char temp[MAXIMUM_LENGTH] = "";
    strcpy(temp, string1);
    strcpy(string1, string2);
    strcpy(string2, temp);
}

char my_tolower(char ch)
{
    return ('A' <= ch && ch <= 'Z') ? ch + 'a' - 'A' - 1 : ch;
}

void swap_pointers(char **str1, char **str2)
{
    assert(str1 != NULL);
    assert(*str1 != NULL);

    assert(str2 != NULL);
    assert(*str2 != NULL);

    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

what_to_do what_do_with_letters(char letter1, char letter2)
{
    // to_lower() стандартная функция
    char letter1_lower = my_tolower(letter1);
    char letter2_lower = my_tolower(letter2);

    if (letter1_lower > letter2_lower)
    {
        return SWAP;
    }
    else if (letter1_lower == letter2_lower)
    {
        return CONTINUE;
    }
    return BREAK;
}

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

void sort_array_set_by_ptr2arr(file_in_array *arr, char **ptr_arr)
{
    assert(arr != NULL);
    assert(ptr_arr != NULL);

    int left = 0, right = arr->amount_str - 1;
    bool is_elem_to_sort = 1;

    while (left < right && is_elem_to_sort)
    {
        is_elem_to_sort = 0;

        for (int string = left; string < right; string++)
        {
            check_strings_elems(&ptr_arr[string], &ptr_arr[string + 1], &is_elem_to_sort, find_idx_of_first_letter(ptr_arr[string]), find_idx_of_first_letter(ptr_arr[string + 1]));
        }
        right--;

        for (int string = right; string > left; string--)
        {
            check_strings_elems(&ptr_arr[string - 1], &ptr_arr[string], &is_elem_to_sort, find_idx_of_first_letter(ptr_arr[string - 1]), find_idx_of_first_letter(ptr_arr[string]));
        }
        left++;
    }
}

void put_sorted_by_ptr2arr_onegin_to_file(const char *name_of_file, char **array, file_in_array *arr)
{
    assert(arr != NULL);
    assert(name_of_file != NULL);
    assert(array != NULL);

    FILE *fptr = fopen(name_of_file, "w");
    assert(fptr != NULL);

    for (int string = 0; string < arr->amount_str; string++)
    {
        if (array[string][0] != '\0')
        {
            fputs(array[string], fptr);
            fputs("\n", fptr);
        }
    }
    free(array);
    free(arr->all_strings_in_file);
    fclose(fptr);
}
