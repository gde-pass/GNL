/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-pass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:29:23 by gde-pass          #+#    #+#             */
/*   Updated: 2017/11/16 17:41:05 by gde-pass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\v' \
			|| c == '\f' || c == '\r' || c == '\n')
		return (1);
	else
		return (0);
}
