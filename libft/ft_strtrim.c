/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:02 by                   #+#    #+#             */
/*   Updated: 2021/10/16 10:33:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t		n;
	char		*str;

	if (!s || !set)
		return (NULL);
	while (*s && ft_strchr(set, *s))
		s++;
	n = ft_strlen(s);
	while (n && ft_strchr(set, s[n]))
		n--;
	str = ft_substr((char *)s, 0, n + 1);
	return (str);
}
