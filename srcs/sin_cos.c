/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sin_cos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:54:55 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/16 18:54:56 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		rotate_1(t_fdf *fdf)
{
	fdf->buff_y = fdf->map[fdf->y_1][fdf->x_1].y_origin;
	fdf->buff_z = fdf->map[fdf->y_1][fdf->x_1].z_change
			? fdf->map[fdf->y_1][fdf->x_1].z_origin
			* fdf->height_z
			: fdf->map[fdf->y_1][fdf->x_1].z_origin;
}

void		rotate_2(t_fdf *fdf)
{
	fdf->buff_y2 = fdf->buff_y * cos((fdf->angle_x_1 * M_PI) / 180)
			- fdf->buff_z * sin((fdf->angle_x_1 * M_PI) / 180);
	fdf->buff_z2 = fdf->buff_y * sin((fdf->angle_x_1 * M_PI) / 180)
			+ fdf->buff_z * cos((fdf->angle_x_1 * M_PI) / 180);
	fdf->buff_x = fdf->map[fdf->y_1][fdf->x_1].x_origin;
	fdf->buff_x2 = fdf->buff_x * cos((fdf->angle_y_1 * M_PI) / 180)
			+ fdf->buff_z2 * sin((fdf->angle_y_1 * M_PI) / 180);
}

void		rotate_3(t_fdf *fdf)
{
	fdf->map[fdf->y_1][fdf->x_1].z =
			-fdf->buff_x * sin((fdf->angle_y_1 * M_PI) / 180)
			+ fdf->buff_z2 * cos((fdf->angle_y_1 * M_PI) / 180);
	fdf->map[fdf->y_1][fdf->x_1].x =
			fdf->buff_x2 * cos((fdf->angle_z_1 * M_PI) / 180)
			- fdf->buff_y2 * sin((fdf->angle_z_1 * M_PI) / 180);
	fdf->map[fdf->y_1][fdf->x_1].y =
			fdf->buff_x2 * sin((fdf->angle_z_1 * M_PI) / 180)
			+ fdf->buff_y2 * cos((fdf->angle_z_1 * M_PI) / 180);
	fdf->x_1++;
}

void		rotate_cor(t_fdf *fdf)
{
	fdf->angle_x_1 = fdf->angle_x;
	fdf->angle_y_1 = fdf->angle_y;
	fdf->angle_z_1 = fdf->angle_z;
	fdf->y_1 = 0;
	while (fdf->y_1 < fdf->rows)
	{
		fdf->x_1 = 0;
		while (fdf->x_1 < fdf->width)
		{
			rotate_1(fdf);
			rotate_2(fdf);
			rotate_3(fdf);
		}
		fdf->y_1++;
	}
}
