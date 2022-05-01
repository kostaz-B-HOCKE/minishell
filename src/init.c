#include "../minishell.h"

t_env	*lst_new_env(char *str)
{
	t_env	*me_env;

	me_env = malloc(sizeof(t_env));
	if (!me_env)
		return (NULL);
	me_env->str = str;
	me_env->next = NULL;
	me_env->number_list = 0;
	return (me_env);
}

t_env	*start_list_env(t_info *inf)
{
	t_env	*start;
	t_env	*new;
	int		i;

	i = 1;
	start = lst_new_env(inf->env[0]);
	new = start;
	while (inf->env[i])
	{
		new->next = lst_new_env(inf->env[i++]);
		new = new->next;
	}
	return (start);
}

int	env_move(t_info *inf)
{
	if (!inf->env_lst)
		inf->env_lst = start_list_env(inf);
//    else
	    return (0);
}

t_info	*init_info(char **env)
{
	t_info	*inf;

	inf = malloc(sizeof(t_info));
	if (!inf) {
        return (NULL);
    }
    inf->is_pipe = 0;
    inf->env = env;
    inf->env_lst = NULL;
    inf->shlvl = NULL;
    inf->split_line = NULL;
    inf->split_pipex = NULL;
    inf->st_line = NULL;
    inf->pipels = NULL;
    inf->line = NULL;
    inf->fd_out = -1;
    inf->fd_in = -1;
    inf->fd_re_out = -1;
    inf->tmp_in = -1;
    inf->pipe_fd_in = -1;
    inf->pipe_fd_out = -1;
    inf->is_redirect = 0;
    inf->is_heredoc = 0;
    inf->is_dollar = 0;
    inf->pipe_index = 0;
	env_move(inf);
	return (inf);
}

void    print_me_env(t_info *inf)
{
    t_env *tmp;

	tmp = inf->env_lst;
	if (tmp != NULL)
	{
		while (tmp->next)
		{
			printf("%s\n",  tmp->str);
			tmp = tmp->next;
		}
		printf("%s\n", tmp->str);
	}
}

void    print_me_link(t_info *inf)
{
    t_link *tmp;

    tmp = inf->link;
    if (tmp != NULL)
    {
        while (tmp->next)
        {
            printf("link:%s\n",  tmp->str);
            tmp = tmp->next;
        }
        printf("link:%s\n", tmp->str);
    }
    else
        printf("no list link\n");
}

void    print_list_pipels(t_info *inf)
{
    t_pipels *tmp;
    int i;

    tmp = inf->pipels;
    if (tmp != NULL)
    {
        while (tmp->next)
        {
            printf("NO NULL\n");
            i = -1;
            while (tmp->arg[++i])
                printf("i%d:%s ", i, tmp->arg[i]);
            printf("\n");
            tmp = tmp->next;
        }
        i = -1;
        while (tmp->arg[++i])
            printf("i%d:%s ", i, tmp->arg[i]);
        printf("\n");
    }
    else
        printf("no list pipels\n");
}

void    re_init_by_inf(t_info *inf)
{
    inf->fd_in = -1;
    inf->fd_out = -1;
//    inf->


}