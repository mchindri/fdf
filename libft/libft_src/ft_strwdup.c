/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:13:35 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/06 17:14:42 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_strwdup(wchar_t *s1)
{
	wchar_t *copy;
	wchar_t *p;
	wchar_t *q;

	if (s1 == NULL)
		return (NULL);
	copy = (wchar_t *)malloc(sizeof(wchar_t) * (ft_strwlen(s1) + 1));
	p = (wchar_t *)s1;
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
