/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-pass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:27:11 by gde-pass          #+#    #+#             */
/*   Updated: 2018/01/23 18:38:52 by gde-pass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

struct s_reste	*ft_find_fd(const int fd, struct s_reste *first)
{
	struct s_reste	*tmp;

	tmp = first;
	while (first != NULL && first->fd != fd)
		first = first->next;
	if (first == NULL)
	{
		if (!(first = (struct s_reste*)malloc(sizeof(struct s_reste))))
			return (NULL);
		first->fd = fd;
		first->reste = NULL;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = first;
	}
	return (first);
}

int				ft_check_bn(struct s_reste *cw, int *n)
{
	int			i;

	i = 0;
	while (cw->reste[i] != '\0')
	{
		if (cw->reste[i] == '\n')
		{
			*n = i;
			return (1);
		}
		i++;
	}
	return (0);
}

struct s_reste	*ft_reset_reste(const int fd, struct s_reste *cw, int n)
{
	int				i;
	struct s_reste	*newreste;

	i = 0;
	if (!(newreste = (struct s_reste*)malloc(sizeof(struct s_reste))))
		return (NULL);
	newreste->fd = fd;
	newreste->next = cw->next;
	if (!(newreste->reste = (char *)malloc(sizeof(char) \
					* (ft_strlen(cw->reste) - n))))
		return (NULL);
	n++;
	while (cw->reste[n] != '\0')
	{
		newreste->reste[i] = cw->reste[n];
		i++;
		n++;
	}
	newreste->reste[i] = '\0';
	cw->reste = newreste->reste;
	free(newreste);
	return (cw);
}

int				get_next_line(const int fd, char **line)
{
	static struct s_reste	*first = NULL;
	struct s_reste			*cw;
	char					buffer[BUFF_SIZE + 1];
	int						n;
	ssize_t					vrr;

	cw = NULL;
	ft_bzero(buffer, BUFF_SIZE + 1);
	n = 0;
	if (fd < 3 || BUFF_SIZE < 1 || line == NULL)
		return (ERROR);

	if (first == NULL)
	{
		if (!(first = (struct s_reste*)malloc(sizeof(struct s_reste))))
			return (ERROR);
		first->fd = fd;
		first->reste = NULL;
		first->next = NULL;
	}
	cw = ft_find_fd(fd, first);
	if (cw->reste == NULL)
	{
		if (!(cw->reste = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (ERROR);
		vrr = read(fd, cw->reste, BUFF_SIZE);
		if (vrr == -1)
			return (ERROR);
		cw->reste[vrr] = '\0';
	}
	while (ft_check_bn(cw, &n) == 0)
	{
		ft_bzero(buffer, BUFF_SIZE);
		vrr = read(fd, buffer, BUFF_SIZE);
		if (vrr == -1)
			return (ERROR);
		else if (vrr == 0)
			return (ENDREAD);
		buffer[vrr] = '\0';
		cw->reste = ft_strjoin(cw->reste, buffer);
	}
	if (!(*line = (char *)malloc(sizeof(char) * (n + 1))))
		return (ERROR);
	*line = ft_strncpy(*line, cw->reste, n);
	(*line)[n] = '\0';
	cw = ft_reset_reste(fd, cw, n);
	return (READLINE);
}
