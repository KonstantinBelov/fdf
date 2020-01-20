/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:29:55 by kbelov            #+#    #+#             */
/*   Updated: 2019/12/20 20:29:59 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	prepare(char *file_name, t_fdf *f)
{
	char	*line;
	int		fd;
	int		i;

	f->height = 0;
	f->width = 0;
	fd = open(file_name, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		f->height++;
		if (!f->width)
			f->width = strspllen(line, ' ');
		free(line);
	}
	close(fd);
	f->map = (int **)malloc(sizeof(int *) * (f->height + 1));
	i = -1;
	while (++i <= f->height)
		f->map[i] = (int *)malloc(sizeof(int) * (f->width + 1));
	f->shift_x = 500;
	f->shift_y = 100;
}

void	read_file(char *file_name, t_fdf *f)
{
	int		fd;
	char	*line;
	char	**split;
	int		n;
	int		x;

	fd = open(file_name, O_RDONLY, 0);
	n = 0;
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		x = -1;
		while (split[++x])
		{
			f->map[n][x] = ft_atoi(split[x]);
			free(split[x]);
		}
		free(split);
		free(line);
		n++;
	}
	f->map[++n] = NULL;
	close(fd);
}
