/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:50:12 by lykostan          #+#    #+#             */
/*   Updated: 2023/01/28 20:50:14 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *s)
{
	int		size;
	int		i;
	char	*s1;

	s1 = "(null)";
	i = -1;
	if (s == NULL)
		while (++i < 6)
			write(1, &s1[i], 1);
	else
	{
		size = ft_strlen(s);
		while (++i < size)
			write(1, &s[i], 1);
	}
	return (i);
}
