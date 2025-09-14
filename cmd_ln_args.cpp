#include <assert.h>
#include <string.h>

void whete_put_sorted_onegin(int argc, char **argv, char **ptrfile_to_put_results)
{
    assert(argv != NULL);
    for (size_t flg_idx = 0; flg_idx < argc; flg_idx++)
    {
        if (strstr(argv[flg_idx], ".txt") != NULL)
        {
            *ptrfile_to_put_results = argv[flg_idx];
        }
    }
}