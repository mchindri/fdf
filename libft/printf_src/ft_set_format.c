/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:57:04 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/07 10:53:09 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	se pot gasi si $ si in alte locuri in afara de la inceput
*/

static int		ft_is_positional_arg(char *str)
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

static void		ft_set_special_conv(t_type_format *form)
{
	if (ft_strchr("DOU", form->conv))
	{
		form->conv += 32;
		form->len_mod[0] = 'l';
		form->len_mod[1] = 0;
	}
	else if (form->conv == 'C')
	{
		form->conv = 'c';
		ft_strcpy(form->len_mod, "l");
	}
	else if (form->conv == 'p')
	{
		form->pointer = YES;
		form->len_mod[0] = 'l';
		form->len_mod[1] = 0;
		form->alternate = YES;
		form->conv = 'x';
	}
	else if (form->conv == 'S')
	{
		form->len_mod[0] = 'l';
		form->len_mod[1] = 0;
		form->conv = 's';
	}
}

t_type_format	ft_set_format(char *str, va_list *ap)
{
	t_type_format form;

	ft_bzero(&form, sizeof(t_type_format));
	if (*str == 0)
		return (form);
	if (ft_is_positional_arg(str))
		form.nb_arg = ft_atoi(str);
	ft_set_flags(str, &form);
	ft_set_weidth(str, &form, ap);
	if (form.min_weidth < 0)
	{
		form.min_weidth *= -1;
		form.pad_side = LEFT;
	}
	ft_set_precision(str, &form, ap);
	ft_set_lenmod(str, &form);
	ft_set_special_conv(&form);
	return (form);
}
