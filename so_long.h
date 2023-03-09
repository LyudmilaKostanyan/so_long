/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:52:25 by lykostan          #+#    #+#             */
/*   Updated: 2023/02/28 19:52:27 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>
# include <ft_printf.h>
# include <mlx.h>

typedef struct s_count
{
	int	e_count;
	int	c_count;
	int	p_count;
}	t_count;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img_0;
	void	*img_1;
	void	*img_p;
	void	*img_pl;
	void	*img_c;
	void	*img_e;
	void	*img_el;
	void	*img_er;
	void	*img_r;
	int		size;
	char	**split;
	int		x;
	int		y;
	int		i;
	int		j;
	char	a;
	int		c;
	int		count;
}	t_vars;

void	parsing_rectangular(char **split);
void	norm_parsing_borders(char **split, int i);
void	parsing_borders(char **split);
void	parsing_area(char **split);
int		parsing_pce(const char *s);
int		split_size(char **split);
char	**split_dup(char **split);
int		way_check(char **split, int y, int x);
int		coin_way_check(char **split, int y, int x, int *c);
void	parsing_way(char **split, int c);
char	*ft_open(char *file, int count);
char	**parse(char *file, int count, int *c);
char	**area(char *file, int *c);
void	ft_init(t_vars *mlx, char **argv);
void	map(char **split, t_vars *mlx);
void	find_p(t_vars *mlx);
void	up(t_vars *mlx, void *img, void *imge);
void	down(t_vars *mlx, void *img, void *imge);
void	left(t_vars *mlx);
void	right(t_vars *mlx);
void	hook(int keycode, t_vars *mlx);
int		key_hook(int keycode, t_vars *mlx);
void	split_free(char **split);
int		ft_close(void *i);
void	coins(t_vars *mlx);
void	map2(char **split, t_vars *mlx);

#endif
