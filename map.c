/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:24:08 by lykostan          #+#    #+#             */
/*   Updated: 2023/02/28 20:24:10 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map(char **split, t_vars *mlx)
{
	while (split[++mlx->i])
	{
		mlx->j = -1;
		mlx->x = 0;
		while (split[mlx->i][++mlx->j])
		{
			map2(split, mlx);
			mlx->x += mlx->size;
		}
		mlx->y += mlx->size;
	}
}

void	up(t_vars *mlx, void *img, void *imge)
{
	if (mlx->split[mlx->y - 1][mlx->x] != '1')
	{
		mlx->count++;
		if (mlx->split[mlx->y - 1][mlx->x] == 'R')
			exit(0);
		if (mlx->split[mlx->y - 1][mlx->x] != 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, img,
				mlx->x * mlx->size, (mlx->y - 1) * mlx->size);
		else
		{
			if (mlx->c == 0)
				exit(0);
			mlx_put_image_to_window(mlx->mlx, mlx->win, imge,
				mlx->x * mlx->size, (mlx->y - 1) * mlx->size);
		}
		if (mlx->split[mlx->y][mlx->x] != 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_0,
				mlx->x * mlx->size, mlx->y * mlx->size);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_e,
				mlx->x * mlx->size, mlx->y * mlx->size);
		mlx->y -= 1;
		coins(mlx);
	}
}

void	down(t_vars *mlx, void *img, void *imge)
{
	if (mlx->split[mlx->y + 1][mlx->x] != '1')
	{
		mlx->count++;
		if (mlx->split[mlx->y + 1][mlx->x] == 'R')
			exit(0);
		if (mlx->split[mlx->y + 1][mlx->x] != 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, img,
				mlx->x * mlx->size, (mlx->y + 1) * mlx->size);
		else
		{
			if (mlx->c == 0)
				exit(0);
			mlx_put_image_to_window(mlx->mlx, mlx->win, imge,
				mlx->x * mlx->size, (mlx->y + 1) * mlx->size);
		}
		if (mlx->split[mlx->y][mlx->x] != 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_0,
				mlx->x * mlx->size, mlx->y * mlx->size);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_e,
				mlx->x * mlx->size, mlx->y * mlx->size);
		mlx->y += 1;
		coins(mlx);
	}
}

void	left(t_vars *mlx)
{
	if (mlx->split[mlx->y][mlx->x - 1] != '1')
	{
		mlx->count++;
		if (mlx->split[mlx->y][mlx->x - 1] == 'R')
			exit(0);
		if (mlx->split[mlx->y][mlx->x - 1] != 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_pl,
				(mlx->x - 1) * mlx->size, mlx->y * mlx->size);
		else
		{
			if (mlx->c == 0)
				exit(0);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_el,
				(mlx->x - 1) * mlx->size, mlx->y * mlx->size);
		}
		if (mlx->split[mlx->y][mlx->x] != 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_0,
				mlx->x * mlx->size, mlx->y * mlx->size);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_e,
				mlx->x * mlx->size, mlx->y * mlx->size);
		mlx->x -= 1;
		coins(mlx);
	}
}

void	right(t_vars *mlx)
{
	if (mlx->split[mlx->y][mlx->x + 1] != '1')
	{
		mlx->count++;
		if (mlx->split[mlx->y][mlx->x + 1] == 'R')
			exit(0);
		if (mlx->split[mlx->y][mlx->x + 1] != 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_p,
				(mlx->x + 1) * mlx->size, mlx->y * mlx->size);
		else
		{
			if (mlx->c == 0)
				exit(0);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_er,
				(mlx->x + 1) * mlx->size, mlx->y * mlx->size);
		}
		if (mlx->split[mlx->y][mlx->x] != 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_0,
				mlx->x * mlx->size, mlx->y * mlx->size);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_e,
				mlx->x * mlx->size, mlx->y * mlx->size);
		mlx->x += 1;
		coins(mlx);
	}
}
