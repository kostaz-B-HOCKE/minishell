#include "../minishell.h"

void	mercury_repl_env(t_info *inf, char *str, char *way, int symb)
{
    t_env	*temp;

    temp = inf->env_lst;
    while (temp)
    {
        if (!ft_strncmp(temp->str, str, symb))
        {
            printf("%s///////%s\n",    YELLOW, RESET);
            printf("%s\n", temp->str);
            printf("%s///////%s\n",    YELLOW, RESET);
            free(temp->str);
            temp->str = NULL;
            temp->str = ft_strjoin(str, way);
            break ;
        }
        temp = temp->next;
    }
}

void    ftt_cd(t_info *inf)
{
    gl_exit = 0;
    print_me_env(inf);
    mercury_repl_env(inf, "_=", "cd", 2);
//    print_me_env(inf);
//    printf("cd ok\n");
//    print_me_env(inf);
//    printf("chdir:%d\n", chdir("/Users/eabradol/"));
//    printf("cd ok\n");
}
