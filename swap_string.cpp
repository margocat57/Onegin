#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "structures_consts.h"

void strswap_strcpy(char *string1, char *string2)
{
    assert(string1 != NULL);
    assert(string2 != NULL);

    char temp[MAXIMUM_LENGTH] = "";
    strcpy(temp, string1);
    strcpy(string1, string2);
    strcpy(string2, temp);
}

void strswap_char(char *string1, char *string2)
{
    assert(string1 != NULL);
    assert(string2 != NULL);

    char a = '\0';
    char *temp = &a;
    // не while (*string !='\0')
    // потому что '\0' не скопируется и придется его вручную ставить
    for (int count = 0; count < MAXIMUM_LENGTH; count++)
    {
        *temp = *string1;
        *string1 = *string2;
        *string2 = *temp;
        string1++;
        string2++;
    }
}

void strswap_int(char *string1, char *string2)
{
    assert(string1 != NULL);
    assert(string2 != NULL);

    unsigned long long int a = 1;
    unsigned long long int *temp = &a;

    for (int count = 0; count < MAXIMUM_LENGTH; count += 8)
    {
        if (MAXIMUM_LENGTH - count < sizeof(long long int))
        {
            strswap_char(string1, string2);
            break;
        }
        *temp = *(unsigned long long int *)string1;
        *(unsigned long long int *)string1 = *(unsigned long long int *)string2;
        *(unsigned long long int *)string2 = *(unsigned long long int *)temp;
        string1 += 8;
        string2 += 8;
    }
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

char my_tolower(char ch)
{
    return ('A' <= ch && ch <= 'Z') ? ch + 'a' - 'A' - 1 : ch;
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