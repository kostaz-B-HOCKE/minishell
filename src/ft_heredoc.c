#include "../minishell.h"

char    *ft_heredok(char *str, int *i, t_info *inf)
{
    char    *start;
    char    *end;
    char    *line;
    int     n;
    int     j;

    start = init_redirect(str, i, &n);
    if (check_len(str + n) || check_token(str[n]))
        return (_free_str_2(start, str));
    j = n;
    pass_space_two(str, &n);
    end = ft_substr(str, n, ft_strlen(str));
    end = delete_spese(end);
    start[n++] = 0;
    line = ft_strdup(start + j);

//    ...
    return (str);
}
