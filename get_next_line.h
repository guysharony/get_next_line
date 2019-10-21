/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:50:55 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/19 11:43:32 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
int		get_line_length(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif
