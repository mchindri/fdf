/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 18:48:44 by mchindri          #+#    #+#             */
/*   Updated: 2015/11/15 20:46:17 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst->next != NULL)
		ft_lstiter(lst->next, f);
	f(lst);
}
