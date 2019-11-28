/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:41:13 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/28 14:28:39 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			draw_wall(int key, void *param)
{
	t_map	*map;
	t_pos	*wall;
	t_win	*ptr;
	float	begin;

	(void)key;
	map = (t_map*)param;
	wall = (t_pos*)map->pos;
	ptr = (t_win*)map->ptr;
	begin = PROJ_PLANE_Y - (wall->slice_height / 2);
	while (begin <= begin + wall->slice_height)
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr,
		wall->posx, begin++, ptr->color);
	return (1);
}

/*void		draw_wall(int slice_height, t_win *ptr, t_pos *wall)
{
	int		begin;

	begin = PROJ_PLANE_Y - (slice_height / 2);
	while (begin <= begin + slice_height)
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr,
		wall->posx, begin++, ptr->color);
}
*/