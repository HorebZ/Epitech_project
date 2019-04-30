/*
** EPITECH PROJECT, 2019
** MYSH
** File description:
** minishell1
*/

#include "my_sh.h"

int exec_cmd(minishell_t *mysh, char **env)
{
    pid_t pid  = 0;
    int   fd   = 0;
    int status = 0;

    pid = fork();
    if (pid == 0)
        fd = execve(mysh->conc, mysh->args, env);
    else if (waitpid(pid, &status, F_OK)) {
        if (fd == -1)
            exit(0);
        if (status == 11)
            write(1, "Segmentation fault\n", 18);
        else if (status == 139)
            write(1, "Segmentation fault (core dumped)\n", 33);
    }
    return 0;
}

void cmd_not_found(minishell_t *mysh)
{
    for (size_t i = 0; mysh->args[0][i]; i++)
        write(1, &mysh->args[0][i], 1);
    ERR_CM;
}

int minishell_exec(minishell_t *mysh, char **env)
{
    size_t len = 0;

    mysh->cmds = NULL;
    if (getline(&mysh->cmds, &len, stdin) == -1)
        exit(0);
    mysh->cmds[my_strlen(mysh->cmds) - 1] = '\0';
    if (mysh->cmds[0] == '\0')
        return 0;
    if (mysh->cmds[0] == 'e' && mysh->cmds[1] == 'x' && mysh->cmds[2] == 'i' &&
        mysh->cmds[3] == 't' && mysh->cmds[4] == '\0')
        exit(0);
    mysh->args = str_tab(mysh->cmds, ' ');

    if (cmd_to_path(mysh) == -1) {
        cmd_not_found(mysh);
    } else
        exec_cmd(mysh, env);
    return 0;
}

int main(int ac, char **av, char **env)
{
    minishell_t mysh;

    get_env(&mysh, env);
    while (1) {
        PROMPT;
        if (minishell_exec(&mysh, env) == -1)
            break;
    }
    return 0;
}
