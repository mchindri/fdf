/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:50:14 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/28 15:17:47 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_write_down(t_map *map, t_point a, t_point b, int color)
{
	int sign;

	sign = 1;
	if (a.y == b.y)
	{
		if (a.x > b.x)
			sign = -1;
		while (a.x != b.x)
		{
			mlx_pixel_put_to_image(map->ptr.img, a, color, map);
			a.x += sign;
		}
		mlx_pixel_put_to_image(map->ptr.img, a, color, map);
		return ;
	}
	if (a.y > b.y)
		sign = -1;
	while (a.y != b.y)
	{
		mlx_pixel_put_to_image(map->ptr.img, a, color, map);
		a.y += sign;
	}
	mlx_pixel_put_to_image(map->ptr.img, a, color, map);
}

void	ft_write_diag_on_x(t_map *map, t_point steps, t_point point, float m)
{
	int		st;
	float	start;
	int		i;
	int		n;
	t_point	a;

	i = steps.x;
	n = steps.y;
	start = point.y;
	a.x = i;
	a.y = start;
	mlx_pixel_put_to_image(map->ptr.img, a, map->color, map);
	while (i <= n)
	{
		st = round(start);
		a.x = i;
		a.y = start;
		mlx_pixel_put_to_image(map->ptr.img, a, map->color, map);
		start += m;
		i++;
	}
}

void	ft_write_diag_on_y(t_map *map, t_point steps, t_point point, float m)
{
	int		st;
	float	start;
	int		i;
	int		n;
	t_point a;

	i = steps.x;
	n = steps.y;
	start = point.x;
	a.x = start;
	a.y = i;
	mlx_pixel_put_to_image(map->ptr.img, a, map->color, map);
	while (i <= n)
	{
		st = round(start);
		a.x = start;
		a.y = i;
		mlx_pixel_put_to_image(map->ptr.img, a, map->color, map);
		start += m;
		i++;
	}
}

void	ft_write_line(t_map *map, t_point a, t_point b, int color)
{
	float	m;
	t_point steps;

	if (a.x == b.x || a.y == b.y)
		ft_write_down(map, a, b, color);
	else if (abs(a.x - b.x) > abs(a.y - b.y))
	{
		m = ((float)(b.y - a.y)) / (b.x - a.x);
		steps.x = (int)fmin(a.x, b.x);
		steps.y = (int)fmax(a.x, b.x);
		if (a.x < b.x)
			ft_write_diag_on_x(map, steps, a, m);
		else
			ft_write_diag_on_x(map, steps, b, m);
	}
	else
	{
		m = ((float)(b.x - a.x)) / (b.y - a.y);
		steps.x = (int)fmin(a.y, b.y);
		steps.y = (int)fmax(a.y, b.y);
		if (a.y < b.y)
			ft_write_diag_on_y(map, steps, a, m);
		else
			ft_write_diag_on_y(map, steps, b, m);
	}
}

void	ft_draw_map(t_map *map)
{
	int i;
	int j;

	if (map->perspective == PARALLEL)
		ft_set_parallel(map);
	else
		ft_set_iso(map);
	map->ptr.img = mlx_new_image(map->ptr.mlx, map->win_width, map->win_length);
	i = -1;
	while (++i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			if (i != map->lines - 1)
				ft_write_line(map, map->map[i][j], map->map[i + 1][j],
						map->color);
			if (j != map->columns - 1)
				ft_write_line(map, map->map[i][j], map->map[i][j + 1],
						map->color);
			j++;
		}
	}
	mlx_put_image_to_window(map->ptr.mlx, map->ptr.win, map->ptr.img, 0, 0);
	mlx_destroy_image(map->ptr.mlx, map->ptr.img);
}
