/*
** EPITECH PROJECT, 2019
** MY_PUTNBR
** File description:
** puts nbr
*/

#include "my_match.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putnbr(int nb)
{
    if (nb > 9)
        my_putnbr(nb / 10);
    my_putchar((nb % 10) + '0');
}
