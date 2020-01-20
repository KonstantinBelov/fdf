/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:30:23 by kbelov            #+#    #+#             */
/*   Updated: 2019/12/20 20:30:26 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		projection(float *x, float *y, int z, t_fdf *f)
{
	*x = (*x - *y) * cos(f->projection);
	*y = (*x + *y) * sin(f->projection) - z;
}

void		add_zoom(float *x1, float *y1, t_fdf *f)
{
	f->x *= f->zoom;
	f->y *= f->zoom;
	*x1 *= f->zoom;
	*y1 *= f->zoom;
}

void		bresenham(float x1, float y1, t_fdf *f)
{
	float	x_step;
	float	y_step;
	int		max;

	f->z = f->map[(int)f->y][(int)f->x] * f->elevation;
	f->z1 = f->map[(int)y1][(int)x1] * f->elevation;
	add_zoom(&x1, &y1, f);
	f->color = (f->z || f->z1) ? 0xe80c0c : 0xffffff;
	projection(&f->x, &f->y, f->z, f);
	projection(&x1, &y1, f->z1, f);
	f->x += f->shift_x;
	x1 += f->shift_x;
	f->y += f->shift_y;
	y1 += f->shift_y;
	x_step = x1 - f->x;
	y_step = y1 - f->y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(f->x - x1) || (int)(f->y - y1))
	{
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, f->x, f->y, f->color);
		f->x += x_step;
		f->y += y_step;
	}
}

void		draw(t_fdf *f)
{
	int n;
	int x;

	n = -1;
	while (++n < f->height)
	{
		x = -1;
		while (++x < f->width)
		{
			if (n < f->height - 1)
			{
				f->x = x;
				f->y = n;
				bresenham(x, n + 1, f);
			}
			if (x < f->width - 1)
			{
				f->x = x;
				f->y = n;
				bresenham(x + 1, n, f);
			}
		}
	}
}
