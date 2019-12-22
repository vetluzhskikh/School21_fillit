/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:00:59 by nyaacc            #+#    #+#             */
/*   Updated: 2019/11/10 19:47:00 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list			*just_do_it(t_list *buffer, int fd)
{
	int					i;
	char				tmp[BUFF_SIZE + 1];
	char				*tmp2;

	i = 0;
	while ((i = read(fd, tmp, BUFF_SIZE)))
	{
		tmp[i] = '\0';
		tmp2 = buffer->content;
		buffer->content = ft_strjoin(buffer->content, tmp);
		free(tmp2);
		if (ft_strchr(tmp, '\n') != NULL)
			break ;
	}
	return (buffer);
}

static t_list			*buffer_work(t_list **start, const int fd)
{
	t_list				*buffer;

	if (!start)
		return (NULL);
	buffer = *start;
	while (buffer)
	{
		if (buffer->content_size == (size_t)fd)
			return (buffer);
		buffer = buffer->next;
	}
	if (!(buffer = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(start, buffer);
	return (buffer);
}

static t_list			*cut_buffer(t_list *buffer, size_t npos)
{
	char				*tmp;

	if (ft_strlen(buffer->content) >= npos)
	{
		tmp = buffer->content;
		buffer->content = ft_strdup(&((buffer->content)[npos + 1]));
		free(tmp);
	}
	else
		ft_strclr(buffer->content);
	return (buffer);
}

int						get_next_line(const int fd, char **line)
{
	static t_list		*start;
	t_list				*buffer;
	char				tmp[BUFF_SIZE + 1];
	size_t				npos;
	size_t				len;

	npos = 0;
	len = 0;
	if (!line || fd <= -1 || BUFF_SIZE <= 0 || read(fd, tmp, 0) < 0)
		return (-1);
	if (!(buffer = buffer_work(&start, fd)))
		return (-1);
	if (!(buffer = just_do_it(buffer, fd)))
		return (-1);
	if ((len = ft_strlen(buffer->content)) == 0)
		return (0);
	while (*((unsigned char*)buffer->content + npos) != '\n' &&
	npos <= len)
		npos++;
	*line = ft_strsub(buffer->content, 0, npos);
	buffer = cut_buffer(buffer, npos);
	return (1);
}
