/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 06:39:18 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/29 07:25:14 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*ft_strdup(const char *s1)
{
	char	*a;

	if (!(a = (char*)malloc(sizeof(*a) * (ft_strlen(s1) + 1))))
		return (NULL);
	return (ft_strcpy(a, (char *)s1));
}

static char		*ft_strnew(void)
{
	char	*a;

	if (!(a = (char *)malloc(sizeof(char) * (1))))
		return (NULL);
	a[0] = '\0';
	return (a);
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
	char			buffer[BUFFER_SIZE + 1];
	static char		*content[4096];
	int				read_output;
	char			*tmp;

	if ((!content[fd] && !(content[fd] = ft_strnew())) || fd < 0
	|| !line || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	while (!(ft_strchr(content[fd], '\n')) &&
	(read_output = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_output] = '\0';
		tmp = content[fd];
		content[fd] = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	*line = ft_substr(content[fd], 0, ft_linelen(content[fd]));
	if (get_line(content[fd]) == NULL)
	{
		free(content[fd]);
		content[fd] = NULL;
		return (0);
	}
	return (1);
}
