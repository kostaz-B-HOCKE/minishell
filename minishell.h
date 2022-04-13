#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
#include "libft/libft.h"

int	gl_exit;

typedef struct	s_env
{
	char			*str;
	int				number_list;
	struct s_env	*next;
//	struct s_env	*previous;
}				t_env;

typedef struct	s_info
{
	char	*st_line;   //стартовая линия
	char	**split_line; //линия меняеться
	char	*line;		  //активка
	char	**split_pipex;
	char 	**env;



	char	*shlvl;
	t_env	*env_lst;
}		t_info;

//pipex
void	execute(char *argv, t_info *inf);
char	*find_path(char *cmd, t_info *inf);
int		ft_pipex(t_info *inf);

t_info	*init_info(char **env);

void	cheak_cmd(t_info *inf);
int		adopt_cmd(t_info *inf);

//parsing
int	parsing_s(t_info *inf, char *str);
void	two_mark(t_info *inf);
void	one_mark(t_info *inf);


//info.c
t_info	*init_info(char **env);
int	lst_add_back(t_info *inf, t_env *env_new);
t_env	*lst_new_env(char *str);
int	env_move(t_info *inf);


//shell_level.c
void	shell_level(t_info *inf);

//utilus.c
void	print_error(char *error, char *str);


#endif
