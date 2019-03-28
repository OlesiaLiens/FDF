/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:51:39 by oshyiata          #+#    #+#             */
/*   Updated: 2019/02/26 13:53:21 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strfree(char **join, char **buf, int res)
{
	if ((*join) != NULL)
		ft_strdel(join);
	if ((*buf) != NULL)
		ft_strdel(buf);
	return (res);
}

int		ft_fill_line(t_gnl *gnl, char **join, char **line)
{
	gnl->temp = ft_strdup(gnl->index_n + 1);
	*line = ft_strsub(*join, 0, gnl->index_n - *join);
	ft_strdel(join);
	ft_strdel(&(gnl->buf));
	*join = ft_strdup(gnl->temp);
	ft_strdel(&(gnl->temp));
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	t_gnl			gnl;
	static	char	*join[MAX_FD];

	if (line == NULL || (BUFF_SIZE < 0 || BUFF_SIZE > 10000000 ||
		fd > MAX_FD) || fd < 0 || !(gnl.buf = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while ((gnl.res = read(fd, gnl.buf, BUFF_SIZE)) > 0)
	{
		gnl.buf[gnl.res] = '\0';
		gnl.join2 = ft_strjoin(join[fd], gnl.buf);
		free(join[fd]);
		join[fd] = gnl.join2;
		gnl.temp = ft_strchr(join[fd], '\n');
		if (gnl.temp != NULL)
			break ;
	}
	if (join[fd] && (gnl.index_n = ft_strchr(join[fd], '\n')))
		return (ft_fill_line(&gnl, &join[fd], line));
	if (gnl.res == -1)
		return (ft_strfree(&join[fd], &(gnl.buf), -1));
	if ((ft_strlen(join[fd]) == 0) || (gnl.temp == NULL && join[fd] == NULL))
		return (ft_strfree(&join[fd], &(gnl.buf), 0));
	*line = ft_strdup(join[fd]);
	return (ft_strfree(&join[fd], &gnl.buf, 1));
}
