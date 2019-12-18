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

#ifndef FILLER_H
# define FILLER_H

# include "get_next_line.h"
# include "minilibx_macos/mlx.h"

typedef	struct	s_state
{
	int     width;
    int     height;
    int     **map;
}				t_fdf;

#endif
