#include "../minishell.h"

char	*build_error_str(char *file)
{
    char	*error;
    char	*tmp;

    error = ft_strjoin(ERROR_NAME, ": ");
    tmp = error;
    error = ft_strjoin(error, file);
    free(tmp);
    return (error);
}

void	micro_print_err(char *cmd)
{
    char	*err;

    err = build_error_str(cmd);
    write(2, err, ft_strlen(err));
    write(2, ": ", 2);
    write(2, COMMAND_TOKEN, ft_strlen(COMMAND_TOKEN));
    write(2, "\n", 1);
    free(cmd);
    free(err);
}