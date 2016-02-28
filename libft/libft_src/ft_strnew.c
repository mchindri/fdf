/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 13:52:59 by mchindri          #+#    #+#             */
/*   Updated: 2015/11/05 14:03:02 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	s = (char *)malloc(size);
	if (!s)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
