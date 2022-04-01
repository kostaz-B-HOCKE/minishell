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

typedef struct	s_info
{
	char	*st_line;
	char	**split_line;
	char	**split_pipex;
	char 	**env;


}		t_info;


//pipex
char	*find_path(char *cmd, char **envp);



int		init_info(t_info *inf, char **env);

#endif