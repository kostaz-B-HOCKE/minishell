#include "../minishell.h"

//препарсинг
void	chek_mark_lid(char *str, int *i, char c)
{
	int i1;
	char *part_str;

	i1 = *i;
	while (str[++i1])
	{
		if (str[i1] == '\'')
		{
			printf("Y\n");
			*i = i1 + 1;
			printf("Y\n");
			return ;
		}
	}
	printf("No\n");
}

char	*ft_gap(char *str, int *i, char c)
{
	int j = *i;
	char *tmp;
	char *tmp2;
	char *tmp3;

	while (str[++(*i)])
		if (str[(*i)] == c)
			break ;
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp = ft_strjoin(tmp, tmp2);
	tmp3 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp3);
	free(str);
	*i = *i - 2;
	return (tmp);
}

char	*ft_gap2(char *str, int *i, char c, char **env)
{
	int	j = *i;
	char *tmp;
	char *tmp2;
	char *tmp3;

	while (str[++(*i)])
	{
		if (str[*i] == '\\' && (str[*i + 1] == '\"' || str[*i + 1] == '$' || str[*i + 1] == '\\'))
				str = ft_slesh(str, i);
		if (str[*i] == '\"')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp = ft_strjoin(tmp, tmp2);
	tmp3 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp3);
	free(str);
	*i = *i - 2;
	return (tmp);
}
