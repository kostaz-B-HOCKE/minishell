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
	{
		inf->env_lst = start_list_env(inf);
	}
	return (0);
}

t_info	*init_info(char **env)
{
	t_info	*inf;

	inf = malloc(sizeof(t_info));
	if (!inf)
		return (NULL);
	inf->env_lst = NULL;
	inf->env = env;
	inf->shlvl = NULL;
	inf->split_line = NULL;
	inf->line = NULL;
	inf->st_line = NULL;
	inf->split_pipex = NULL;
	env_move(inf);
	return (inf);
}
