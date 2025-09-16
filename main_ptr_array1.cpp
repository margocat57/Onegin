#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "structures_consts.h"
#include "swap_string.h"
#include "ptr_func.h"
#include "cmd_ln_args.h"
#include "info_about_file_.h"

int main(int argc, char **argv)
{
    whete_put_sorted_onegin(argc, argv, PTR_FILE_NM);
    file_info info = info_about_file("textonegin.txt");
    char **test_array = read_to_ptr_array1("textonegin.txt", &info);
    sort_array_set_by_ptr1arr(test_array, &info);
    put_sorted_by_ptr1arr_onegin_to_file(FILE_NAME, test_array, &info);
    free_memory(test_array, &info);
    return 0;
}

// ./ptr_array1