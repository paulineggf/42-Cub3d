/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:41:13 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/02 21:54:54 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			draw_wall(int key, void *param)
{
	t_map	*map;
	t_pos	*wall;
	int		begin;
	int		tmp;

	map = (t_map*)param;
	map->gamer->degree += 30.0;
	map->ptr->x = 0;
	map->gamer->beta = 30.0;
	while (map->ptr->x <= PROJ_PLANE_X)
	{
		if (!(wall = is_wall(map)))
			return (0);
		wall->slice_height = (double)(BLOCK_SIZE)
		/ (wall->dis * cos((double)(map->gamer->beta * M_PI / 180.0))) * (map->dis_proj_plane);
	//	printf("dis wall : %f\n", (float)(dis_wall(map->gamer, wall)));
	//	printf("slice height : %f\n\n", wall->slice_height);
		begin = (PROJ_PLANE_Y / 2) - (wall->slice_height / 2);
		if (begin < 0 || begin > PROJ_PLANE_Y)
			begin = 0;
		tmp = begin;
		while (begin <= tmp + wall->slice_height && begin < PROJ_PLANE_Y)
			mlx_pixel_put((void*)&key, map->ptr->win_ptr,
			map->ptr->x, begin++, map->ptr->color);
		map->gamer->degree -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->gamer->beta -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->ptr->x += 1;
		free(wall);
		wall = NULL;
	}
	return (1);
}
