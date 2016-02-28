/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:20:44 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/01 17:01:11 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_select_arg(va_list ap, int poz)
{
	static t_list	*lst = NULL;
	t_list			*aux;
	int				arg;
	int				i;

	i = 0;
	aux = lst;
	while (aux)
	{
		if (i == poz - 1)
			return (*(int *)(aux->content));
		aux = aux->next;
		i++;
	}
	while (i < poz)
	{
		arg = va_arg(ap, int);
		aux = ft_lstnew(&arg, sizeof(int));
		ft_lstadd(&lst, aux);
		i++;
	}
	return (arg);
}
