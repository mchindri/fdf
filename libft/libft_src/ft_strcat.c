/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 20:01:14 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/21 20:08:03 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t i_start;

	i_start = ft_strlen(s1);
	i = 0;
	while (i < ft_strlen(s2))
	{
		s1[i_start + i] = s2[i];
		i++;
	}
	s1[i_start + i] = '\0';
	return (s1);
}
