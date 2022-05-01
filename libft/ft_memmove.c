/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:30:37 by                   #+#    #+#             */
/*   Updated: 2021/10/14 15:49:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (dst);
	if (src < dst)
	{
		while (len--)
			str1[len] = str2[len];
	}
	else if (src >= dst)
		while (len--)
			*(str1++) = *(str2++);
	return (dst);
}
