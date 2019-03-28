/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:10:00 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/25 19:10:00 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_text(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 30,
			60, 0xFF0000, "HOW TO USE");
	mlx_string_put(fdf->mlx, fdf->win,
			30, 80, 0xFFFF00, "Quit = ESC");
	mlx_string_put(fdf->mlx, fdf->win,
			30, 100, 0xFFFF00, "Move = ^ v < >");
	mlx_string_put(fdf->mlx, fdf->win,
			30, 120, 0xFFFF00, "Zoom = page-up page-down");
	mlx_string_put(fdf->mlx, fdf->win,
			30, 140, 0xFFFF00, "Change Height_Z = + - ");
	mlx_string_put(fdf->mlx, fdf->win,
			30, 160, 0xFFFF00, "Change Y = 4 6");
	mlx_string_put(fdf->mlx, fdf->win,
			30, 180, 0xFFFF00, "Change X = 8 2");
	mlx_string_put(fdf->mlx, fdf->win,
			30, 200, 0xFFFF00, "Change Z = 7 9");
}
