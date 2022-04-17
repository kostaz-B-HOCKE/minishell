#include "../minishell.h"

int	ft_ifkey_dollar(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

char	*ft_dollar_pv(char *str, int *i, char **env)
{
	int j = *i;
	char *tmp;
	char *tmp2;
	char *tmp3;
	int k = -1;
	int z = 0;

	while (str[++(*i)])
		if (!ft_ifkey_dollar(str[*i]))		
			break ;
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	// *i = *i - ft_strlen(tmp);
	while (env[++k])
	{
		if (strstr(env[k], tmp))
		{
			while (env[k][z] && env[k][z] != '=')
				z++;
			tmp2 = ft_substr(env[k], 0, z);
			if (!strcmp(tmp, tmp2))
				break ;
		}
	}
	tmp2 = ft_substr(env[k], z + 1, ft_strlen(env[k]) - z);
	printf("s1: %s\ns2: %s\n", tmp2, str);
	// free(tmp);
	// free(tmp3);
	// free(str);
	return (tmp2);
}

char *ft_dollar(char *str, int *i, char **env)
{
	char	*string;
	int		j;
	char	*tmp;
	char	*tmp2;

	j = *i;
	tmp = ft_substr(str, 0, j);
	string = ft_dollar_pv(str, i, env);
	printf("string %s\n", string);
	j = ft_strlen(string);
	// *i = *i + j;
	tmp2 = ft_substr(str, j, ft_strlen(str) - 1);
	str = ft_strjoin_free(tmp, string);
		// printf("%s\n", str);
	str = ft_strjoin_free(str, tmp2);
	// printf("%s\n", str);
	return (str);
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
