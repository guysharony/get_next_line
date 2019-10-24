/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:28:01 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/24 13:20:23 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		file;
	int		c;
	char	*line;

	if (argc > 1)
	{
		file = open(argv[1], O_RDONLY);
		while ((c = get_next_line(file, &line)))
			printf("File descriptor[%d]: %s\n", c, line);
	}
	else
		printf("Please enter a file name!\n");
	return (0);
}
