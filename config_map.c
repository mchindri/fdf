/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 09:43:37 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/28 15:43:10 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**x' = x cos f - y sin f
**y' = y cos f + x sin f
*/

void	ft_error(char *mesage)
{
	ft_putstr(mesage);
	exit(EXIT_FAILURE);
}

void	ft_rotate(t_point *a, char axis, float deegres)
{
	float	angle;
	float	x[2];

	angle = (PI * deegres) / 180;
	if (axis == 'x')
	{
		x[0] = a->h * cos(angle) + a->y1 * sin(angle);
		x[1] = a->y1 * cos(angle) - a->h * sin(angle);
		a->h = round(x[0]);
		a->y1 = round(x[1]);
	}
	else if (axis == 'y')
	{
		x[0] = a->x1 * cos(angle) + a->h * sin(angle);
		x[1] = a->h * cos(angle) - a->x1 * sin(angle);
		a->x1 = round(x[0]);
		a->h = round(x[1]);
	}
	else if (axis == 'z')
	{
		x[0] = a->x1 * cos(angle) + a->y1 * sin(angle);
		x[1] = a->y1 * cos(angle) - a->x1 * sin(angle);
		a->x1 = round(x[0]);
		a->y1 = round(x[1]);
	}
}
