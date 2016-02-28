/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 12:53:54 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/28 14:56:23 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_set_color(unsigned char red, unsigned char green, unsigned char blue)
{
	int color;

	color = 0;
	color += blue;
	color += green << 8;
	color += red << 16;
	color += SHADOW << 24;
	return (color);
}

/*
** esc = exit
** w,a,s,d = move map;
** 4-6, 8-2, 7-8 (numpad) = rotate map
** z-x = zoom +-
** c   = change color
** e-r = move the eye
** [-] = add, strubstract height
** p   = retrun to defauly
** m   = change perspective
*/

void	ft_more_hook(int key, t_map *map)
{
	if (key == 6)
		map->zoom++;
	else if (key == 7)
		map->zoom--;
	else if (key == 15)
		map->eye.h += 100;
	else if (key == 14)
		map->eye.h -= 100;
	else if (key == 30)
		map->height += 1;
	else if (map->height > 1 && key == 33)
		map->height -= 1;
	else if (key == 91)
		map->axis[0].value += 10;
	else if (key == 84)
		map->axis[0].value -= 10;
	else if (key == 88)
		map->axis[1].value += 10;
	else if (key == 86)
		map->axis[1].value -= 10;
	else if (key == 89)
		map->axis[2].value += 10;
	else if (key == 92)
		map->axis[2].value -= 10;
}

int		ft_key_hook(int key, t_map *map)
{
	ft_more_hook(key, map);
	if (key == 53)
		exit(0);
	else if (key == 8)
		map->color = ft_set_color(rand() % 256, rand() % 256, rand() % 256);
	else if (key == 35)
		ft_preset_map(map);
	else if (key == 2)
		map->trans.x += 5;
	else if (key == 0)
		map->trans.x -= 5;
	else if (key == 1)
		map->trans.y += 5;
	else if (key == 13)
		map->trans.y -= 5;
	else if (key == 46)
	{
		if (map->perspective == 0)
			map->perspective++;
		else
			map->perspective--;
		ft_preset_map(map);
	}
	ft_draw_map(map);
	return (0);
}

int		main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf file.fdf\n");
		return (0);
	}
	map.map = ft_read_file(argv[1], &map.lines, &map.columns);
	if (map.map == NULL)
	{
		ft_putstr("Map error\n");
		exit(1);
	}
	map.perspective = 0;
	ft_preset_map(&map);
	map.ptr.mlx = mlx_init();
	map.ptr.win = mlx_new_window(map.ptr.mlx, map.win_width,
			map.win_length, "fdf");
	ft_draw_map(&map);
	mlx_key_hook(map.ptr.win, ft_key_hook, &map);
	mlx_loop(map.ptr.mlx);
	return (0);
}
