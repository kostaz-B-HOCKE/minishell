/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:25:26 by                   #+#    #+#             */
/*   Updated: 2021/10/13 18:25:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*str1;
	int				i;

	i = 0;
	dst1 = (unsigned char *)dst;
	str1 = (unsigned char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (n > 0)
	{
		dst1[i] = str1[i];
		i++;
		n--;
	}
	return (dst);
}
