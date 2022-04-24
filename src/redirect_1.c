#include "../minishell.h"

int open_write_file(char *str, t_info *inf)
{
    int fd;
    char    *error;

    str = bild_file_check(str, inf);
    if (!str)
        return (1);
    fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, S_IWRITE | S_IREAD | S_IRGRP | S_IROTH);
    if (fd == -1)
    {
        gl_exit = 1;
        return (1);
    }
    free(str);
    close(inf->fd_out);
    inf->fd_out = fd;
    inf->is_redirect++;
    return (0);
}

char	*ft_redirect_1(char *str, int *i, t_info *inf)
{
    char    *start;
    char    *file;
    char    *end;
    int     n;
    int     j;

    printf("OPEN\n");
    start = init_redirect(str, i, &n);
    j = n;
    pass_space_two(str, &n);
    end = ft_substr(str, n, ft_strlen(str));
    end = delete_spese(end);//не дает с
    start[n++] = 0;
    file = ft_strdup(start + j);
    printf("file_new:%s\n", file);
    open_write_file(file, inf);
    return (str);
}
