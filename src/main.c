#include "../minishell.h"

int	start_readline(t_info *inf)
{
	char *cmd[2];

	cmd[0] = "cat";
	cmd[1] = "-e";
	if (ft_strnstr(inf->st_line, "|", ft_strlen(inf->st_line)))
		write(1, "|||\n", 4);
	pid_t pid = fork();
	if (pid == 0)
	{
		execve(find_path("ls", inf->env), cmd, inf->env);
	}
	waitpid(pid, NULL, 0);
	return (0);
}

//int	adopt_cmd(t_info *inf)
//{
//	pid_t	pid;
//
//	pid = fork();
//	if (pid == 0)
//	{
//
//		execve(find_path("ls", inf->env), cmd, inf->env);
//	}
//	waitpid(pid, NULL, 0);
//	return (0);
//}

int main(int ac, char **argv, char **env)
{
	t_info	inf;

	gl_exit = 0;
	init_info(&inf, env);
	while (1)
	{
		inf.st_line = readline(">: ");
		start_readline(&inf);
//		if (ft_strchr(info.start_line, '2'))
//			super_exit = 1;
		if (gl_exit == 1)
			break ;
	}
}

int _9main(int ac, char **argv, char **env)
{
	char *cmd[2];

	cmd[0] = "cat";
	cmd[1] = "-e";
	printf("%s\n", find_path("cat", env));
//	while (1)
//	{
		execve(find_path("cat", env), cmd, env);
//	}
	return (1);
}

