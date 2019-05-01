/*
** EPITECH PROJECT, 2018
** SWAP_PA
** File description:
** swap_pa
*/

#include "my_swap.h"

void swap_pa(para_t *mem)
{
    for (; mem->nb_pa > 1; mem->nb_pa--)
        write(1, "pa ", 3);
    write(1, "pa\n", 3);
}
