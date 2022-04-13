#include "../minishell.h"

void	print_error(char *error, char *str)
{
	ft_putstr_fd("\033[0;31m\033[1mminishell ▸ \033[0m", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(error, 2);
	gl_exit = 1;
}
