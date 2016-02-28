/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 20:40:13 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/21 20:50:48 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || \
			str[i] == ' ' || str[i] == '\f' || str[i] == '\r')
		i++;
	sign = 0;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (sign == 1)
		return (-nb);
	return (nb);
}
