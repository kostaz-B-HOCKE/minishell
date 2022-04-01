#include "../minishell.h"

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int 	i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = _find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, envp) == -1)
		exit(EXIT_FAILURE);
}


int	ft_pipe(t_info *inf)
{


	return (0);
}
