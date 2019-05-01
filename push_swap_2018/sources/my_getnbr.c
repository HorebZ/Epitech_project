/*
** EPITECH PROJECT, 2018
** MY_GETNBR
** File description:
** str to int
*/

int my_getnbr(char const *str)
{
    int nbr = 0;
    int neg = 0;

    if (*str == '-') {
        str++;
        neg++;
    }
    for (; *str; str++) {
        nbr *= 10;
        nbr  = (*str - 48) + nbr;
    }
    if (neg)
        nbr *= -1;
    return nbr;
}
