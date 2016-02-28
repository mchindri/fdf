/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 10:26:25 by mchindri          #+#    #+#             */
/*   Updated: 2015/11/22 11:16:04 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	leng(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char		*p;
	unsigned	aux;
	int			len;

	len = leng(n);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	p[len--] = 0;
	if (n < 0)
		aux = n * -1;
	else
		aux = n;
	while (aux)
	{
		p[len--] = aux % 10 + '0';
		aux /= 10;
	}
	if (n < 0)
		p[0] = '-';
	else if (n == 0)
		p[0] = '0';
	return (p);
}
