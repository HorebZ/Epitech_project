/*
** EPITECH PROJECT, 2018
** PUSH_SWAP
** File description:
** push_swap
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

list_t *swap_pb(list_t *l_a)
{
    list_t *new = malloc(sizeof(list_t));
    list_t *tmp = l_a->nxt;

    new->nbr = tmp->nbr;
    new->nxt = NULL;
    for (tmp = tmp->nxt; tmp->nxt != NULL; tmp = tmp->nxt)
        new = alternate_node(new, tmp->nbr);
    new = alternate_node(new, tmp->nbr);
    write(1, "pb ", 3);
    return (new);
}