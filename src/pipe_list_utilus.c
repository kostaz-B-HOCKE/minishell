#include "../minishell.h"

int	pipes_size(t_pipels *pipes)
{
    int		count;

    count = 0;
    while (pipes)
    {
        count++;
        pipes = pipes->next;
    }
    return (count);
}
