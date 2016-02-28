/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 20:27:10 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/21 20:33:56 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		length;

	length = ft_strlen(s2);
	if (length == 0)
		return ((char*)s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (j == length - 1)
				return ((char*)s1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
