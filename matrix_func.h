#ifndef MATRIX_FUNC_H
#define MATRIX_FUNC_H
#include "structures_consts.h"

char Onegin_array[NUMBER_OF_STRINGS][MAXIMUM_LENGTH] = {};

void fill_matrix(const char *name_of_file, char array[][MAXIMUM_LENGTH]);

void sort_array_set_by_matrix(char array[][MAXIMUM_LENGTH]);

void put_sorted_by_mtrx_onegin_to_file(const char *name_of_file, char array[][MAXIMUM_LENGTH]);

#endif // MATRIX_FUNC_H