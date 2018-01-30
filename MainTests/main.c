/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-pass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:56 by gde-pass          #+#    #+#             */
/*   Updated: 2018/01/30 16:34:57 by gde-pass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	if (argc != 2)
	{
		ft_putstr("\33[31mUsage : 'a.out [File to read]'\n");
		return (ERROR);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		ft_putstr("\033[31mFailed to open argv[1]\n");
		return (ERROR);
	}
	while (42)
	{
		ret = get_next_line(fd, &line);
		if (ret == 0 || ret == -1)
			break ;
		ft_putendl(line);
	}
	if (argc == 2)
		{
			char *filename = argv[1];
			char *exename = argv[0];
			char *cmd = ft_strjoin (exename, " "); cmd = ft_strjoin(cmd, filename);
			char *redir = " > Tocompare.txt"; cmd = ft_strjoin(cmd, redir);
			system(cmd);
			close (fd);
			system("/Users/gde-pass/Documents/workspace42/GNL/script.sh");
		}
}
