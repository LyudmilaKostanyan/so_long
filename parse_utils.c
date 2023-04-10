/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:13:41 by lykostan          #+#    #+#             */
/*   Updated: 2023/02/25 15:13:43 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_mes(char *str, int condition)
{
	if (condition)
	{
		perror(str);
		exit(1);
	}
}

void	parsing_rectangular(char **split)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(split[0]);
	while (split[++i])
		err_mes("Map isn't rectangular", ft_strlen(split[i]) != len);
}

void	parsing_borders(char **split)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (split[++i])
	{
		j = -1;
		if (split[i + 1] == NULL || i == 0)
			while (split[i][++j])
				err_mes("No walls", split[i][j] != 49);
		else
		{
			len = ft_strlen(split[i]) - 1;
			while (split[i][++j])
				err_mes("No walls", split[i][0] != 49 || split[i][len] != 49);
		}
	}
}

void	parsing_area(char **split)
{
	int	i;
	int	j;

	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
			err_mes("Other symbols in map", split[i][j] != '0'
				&& split[i][j] != '1' && split[i][j] != 'E'
				&& split[i][j] != 'P' && split[i][j] != 'C'
				&& split[i][j] != 'R');
	}
}

int	parsing_pce(const char *s)
{
	t_count	a;
	int		i;

	i = -1;
	a.p_count = 0;
	a.c_count = 0;
	a.e_count = 0;
	while (s[++i])
	{
		if (s[i] == 'E')
			a.e_count++;
		else if (s[i] == 'P')
			a.p_count++;
		else if (s[i] == 'C')
			a.c_count++;
	}
	err_mes("Few symbols in the map",
		a.c_count == 0 || a.e_count != 1 || a.p_count != 1);
	return (a.c_count);
}
