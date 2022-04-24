#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
#include "libft/libft.h"
# define SHELL_NAME "minishell% "
# define ERROR_NAME "minishell"
# define ONE_TOKEN "Error! Unclosed quote"
# define TWO_TOKEN "Error! Unclosed dquote"
# define THREE_TOKEN "Error! Unclosed pipe"
# define SYNTAX_TOKEN "syntax error"
# define COMMAND_TOKEN "command not found"
# define IN_TOKEN "syntax error near unexpected token `<'"
# define OUT_TOKEN "syntax error near unexpected token `>'"
# define PIPE_TOKEN "syntax error near unexpected token `|'"
# define NEW_TOKEN "syntax error near unexpected token `newline'"
# define BUFFER_SIZE 1024
# define D "/"
# define TTT t_link

int	gl_exit;

typedef struct  s_link
{
    char    *str;
    struct  s_link *next;
}           t_link;

typedef struct	s_env
{
	char			*str;
	int				number_list;
	struct s_env	*next;
//	struct s_env	*previous;
}				t_env;

typedef struct  s_pipels
{
    char        *str;
    int         fd_in;
    int         fd_out;
    int         fr_re_out;
    char        **arg;
    int         index;
    int         is_redirect;
    int         is_dollar;
    int			is_heredoc;
    char        *heredoc;
//    int         fd_
//    int         is_heredoc;
    struct s_pipels *next;
}   t_pipels;

typedef struct	s_info
{
	char	*st_line;   //стартовая линия
	char	**split_line; //линия меняеться
	char	*line;		  //активка
	char	**split_pipex;
	char 	**env;

    int     pipe_index;
    int     is_pipe;
    int     fd_in;
    int     fd_out;
    int     is_redirect;
    int     pipe_fd_in;
    int     pipe_fd_out;
    int		tmp_in;

	char	*shlvl;
    t_pipels *pipels;
    t_link  *link;
	t_env	*env_lst;
}		t_info;

//pipex
void	execute(char *argv, t_info *inf);
char	*find_path(char *cmd, t_info *inf);
int		ft_pipex(t_info *inf);

t_info	*init_info(char **env);
void    re_init_by_inf(t_info *inf);
void    print_me_env(t_info *inf);
void    print_me_link(t_info *inf);

void	cheak_cmd(t_info *inf);
int		adopt_cmd(t_info *inf);

//parsing
char	*delete_spese(char *str);
void    parsing_s(t_info *inf, char *str);
void	two_mark(t_info *inf);
char	*one_mark(t_info *inf, char *str, int *i);
char	*ft_gap(char *str, int *i, char c);
char	*ft_gap2(char *str, int *i, char c, t_info *inf);
char	*ft_dollar_pv(char *str, int *i, char **env);
char	*ft_slesh(char *str, int *i);
char	*delete_spese(char *str);
void    pass_space_two(char *input, int *i);
char	*init_redirect(char *str, int *i, int *n);
char    *bild_file_check(char *file_name, t_info *inf);
char	*ft_redirect_1(char *str, int *i, t_info *inf);
char	*get_next_line(int fd);// mood pet3
void    put_link_to_pipe(t_info *inf);


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

//check_util.c
int     check_token(char c);
int     check_len(char *s);

//free
char	*free_str_2(char *s1, char *s2);
char	*free_str_3(char *s1, char *s2, char *s3);
void	free_arr(char **arr);

//list_command_util.c
t_link  *list_new_mini(char *str);
void    link_add_list(t_link **old, t_link *new);
void    free_link(t_link **link);
int     link_size(t_link *link);

//pipe_list_utilus.c
int	pipes_size(t_pipels *pipes);

//exe_command.c
void    exe_command(t_info *inf);
void    cmd_exe(t_info *inf);


void    link_to_str(char *str, t_info *inf);
#endif
