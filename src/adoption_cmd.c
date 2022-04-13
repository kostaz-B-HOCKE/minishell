#include "../minishell.h"

void	cheak_cmd(t_info *inf)
{
	if (!ft_strncmp(inf->line, "pwd", ft_strlen(inf->line)))
	{
		write(1, "pwd\n", 4);
	}
	if (!ft_strncmp(inf->line, "cd", ft_strlen(inf->line)))
	{
		write(1, "cd\n", 4);
	}
	else
		adopt_cmd(inf);
}

int	adopt_cmd(t_info *inf)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execute(inf->line, inf);
	}
	else
		waitpid(pid, NULL, 0);
	return (0);
}

//int adopt_cmd_pipe(t_info *inf)
//{
//
//}
