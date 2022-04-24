#include "../minishell.h"

void	print_error(char *error, char *str)
{
	ft_putstr_fd("\033[0;31m\033[1mminishell ▸ \033[0m", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(error, 2);
	gl_exit = 1;
}

char	*ft_strjoin_free(char *s1, char *s2)
{
    size_t	i;
    size_t	n;
    char	*str;
    size_t	len;

    i = 0;
    n = 0;
    if (!s1 || !s2)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2);
    str = malloc(sizeof(char) * len + 1);
    if (!str)
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[n])
    {
        str[i + n] = s2[n];
        n++;
    }
    str[i + n] = '\0';
    free(s1);
    free(s2);
    return (str);
}
