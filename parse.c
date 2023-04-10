/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:08:34 by lykostan          #+#    #+#             */
/*   Updated: 2023/02/28 20:08:36 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void *i)
{
	(void)i;
	exit(0);
}

void	split_free(char **split)
{
	int	i;

	i = split_size(split) - 1;
	while (i > -1)
	{
		free(split[i]);
		i--;
	}
	free(split);
	split = NULL;
}

char	*ft_open(char *file, int count)
{
	int		fd;
	char	*s;
	char	*str;
	int		i;

	s = malloc(count + 1);
	err_mes("Malloc error", s == NULL);
	fd = open(file, O_RDONLY);
	read(fd, s, count);
	s[count] = 0;
	close(fd);
	str = ft_strtrim(s, "\n");
	i = 0;
	while (str[++i])
		err_mes("Incorrect map", str[i] == '\n' && str[i - 1] == '\n');
	free(str);
	return (s);
}

char	**parse(char *file, int count, int *c)
{
	char	**split;
	char	*s;

	s = ft_open(file, count);
	split = ft_split(s, '\n');
	err_mes("Malloc error", split == NULL);
	parsing_rectangular(split);
	parsing_borders(split);
	*c = parsing_pce(s);
	parsing_area(split);
	parsing_way(split, *c);
	free(s);
	return (split);
}

char	**area(char *file, int *c)
{
	char	**split;
	int		fd;
	char	a;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	err_mes("Wrong fd", fd < 0);
	while (read(fd, &a, 1) > 0)
		count++;
	err_mes("Read error", count == 0);
	close(fd);
	split = parse(file, count, c);
	return (split);
}
