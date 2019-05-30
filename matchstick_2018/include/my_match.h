/*
** EPITECH PROJECT, 2019
** MY_MATCH
** File description:
** my.h for Matchstich
*/

#ifndef _MY_MATCH__
#define _MY_MATCH__

// == > INLUDE LIB.C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// == > PERSONNAL_LIB
#include "get_next_line.h"

// == > MESSAGE_MACRO
#define BREAK write(1, "\n", 1)
#define P_TRN write(1, "Your turn:\n", 11)
#define PLINE write(1, "Line: ", 6)
#define PMATC write(1, "Matches: ", 9)
#define PINFO write(1, "Player removed ", 15)
#define B_TRN write(1, "AI's turn...\n", 14)
#define BINFO write(1, "AI removed ", 11)
#define _INFO write(1, " match(es) from line ", 21)
#define ERR_S write(1, "Error: invalid input (positive number expected)\n", 48)
#define ERR_L write(1, "Error: this line is out of range\n", 33)
#define ERR_0 write(1, "Error: you have to remove at last one match\n", 44)
#define ERR_R write(1, "Error: not enougt matches on this line\n", 39)
#define ERR_M write(1, "Error: you cannot remove more than ", 35)
#define ERR__ write(1, " matches per turn\n", 18)
#define WINER write(1, "I lost... snif... but I'll get you next time!!\n", 47)
#define LOSER write(2, "You lost, too bad...\n", 21)

typedef struct match_stock_s
{
    int *stik;
    int  size;
    int  play;
    int  lnth;
    int  total;
} match_stock_t;

// == > DRAW_MAP.C
void  draw_map(match_stock_t *map);

// == > ROUND.C
void  info_rnd(match_stock_t *map, char *l, char *m);
void  aiai_trn(match_stock_t *map);
int   play_trn(match_stock_t *map, char *l, char *m);
int   line_anl(match_stock_t *map, char *l);
int   stik_anl(match_stock_t *map, char *l, char *m);

// ==> MY_LIB
int   my_getnbr(char const *str);
int   my_strlen(char const *str);
void  my_putnbr(int nb);

#endif
