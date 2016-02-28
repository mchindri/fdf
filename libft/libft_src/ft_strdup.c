/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:52:40 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/28 15:55:51 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *copy;
	char *p;
	char *q;

	if (s1 == NULL)
		return (NULL);
	copy = (char *)malloc(ft_strlen(s1) + 1);
	p = (char *)s1;
	q = copy;
	while (*p != '\0')
	{
		*q = *p;
		q++;
		p++;
	}
	*q = '\0';
	return (copy);
}
