#include "../minishell.h"

//void    ft_exit()
//{
//
//
//}


void    ftt_echo(t_info *inf)
{
    int i;
    int option;

    i = 0;
    if (!inf->pipels->arg[1])
    {
        write(1, "\n", 1);
        return ;
    }
//    if (inf->pipels->arg[1][0] == ' ' && inf->pipels->arg[1][0] == 'n')
    while (inf->pipels->arg[++i])
    {
//        printf("EEE\n");
        printf("%s", inf->pipels->arg[i]);
        printf(" ");
    }
    while (inf->pipels->arg[i] && ft_strncmp(inf->pipels->arg[i], "-n", 3))
        i++;
    printf("\n");
//    write(1, "\n", 1);
}

