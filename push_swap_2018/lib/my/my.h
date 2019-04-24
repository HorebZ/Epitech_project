/*
** EPITECH PROJECT, 2018
** MY
** File description:
** MY
*/

#ifndef MY_H
#define MY_H

typedef struct para
{
    int pos_s;
    int small;
    int nb_pa;
} para_t;

typedef struct list
{
    int nbr;
    struct list *nxt;
    struct list *prv;
} list_t;

list_t *alternate_node(list_t *l, int nmbr);
list_t *mv_node(list_t *l_a, para_t *mem);
list_t *my_node(list_t *l, char *str);
list_t *swap_ra(list_t *l_a);
list_t *swap_pb(list_t *l_a);
void    swap_pa(para_t *mem);
int     my_getnbr(char const *str);

#endif
