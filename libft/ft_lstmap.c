/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:16:02 by                   #+#    #+#             */
/*   Updated: 2021/10/15 13:16:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ll;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	ll = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&ll, del);
			return (NULL);
		}
		ft_lstadd_back(&ll, new);
		lst = lst->next;
	}
	return (ll);
}
