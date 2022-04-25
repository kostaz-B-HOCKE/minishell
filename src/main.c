#include "../minishell.h"

void	handler(int sig)
{
    (void)sig;
    rl_on_new_line();
    rl_redisplay();
    write(1, "  \n", 3);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
    gl_exit = 1;
}

void	sig_handler(void)
{
    struct sigaction	sa;
    sigset_t			set;

    signal(SIGQUIT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    sa.sa_handler = handler;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sa.sa_mask = set;
    sigaction(SIGINT, &sa, NULL);
}

int	start_readline(t_info *inf)
{
	inf->split_line = ft_split(inf->st_line, ' ');
	if (!find_path(inf->split_line[0], inf))
	{
		write(1, "zsh: command not found: ", 24);
		ft_putstr_fd(inf->split_line[0], 1);
		write(1, "\n", 1);
	}
	else
	{
		inf->line = inf->st_line;
//		if (parsing_s(inf))
//			return (1);
		cheak_cmd(inf);
	}
	return (0);
}

void	two_mark(t_info *inf)
{
	int i;

//	inf->line =
	printf("|\"|\n");
}

int	cheak_pipe(t_info *inf)
{
	inf->line = inf->st_line;
	if (ft_strnstr(inf->st_line, "|", ft_strlen(inf->st_line)))
	{
		//работает, закрывает основныой процесс нужно запустить в дочернем
//		ft_pipex(inf);
		printf("|||\n");
	}
	else
		start_readline(inf);
	return (0);
}

void    start_shell(t_info *inf)
{
    char *str;

    while (1)
    {
        sig_handler();//control + D выдает сегу
        str = readline("mimishell: ");
        if (!str)
            break ;
		if (ft_strlen(str) != 0)
			add_history(str);
        parsing_s(inf, str);
    }
}

int main(int ac, char **argv, char **env)
{
    char 	*str;

    t_info	*inf;
	t_env	*tmp;

	gl_exit = 0;
	inf = init_info(env);

//  print_me_env(inf);
//	shell_level(inf);
//	printf("__/__/__/__/__/__/__/__/__/__/__/\n");

    start_shell(inf);
}

