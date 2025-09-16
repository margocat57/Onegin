#ifndef PTR_FUNC_H
#define PTR_FUNC_H

char **read_to_ptr_array1(const char *name_of_file, file_info *info);

void sort_array_set_by_ptr1arr(char **array, file_info *info);

int find_idx_of_first_letter(char *string);

void check_strings_elems(char **str1, char **str2, bool *is_elem_to_sort, int idx_str1, int idx_str2);

void put_sorted_by_ptr1arr_onegin_to_file(const char *name_of_file, char **array, file_info *info);

int str_with_min_len(char *str1, char *str2);

void free_memory(char **array, file_info *info);
#endif // PTR_FUNC_H