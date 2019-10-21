/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:49:42 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/21 13:50:53 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*ft_strchr(const char *s, int c)
{
	size_t	a;

	a = -1;
	while (++a < ft_strlen(s) + 1)
		if (*(s + a) == (char)c)
			return ((char *)(s + a));
	return (NULL);
}

static char		*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(s, '\0', size + 1);
	return (s);
}

static int		ft_linelen(char *a)
{
	int		b;

	b = 0;
	while (a[b] != '\n')
		b++;
	return (b);
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

int				get_next_line(int fd, char **line)
{
	char			a[BUFFER_SIZE + 1];
	static char		*b[200];
	int				c;

	if (!b[fd] && (b[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while ((c = read(fd, a, BUFFER_SIZE)) > 0)
	{
		a[c] = '\0';
		b[fd] = ft_strjoin(b[fd], a);
	}
	*line = ft_substr(b[fd], 0, ft_linelen(b[fd]));
	if (ft_strchr(b[fd], '\n'))
	{
		ft_strcpy(b[fd], ft_strchr(b[fd], '\n') + 1);
		return (1);
	}
	return (0);
}
