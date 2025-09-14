#ifndef STRUCTURES_CONSTS_H
#define STRUCTURES_CONSTS_H

#include <string.h>

const size_t MAXIMUM_LENGTH = 60;
const size_t NUMBER_OF_STRINGS = 810;

struct file_info
{
    size_t strings;
    size_t max_len;
};

struct file_info_fstat
{
    size_t amount_str;
    size_t maximum_len;
};

enum what_to_do
{
    BREAK = 0,
    SWAP = 1,
    CONTINUE = 2
};

#endif // STRUCTURES_CONSTS_H