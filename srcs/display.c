/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:32:07 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/14 21:02:30 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Fdf");
	fdf->zoom = 20;
	fdf->height_z = 1;
	fdf->y_move = 0;
	fdf->x_move = 0;
	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
}

void		draw_dots_3(t_fdf *fdf, t_pixel offset, t_iter iter)
{
	t_line	line;

	line.start.x = (offset.x + (fdf->map[iter.i][iter.j].x
								+ fdf->x_move) * fdf->zoom);
	line.start.y = offset.y + (fdf->map[iter.i][iter.j].y
			+ fdf->y_move) * fdf->zoom;
	line.end.x = offset.x + (fdf->map[iter.i + 1][iter.j].x
			+ fdf->x_move) * fdf->zoom;
	line.end.y = offset.y + (fdf->map[iter.i + 1][iter.j].y
			+ fdf->y_move) * fdf->zoom;
	braz(fdf->mlx, fdf->win, line);
}

void		draw_dots_2(t_fdf *fdf, t_pixel offset, t_iter iter)
{
	t_line	line;

	line.start.x = (offset.x + (fdf->map[iter.i][iter.j].x
			+ fdf->x_move) * fdf->zoom);
	line.start.y = offset.y + (fdf->map[iter.i][iter.j].y
			+ fdf->y_move) * fdf->zoom;
	line.end.x = offset.x + (fdf->map[iter.i][iter.j + 1].x
			+ fdf->x_move) * fdf->zoom;
	line.end.y = offset.y + (fdf->map[iter.i][iter.j + 1].y
			+ fdf->y_move) * fdf->zoom;
	braz(fdf->mlx, fdf->win, line);
}

void		draw_dots(t_fdf *fdf)
{
	t_pixel	offset;
	t_iter	iter;

	offset.x = (double)WIDTH / 3;
	offset.y = (double)HEIGHT / 3;
	iter.i = -1;
	while (++iter.i < fdf->rows)
	{
		iter.j = -1;
		while (++iter.j < fdf->width)
		{
			if (iter.j + 1 < fdf->width)
				draw_dots_2(fdf, offset, iter);
			if (iter.i + 1 < fdf->rows)
				draw_dots_3(fdf, offset, iter);
		}
	}
}
