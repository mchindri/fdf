/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 18:21:04 by mchindri          #+#    #+#             */
/*   Updated: 2015/11/15 21:02:11 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next != NULL)
		ft_lstdel(&((*alst)->next), del);
	ft_lstdelone(alst, del);
}
