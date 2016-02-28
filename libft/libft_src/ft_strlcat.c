/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 20:13:47 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/21 20:19:07 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_size;
	size_t	s_size;

	d_size = ft_strlen(dst);
	s_size = ft_strlen(src);
	if (d_size >= size)
		return (s_size + size);
	j = 0;
	i = d_size;
	while (src[j] && j < size - d_size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (d_size + s_size);
}
