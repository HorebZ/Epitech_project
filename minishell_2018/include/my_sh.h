/*
** EPITECH PROJECT, 2019
** MY_SH
** File description:
** my.h for mysh project
*/

#ifndef _MY_SH__
#define _MY_SH__

// == > INCLUDE LIB.C
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

// == > MACRO
#define PROMPT write(1, "$> ", 3);
#define ERR_CM write(2, ": Command not found.\n", 21);

typedef struct minishell_s
{
    char **env;
    char **args;
    char **path;
    char  *cmds;
    char  *conc;
} minishell_t;

// == > CFG_ENV.C
void   get_env(minishell_t *mysh, char **env);
int    cmd_to_path(minishell_t *mysh);

// == > MY_STRLIB
char  *my_strcpy(char *dest, char const *src, int n);
char  *my_strcat(char *src01, char *src02);
int    my_strlen(char const *str);

// == > STR_TAB.C
char **str_tab(char const *str, char sp);

#endif /* _MY_SH__ */
