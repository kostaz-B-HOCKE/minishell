/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:15:53 by                   #+#    #+#             */
/*   Updated: 2021/10/14 14:58:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pom2(int n)
{
	int	t;

	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		t = 1;
		n = -n;
	}
	else
		t = 0;
	while (n > 0)
	{
		n = n / 10;
		t++;
	}
	return (t);
}

char	*pom1(int n, int t)
{
	char	*str;

	str = malloc(sizeof(char) * (t + 1));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[t--] = '\0';
	while (n > 0)
	{
		str[t--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	return (pom1(n, pom2(n)));
}
