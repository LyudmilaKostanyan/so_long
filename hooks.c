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
	char	*s;

	if (keycode == UP || keycode == W)
	{
		if (mlx->a == 'l')
			up(mlx, mlx->img_pl, mlx->img_el);
		else
			up(mlx, mlx->img_p, mlx->img_er);
	}
	if (keycode == DOWN || keycode == S)
	{
		if (mlx->a == 'l')
			down(mlx, mlx->img_pl, mlx->img_el);
		else
			down(mlx, mlx->img_p, mlx->img_er);
	}
	if (keycode == LEFT || keycode == A)
		left(mlx);
	if (keycode == RIGHT || keycode == D)
		right(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->img_1, 0, 0);
	s = ft_itoa(mlx->count);
	mlx_string_put(mlx->mlx, mlx->win, 0, 0, 0xFFFFFF, s);
	free(s);
}

int	key_hook(int keycode, t_vars *mlx)
{
	if (keycode == 65307)
		ft_close(mlx);
	hook(keycode, mlx);
	return (0);
}
