/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:38:35 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/21 19:42:11 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char*)dst;
	q = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		p[i] = q[i];
		if (q[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
