/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-pass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:48:29 by gde-pass          #+#    #+#             */
/*   Updated: 2018/01/23 15:56:16 by gde-pass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;
	struct stat	chat;

	(void)argc;
	while (*++argv)
	{
		fd = open(*argv, O_RDONLY);
		if (stat(*argv, &chat))
		{
			printf("bad file %s\n", *argv);
			continue ;
		}
		if ((chat.st_mode & S_IXUSR))
		{
			printf("bad file bad access or not regular %s\n", *argv);
			continue ;
		}
		printf("\33[38;2;255;23;255mI open %s\n\33[37m", *argv);
		while (23)
		{
			ret = get_next_line(fd, &line);
			if (ret == -1)
				break ;
			printf("[%d]%s\n", ret, line);
			if (!ret)
				break ;
		}
	}
	//while (42)
	//	continue ;
}
