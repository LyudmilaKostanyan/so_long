/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:50:28 by lykostan          #+#    #+#             */
/*   Updated: 2023/01/28 20:50:29 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr_pf(const char *str, int c)
{
	int	i;

	i = -1;
	c %= 256;
	if (c == 0)
		return (ft_strlen(str) - 1);
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}
