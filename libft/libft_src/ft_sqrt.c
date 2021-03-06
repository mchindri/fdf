/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:21:55 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/22 15:24:45 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	ft_sqrt(unsigned n)
{
	unsigned i;

	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}
