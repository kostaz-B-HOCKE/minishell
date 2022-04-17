#include "../minishell.h"

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

char	*ft_chek_redirect(char *str, int *i, t_info *inf)
{
	

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
		{
			printf("i1: %d ", i);
			str = ft_dollar_pv(str, &i, env);
			printf("i2: %d\n", i);
		}
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			printf("YES\n");
			str = ft_blank(str, &i);
		}
		if (str[i] == '>' || str[i] == '<')
			str = ft_chek_redirect(str, &i, inf);
	}
	printf("%s\n", str);
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

