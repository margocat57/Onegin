#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "structures_consts.h"
#include "matrix_func.h"
#include "info_about_file_.h"

int main(void)
{
    info_about_file("textonegin.txt");
    fill_matrix("textonegin.txt", Onegin_array);
    sort_array_set_by_matrix(Onegin_array);
    put_sorted_by_mtrx_onegin_to_file("onegin_sorted.txt", Onegin_array);

    return 0;
}

// ./matrix
