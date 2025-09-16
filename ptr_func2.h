#ifndef PTR_FUNC2_H
#define PTR_FUNC2_H
#include "structures_consts.h"

char **create_ptr_array(file_in_array *arr);
void strswap_strcpy(char *string1, char *string2);

int find_idx_of_first_letter(char *string);

void check_strings_elems(char **str1, char **str2, bool *is_elem_to_sort, int idx_str1, int idx_str2);

void sort_array_set_by_ptr2arr(file_in_array *arr, char **ptr_arr);

int str_with_min_len(char *str1, char *str2);

void put_sorted_by_ptr2arr_onegin_to_file(const char *name_of_file, char **array, file_in_array *arr);

#endif // PTR_FUNC2_H