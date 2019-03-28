/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:47:08 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/16 15:47:09 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_rotation(t_fdf *fdf, int key)
{
	key_rotation_2(fdf, key);
	if (key == 91)
		fdf->angle_x += 3;
	if (key == 84)
		fdf->angle_x -= 3;
	if (key == 88)
		fdf->angle_y += 3;
	if (key == 86)
		fdf->angle_y -= 3;
	if (key == 92)
		fdf->angle_z += 3;
	if (key == 89)
		fdf->angle_z -= 3;
	if (key == 88 || key == 86 || key == 91 || key == 34
		|| key == 35 || key == 84 || key == 92 || key == 89)
		rotate_cor(fdf);
}

void		change_z(t_fdf *fdf, int key)
{
	if (key == 69)
	{
		fdf->height_z += 0.1;
	}
	if (key == 78)
	{
		fdf->height_z -= 0.1;
	}
	if (key == 69 || key == 78)
		rotate_cor(fdf);
}

void		change_coords(t_fdf *fdf, int key)
{
	if (key == UP)
	{
		fdf->y_move -= 2;
	}
	if (key == DOWN)
	{
		fdf->y_move += 2;
	}
	if (key == RIGHT)
	{
		fdf->x_move += 2;
	}
	if (key == LEFT)
	{
		fdf->x_move -= 2;
	}
}

void		zoom(t_fdf *fdf, int key)
{
	if (key == 116 && fdf->zoom <= 70)
		fdf->zoom = fdf->zoom + 0.9;
	if (key == 121 && fdf->zoom > 0)
		fdf->zoom = fdf->zoom - 0.9;
}

int			set_key(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	zoom(fdf, key);
	change_coords(fdf, key);
	change_z(fdf, key);
	key_rotation(fdf, key);
	if (key == ESC)
	{
		exit(EXIT_SUCCESS);
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_dots(fdf);
	put_text(fdf);
	return (0);
}
