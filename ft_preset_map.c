/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preset_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:09:08 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/28 14:57:09 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_parallel(t_map *map)
{
	int		i;
	int		j;
	t_line	d;

	i = -1;
	while (++i < map->lines && !(j = 0))
		while (j < map->columns)
		{
			map->map[i][j].x1 = map->zoom * (j - map->columns / 2);
			map->map[i][j].y1 = map->zoom * (i - map->lines / 2);
			map->map[i][j].h = map->map[i][j].h1 * map->height;
			ft_rotate(&map->map[i][j], map->axis[0].axis, map->axis[0].value);
			ft_rotate(&map->map[i][j], map->axis[1].axis, map->axis[1].value);
			ft_rotate(&map->map[i][j], map->axis[2].axis, map->axis[2].value);
			d.a = map->map[i][j].x1 - map->eye.x;
			d.b = map->map[i][j].y1 - map->eye.y;
			d.c = map->map[i][j].h - map->eye.h;
			map->map[i][j].x = (d.a / (float)d.c) *
				(map->win_h - map->eye.h) + map->eye.x;
			map->map[i][j].y = (d.b / (float)d.c) *
				(map->win_h - map->eye.h) + map->eye.y;
			map->map[i][j].x += map->win_width / 2 + map->trans.x;
			map->map[i][j].y += map->win_length / 2 + map->trans.y;
			j++;
		}
}

/*
**  screen.x = map.x * TILE_WIDTH_HALF - map.y * TILE_WIDTH_HALF;
**  screen.y = map.x * TILE_HEIGHT_HALF + map.y * TILE_HEIGHT_HALF;
*/

void	ft_set_iso(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			map->map[i][j].x = i * map->zoom / 2. + j * map->zoom / 2.
				+ map->trans.x;
			map->map[i][j].y = i * map->zoom / 2. - j * map->zoom / 2.
				+ map->trans.y;
			map->map[i][j].y -= map->map[i][j].h1 * map->height;
			j++;
		}
		i++;
	}
}

void	ft_calc_zoom_and_dim(t_map *map)
{
	if (map->lines < 50 && map->columns < 50)
		map->zoom = 30;
	else if (map->lines < 100 && map->lines < 100)
		map->zoom = 15;
	else if (map->lines < 200 && map->lines < 200)
		map->zoom = 5;
	else
		map->zoom = 2;
	map->win_width = (map->lines + map->columns) * map->zoom / 1.5;
	map->win_length = (map->lines + map->columns) * map->zoom / 2;
}

void	ft_preset_map(t_map *map)
{
	ft_calc_zoom_and_dim(map);
	map->z_eye = 1000;
	map->dif_eye_win = map->z_eye - map->z_eye / 4;
	map->height = 10;
	map->trans.x = 0;
	if (map->perspective == 0)
		map->trans.y = 0;
	else
		map->trans.y = map->lines * map->zoom;
	map->axis[0].axis = 'x';
	map->axis[1].axis = 'y';
	map->axis[2].axis = 'z';
	map->axis[0].value = 50;
	map->axis[1].value = 20;
	map->axis[2].value = 30;
	map->eye.x = 0;
	map->eye.y = 0;
	map->eye.h = map->z_eye;
	map->win_h = map->z_eye - map->dif_eye_win;
	map->color = ft_set_color(255, 255, 255);
}
