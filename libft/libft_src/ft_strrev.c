/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:12:18 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/22 14:50:21 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	aux;

	j = ft_strlen(s) - 1;
	i = 0;
	while (i < j)
	{
		aux = s[j];
		s[j] = s[i];
		s[i] = aux;
		i++;
		j--;
	}
	return (s);
}
