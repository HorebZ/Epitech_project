/*
** EPITECH PROJECT, 2019
** GTL
** File description:
** The get next line
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char *love_good_malloc(char *str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}

int the_end_of_blop_line(char *buf, int i)
{
    int y = 0;

    for (; buf[i] != '\n'; i++, y++) {
        if (buf[i] == '\n')
            return (y);
        if (buf[i] == '\0')
            return (-1);
    }
    return (y);
}

char *stct(char *dest, char *src)
{
    char  *str;
    int    i = 0;
    int    j = 0;
    size_t size_src = 0;
    size_t size_des = 0;

    for (; src[size_src] != '\0'; size_src++);
    for (; dest[size_des] != '\0'; size_des++);
    if ((str = malloc(sizeof(char) * (size_des + size_src +1))) == NULL)
        return (NULL);
    love_good_malloc(str, size_des + size_src + 1);
    for (; dest[i] != '\0'; i++, j++)
        str[i] = dest[j];
    j = 0;
    for (; src[j] != '\0'; i++, j++)
        str[i] = src[j];
    return (str);
}

int first_check(waste_bin_t *block, int const fd)
{
    if (block->i == 0) {
    if ((block->buf_bg = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
        return (1);
    block->buf_bg = love_good_malloc(block->buf_bg, READ_SIZE + 1);
    if ((block->r = read(fd, block->buf_bg, READ_SIZE)) == -1 || block->r == 0)
        return (1);
    }
    return (0);
}

char *get_next_line(const int fd)
{
    static waste_bin_t block;
    trash_can_t        black;

    if (first_check(&block, fd) == 1)
        return (NULL);
    while ((black.len = the_end_of_blop_line(block.buf_bg, block.i)) == -1) {
        if ((black.buf = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
            return (NULL);
        black.buf = love_good_malloc(black.buf, READ_SIZE + 1);
        if ((block.r = read(fd, black.buf, READ_SIZE)) == -1 || block.r ==0)
            return (NULL);
        block.buf_bg = stct(block.buf_bg, black.buf);
    }
    if ((black.str = malloc(sizeof(char) * (black.len + 2))) == NULL)
        return (NULL);
    black.str = love_good_malloc(black.str, black.len + 2);
    for (black.len = 0; block.buf_bg[block.i] != '\n'; block.i++, black.len++)
        black.str[black.len] = block.buf_bg[block.i];
    block.i++;
    return (black.str);
}
