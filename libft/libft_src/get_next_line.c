/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 15:01:29 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/15 09:39:16 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		**ft_search_buf_in_list(t_list **lst, int fd)
{
	t_list		*aux;
	t_buf		content;

	aux = *lst;
	if (*lst != NULL)
		while (aux)
		{
			if (fd == ((t_buf *)(aux->content))->fd)
				return (&(((t_buf *)(aux->content))->buf));
			else
				aux = aux->next;
		}
	content.fd = fd;
	content.buf = NULL;
	aux = ft_lstnew((void *)&content, sizeof(content));
	if (!aux)
		return (NULL);
	ft_lstadd(lst, aux);
	return (&(((t_buf *)((*lst)->content))->buf));
}

static int		ft_concat(char **buf, char *str)
{
	char *aux;

	if (*buf == NULL)
		*buf = ft_strdup(str);
	else
	{
		aux = ft_strdup(*buf);
		free(*buf);
		*buf = (char *)malloc(ft_strlen(aux) + BUFF_SIZE + 1);
		ft_bzero(*buf, ft_strlen(aux) + BUFF_SIZE + 1);
		if (*buf == NULL)
			return (-1);
		ft_strcpy(*buf, aux);
		free(aux);
		ft_strcat(*buf, str);
	}
	return (1);
}

static int		ft_read_buf(int fd, char **buf)
{
	char	aux[BUFF_SIZE + 1];
	char	*endl_pos;
	int		buf_len;

	if (*buf == NULL || **buf == '\0')
		endl_pos = NULL;
	else
		endl_pos = ft_strchr(*buf, '\n');
	if (endl_pos == NULL)
		buf_len = read(fd, aux, BUFF_SIZE);
	while (endl_pos == NULL && buf_len != 0)
	{
		if (buf_len == -1)
			return (-1);
		aux[buf_len] = '\0';
		if (ft_concat(buf, aux) == -1)
			return (-1);
		endl_pos = ft_strchr(*buf, '\n');
		if (endl_pos == NULL)
			buf_len = read(fd, aux, BUFF_SIZE);
	}
	return (1);
}

static int		ft_write_in_line(char **buf, char **line)
{
	size_t	len;
	char	*endl_pos;

	endl_pos = ft_strchr(*buf, '\n');
	if (endl_pos == NULL)
		len = ft_strlen(*buf);
	else
		len = endl_pos - *buf;
	*line = (char *)malloc(len + 1);
	if (*line == NULL)
		return (-1);
	ft_strncpy(*line, *buf, len);
	(*line)[len] = '\0';
	if (ft_strlen(*buf) == 0)
		return (0);
	ft_strcpy(*buf, (*buf) + len);
	if (**buf == '\n')
		ft_strcpy(*buf, *buf + 1);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lst = NULL;
	char			**buf;
	int				can_read;
	int				can_write;

	if (!line)
		return (-1);
	buf = ft_search_buf_in_list(&lst, fd);
	can_read = ft_read_buf(fd, buf);
	if (can_read == -1)
		return (-1);
	can_write = ft_write_in_line(buf, line);
	if (can_write == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (can_write == 0)
	{
		free(*buf);
		*buf = ft_strdup("");
		return (0);
	}
	return (1);
}
