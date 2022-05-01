/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:45:01 by                   #+#    #+#             */
/*   Updated: 2021/10/16 14:24:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	n;

	i = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(&s[i]);
	if (n < len)
		len = n;
	if (start > n)
		len = 0;
	str = malloc(sizeof(char ) * (len + 1));
	if (!str)
		return (NULL);
	n = 0;
	while (s[start] && n < len)
		str[n++] = s[start++];
	str[n] = '\0';
	return (str);
}
