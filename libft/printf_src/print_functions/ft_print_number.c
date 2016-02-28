/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:26:25 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/07 11:08:17 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	ft_conv_unsigned(char *len_mod, va_list *ap)
{
	uintmax_t	n;

	if (len_mod[0] == 'h')
	{
		if (len_mod[1] == '\0')
			n = (unsigned short)(uintmax_t)va_arg(ap[0], unsigned int);
		else
			n = (unsigned char)(uintmax_t)va_arg(ap[0], unsigned int);
	}
	else if (len_mod[0] == 'l')
		n = (uintmax_t)va_arg(ap[0], unsigned long);
	else if (len_mod[0] == 'l' && len_mod[1] == 'l')
		n = (uintmax_t)va_arg(ap[0], unsigned long long);
	else if (len_mod[0] == 'j')
		n = (uintmax_t)va_arg(ap[0], uintmax_t);
	else if (len_mod[0] == 'z')
		n = (uintmax_t)va_arg(ap[0], size_t);
	else
		n = (intmax_t)va_arg(ap[0], unsigned);
	return (n);
}

static uintmax_t	ft_conv_signed(char *len_mod, va_list *ap, int *sign)
{
	intmax_t	n_neg;

	if (len_mod[0] == 'h')
	{
		if (len_mod[1] == '\0')
			n_neg = (short)(intmax_t)va_arg(ap[0], int);
		else
			n_neg = (char)(intmax_t)va_arg(ap[0], int);
	}
	else if (len_mod[0] == 'l')
		n_neg = (intmax_t)va_arg(ap[0], long);
	else if (len_mod[0] == 'l' && len_mod[1] == 'l')
		n_neg = (intmax_t)va_arg(ap[0], long long);
	else if (len_mod[0] == 'j' || len_mod[0] == 'z')
		n_neg = (intmax_t)va_arg(ap[0], intmax_t);
	else
		n_neg = (intmax_t)va_arg(ap[0], int);
	*sign = 0;
	if (n_neg < 0)
	{
		*sign = 1;
		return (n_neg * (-1));
	}
	else
		return (n_neg);
}

static void			ft_upper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

static char			*ft_convert_in_str(uintmax_t n, t_type_format form)
{
	char *str;

	if (ft_strchr("idu", form.conv))
		str = ft_uitoa_base(n, 10);
	else if (form.conv == 'o' || form.conv == 'O')
	{
		if (form.len_mod[0] == 'h' && form.len_mod[1] == 0)
			str = ft_uitoa_base((unsigned short)n, 8);
		else
			str = ft_uitoa_base(n, 8);
	}
	else if (form.conv == 'X')
	{
		str = ft_uitoa_base(n, 16);
		ft_upper(str);
	}
	else
		str = ft_uitoa_base(n, 16);
	return (str);
}

int					ft_print_number(t_type_format form, va_list *ap)
{
	uintmax_t	n;
	int			sign;
	char		*str;
	int			size;

	if (ft_strchr("diDI", form.conv))
		n = ft_conv_signed(form.len_mod, ap, &sign);
	else
	{
		sign = 0;
		n = ft_conv_unsigned(form.len_mod, ap);
	}
	str = ft_convert_in_str(n, form);
	str = ft_format_number(str, form, sign);
	if (str == NULL)
		return (-1);
	ft_putstr(str);
	size = ft_strlen(str);
	free(str);
	return (size);
}
