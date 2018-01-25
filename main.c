/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-pass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:56 by gde-pass          #+#    #+#             */
/*   Updated: 2018/01/23 16:02:43 by gde-pass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (42)
	{
		ret = get_next_line(fd, &line);
		if (ret == 0 || ret == -1)
			break ;

		printf("|%s|\n", line);
	}
	if (argc == 2)
		close (fd);
}
