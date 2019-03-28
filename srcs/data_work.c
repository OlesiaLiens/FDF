/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:44:41 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/14 21:26:18 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list			**ft_lstappend(t_list **lst, void *data, size_t data_size)
{
	t_list *cur;

	if (!lst)
		return (NULL);
	if (!(*lst))
	{
		*lst = ft_lstnew(data, data_size);
		(*lst)->content_size = 1;
	}
	else
	{
		cur = *lst;
		while (cur->next)
			cur = cur->next;
		cur->next = ft_lstnew(data, data_size);
		cur->next->content_size = cur->content_size + 1;
	}
	return (lst);
}

int				line_width(char *line, char c)
{
	size_t		i;
	int			word;

	i = 0;
	word = 0;
	while (line[i])
	{
		if (line[i] != c)
		{
			while (line[i] != c && line[i] != '\0')
				i++;
			word++;
		}
		if (line[i] == '\0')
			break ;
		i++;
	}
	return (word);
}

int				is_valid_chars(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' '
		|| line[i] == '\t'
		|| line[i] == '-'
		|| ft_isdigit(line[i])
		|| line[i] == ','
		|| line[i] == 'x'
		|| (line[i] >= 'A' && line[i] <= 'F')
		|| (line[i] >= 'a' && line[i] <= 'f'))
			i++;
		else
		{
			return (0);
		}
	}
	return (1);
}

int				is_line_valid(t_fdf *fdf, char *line)
{
	char	delimeter;

	delimeter = ' ';
	if (is_valid_chars(line))
	{
		if (fdf->width == -1)
		{
			fdf->width = line_width(line, delimeter);
			return (1);
		}
		else if (fdf->width == line_width(line, delimeter))
			return (1);
		else
		{
			fdf->status = INVALID_MAP;
			invalid_map();
		}
	}
	else
	{
		invalid_map();
	}
	return (0);
}

void			open_file(t_fdf *fdf, char *file_name)
{
	int		fd;
	char	*line;
	t_list	*raw_data_lst;

	raw_data_lst = NULL;
	fdf->rows = 0;
	if ((fd = open(file_name, O_RDONLY)) < 0 || (read(fd, 0, 0)) < 0)
		ft_usage();
	else
	{
		while ((get_next_line(fd, &line)) > 0 && is_line_valid(fdf, line))
		{
			fdf->rows++;
			ft_lstappend(&raw_data_lst, line, ft_strlen(line) + 1);
			ft_memdel((void**)&line);
		}
		if (fdf->rows < 2 || fdf->width < 2)
			fdf->status = INVALID_MAP;
		if (fdf->status)
			invalid_map();
		fdf->map = (t_cor**)malloc(sizeof(t_cor*) * fdf->rows);
		parse_string(raw_data_lst, fdf);
	}
	ft_lstdel(&raw_data_lst, &del_content);
}
