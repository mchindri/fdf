/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 12:55:09 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/28 15:17:17 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <math.h>
# include <mlx.h>

# define PI 3.14159265359
# define SHADOW 0

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_point
{
	int	x;
	int	y;
	int	x1;
	int y1;
	int h;
	int	h1;
}				t_point;

/*
**	a = x2 - x1
**	b = y2 - y1
**	c = z2 - z1
**	x = (a/c) * (z - z1) + x1
**	y = (b/c) * (z - z1) + y1
*/

typedef struct	s_line
{
	float	a;
	float	b;
	float	c;
}				t_line;

/*
**	win: dreptunghi: x1 - colt stanga sus;
**					 x2 - colt dreapta jos;
*/

typedef struct	s_map
{
	t_point **map;
	t_point eye;
	int		win_h;
	int		lines;
	int		columns;
	t_point trans;
	int		color;
	int		win_width;
	int		win_length;
	int		zoom;
	int		z_eye;
	int		dif_eye_win;
	float	height;
	t_mlx	ptr;
	enum
	{
		PARALLEL,
		ISO
	}		perspective;
	struct
	{
		char	axis;
		float	value;
	}		axis[3];
}				t_map;

t_point			**ft_read_file(char *file, int *lines, int *columns);
int				mlx_pixel_put_to_image(void *img, t_point a, int color,
		t_map *map);
void			ft_draw_map(t_map *map);
void			ft_preset_map(t_map *map);
int				ft_set_color(unsigned char red, unsigned char gren,
		unsigned char blue);
void			ft_set_parallel(t_map *map);
void			ft_set_iso(t_map *map);
void			ft_rotate(t_point *a, char axis, float degrees);
void			ft_error(char *mesage);

#endif
