/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-pass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:27:11 by gde-pass          #+#    #+#             */
/*   Updated: 2018/01/22 19:33:54 by gde-pass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_load_first_lunch(const int fd, ssize_t *ret, char **reste)
{
  *reste = malloc(sizeof(char) * (BUFF_SIZE + 1));
  *ret = read(fd, *reste, BUFF_SIZE);
  (*reste)[*ret] = '\0';
}

int				ft_check_bn(char *reste, int *n)
{
	int			i;

	i = 0;
	while (reste[i] != '\0')
	{
		if (reste[i] == '\n')
		{
			*n = i;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_reset_reste(char *reste, int n)
{
	int				i;
	char	    *newreste;

	i = 0;
	n = n + 1;
  newreste = malloc(sizeof(char) * (ft_strlen(reste) - n + 1));
	while (reste[n] != '\0')
	{
		newreste[i] = reste[n];
		i++;
		n++;
	}
	newreste[i] = '\0';
	reste = newreste;
  free(newreste);
	return (reste);
}

void ft_line(char ***line, int n, char *reste)
{
  **line = malloc(sizeof(char) * (n + 1));
  **line = ft_strncpy(**line, reste, n);
  (**line)[n] = '\0';
}

int get_next_line(const int fd, char **line)
{
  static char *reste = NULL;
  int         n;
  char        *buffer;
  ssize_t     ret;

  buffer = ft_strnew(BUFF_SIZE + 1);
  n = 0;
  if (fd < 3 || BUFF_SIZE < 1 || line == NULL)
		return (ERROR);

  if (reste == NULL)
    ft_load_first_lunch(fd, &ret, &reste);

  while (ft_check_bn(reste, &n) == 0)
  {
    ret = read(fd, buffer, BUFF_SIZE);
    if (ret == 0)
      return(ENDREAD);
    buffer[ret] = '\0';
    reste = ft_strjoin(reste, buffer);
  }
  ft_line(&line, n, reste);
  reste = ft_reset_reste(reste, n);
  return (READLINE);
}
