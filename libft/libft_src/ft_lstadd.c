/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 18:41:23 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/16 13:05:02 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *aux;

	if (*alst != NULL)
	{
		aux = *alst;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	else
		*alst = new;
}
