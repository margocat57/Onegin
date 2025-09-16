#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "structures_consts.h"
#include "swap_string.h"
#include "ptr_func2.h"
#include "cmd_ln_args.h"
#include "work_with_file.h"

int main(int argc, char **argv)
{
    whete_put_sorted_onegin(argc, argv, PTR_FILE_NM);
    file_in_array info = file_information("textonegin.txt");
    char **test_array = create_ptr_array(&info);
    sort_array_set_by_ptr2arr(&info, test_array);
    put_sorted_by_ptr2arr_onegin_to_file(FILE_NAME, test_array, &info);
    return 0;
}

// ./ptr_array2