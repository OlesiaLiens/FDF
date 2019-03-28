/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_key2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:06:00 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/27 19:06:00 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_rotation_2(t_fdf *fdf, int key)
{
	if (key == 35)
	{
		fdf->angle_x = 0;
		fdf->angle_y = 0;
		fdf->angle_z = 0;
	}
	if (key == 34)
	{
		fdf->angle_x = 45;
		fdf->angle_y = 26.65;
		fdf->angle_z = -30;
	}
}
