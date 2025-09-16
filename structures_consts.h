#ifndef STRUCTURES_CONSTS_H
#define STRUCTURES_CONSTS_H

#include <string.h>

const size_t MAXIMUM_LENGTH = 47;
const size_t NUMBER_OF_STRINGS = 5332;

struct file_info
{
    size_t strings;
    size_t max_len;
};

struct file_in_array
{
    size_t amount_str;
    size_t amount_of_symb;
    char *all_strings_in_file;
};

enum what_to_do
{
    BREAK = 0,
    SWAP = 1,
    CONTINUE = 2
};

#endif // STRUCTURES_CONSTS_H