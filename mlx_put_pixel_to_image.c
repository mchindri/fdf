/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:57:08 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/28 15:13:44 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mlx_pixel_put_to_image(void *img, t_point a, int clr, t_map *map)
{
	char	*data;
	int		bpp;
	int		endian;
	int		sizeline;
	int		i;

	if (!(a.x >= 0 && a.y >= 0 && a.x <= map->win_width &&
				a.y <= map->win_length))
		return (1);
	i = 0;
	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	if (endian == 0)
		while (i != bpp / 8)
		{
			data[a.y * sizeline + a.x * (bpp / 8) + i++] = 0x000000FF & clr;
			data[a.y * sizeline + a.x * (bpp / 8) + i++] =
				(0x0000FF00 & clr) >> 8;
			data[a.y * sizeline + a.x * (bpp / 8) + i++] =
				(0x00FF0000 & clr) >> 16;
			data[a.y * sizeline + a.x * (bpp / 8) + i++] =
				(0xFF000000 & clr) >> 24;
		}
	return (0);
}
