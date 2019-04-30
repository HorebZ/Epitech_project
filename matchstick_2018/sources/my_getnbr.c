/*
** EPITECH PROJECT, 2018
** MY_GETNBR
** File description:
** /!\ Getnbr special matchstick
*/

#include "my_match.h"

int my_getnbr(char const *str)
{
    int nbr = 0;

    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return -1;
    if (*str == '-')
        return -1;
    for (; *str; str++, nbr *= 10)
        nbr  = (*str - 48) + nbr;
    return nbr;
}
