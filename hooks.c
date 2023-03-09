/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:48:26 by lykostan          #+#    #+#             */
/*   Updated: 2023/03/02 15:48:28 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coins(t_vars *mlx)
{
	if (mlx->split[mlx->y][mlx->x] == 'C' && mlx->c > 0)
	{
		mlx->c--;
		mlx->split[mlx->y][mlx->x] = '0';
	}
}

void	find_p(t_vars *mlx)
{
	int	k;

	mlx->y = -1;
	k = 0;
	while (mlx->split[++mlx->y])
	{
		mlx->x = -1;
		while (mlx->split[mlx->y][++mlx->x])
		{
			if (mlx->split[mlx->y][mlx->x] == 'P')
			{
				k++;
				break ;
			}
		}
		if (k != 0)
			break ;
	}
}

void	hook(int keycode, t_vars *mlx)
{
	if (keycode == 13 || keycode == 126)
	{
		if (mlx->a == 'l')
			up(mlx, mlx->img_pl, mlx->img_el);
		else
			up(mlx, mlx->img_p, mlx->img_er);
	}
	if (keycode == 1 || keycode == 125)
	{
		if (mlx->a == 'l')
			down(mlx, mlx->img_pl, mlx->img_el);
		else
			down(mlx, mlx->img_p, mlx->img_er);
	}
	if (keycode == 0 || keycode == 123)
	{
		left(mlx);
		mlx->a = 'l';
	}
	if (keycode == 2 || keycode == 124)
	{
		right(mlx);
		mlx->a = 'r';
	}
}

int	key_hook(int keycode, t_vars *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	hook(keycode, mlx);
	return (0);
}
