/*
** EPITECH PROJECT, 2019
** ROUND
** File description:
** fonction for round
*/

#include "my_match.h"

void info_rnd(match_stock_t *map, char *l, char *m)
{
    int nbr_l = my_getnbr(l);
    int nbr_m = my_getnbr(m);

    PINFO;
    write(1, m, nbr_m);
    _INFO;
    write(1, l, nbr_l);
    BREAK;
    map->stik[nbr_l - 1] -= nbr_m;
    map->total -= nbr_m;
}

int stik_anl(match_stock_t *map, char *l, char *m)
{
    if (m == NULL || my_getnbr(m) == -1) {
        ERR_S;
        return (-1);
    } else if (my_getnbr(m) <= 0) {
        ERR_0;
        return (-1);
    } else if (my_getnbr(m) > map->play) {
        ERR_M;
        my_putnbr(map->play);
        ERR__;
        return (-1);
    } else if (my_getnbr(m) > map->stik[my_getnbr(l) - 1]) {
        ERR_R;
        return (-1);
    }
    return (0);
}

int line_anl(match_stock_t *map, char *l)
{
    if (l == NULL || my_getnbr(l) == -1) {
        ERR_S;
        return (-1);
    } else if (my_getnbr(l) == 0 || my_getnbr(l) > map->size) {
        ERR_L;
        return (-1);
    }
    return (0);
}

void aiai_trn(match_stock_t *map)
{
    int l = 0;

    for (int m = 0; m != 1; l++)
        if (map->stik[l] > 0)
            m = 1;
    l--;
    BINFO;
    write(1, "1", 1);
    _INFO;
    my_putnbr(l);
    BREAK;
    map->stik[l]--;
    map->total--;
}

int play_trn(match_stock_t *map)
{
    char *l = NULL;
    char *m = NULL;

    PLINE;
    l = get_nxt_line(0);
    while (line_anl(map, l) == -1) {
        free(l);
        PLINE;
        l = get_nxt_line(0);
    }
    PMATC;
    m = get_nxt_line(0);
    while (stik_anl(map, l, m) == -1){
        free(m);
        return (-1);
    }
    info_rnd(map, l, m);
    return (1);
}