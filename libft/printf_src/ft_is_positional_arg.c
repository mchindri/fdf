/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_positional_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:05:03 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/01 16:55:24 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_positional_arg(char *str)
{
	while (*str)
	{
		if (*str == '$')
			return (1);
		if (*str == '*')
			return (0);
		str++;
	}
	return (0);
}
