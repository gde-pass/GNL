/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-pass <gde-pass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:36:02 by gde-pass          #+#    #+#             */
/*   Updated: 2018/01/31 13:22:25 by gde-pass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define ERROR -1
# define READLINE 1
# define ENDREAD 0
# define BUFF_SIZE 32

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

struct				s_reste
{
	int				fd;
	char			*reste;
	struct s_reste	*next;
};

int					get_next_line(const int fd, char **line);

#endif
