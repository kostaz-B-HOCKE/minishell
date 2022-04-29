#include "../minishell.h"

void    link_to_str(char *str, t_info *inf)
{
    if (!inf->link)
        inf->link = list_new_mini(str);
    else
        link_add_list(&(inf->link), list_new_mini(str));
}

int	ft_envsize(t_env *lst)
{
    int	amount;

    amount = 0;
    while (lst)
    {
        lst = lst->next;
        amount++;
    }
    return (amount);
}
