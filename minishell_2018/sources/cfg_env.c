/*
** EPITECH PROJECT, 2019
** CFG_ENV
** File description:
** fonction with env
*/

#include "my_sh.h"

int cmd_to_path(minishell_t *mysh)
{
    int   acces        = -1;
    char  buffer[1000] = {0};
    char *tmp = getcwd(buffer, 1000);

    if (mysh->path[0] == NULL)
        return acces;
    for (size_t i = 0; mysh->path[i]; i++) {
        mysh->conc = my_strcat(my_strcat(mysh->path[i], "/"), mysh->args[0]);
        if ((access(mysh->conc, X_OK)) == 0) {
            acces = 0;
            break;
        }
    }
    if (acces == -1) {
        mysh->conc = my_strcat(my_strcat(tmp, "/"), mysh->args[0]);
        if ((access(mysh->conc, X_OK)) == 0)
            acces = 0;
    }
    return acces;
}

void get_env(minishell_t *mysh, char **env)
{
    char *tmp;
    char buffer[1000] = {0};
    int i = 0;

    if (env[0] == NULL) {
        mysh->path    = malloc(sizeof(char *) * 2);
        mysh->path[0] = getcwd(buffer, 1000);
        mysh->path[1] = NULL;
        return;
    } else
        mysh->env = env;
    for (; env[i] != NULL && (env[i][0] != 'P' || env[i][1] != 'A'); i++);
    tmp = env[i] + 5;
    mysh->path = str_tab(tmp, ':');
}

void display_env(minishell_t *mysh)
{
    for (size_t i = 0; mysh->env[i]; i++)
        for (size_t j = 0; mysh->env[i][j]; j++)
            write(1, &mysh->env[i][j], 1);
}
