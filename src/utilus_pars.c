#include "../minishell.h"

char    *bild_file_check(char *file_name, t_info *inf)
{
    int i;

    i = -1;
    while (file_name[++i])
    {
        if (file_name[i] == '$')
            ft_dollar_pv(file_name, &i, inf->env);
        if (file_name[i] == '\'')
            ft_gap(file_name, &i, '\'');
//        if (file_name[i] == '\"')
//            ft_gap2(file_name, &i, '\"', inf->env_lst);
        if (!(*file_name))
            return (NULL);
    }
    return (file_name);
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
