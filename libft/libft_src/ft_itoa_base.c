/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 11:36:59 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/07 11:43:58 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_create_str(char *str, int size, unsigned nb, int base)
{
	int aux;

	if (nb == 0)
		str[size] = '0';
	else
		while (nb > 0)
		{
			aux = nb % base;
			if (aux <= 9)
				str[size] = aux + '0';
			else
				str[size] = aux - 10 + 'a';
			nb /= base;
			size--;
		}
}

static char	*ft_alloc_str(unsigned nb, int base)
{
	int			size;
	unsigned	nb_cpy;
	char		*str;

	nb_cpy = nb;
	size = 0;
	if (nb == 0)
		size = 1;
	else
		while (nb_cpy > 0)
		{
			nb_cpy /= base;
			size++;
		}
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	size--;
	ft_create_str(str, size, nb, base);
	return (str);
}

char		*ft_itoa_base(unsigned value, int base)
{
	char		*str;

	if (base < 2 || base > 16)
		return (NULL);
	str = ft_alloc_str(value, base);
	return (str);
}
