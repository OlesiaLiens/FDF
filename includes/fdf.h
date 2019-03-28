/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:20:15 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/12 21:12:10 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# define WIDTH 1200
# define HEIGHT 1200
# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

typedef struct	s_iter
{
	int			i;
	int			j;
}				t_iter;

typedef struct	s_pixel
{
	double		x;
	double		y;
}				t_pixel;

typedef struct	s_line
{
	int			dx;
	int			dy;
	double		d;
	double		length_x;
	double		length_y;
	double		length;
	int			x;
	int			y;
	t_pixel		start;
	t_pixel		end;
}				t_line;

typedef struct	s_cor
{
	double		x;
	double		y;
	double		z;
	int			z_change;
	double		z_origin;
	double		x_origin;
	double		y_origin;
	int			color;
}				t_cor;

typedef struct	s_fdf
{
	size_t		x_1;
	size_t		y_1;
	double		buff_x;
	double		buff_x2;
	double		buff_y;
	double		buff_y2;
	double		buff_z;
	double		buff_z2;
	double		angle_x_1;
	double		angle_y_1;
	double		angle_z_1;

	int			width;
	int			rows;
	int			status;
	t_cor		**map;
	void		*mlx;
	void		*win;
	double		zoom;
	int			x_move;
	int			y_move;
	double		height_z;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	double		x;
	double		y;
	double		z;
}				t_fdf;

enum			e_err_code
{
	INVALID_MAP = 404
};

void			ft_usage(void);
void			open_file(t_fdf *fdf, char *file_name);
int				is_valid_chars(char *line);
int				is_line_valid(t_fdf *fdf, char *line);
int				line_width(char *line, char c);
int				ft_my_atoi(const char *str, int *i);
void			braz(void *mlx, void *win, t_line line);
void			init_mlx(t_fdf *fdf);
void			draw_dots(t_fdf *fdf);
int				set_key(int key, void	*param);
void			invalid_map(void);
void			rotate_cor(t_fdf *fdf);
void			parse_string(t_list *raw_data_lst, t_fdf *fdf);
void			put_text(t_fdf *fdf);
void			key_rotation_2(t_fdf *fdf, int key);

#endif
