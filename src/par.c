#include "../minishell.h"

void	one_mark(t_info *inf)
{
	printf("|\'|\n");
}

void	_two_mark(t_info *inf)
{
	printf("|\"|\n");
}

int	delete_spese(char *str)
{
	int i;

	while (str[i] && str[i] == ' ')
		i++;
//	str = ft_substr()

	return (0);
}

int	parsing_s(t_info *inf, char *str)
{
	int i;

	i = 0;

//	str = delete_spese(str);
//	ft_split(inf->line, ' ');
//	while (inf->)
//	if (ft_strnstr(inf->st_line, "\'", ft_strlen(inf->st_line)))
//		one_mark(inf);
//	if (ft_strnstr(inf->st_line, "\"", ft_strlen(inf->st_line)))
//		two_mark(inf);
	return (0);
}
