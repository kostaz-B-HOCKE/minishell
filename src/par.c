#include "../minishell.h"

void	pass_space_two(char *input, int *i)
{
    while (input[*i] && input[*i] != ' '
           && input[*i] != '<' && input[*i] != '>' && input[*i] != '|')
        (*i)++;
}

char	*delete_spese(char *str)
{
	int		i;
	int		len;
	char	*res;

	if (!str)
		return (str);
	i = -1;
	while (str[++i] == ' ')
		;
	res = ft_substr(str, i, ft_strlen(str) - i);
	free(str);
	len = ft_strlen(res);
	while (len >= 0 && ft_strchr(" ", res[len]))
		len--;
	len++;
	res[len] = 0;
	str = ft_strdup(res);
	free(res);
	return (str);
}

char	*ft_blank(char *str, int *i)
{
	int j;
	char *tmp;
	char *tmp2;
	char *tmp3;

	j = *i;
	while (str[j] && str[j] == ' ')
		j++;
	tmp = ft_substr(str, 0, *i);
	tmp2 = ft_substr(str, j - 1, ft_strlen(str) - 1);
	tmp3 = ft_strjoin(tmp, tmp2);
	free(str);
	free(tmp);
	free(tmp2);
	return (tmp3);
}

char	*init_redirect(char *str, int *i, int *n)
{
	char *tmp;

	*n = *(i)--;
	tmp = ft_strdup(str);
	tmp[(*n)++] = 0;
	(*i)++;
	while (str[*n] == ' ')
		(*n)++;
	return (tmp);
}

char    *bild_file_check(char *file_name, t_info *inf)
{
    int i;

    i = -1;
    while (file_name[++i])
    {
        if (file_name[i] == '\'')
            ft_gap(file_name, &i, '\'');
        if (file_name[i] == '\"')
            ft_gap2(file_name, &i, '\"', inf);
        if (file_name[i] == '$')
            ft_dollar_pv(file_name, &i, inf->env);
        if (!(*file_name))
            return (NULL);
    }
    return (file_name);
}

int	open_redir_1(char *file, t_info *inf)
{
    int fd;
    char *error;

    file = bild_file_check(file, inf);
    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH); //FOR LINUX!!!!!
    if (fd == -1)
    {
//        error = bild_file_check(file);
//        perror(error);
//        free_two_str(error, file);
        gl_exit = 1;
        return (1);
    }
    free(file);
//    close(inf->fd_in)
    close(inf->fd_in);
    inf->fd_in = fd;
    inf->is_redirect++;
	return (0);
}

char    *ft_redirect_2(char *str, int *i, t_info *inf)
{
    char    *tmp;
    int j = 0;

//  is_herredo
    return (str);
}

//char    *ft_heredok(char *str, int *i, t_info *inf)
//{
//    char    *start;
//    char    *end;
//    char    *line;
//    int     n;
//    int     j;
//
//    start = init_redirect(str, i, &n);
//   if (check_len(str + n) || check_token(str[n]))
//        return (free_str_2(start, str));
//    j = n;
//    pass_space_two(str, &n);
//    end = ft_substr(str, n, ft_strlen(str));
//    start[n++] = 0;
//    line = ft_strdup(start + j);
//    read_heredoc(line, inf);
//    return (str);
//}

void    read_heredoc(char *str, t_info *inf)
{
    char *tmp;
    char *tmp2;
    char *tmp3;

    tmp = str;
    str = ft_strjoin(str, "\n");
    free(tmp);
    tmp = ft_strdup("");
//    write(1, "> ", 2);
//    printf("%s\n", tmp2);
    tmp2 = get_next_line(0);
}

char	*ft_chek_redirect(char *str, int *i, t_info *inf)
{
	if (str[*i] == '>' && str[*i + 1] == '>')
        printf(">>!\n");
	else if (str[*i] == '>')
        str = ft_redirect_1(str, i, inf);
	else if (str[*i] == '<' && str[*i + 1] == '<')
        printf("<<\n");
	else if (str[*i] == '<')
		printf("<\n");
	return (str);
}

char	*parse_spaces(char *input, int *index, t_info *inf)
{
    char	*start;
    char	*end;
    int		i;

    i = *index;
    start = ft_strdup(input);
    start[i++] = 0;
    link_to_str(start, inf);
    while (input[i] == ' ')
        (i)++;
    end = ft_substr(input, i, ft_strlen(input));
    free(input);
    *index = -1;
    return (end);
}

char    *chek_symbol_str(t_info *inf, char *str, int *i)
{
	char **env;

	env = inf->env;
//        printf("str:%s\n", str);
	while (str[++(*i)])
	{
		if (str[*i] == '\'')
            str = ft_gap(str, i, '\'');
		else if (str[*i] && str[*i] == '\"')
			str = ft_gap2(str, i, '\"', inf);
		else if (str[*i] == '$' && (ft_isalnum(str[*i + 1]) || str[*i + 1] == '?'))
            str = ft_dollar_pv(str, i, env);
//        else if (str[*i] == '|')
//            ft_pipex_cutting(str, &i, inf);
//		else if (str[*i] == '>' || str[*i] == '<')
//			str = ft_chek_redirect(str, i, inf);
		else if (str[*i] && str[*i] == ' ')
			str = parse_spaces(str, i, inf);
        if (!str)
            return (NULL);
	}
    if (ft_strlen(str) != 0)
        link_to_str(str, inf);
    put_link_to_pipe(inf);

//    print_list_pipels(inf);
//  print_me_link(inf);
//	printf("++++++++++++++++++++++++++++++++++++++\n%s\n", str);
	return (str);
}

void    parsing_s(t_info *inf, char *str)
{
	t_pipels	*tmp;
    int			i;

    i = -1;
    if (str[0] == 0)
    {
        free(str);
        return ;
    }
	str = delete_spese(str);
	str = chek_symbol_str(inf, str,	&i);
	if (!str)
	{
		inf->pipe_index = 0;
		free_link(&inf->link);
        free_pipels(&inf->pipels);
		gl_exit = 258;
		return ;
	}
    if (ft_strlen(str) == 0)
        free(str);
	tmp = inf->pipels;
    cmd_exe(inf);
	inf->pipels = tmp;
	printf("DEBUG #1 parsing\n");
    free_pipels(&inf->pipels);
	printf("DEBUG #2 parsing\n");
}

