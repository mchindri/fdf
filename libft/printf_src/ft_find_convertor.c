/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_convertor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:09:33 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/01 16:55:06 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_find_convertor(char *s)
{
	char	*q;

	while (*s)
	{
		q = CONVERTOR;
		while (*s)
			if (*q == *s)
				return (s);
			else
				q++;
		s++;
	}
	return (NULL);
}
