/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 08:06:27 by mchindri          #+#    #+#             */
/*   Updated: 2015/11/22 13:04:45 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *p;
	char *q;
	char *p2;

	if (!s)
		return (NULL);
	p = (char *)malloc(ft_strlen(s) + 1);
	ft_strcpy(p, s);
	q = p;
	while (*q == ' ' || *q == '\t' || *q == '\n')
		q++;
	ft_strcpy(p, q);
	while (*q)
		q++;
	q--;
	while (*q == ' ' || *q == '\t' || *q == '\n')
		q--;
	*(q + 1) = '\0';
	p2 = (char *)malloc(ft_strlen(p) + 1);
	ft_strcpy(p2, p);
	free(p);
	return (p2);
}
