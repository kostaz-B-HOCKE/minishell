#include "../minishell.h"

void	mercury_repl_env(t_info *inf, char *str, char *way, int symb)
{
    t_env	*temp;

    temp = inf->env_lst;
    while (temp)
    {
        if (!ft_strncmp(temp->str, str, symb))
        {
//            printf("%s///////%s\n",    RED, RESET);
//            printf("%s\n", temp->str);
//            if (temp->str)
//                free(temp->str);
            temp->str = NULL;
            temp->str = ft_strjoin(str, way);
            printf("%s\n", temp->str);
            break ;
        }
        temp = temp->next;
    }
}

int get_var_env(t_info *inf, char **way, char *key_word, int n)
{
    t_env   *tmp;

    tmp = inf->env_lst;
    while (tmp)
    {
        if (!ft_strncmp(tmp->str, key_word, n))
        {
            *way = tmp->str + n;
            // printf("%s\n", key_word);
            // printf("%s\n", tmp->str + n);
            return (0);
        }
        tmp = tmp->next;
    }
    return (1);
}

void	do_chdir(char *str)
{
    int	fd;

    fd = 0;
    fd = open(str, O_DIRECTORY);
    ft_putstr_fd("minishell: cd: ", 2);
    ft_putstr_fd(str, 2);
    if (access(str, 0) < 0)
        ft_putendl_fd(": No such file or directory", 2);
    else if (fd < 0)
        ft_putendl_fd(": Permission denied", 2);
    else
        write(2, "\n", 1);
    if (fd > 0)
        close(fd);
    gl_exit = 1;
}

void    one_arg(t_info *inf)
{
    char    *way;

    if (get_var_env(inf, &way, "HOME=", 5))
    {
        print_error(" : HOME not set", "cd");
        return ;
    }
  if (chdir(way))
        do_chdir(way);
    // get_var_env(inf, &way, "PWD=", 4);
    // printf("%sCHEK%s\n",    YELLOW, RESET);
    mercury_repl_env(inf, "OLDPWD=", way, 7);
    // get_var_env(inf, &way, "HOME=", 5);
    mercury_repl_env(inf, "PWD=", way, 4);
    // get_var_env(inf, &way, "PWD=", 4);
    // get_var_env(inf, &way, "OLDPWD=", 7);
    // printf("qqq\n");
}

void    cd_way(t_info *inf, char *way)
{
    char    *tmp;
    char    *tmp2;

    if (inf->pipels->arg[1][0] == '/')
    {
        tmp2 = ft_strjoin(way, "/");
        tmp = ft_strjoin(tmp2, inf->pipels->arg[1]);
        free(tmp2);
        if (chdir(tmp) >= 0)
        {
            mercury_repl_env(inf, "OLDPWD=", way, 7);
            mercury_repl_env(inf, "PWD=", tmp, 4);
        }
        else
            do_chdir(inf->pipels->arg[1]);
        free(tmp);
    }
    else if (chdir(inf->pipels->arg[1]) >= 0)
    {
        mercury_repl_env(inf, "OLDPWD=", way, 7);
        mercury_repl_env(inf, "PWD=", inf->pipels->arg[1], 4);
    }
    else {
        do_chdir(inf->pipels->arg[1]);
    }
}

void    cd_back(t_info *inf)
{


}

void    ftt_cd(t_info *inf)
{
    gl_exit = 0;
    char    *way;

//    printf("inf->pipels->arg[1]:%s\n", inf->pipels->arg[1]);
//    printf("%s///////%s\n", YELLOW, RESET);
//    print_me_env(inf);
    mercury_repl_env(inf, "_=", "cd", 2);
    if (!inf->pipels->arg[1])
        one_arg(inf);
    else if (inf->pipels->arg[1] && !ft_strncmp(inf->pipels->arg[1], "..", 2) && ft_strlen(inf->pipels->arg[1]) == 2)
        cd_back(inf);
    else if (inf->pipels->arg[1] && !ft_strncmp(inf->pipels->arg[1], ".", 1) && ft_strlen(inf->pipels->arg[1]) == 1)
    {
        get_var_env(inf, &way, "PWD=", 4);
        // printf("way:%s\n", way);
        // chdir(way);
        mercury_repl_env(inf, "OLDPWD=", way, 7);
        return ;
    }
    else {
        get_var_env(inf, &way, "PWD=", 4);
        cd_way(inf, way);
    }

//    mercury_repl_env(inf, "_=", "cd", 2);//зачем ?
//    if (!in)
//    print_me_env(inf);
//    printf("cd ok\n");
//    print_me_env(inf);
//    printf("chdir:%d\n", chdir("/Users/eabradol/"));
//    printf("cd ok\n");
}
