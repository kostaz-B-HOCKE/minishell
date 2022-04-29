#include "../minishell.h"

int	ft_ifkey_dollar(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

char	*ft_dollar(char *str, int *i, char *s2, int j)
{
	char	*tmp;
	char 	*tmp2;
	char 	*tmp3;

	tmp = ft_substr(str, 0, *i - j);
	tmp2 = ft_substr(str, *i, ft_strlen(str));
	if (!*s2)
	{
		*i = j - *i;
		tmp3 = ft_strjoin_free(tmp, tmp2);
	}
	else
	{
//		*i = *i - ft_strlen(s2) - 1;
		tmp3 = ft_strjoin_free(tmp, s2);
		tmp3 = ft_strjoin_free(tmp3, tmp2);
	}
	return (tmp3);
}

//ищет слово в env
char    *ft_dollar_grep(int *i, int j, char *str, char **env)
{
    char *tmp;
    char *tmp2;
    int k = -1;
    int z = 0;
    int	flag = 0;

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
            else {
                free(tmp2);
            }
        }
    }
    free(tmp);
    free(tmp2);
    if (flag == 1)
    {
        tmp = ft_substr(env[k], z + 1, ft_strlen(env[k]) - z);
    }
    else
        tmp = ft_strdup("\0");
    return (tmp);
}

char	*ft_dollar_pv(char *str, int *i, char **env)
{
	int j;
    char *end;
    char *start;
    char *mid;

    j = *i;
	while (str[++(*i)])
		if (!ft_ifkey_dollar(str[*i]))		
			break ;
    if (*i == j + 1 && str[j + 1] != '?')
        return (str);
    start = ft_substr(str, 0, j);
    end = ft_substr(str, *i, ft_strlen(str));
    if (str[j + 1] == '?' && *i == j + 1) {
        mid = ft_itoa(gl_exit);
    }
    else
        mid = ft_dollar_grep(i, j, str, env);
    free(str);
    str = ft_strjoin_free(start, mid);
    *i = ft_strlen(str);
    start = ft_strjoin_free(str, end);
    return (start);
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
