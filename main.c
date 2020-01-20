/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:51:11 by kbelov            #+#    #+#             */
/*   Updated: 2019/12/17 18:51:23 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *f)
{
	printf("%d\n", key);
	if (key == 123 || key == 124 || key == 125 || key == 126 || key == 116 ||
		key == 121)
		deal_key_2(key, f);
	else if (key == 53)
		exit(0);
	else if (key == 24)
		f->zoom += 4;
	else if (key == 27)
		f->zoom -= 4;
	else if (key == 13)
		f->elevation += 1;
	else if (key == 1)
		f->elevation -= 1;
	else if (key == 69)
		f->zoom += 1;
	else if (key == 78)
		f->zoom -= 1;
	else
		return (1);
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	draw(f);
	return (0);
}

void	deal_key_2(int key, t_fdf *f)
{
	if (key == 126)
		f->shift_y -= 10;
	else if (key == 125)
		f->shift_y += 10;
	else if (key == 123)
		f->shift_x -= 10;
	else if (key == 124)
		f->shift_x += 10;
	else if (key == 116)
		f->projection += 0.1;
	else if (key == 121)
		f->projection -= 0.1;
}

int		main(int ac, char *av[])
{
	t_fdf *f;

	f = (t_fdf *)malloc(sizeof(t_fdf));
	if (ac == 2)
	{
		prepare(av[1], f);
		read_file(av[1], f);
	}
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, 1920, 1080, "FDF");
	f->zoom = 32;
	f->projection = 0.8;
	f->elevation = 1;
	draw(f);
	mlx_key_hook(f->win_ptr, deal_key, f);
	mlx_loop(f->mlx_ptr);
	return (0);
}
