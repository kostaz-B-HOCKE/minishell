#include "../minishell.h"

void    link_to_str(char *str, t_info *inf)
{
    if (!inf->link)
        inf->link = list_new_mini(str);
    else
        link_add_list(&(inf->link), list_new_mini(str));
}
