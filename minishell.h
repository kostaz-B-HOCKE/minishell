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
char	*delete_spese(char *str);
int		parsing_s(t_info *inf, char *str, char **env);
void	two_mark(t_info *inf);
char	*one_mark(t_info *inf, char *str, int *i);
char	*ft_gap(char *str, int *i, char c);
char	*ft_gap2(char *str, int *i, char c, char **env);
char *ft_dollar(char *str, int *i, char **env);
char	*ft_slesh(char *str, int *i);

//info.c
t_info	*init_info(char **env);
int	lst_add_back(t_info *inf, t_env *env_new);
t_env	*lst_new_env(char *str);
int	env_move(t_info *inf);


//shell_level.c
void	shell_level(t_info *inf);

//utilus.c
void	print_error(char *error, char *str);
char	*ft_strjoin_free(char *s1, char *s2);



#endif
