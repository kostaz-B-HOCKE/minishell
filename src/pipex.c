#include "../minishell.h"

void	execute(char *argv, t_info *inf)
{
	char	**cmd;
	int 	i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], inf);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, inf->env) == -1)
		exit(EXIT_FAILURE);
}

void	execute_final(t_info *inf, int i)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[0]);
//		dup2(fd[1], STDOUT_FILENO);
		execute(inf->split_pipex[i], inf);
	}
	else
	{
//		close(fd[1]);
//		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	child_process(t_info *inf, int i)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(inf->split_pipex[i], inf);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	ft_pipex(t_info *inf)
{
	int i;
	int nu;

	i = 0;
	nu = 0;
	inf->split_pipex = ft_split(inf->st_line, '|');
	while (inf->split_pipex[nu])
		nu++;
	write(1, ft_itoa(nu), ft_strlen(ft_itoa(nu)));
	while (i < nu - 1)
	{
		inf->split_line = ft_split(inf->split_pipex[i], ' ');
		child_process(inf, i);
		i++;
	}
	execute_final(inf, i);
//	execute(inf->split_pipex[i], inf);
	return (0);
}

//char    *ft_pipex_cutting(char *str, int *i, t_info *inf)
//{
//
//
//
//
//    return (str);
//}

//не работает
char	*ft_pipex_cutting(char *str, int *i, t_info *inf)
{
    char	*tmp;
    char	*end;
    int		j;

    j = *i;
    tmp = ft_substr(str, 0, j);
    printf("1:%s\n", tmp);
    tmp = ft_strdup(str);
    printf("2:%s\n", tmp);
    tmp[j++] = 0;
    printf("2:%s\n", tmp);


    if (ft_strlen(tmp) != 0) //зачем
        link_to_str(tmp, inf);
    else
        free(tmp);
    printf("ok2\n");
    print_me_link(inf);
//    if (check_pipe_token(input, inf))
//        return (NULL);
    put_link_to_pipe(inf);
//    pass_space_one(input, &j);
//    if (check_p_token(input, j))
//        return (NULL);
    end = ft_substr(str, j, ft_strlen(str));
    printf("%s\n", end);
//    if (check_unclosed_pipe(input, end))
//        return (NULL);
    *i = -1;
    free(str);
    return (end);
}
