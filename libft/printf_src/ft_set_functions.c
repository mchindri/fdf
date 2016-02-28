/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:37:18 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/07 10:24:19 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_select_param(char *str, int *i, va_list *ap)
{
	int j;
	int n;
	int weidth;

	j = *i + 1;
	while (str[j] && str[j] != '$' && str[j] != '*')
		j++;
	if (str[j] != '$')
	{
		weidth = va_arg(ap[0], int);
		return (weidth);
	}
	n = ft_atoi(str + *i + 1);
	weidth = ft_select_arg(ap[1], n);
	(*i) += j;
	return (weidth);
}

void			ft_set_flags(char *str, t_type_format *form)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' && (!ft_isdigit(str[i - 1]) || i == 0))
			form->pad_type = ZERO;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			form->pad_side = LEFT;
		else if (str[i] == ' ')
			form->space = YES;
		else if (str[i] == '+')
			form->sign = SIGNED;
		else if (str[i] == '#')
			form->alternate = YES;
		else if (str[i] == '\'')
			form->thousand_grouped = YES;
		i++;
	}
}

void			ft_set_weidth(char *str, t_type_format *form, va_list *ap)
{
	int i;

	if (form->nb_arg != 0)
	{
		while (*str != '$')
			str++;
		str++;
	}
	i = 0;
	while (str[i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]))
		{
			form->min_weidth = ft_atoi(str + i);
			while (ft_isdigit(str[i]))
				i++;
			i--;
		}
		else if (str[i] == '*')
			form->min_weidth = ft_select_param(str, &i, ap);
		i++;
	}
}

void			ft_set_precision(char *str, t_type_format *form, va_list *ap)
{
	int n;
	int i;

	n = -1;
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i])
	{
		i++;
		if (ft_isdigit(str[i]))
			n = ft_atoi(str + i);
		else if (str[i] == '*')
		{
			n = ft_select_param(str, &i, ap);
			if (n < 0)
				n = -1;
		}
		else
			n = 0;
	}
	form->precision = n;
}

void			ft_set_lenmod(char *str, t_type_format *form)
{
	char	*p;

	p = str + ft_strlen(str) - 1;
	form->conv = *p;
	p--;
	if (p >= str && ft_isalpha(*p))
	{
		(form->len_mod)[0] = *p;
		p--;
	}
	if (p >= str && ft_isalpha(*p))
		(form->len_mod)[1] = *p;
}
