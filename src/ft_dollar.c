#include "../minishell.h"

int	ft_ifkey_dollar(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

char	*ft_dollar(char *str, int *i, char *s2, int j)
{
	char	*string;
	char	*tmp;
	char 	*tmp2;
	char 	*tmp3;

	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, *i, ft_strlen(str));
	if (!*s2)
	{
		*i = j - *i;
		printf("!1!\n");
		tmp3 = ft_strjoin_free(tmp, tmp2);
		printf("!2!\n");
	}
	else
	{
		printf("!0!\n");
		*i = *i - ft_strlen(s2) - 1;
		tmp3 = ft_strjoin_free(tmp, s2);
		tmp3 = ft_strjoin_free(tmp3, tmp2);
	}
	return (tmp3);
}

char	*ft_dollar_pv(char *str, int *i, char **env)
{
	int j = *i;
	char *tmp;
	char *tmp2;
	int k = -1;
	int z = 0;
	int	flag = 0;

	while (str[++(*i)])
		if (!ft_ifkey_dollar(str[*i]))		
			break ;
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	while (env[++k])
	{
		if (strstr(env[k], tmp))
		{
			while (env[k][z] && env[k][z] != '=')
				z++;
			tmp2 = ft_substr(env[k], 0, z);
			if (!strcmp(tmp, tmp2))
			{
				flag = 1;
				break ;
			}
			else
				free(tmp2);
		}
	}
	printf("flag %d\n", flag);
	free(tmp);
	// free(tmp2);
	if (flag == 1)
	{
		tmp2 = ft_substr(env[k], z + 1, ft_strlen(env[k]) - z);
	}
	else
		tmp2 = ft_strdup("\0");
	return (ft_dollar(str, i, tmp2, j));
}

char	*ft_slesh(char *str, int *i)
{
	char *tmp;
	char *tmp2;

	tmp = ft_substr(str, 0, *i);
	tmp2 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp2);
	free(tmp2);
	free(str);
	++(*i);
	return (tmp);
}
