#include "../minishell.h"

//препарсинг

int prepars(char *str, int *i, char c)
{
    while(str[++(*i)])
    {
        if (str[(*i)] == c) {
            return (0);
        }
    }
    printf("%s: %s\n", ERROR_NAME, "Error! Unclosed quote");
    free(str);
    return (1);
}

char	*ft_gap(char *str, int *i, char c)
{
	int j = *i;
	char *tmp;
	char *tmp2;
	char *tmp3;

    if (prepars(str, i, c))
        return (NULL);
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp = ft_strjoin_free(tmp, tmp2);
	tmp3 = ft_strdup(str + *i + 1);
	tmp2 = ft_strjoin(tmp, tmp3);
	free(str);
    free(tmp);
    free(tmp3);
	*i = *i - 2;
	return (tmp2);
}

char *prepars_two(char *str, int *i, char c, t_info *inf)
{
    while(str[++(*i)])
    {
        if (str[*i] == '$' && (ft_isalnum(str[*i + 1]) || str[*i + 1] == '?')) {
            str = ft_dollar_pv(str, i, inf->env);
        }
        if (str[(*i)] == c)
            return (str);
    }
    free(str);
    return (NULL);
}

char	*ft_gap2(char *str, int *i, char c, t_info *inf)
{
	int	j = *i;
	char *tmp;
	char *tmp2;
	char *tmp3;

    if (!(str = prepars_two(str, i, c, inf)))
        return (NULL);
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp = ft_strjoin_free(tmp, tmp2);
	tmp3 = ft_strdup(str + *i + 1);
	tmp2 = ft_strjoin(tmp, tmp3);
	free(str);
    if (ft_strlen(tmp2) == 0)
        link_to_str(tmp2, inf);
	*i = *i - 2;
    free(tmp);
    free(tmp3);
	return (tmp2);
}
