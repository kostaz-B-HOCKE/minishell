#include "../minishell.h"

char    **put_link_to_arg(int size, t_info *inf)
{
    int i;
    char **res;

    i = 0;
    res = malloc(sizeof(char *) * size + 1);
    if (!res)
        return (NULL);
    while (inf->link)
    {
        res[i] = inf->link->str;
        inf->link = inf->link->next;
        i++;
    }
    res[i] = NULL;
    return (res);
}



t_pipels *new_list_pipe(char **arg, t_info *inf)
{
    t_pipels *new;

    new = malloc(sizeof(t_pipels));
    if (!new)
        return (NULL);
    new->index = inf->pipe_index;
    new->arg = arg;
    if (inf->heredoc)
        new->heredoc = ft_strdup(inf->heredoc);
    else
        new->heredoc = NULL;
    new->next = NULL;
    new->is_redirect = inf->is_redirect;
    new->fd_in = inf->fd_in;
    new->fd_out = inf->fd_out;
    new->fr_re_out = inf->fd_re_out;
    new->is_heredoc = inf->is_heredoc;
    new->is_dollar = inf->is_dollar;
    return (new);
}

void    pipes_add_back(t_pipels **old, t_pipels *new)
{
    t_pipels *tmp;

    tmp = *old;
    if (tmp && new)
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void    put_link_to_pipe(t_info *inf)
{
    t_link  *tmp;
    int     size;
    char    **arg;

    size = link_size(inf->link);
    tmp = inf->link;
    arg = put_link_to_arg(size, inf);
    if (!inf->pipels) {
        inf->pipels = new_list_pipe(arg, inf);
    }
    else
    {
        pipes_add_back(&(inf->pipels), new_list_pipe(arg, inf));
        inf->is_pipe = 1;
    }
    inf->pipe_index++;
    re_init_by_inf(inf);
    free_link(&tmp);
    inf->link = NULL;
}
