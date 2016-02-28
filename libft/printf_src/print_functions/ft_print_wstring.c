/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 16:43:04 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/07 11:09:23 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_putwstr_(wchar_t *str)
{
	size_t	i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		ft_putwchar(str[i]);
		nb += ft_wchar_len(str[i]);
		i++;
	}
	return (nb);
}

static int		ft_cutstr(wchar_t *str, int len)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (size + ft_wchar_len(str[i]) <= len)
	{
		size += ft_wchar_len(str[i]);
		i++;
	}
	str[i] = '\0';
	return (size);
}

static int		ft_print_pad(t_type_format form, wchar_t *w_str, char c, int nb)
{
	if (form.pad_side == RIGHT)
	{
		while (nb < form.min_weidth)
		{
			ft_putchar(c);
			nb++;
		}
		ft_putwstr_(w_str);
	}
	else
	{
		ft_putwstr_(w_str);
		while (nb < form.min_weidth)
		{
			ft_putchar(' ');
			nb++;
		}
	}
	free(w_str);
	return (nb);
}

int				ft_print_wstring(t_type_format form, va_list *ap)
{
	wchar_t *w_str;
	int		nb;
	char	c;

	nb = 0;
	w_str = ft_strwdup((wchar_t *)va_arg(ap[0], wchar_t *));
	if (w_str == 0 || 0 == ft_memcmp(w_str, L"(null)", sizeof(L"(null)")))
	{
		ft_putstr("(null)");
		return (6);
	}
	nb = ft_strwlen(w_str);
	if (form.precision <= nb && form.precision != -1)
		nb = ft_cutstr(w_str, form.precision);
	if (form.pad_type == BLANK)
		c = ' ';
	else
		c = '0';
	return (ft_print_pad(form, w_str, c, nb));
}
