/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 23:02:53 by kbelov            #+#    #+#             */
/*   Updated: 2019/04/07 00:21:37 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_matrix(char **matrix)
{
	int		y;
	int		x;

	y = -1;
	while (matrix[++y])
	{
		x = -1;
		while (matrix[y][++x])
			write(1, &matrix[y][x], 1);
	}
	write(1, "\n", 1);
}
