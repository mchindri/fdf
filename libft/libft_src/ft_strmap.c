/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 14:42:08 by mchindri          #+#    #+#             */
/*   Updated: 2015/11/22 12:50:17 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *p;
	char *p2;
	char *s2;

	if (s && f)
	{
		p = (char *)malloc(ft_strlen(s));
		s2 = (char *)s;
		p2 = p;
		while (*s2)
		{
			*p2 = f(*s2);
			p2++;
			s2++;
		}
		*p2 = '\0';
		return (p);
	}
	return (NULL);
}
