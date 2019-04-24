/*
** EPITECH PROJECT, 2018
** ALTERNATE_NODE
** File description:
** help for ra fonction
*/

#include <stdlib.h>
#include "my.h"

list_t *alternate_node(list_t *l, int nmbr)
{
    list_t *lis = malloc(sizeof(list_t));
    list_t *tmp = l;

    lis->nbr = nmbr;
    lis->nxt = NULL;
    if (tmp == NULL)
        return (lis);
    else {
        for (; tmp->nxt != NULL; tmp = tmp->nxt);
        tmp->nxt = lis;
    }
    return (l);
}