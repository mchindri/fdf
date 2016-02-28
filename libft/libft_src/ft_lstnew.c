/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 18:04:00 by mchindri          #+#    #+#             */
/*   Updated: 2015/11/15 19:27:33 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = malloc(sizeof(content_size));
	if (!(lst->content))
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}
