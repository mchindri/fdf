/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 13:21:13 by mchindri          #+#    #+#             */
/*   Updated: 2015/11/05 13:35:02 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char*)malloc(size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
