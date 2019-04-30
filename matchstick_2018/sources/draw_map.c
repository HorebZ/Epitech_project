/*
** EPITECH PROJECT, 2019
** DRAW_MAP
** File description:
** draw_map for matchstich
*/

#include "my_match.h"

void draw_map(match_stock_t *map)
{
    int    nb_space = (map->lnth / 2) -1;
    size_t k = 0;

    for (size_t y = 0; y < map->lnth; y++)
        write(1, "*", 1);
    write(1, "\n", 1);
    for (size_t i = 0; i < map->size; i++, nb_space--, k = 0) {
        write(1, "*", 1);
        k++;
        for (size_t h = 0; h < nb_space; h++, k++)
            write(1, " ", 1);
        for (size_t p = 0; p < map->stik[i]; p++, k++)
            write(1, "|", 1);
        for (k = k + 1; k < map->lnth; k++)
            write(1, " ", 1);
        write(1, "*\n", 2);
    }
    for (size_t f = 0; f < map->lnth; f++)
        write(1, "*", 1);
    write(1, "\n", 1);
}
