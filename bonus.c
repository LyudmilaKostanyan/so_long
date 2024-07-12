/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:34:20 by lykostan          #+#    #+#             */
/*   Updated: 2023/04/13 17:34:27 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	for_move_first(t_vars *mlx)
{
	if (mlx->a == 'l')
	{
		if (mlx->split[mlx->y][mlx->x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_mel, mlx->x * mlx->size, mlx->y * mlx->size);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_ml, mlx->x * mlx->size, mlx->y * mlx->size);
	}
	else
	{
		if (mlx->split[mlx->y][mlx->x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_me, mlx->x * mlx->size, mlx->y * mlx->size);
		else
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_m, mlx->x * mlx->size, mlx->y * mlx->size);
		}
	}
	mlx->move = 1;
}

void	for_move_second(t_vars *mlx)
{
	if (mlx->a == 'l')
	{
		if (mlx->split[mlx->y][mlx->x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_el, mlx->x * mlx->size, mlx->y * mlx->size);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_pl, mlx->x * mlx->size, mlx->y * mlx->size);
	}
	else
	{
		if (mlx->split[mlx->y][mlx->x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_er, mlx->x * mlx->size, mlx->y * mlx->size);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_p, mlx->x * mlx->size, mlx->y * mlx->size);
	}
	mlx->move = 0;
}

int	for_move(t_vars *mlx)
{
	static int	i;

	if (i == SPEED)
	{
		if (!mlx->move)
			for_move_first(mlx);
		else
			for_move_second(mlx);
		i = 0;
	}
	else
		i++;
	return (0);
}
