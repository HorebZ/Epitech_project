/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** Splits a string into words and return a word array
*/

#include "my_sh.h"

int lg_word(char const *str, char sp, int y, int i)
{
    for (; str[y] && str[y] != sp; y++, i++);
    return i;
}

int nb_word(char const *str, char sp, int i)
{
    for (size_t j = 0; str[j]; j++)
        if (str[j] == sp && (str[j + 1] != sp && str[j + 1] != '\0'))
            i++;
    return i;
}

char **str_tab(char const *str, char sp)
{
    char **tmp = malloc(sizeof(char *) * (nb_word(str, sp, 1) + 1));
    int      j = 0;
    int      y = 0;

    for (int i = 0; str[y] && str[y] != sp; i = 0, j++) {
        tmp[j] = malloc(sizeof(char) * (lg_word(str, sp, y, 0) + 1));
        for (; str[y] && str[y] != sp; tmp[j][i++] = str[y++]);
        for (; str[y] == sp; y++);
        tmp[j][i] = '\0';
    }
    tmp[j] = NULL;
    return tmp;
}
