/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 15:03:21 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/28 15:06:12 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fcntl.h"

t_point	**ft_alloc(int lines, int columns)
{
	t_point **map;
	int		i;

	map = (t_point **)malloc(sizeof(t_point *) * lines);
	if (map == NULL)
		ft_error("Out of memory\n");
	i = 0;
	while (i < lines)
	{
		map[i] = (t_point *)malloc(sizeof(t_point) * columns);
		if (map[i] == NULL)
			ft_error("Out of memory\n");
		i++;
	}
	return (map);
}

int		ft_isnumber(char *str)
{
	char	*nb;
	int		nbi;

	nbi = ft_atoi(str);
	nb = ft_itoa_base(nbi, 10);
	if (ft_strcmp(nb, str) == 0)
		return (1);
	return (0);
}

t_point	**ft_alloc_map(int fd, int *lines, int *columns)
{
	t_point **map;
	int		j;
	char	**number;
	char	*line;

	*lines = 0;
	while (get_next_line(fd, &line))
	{
		number = ft_strsplit(line, ' ');
		free(line);
		j = -1;
		while (number[++j])
			if (0 == ft_isnumber(number[j]))
				ft_error("Map error\n");
		ft_strdel(number);
		if (*lines == 0)
			(*columns) = j;
		else if (*columns != j)
			ft_error("Map error\n");
		(*lines)++;
	}
	map = ft_alloc(*lines, *columns);
	return (map);
}

void	ft_fill_map(t_point **map, int columns, char *file)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**numbers;

	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		numbers = ft_strsplit(line, ' ');
		free(line);
		j = 0;
		while (j < columns)
		{
			map[i][j].h1 = ft_atoi(numbers[j]);
			j++;
		}
		ft_strdel(numbers);
		i++;
	}
	close(fd);
}

t_point	**ft_read_file(char *file, int *lines, int *columns)
{
	t_point **map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Fail to open file\n");
	map = ft_alloc_map(fd, lines, columns);
	close(fd);
	if (map == NULL)
		return (NULL);
	ft_fill_map(map, *columns, file);
	return (map);
}
