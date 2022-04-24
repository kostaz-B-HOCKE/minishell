#include "../minishell.h"

char	*free_str_2(char *s1, char *s2)
{
    free(s1);
    free(s2);
    return (NULL);
}

char	*free_str_3(char *s1, char *s2, char *s3)
{
    free(s1);
    free(s2);
    free(s3);
    return (NULL);
}

void	free_arr(char **arr)
{
    int	i;

    if (arr)
    {
        i = 0;
        while (arr[i])
            free(arr[i++]);
        free(arr);
    }
}

//void	free_pipes(t_pipels **pipes)
//{
//    t_pipels    *tmp;
//
//    while (*pipes)
//    {
//        free_arr((*pipes)->arg);
//        free((*pipes)->heredoc);
//        tmp = *pipes;
//        *pipes = (*pipes)->next;
//        free(tmp);
//    }
//}