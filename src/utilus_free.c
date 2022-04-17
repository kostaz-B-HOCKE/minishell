#include "../minishell.h"

static size_t	ft_max_size(void)
{
	size_t	max_size;
	size_t	bits;

	max_size = 1;
	bits = sizeof(size_t) * 8;
	while (bits--)
	{
		max_size = max_size * 2;
	}
	return (max_size - 1);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	max_size;
	size_t	len;
	size_t	len1;
	size_t	len2;	
	char	*s;

	max_size = ft_max_size();
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((len1 != max_size) && ((max_size - len1 - 1) >= len2))
		len = len1 + len2;
	else
		return (NULL);
	s = (char *)malloc(len + 1);
	if (s == NULL)
		return (NULL);
	ft_memcpy((void *)s, (const void *)s1, len1);
	ft_memcpy((void *)(s + len1), (const void *)s2, len2 + 1);
	free(s2);
	free(s1);
	return (s);
}
