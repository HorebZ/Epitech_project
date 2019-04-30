/*
** EPITECH PROJECT, 2018
** GET_NEXT_LINE
** File description:
** Macro for get_next_line fonction
*/

#ifndef READ_SIZE
#define READ_SIZE (3)

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct waste_bin_s
{
    char   *buf_bg;
    ssize_t r;
    int     i;
} waste_bin_t;

typedef struct trash_can_s
{
    char *str;
    char *buf;
    int   len;
} trash_can_t;

char *get_next_line(const int fd);

#endif /* READ_SIZE */
