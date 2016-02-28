/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:36:18 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/21 19:38:09 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char *)dst;
	q = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		p[i] = q[i];
		i++;
	}
	return (dst);
}
