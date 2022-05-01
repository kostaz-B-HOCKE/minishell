#include "../minishell.h"

void    int_inf_fd(t_info *inf)
{
    int pipe_fd[2];

    if (inf->is_pipe)
    {
        if (pipe(pipe_fd) < 0)
        {
            perror(ERROR_NAME);
            return ;
        }
        inf->pipe_fd_in = pipe_fd[0];
        inf->pipe_fd_in = pipe_fd[1];
    }
}

void    cmd_exe(t_info *inf)
{
    int size;
    int p_fd[2];

    size = pipes_size(inf->pipels);
    if (size == 1)
    {
        cheak_cmd(inf);
    }
    else
    {
//        printf("SEE PIPE\n");
        if (pipe(p_fd) < 0)
        {
            perror(ERROR_NAME);
            return ;
        }
        close(p_fd[1]);
        inf->tmp_in = p_fd[0];
        while (inf->pipels)
        {
            cheak_cmd(inf);
            inf->pipels = inf->pipels->next;
        }
        inf->is_pipe = 0;
        close(inf->tmp_in);
    }
    inf->pipe_index = 0;
}

void	cheak_cmd(t_info *inf)
{
    if (!inf->pipels->arg[0]){
        printf("OX NO\n");
        return;
    }
    int_inf_fd(inf);
    if (ft_strcmp(inf->pipels->arg[0], "env") == 0)
        print_me_env(inf);
//        command_env(inf);
    else if (ft_strcmp(inf->pipels->arg[0], "pwd") == 0) {
//        printf("типо работает pwd\n");
        ftt_pwd(inf);
    }
    else if (ft_strcmp(inf->pipels->arg[0], "echo") == 0)
    {
        ftt_echo(inf);
    }
    else if (!ft_strcmp(inf->pipels->arg[0], "exit"))
        ftt_exit(inf->pipels->arg, inf);
    else if (ft_strcmp(inf->pipels->arg[0], "cd") == 0) {
        ftt_cd(inf);
    }

//        command_cd(inf);
//    else if (ft_strcmp(inf->pipes->arg[0], "export") == 0)
//        command_export(inf);
//    else if (ft_strcmp(inf->pipes->arg[0], "unset") == 0)
//        command_unset(inf);
    else {
        printf("%s??else??%s\n",    YELLOW, RESET);
        exe_command(inf);
    }
//    close(inf->pipe_fd_in);
//    close(inf->pipe_fd_out);
    close(inf->pipe_fd_in);
    close(inf->pipe_fd_out);
}

//int adopt_cmd_pipe(t_info *inf)
//{
//
//}
