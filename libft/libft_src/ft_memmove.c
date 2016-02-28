/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:42:22 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/21 19:44:37 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*aux;

	aux = (unsigned char*)malloc(len);
	i = 0;
	while (i < len)
	{
		aux[i] = *(unsigned char*)(src + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		*(unsigned char*)(dst + i) = aux[i];
		i++;
	}
	free(aux);
	return (dst);
}
