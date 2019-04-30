/*
** EPITECH PROJECT, 2019
** MY_STRLEN
** File description:
** count lentgh of string
*/

#include "my_sh.h"

char *my_strcpy(char *dest, char const *src, int n)
{
    for (size_t i = 0; i < n; i++)
        if (src[i] != '\0')
            dest[i] = src[i];
    return dest;
}

int my_strlen(char const *str)
{
    int i = 0;

    for (;str[i] != '\0'; i++);
    return i;
}

char *my_strcat(char *src01, char *src02)
{
    int   i   = 0;
    int   l01 = my_strlen(src01);
    int   l02 = my_strlen(src02);
    char *tmp = malloc(sizeof(char) * (l01 + l02 + 1));

    for (size_t y = 0; src01[y]; y++, i++)
        tmp[i] = src01[y];
    for (size_t j = 0; src02[j]; j++, i++)
        tmp[i] = src02[j];
    tmp[i++] = '\0';
    return tmp;
}
