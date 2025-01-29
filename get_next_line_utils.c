#include "get_next_line.h"


size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
        return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
        return (NULL);
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (!src)
        return (0);
	i = 0;
	if (n > 0)
	{
		while (i < n - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (NULL);
    if (s1 == NULL)
	{
        s1 = "";
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(&str[0], s1, len1 + 1);
	ft_strlcpy(&str[len1], s2, len2 + 1);
	free(s1);
	return (str);
}