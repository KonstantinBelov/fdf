/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:50:26 by kbelov            #+#    #+#             */
/*   Updated: 2019/12/17 18:50:30 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "minilibx_macos/mlx.h"

typedef	struct	s_fdf
{
	int		width;
	int		height;
	int		**map;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	projection;
	int		elevation;
	float	x;
	float	y;
	int		z;
	int		z1;

	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

int				deal_key(int key, t_fdf *f);
void			deal_key_2(int key, t_fdf *f);
void			prepare(char *file_name, t_fdf *f);
void			add_zoom(float *x1, float *y1, t_fdf *f);
void			read_file(char *file_name, t_fdf *f);
void			bresenham(float x1, float y1, t_fdf *f);
void			projection(float *x, float *y, int z, t_fdf *f);
void			draw(t_fdf *f);

#endif
