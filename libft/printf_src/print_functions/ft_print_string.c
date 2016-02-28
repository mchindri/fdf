/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:14:35 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/06 17:21:02 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_pad(t_type_format form, char *str, char c, int nb)
{
	if (form.pad_side == RIGHT)
	{
		while (nb < form.min_weidth)
		{
			ft_putchar(c);
			nb++;
		}
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		while (nb < form.min_weidth)
		{
			ft_putchar(' ');
			nb++;
		}
	}
	free(str);
	return (nb);
}

int			ft_print_string(t_type_format form, va_list *ap)
{
	char	*str;
	int		nb;
	char	c;

	nb = 0;
	str = ft_strdup((char *)va_arg(ap[0], char *));
	if (str == 0)
	{
		if (form.precision == 0)
			str = ft_strdup("");
		else
		{
			ft_putstr("(null)");
			return (6);
		}
	}
	nb = ft_strlen(str);
	if (form.precision >= 0)
		str[form.precision] = '\0';
	nb = ft_strlen(str);
	if (form.pad_type == BLANK)
		c = ' ';
	else
		c = '0';
	return (ft_print_pad(form, str, c, nb));
}
