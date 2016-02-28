/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 20:06:23 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/21 20:13:39 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t begin;

	begin = ft_strlen(s1);
	i = 0;
	while (i < ft_strlen(s2) && n > 0)
	{
		s1[begin + i] = s2[i];
		i++;
		n--;
	}
	s1[begin + i] = '\0';
	return (s1);
}
