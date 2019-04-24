/*
** EPITECH PROJECT, 2019
** MY_STRLEN
** File description:
** count lentgh of string
*/

#include "my_match.h"

int my_strlen(char const *str)
{
    int i;

    for (i = 0;str[i] != '\0'; i++);
    return (i);
}
