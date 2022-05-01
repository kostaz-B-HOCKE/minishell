/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:30:26 by                   #+#    #+#             */
/*   Updated: 2021/10/16 14:39:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*kill_memory(char **s, char word)
{
	int	j;

	j = 0;
	while (j < word)
	{
		free(s[j]);
		j++;
	}
	free(s);
	return (NULL);
}

int	kolvo(char *s, char c)
{
	int		i;
	size_t	u;

	i = -1;
	u = 0;
	while (s[++i])
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			u++;
	}
	return (u);
}

int	count_strrr(char *s, char c)
{
	size_t	u;

	u = 0;
	while (s[u] != c && s[u] != '\0')
		u++;
	return (u);
}

char	**memory(char **s_str, char *s, char c, int count)
{
	int		i;
	size_t	u;
	size_t	j;

	i = -1;
	while (++i < count)
	{
		while (*s == c)
			s++;
		u = count_strrr(s, c);
		s_str[i] = (char *)malloc(sizeof(char ) * u + 1);
		if (!s_str[i])
			return (kill_memory(s_str, i));
		j = 0;
		while (j < u)
			s_str[i][j++] = *s++;
		s_str[i][j] = '\0';
	}
	s_str[i] = 0;
	return (s_str);
}

char	**ft_split(char *s, char c)
{
	char	**s_str;
	int		count;

	if (!s)
		return (0);
	count = kolvo(s, c);
	s_str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!s_str)
		return (0);
	s_str = memory(s_str, s, c, count);
	return (s_str);
}
