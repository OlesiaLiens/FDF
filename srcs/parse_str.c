/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:22:30 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/22 17:22:31 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		skip_spaces(const char *str, int *index)
{
	while (str[*index])
	{
		(*index)++;
	}
}

int			parse_col(const char *str, int *index)
{
	while (str[*index] && str[*index] != ' ')
	{
		(*index)++;
	}
	return (0x00ff00);
}

void		fill_x_y_z(t_fdf *fdf, int x, int y)
{
	if (fdf->map[y][x].z > 1000000 || fdf->map[y][x].z < -1000000)
		invalid_map();
	fdf->map[y][x].x = x - (fdf->width / 2);
	fdf->map[y][x].y = y - (fdf->rows / 2);
	fdf->map[y][x].z_change = fdf->map[y][x].z != 0 ? 1 : 0;
	fdf->map[y][x].x_origin = fdf->map[y][x].x;
	fdf->map[y][x].y_origin = fdf->map[y][x].y;
	fdf->map[y][x].z_origin = fdf->map[y][x].z;
}

void		parse_string(t_list *current, t_fdf *fdf)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	while (current)
	{
		i = 0;
		while (((char *)(current->content))[i])
		{
			x = -1;
			fdf->map[y] = (t_cor *)malloc(sizeof(t_cor) * fdf->width);
			while (++x < fdf->width)
			{
				fdf->map[y][x].z = ft_my_atoi((char *)(current->content), &i);
				fill_x_y_z(fdf, x, y);
				fdf->map[y][x].color = parse_col((char*)(current->content), &i);
			}
			skip_spaces((char*)(current->content), &i);
		}
		y++;
		current = current->next;
	}
}
