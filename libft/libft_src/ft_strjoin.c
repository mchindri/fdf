/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 15:53:46 by mchindri          #+#    #+#             */
/*   Updated: 2015/11/22 12:59:15 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *p;

	if (s1 && s2)
		p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	else
		return (NULL);
	if (p == NULL)
		return (p);
	ft_strcpy(p, s1);
	ft_strcat(p, s2);
	return (p);
}
