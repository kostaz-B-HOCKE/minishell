#include "../minishell.h"

char	*free_str_2(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

void	preparser(char *str, int *i, char c)
{
	// while (str[++i])
}

char	*delete_spese(char *str)
{
	int		i;
	int		len;
	char	*res;

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
	printf("%s\n", ">>");
	char *tmp;

	*n = *(i)--;
	tmp = ft_strdup(str);
	tmp[(*n)++] = 0;
	(*i)++;
	while (str[*n] == ' ')
		(*n)++;
	return (tmp);
}

char	*ft_redirect_1(char *str, int *i, t_info *inf)
{
	char	*start;
	int		n;

	start = init_redirect(str, i, &n);
	printf("PP:%s\n", start);
	if (check_len(i + n) || check_token(str[n]))
		return ()

	return (str);
}

char	*ft_chek_redirect(char *str, int *i, t_info *inf)
{
	if (str[*i] == '>' && str[*i + 1] == '>')
		ft_redirect_1(str, i, inf);
	else if (str[*i] == '>')
		printf(">\n");
	else if (str[*i] == '<' && str[*i + 1] == '<')
		printf("<<\n");
	else if (str[*i] == '<')
		printf("<\n");
	return (str);
}

int	chek_symbol_str(t_info *inf, char *str, char **env)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			str = ft_gap(str, &i, '\'');
		if (str[i] == '\"')
			str = ft_gap2(str, &i, '\"', env);
		if (str[i] == '\\')
			str = ft_slesh(str, &i);
		if (str[i] == '$')
			str = ft_dollar_pv(str, &i, env);
		if (str[i] == '>' || str[i] == '<')
			str = ft_chek_redirect(str, &i, inf);
		if (str[i] == ' ' && str[i + 1] == ' ')
			str = ft_blank(str, &i);
	}
	printf("++++++++++++++++++++++++++++++++++++++\n%s\n", str);
	return (0);
}

int	parsing_s(t_info *inf, char *str, char **env)
{
	str = delete_spese(str);
	chek_symbol_str(inf, str, env);
//	ft_split(inf->line, ' ');
//	while (inf->)
//	if (ft_strnstr(inf->st_line, "\'", ft_strlen(inf->st_line)))
//		one_mark(inf);
//	if (ft_strnstr(inf->st_line, "\"", ft_strlen(inf->st_line)))
//		two_mark(inf);
//	printf("|%s|\n", str);
	return (0);
}

