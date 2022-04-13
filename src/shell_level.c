#include "../minishell.h"

static int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static void shell_level_pars(t_info *inf, char *str)
{
	int number;
	int		lvl;
//	char *

	if (check_digit(str))
	{
		number = ft_atoi(str);
		if (number < 0)
			;
		if (number == 999)
			;
		else if (number < 1000)
			;
		else
		{
			print_error("", "shell level (1000) too high, resetting to 1");
		}
	}
}

void	shell_level(t_info *inf)
{
	t_env	*tmp;
	char	*str;
	int		lvl;

	tmp = inf->env_lst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->str, "SHLVL=", 6))
			str = ft_substr(tmp->str, 6, ft_strlen(tmp->str) - 6);
		tmp = tmp->next;
	}
	shell_level_pars(inf, str);
	lvl = ft_atoi(str);
	lvl++;
	inf->shlvl = ft_itoa(lvl);
	free(str);
}
