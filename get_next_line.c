/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:25:51 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:46 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strdup(const char *s1)
{
	char	*a;

	if (!(a = (char*)malloc(sizeof(*a) * (ft_strlen(s1) + 1))))
		return (NULL);
	return (ft_strcpy(a, (char *)s1));
}

static char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		b;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	b = ft_strlen(s1) + ft_strlen(s2);
	if ((!(a = (char*)malloc(sizeof(char) * (b + 1)))))
		return (NULL);
	b = 0;
	while (*s1)
		a[b++] = *s1++;
	while (*s2)
		a[b++] = *s2++;
	a[b] = '\0';
	return (a);
}

static int		ft_linelen(char *str)
{
	int		a;

	a = 0;
	while (str[a] != '\n')
		a++;
	return (a);
}

static char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	b;

	b = 0;
	if (!s)
		return (NULL);
	if (!(a = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (ft_strlen(s) > start)
	{
		while (s[start + b] && b < len)
		{
			a[b] = s[start + b];
			b++;
		}
	}
	a[b] = '\0';
	return (a);
}

int				get_next_line(int fd, char **line)
{
	char			a[BUFFER_SIZE + 1];
	static char		*b;
	int				c;

	if (!b && (b = ft_strnew(0)) == NULL)
		return (-1);
	while ((c = read(fd, a, BUFFER_SIZE)) > 0)
	{
		a[c] = '\0';
		b = ft_strjoin(b, a);
	}
	*line = ft_substr(b, 0, ft_linelen(b));
	if (ft_strchr(b, '\n'))
	{
		ft_strcpy(b, ft_strchr(b, '\n') + 1);
		return (1);
	}
	return (0);
}
