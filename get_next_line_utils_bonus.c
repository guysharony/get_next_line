#include "get_next_line_bonus.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	a;

	a = -1;
	while (++a < ft_strlen(s) + 1)
		if (*(s + a) == (char)c)
			return ((char *)(s + a));
	return (NULL);
}

int			ft_linelen(char *str)
{
	int		a;

	a = 0;
	while (str[a] != '\n' && str[a] != '\0')
		a++;
	return (a);
}

size_t		ft_strlen(const char *s)
{
	size_t	t;

	t = 0;
	while (s[t] != '\0')
		t++;
	return (t);
}

char		*get_line(char *content)
{
	if (ft_strchr(content, '\n'))
		return (ft_strcpy(content, ft_strchr(content, '\n') + 1));
	else if (ft_linelen(content) > 0)
		return (ft_strcpy(content, ft_strchr(content, '\0')));
	return (NULL);
}

char		*ft_strcpy(char *dest, const char *src)
{
	unsigned int a;

	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}