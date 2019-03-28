/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brazenkhem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:21:00 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/25 13:21:00 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		braz_3(void *mlx, void *win, t_line line)
{
	line.x = (int)line.start.x;
	line.y = (int)line.start.y;
	line.d = -line.length_y;
	line.length++;
	while (line.length > 0)
	{
		if (line.x < WIDTH && line.y < HEIGHT && line.x >= 0 && line.y >= 0)
			mlx_pixel_put(mlx, win, line.x, line.y, 0xFF4433);
		line.y += line.dy;
		line.d += 2 * line.length_x;
		if (line.d > 0)
		{
			line.d -= 2 * line.length_y;
			line.x += line.dx;
		}
		line.length--;
	}
}

void		braz_2(void *mlx, void *win, t_line line)
{
	line.x = (int)line.start.x;
	line.y = (int)line.start.y;
	line.d = -line.length_x;
	line.length++;
	while (line.length > 0)
	{
		if (line.x < WIDTH && line.y < HEIGHT && line.x >= 0 && line.y >= 0)
			mlx_pixel_put(mlx, win, line.x, line.y, 0xFF4433);
		line.x += line.dx;
		line.d += 2 * line.length_y;
		if (line.d > 0)
		{
			line.d -= 2 * line.length_x;
			line.y += line.dy;
		}
		line.length--;
	}
}

void		braz(void *mlx, void *win, t_line line)
{
	line.dx = (line.end.x - line.start.x >= 0 ? 1 : -1);
	line.dy = (line.end.y - line.start.y >= 0 ? 1 : -1);
	line.length_x = fabs(line.end.x - line.start.x);
	line.length_y = fabs(line.end.y - line.start.y);
	line.length = fmax(line.length_x, line.length_y);
	if (line.length == 0)
	{
		mlx_pixel_put(mlx, win, (int)line.start.x, (int)line.start.y, 0xFF4433);
	}
	if (line.length_y <= line.length_x)
	{
		braz_2(mlx, win, line);
	}
	else
	{
		braz_3(mlx, win, line);
	}
}
