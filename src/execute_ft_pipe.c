#include "../minishell.h"

void	execute_fork_old(char *cmd, char *arg[], t_info *inf)
{
    int		status;
    pid_t	pid;

    pid = fork();
    if (pid < 0)
    {
        perror(ERROR_NAME);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execve(cmd, arg, inf->env);
        micro_print_err(cmd);
        exit(1);
    }
    else
    {
        wait(&status);
        gl_exit = WEXITSTATUS(status);
        free(cmd);
    }
}

