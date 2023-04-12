/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:01:32 by lykostan          #+#    #+#             */
/*   Updated: 2023/02/28 19:01:34 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map2(char **split, t_vars *mlx)
{
	if (split[mlx->i][mlx->j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img_1, mlx->x, mlx->y);
	else if (split[mlx->i][mlx->j] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img_0, mlx->x, mlx->y);
	else if (split[mlx->i][mlx->j] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img_e, mlx->x, mlx->y);
	else if (split[mlx->i][mlx->j] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img_p, mlx->x, mlx->y);
	else if (split[mlx->i][mlx->j] == 'R')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img_r, mlx->x, mlx->y);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img_c, mlx->x, mlx->y);
}

void	ft_images(t_vars *mlx)
{
	int	a;
	int	b;

	mlx->img_0 = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/zeros.xpm", &a, &b);
	mlx->img_1 = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/walls.xpm", &a, &b);
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/right.xpm", &a, &b);
	mlx->img_pl = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/left.xpm", &a, &b);
	mlx->img_c = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/coin.xpm", &a, &b);
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/exit.xpm", &a, &b);
	mlx->img_el = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/exit_left.xpm", &a, &b);
	mlx->img_er = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/exit_right.xpm", &a, &b);
	mlx->img_r = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/toxic.xpm", &a, &b);
	mlx->img_m = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/move.xpm", &a, &b);
	mlx->img_ml = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/move_l.xpm", &a, &b);
}

void	ft_init(t_vars *mlx, char **argv)
{
	int	len1;
	int	len2;
	int	a;
	int	b;

	mlx->size = 50;
	mlx->split = area(argv[1], &mlx->c);
	len1 = split_size(mlx->split);
	len2 = ft_strlen(mlx->split[0]);
	err_mes("Map size too large", len1 > 22 || len2 > 41);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, len2 * mlx->size,
			len1 * mlx->size, "So_long!");
	ft_images(mlx);
	mlx->img_me = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/move_exit.xpm", &a, &b);
	mlx->img_mel = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/move_exit_l.xpm", &a, &b);
	err_mes("Textures not found", !mlx->win || !mlx->mlx || !mlx->img_me
		|| !mlx->img_0 || !mlx->img_1 || !mlx->img_p || !mlx->img_mel
		|| !mlx->img_pl || !mlx->img_c || !mlx->img_e || !mlx->img_el
		|| !mlx->img_er || !mlx->img_r || !mlx->img_m || !mlx->img_ml);
}

void	f()
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
}

int	for_move(t_vars *mlx)
{
	static int	i;

	if (i == 3500)
	{
		if (!mlx->move)
		{
			// if (mlx->a == 'l')
			// {
			// 	if (mlx->split[mlx->y][mlx->x] == 'E')
			// 		mlx_put_image_to_window(mlx->mlx, mlx->win,
			// 			mlx->img_mel, mlx->x * mlx->size, mlx->y * mlx->size);
			// 	else
			// 		mlx_put_image_to_window(mlx->mlx, mlx->win,
			// 			mlx->img_ml, mlx->x * mlx->size, mlx->y * mlx->size);
			// }
			// else
			// {
			// 	if (mlx->split[mlx->y][mlx->x] == 'E')
			// 		mlx_put_image_to_window(mlx->mlx, mlx->win,
			// 			mlx->img_me, mlx->x * mlx->size, mlx->y * mlx->size);
			// 	else
			// 	{
			// 		mlx_put_image_to_window(mlx->mlx, mlx->win,
			// 			mlx->img_m, mlx->x * mlx->size, mlx->y * mlx->size);
			// 	}
			// }
			mlx->move = 1;
		}
		else
		{
			if (mlx->a == 'l')
				if (mlx->split[mlx->y][mlx->x] == 'E')
					mlx_put_image_to_window(mlx->mlx, mlx->win,
						mlx->img_el, mlx->x * mlx->size, mlx->y * mlx->size);
				else
					mlx_put_image_to_window(mlx->mlx, mlx->win,
						mlx->img_pl, mlx->x * mlx->size, mlx->y * mlx->size);
			else
				if (mlx->split[mlx->y][mlx->x] == 'E')
					mlx_put_image_to_window(mlx->mlx, mlx->win,
						mlx->img_er, mlx->x * mlx->size, mlx->y * mlx->size);
				else
					mlx_put_image_to_window(mlx->mlx, mlx->win,
						mlx->img_p, mlx->x * mlx->size, mlx->y * mlx->size);
			mlx->move = 0;
		}
		i = 0;
	}
	else
		i++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	mlx;

	err_mes("Few argumets", argc != 2);
	err_mes("Wrong file type",
		ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4)
		|| ft_strncmp(ft_strrchr(argv[1], '.'),
			".ber", ft_strlen(ft_strrchr(argv[1], '.'))));
	ft_init(&mlx, argv);
	mlx.i = -1;
	mlx.y = 0;
	map(mlx.split, &mlx);
	find_p(&mlx);
	mlx.count = 0;
	mlx.move = 0;
	mlx_hook(mlx.win, 2, 0, &key_hook, &mlx);
	mlx_loop_hook(mlx.mlx, &for_move, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, ft_close, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
