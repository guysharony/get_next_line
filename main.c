/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 08:47:44 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/28 09:19:31 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libc.h>

int		main(int ac, char **av)
{
	int		file;
	char	*line;
	int		ret;

	if (ac > 1)
	{
		file = open(av[1], O_RDONLY);
		ret = get_next_line(file, &line);
		printf("Line [%d]: %s\n", ret, line);
	}
	return (0);
}
