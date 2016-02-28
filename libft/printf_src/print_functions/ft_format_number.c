/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:53:50 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/07 11:08:45 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_unsigned(char ch)
{
	if (ch == 'o' || ch == 'u' || ch == 'x' || ch == 'U' || ch == 'X')
		return (1);
	return (0);
}

/*
**	thousand_group
**	da
*/

static int	ft_calc_size(char *nbr, t_type_format form, int sign)
{
	int size;
	int nb_size;

	size = ft_strlen(nbr);
	nb_size = size;
	if (((form.sign == SIGNED || form.space == YES) &&
				!ft_is_unsigned(form.conv)) || sign == 1)
		size++;
	if (form.alternate == YES && (nbr[0] != '0' || form.pointer == YES ||
				(nbr[0] == '0' && form.precision == 0 && form.conv == 'o')))
	{
		if (form.conv == 'X' || form.conv == 'x' || form.pointer == YES)
			size += 2;
		else
		{
			size++;
			nb_size++;
		}
	}
	if (form.precision > nb_size)
		size += form.precision - nb_size;
	if (form.min_weidth > size)
		size = form.min_weidth;
	return (size);
}

static int	ft_set_start(t_type_format form, char sign)
{
	int start;

	start = 0;
	if (form.pad_type == ZERO && form.pad_side == RIGHT)
	{
		if (form.alternate == YES)
		{
			if (form.conv == 'x')
				start += 2;
			else if (form.conv == 'X')
				start++;
		}
		if (0 == ft_is_unsigned(form.conv))
			if (form.sign == SIGNED || form.space == YES || sign == 1)
				start++;
	}
	return (start);
}

static void	ft_set_alternate(char *formated_nbr, t_type_format form,
		int i, int sg)
{
	int start;

	start = ft_set_start(form, sg);
	if (form.precision == -1 && form.pad_side == RIGHT && form.pad_type == ZERO)
		while (i >= start)
			formated_nbr[i--] = '0';
	if (form.alternate == YES && form.conv == 'x')
		formated_nbr[i--] = 'x';
	else if (form.alternate == YES && form.conv == 'X')
		formated_nbr[i--] = 'X';
	if (form.alternate == YES && ft_strchr("xXo", form.conv))
		formated_nbr[i--] = '0';
	if (sg == 1)
		formated_nbr[i--] = '-';
	else if (form.sign == SIGNED && !ft_is_unsigned(form.conv))
		formated_nbr[i--] = '+';
	else if (form.space == YES)
		i--;
	if (form.pad_side == LEFT && i >= 0)
	{
		ft_strcpy(formated_nbr, formated_nbr + i + 1);
		ft_memset(formated_nbr + ft_strlen(formated_nbr), ' ', i + 1);
	}
}

char		*ft_format_number(char *nbr, t_type_format form, int sign)
{
	char	*formated_nbr;
	int		nbr_len;
	int		size;
	int		i;
	int		j;

	size = ft_calc_size(nbr, form, sign);
	if (NULL == (formated_nbr = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(formated_nbr, ' ', size);
	formated_nbr[size] = 0;
	nbr_len = ft_strlen(nbr);
	i = ft_strlen(formated_nbr) - nbr_len;
	if (nbr[0] == '0' && form.precision == 0)
		nbr[0] = '\0';
	ft_strcpy(formated_nbr + i, nbr);
	if (form.conv == 'o' && form.alternate == YES)
		nbr_len++;
	j = 0;
	while (nbr_len + j < form.precision)
		formated_nbr[i - j++ - 1] = '0';
	i -= j + 1;
	ft_set_alternate(formated_nbr, form, i, sign);
	free(nbr);
	return (formated_nbr);
}
