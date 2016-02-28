/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 20:34:00 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/21 20:36:05 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	size = ft_strlen(s2);
	if (s2[0] == 0)
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < n)
		{
			if (j == size - 1)
				return ((char*)s1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
