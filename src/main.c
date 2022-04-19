#include "../minishell.h"

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
 
int main(int ac, char **argv, char **env)
{
	t_info	*inf;
	char 	*str;
	t_env	*tmp;

	gl_exit = 0;
	inf = init_info(env);
//	shell_level(inf);
//	printf("__/__/__/__/__/__/__/__/__/__/__/\n");
//	tmp = inf->env_lst;
//	if (tmp != NULL)
//	{
//		while (tmp->next)
//		{
//			printf("%s\n",  tmp->str);
//			tmp = tmp->next;
//		}
//		printf("%s\n", tmp->str);
//	}

	while (1)
	{
		str = readline("mimishell: ");
//		if (ft_strlen(str) != 0)
//			add_history(str);
		parsing_s(inf, str, env);
//		printf("%s\n", str);
//		cheak_pipe(inf);
//		if (ft_strlen(str) != 0)
//			add_history(str);
//		parsing_s(inf, str);
		if (ft_strnstr(str, "exit", ft_strlen(str)))
			exit(EXIT_SUCCESS);
		if (gl_exit == 1)
			break ;
	}
}
//int _9main(int ac, char **argv, char **env)
//{
//	char *cmd[2];
//
//	cmd[0] = "cat";
//	cmd[1] = "-e";
//	printf("%s\n", find_path("cat", env));
//		execve(find_path("cat", env), cmd, env);
//	return (1);
//}

