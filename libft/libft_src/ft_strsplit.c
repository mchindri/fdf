/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 10:10:35 by mchindri          #+#    #+#             */
/*   Updated: 2015/11/22 13:00:13 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_words(char *str, char c)
{
	int		i;
	char	*p;

	i = 0;
	p = str;
	while (*p == c)
		p++;
	while (*p)
	{
		i++;
		while (*p != c && *p)
			p++;
		while (*p == c)
			p++;
	}
	return (i);
}

int		count_letters(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

void	ft_cpy(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*p;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = count_words((char *)s, c);
	tab = (char**)malloc(sizeof(*tab) * (i + 1));
	p = (char *)s;
	while (*p == c)
		p++;
	i = 0;
	while (*p)
	{
		j = count_letters(p, c);
		tab[i] = (char*)malloc(sizeof(tab[i][j]) * (j + 1));
		ft_cpy(tab[i], p, j);
		p += j;
		while (*p == c)
			p++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
