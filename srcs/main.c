/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:29:34 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/12 20:11:53 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			exit_x(void)
{
	exit(1);
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_usage();
		return (0);
	}
	fdf = ft_bzero(ft_memalloc(sizeof(t_fdf)), sizeof(t_fdf));
	fdf->width = -1;
	open_file(fdf, argv[1]);
	init_mlx(fdf);
	fdf->angle_x = 48;
	fdf->angle_y = 30;
	fdf->angle_z = -6;
	rotate_cor(fdf);
	draw_dots(fdf);
	mlx_hook(fdf->win, 2, 5, set_key, (void *)fdf);
	mlx_hook(fdf->win, 17, 1L << 17, exit_x, fdf);
	put_text(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
