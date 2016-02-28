/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fractional.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:29:51 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/27 17:31:26 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_fractional(t_type_format form, va_list *ap)
{
	(void)ap;
	(void)form;
	ft_putstr("is a fractional\n");
	return (0);
}
