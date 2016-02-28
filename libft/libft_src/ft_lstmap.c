/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 18:52:41 by mchindri          #+#    #+#             */
/*   Updated: 2015/11/15 21:01:57 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *aux;
	t_list *aux2;
	t_list *map;

	if (lst->next != NULL)
	{
		aux2 = ft_lstmap(lst->next, f);
		if (!aux2)
			return (NULL);
	}
	aux = f(lst);
	map = ft_lstnew(aux->content, aux->content_size);
	if (!map)
		return (NULL);
	if (lst->next != NULL)
		map->next = aux2;
	else
		map->next = NULL;
	return (map);
}
