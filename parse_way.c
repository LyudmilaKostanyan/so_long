/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:08:28 by lykostan          #+#    #+#             */
/*   Updated: 2023/02/28 20:08:30 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	split_size(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		;
	return (i);
}

char	**split_dup(char **split)
{
	char	**s;
	int		i;

	s = malloc(sizeof(char *) * (split_size(split) + 1));
	if (s == NULL)
		return (NULL);
	i = -1;
	while (split[++i])
	{
		s[i] = ft_strdup(split[i]);
		if (s[i] == NULL)
		{
			while (--i > -1)
				free(s[i]);
			return (NULL);
		}
	}
	s[i] = NULL;
	return (s);
}

int	way_check(char **split, int y, int x)
{
	if (split[y][x] == '1' || split[y][x] == 'R' || y < 0 || x < 0)
		return (0);
	if (split[y][x] == 'E')
		return (1);
	split[y][x] = '1';
	if (way_check(split, y, x + 1))
		return (1);
	if (way_check(split, y, x - 1))
		return (1);
	if (way_check(split, y - 1, x))
		return (1);
	if (way_check(split, y + 1, x))
		return (1);
	return (0);
}

int	coin_way_check(char **split, int y, int x, int *c)
{
	if (split[y][x] == '1' || split[y][x] == 'R' || y < 0 || x < 0)
		return (0);
	else if (split[y][x] == 'C')
		*c -= 1;
	if (*c == 0)
		return (77);
	split[y][x] = '1';
	if (coin_way_check(split, y, x + 1, c))
		return (100);
	if (coin_way_check(split, y, x - 1, c))
		return (100);
	if (coin_way_check(split, y - 1, x, c))
		return (100);
	if (coin_way_check(split, y + 1, x, c))
		return (100);
	return (0);
}

void	parsing_way(char **split, int c)
{
	int		i;
	int		j;
	char	**s;
	char	**s2;

	i = -1;
	s = split_dup(split);
	s2 = split_dup(split);
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			if (split[i][j] == 'P')
			{
				if (!way_check(s, i, j) || coin_way_check(s2, i, j, &c) != 100)
				{
					perror("Error\n");
					exit(1);
				}
			}
		}
	}
	split_free(s);
	split_free(s2);
}
