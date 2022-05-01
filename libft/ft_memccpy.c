/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:22:08 by                   #+#    #+#             */
/*   Updated: 2021/10/14 15:29:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)d;
	str2 = (unsigned char *)s;
	if (!d && !s)
		return (d);
	while (n--)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)c)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
