/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:13:45 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/03 17:34:16 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		draw_wall3(t_map *map, t_pos *wall, unsigned int *str)
{
	int		tmp;

	if (!(wall = is_wall(map)))
		return (0);
	wall->slice_height = (double)(BLOCK_SIZE)
	/ (wall->dis * cos((double)(map->gamer->beta * M_PI / 180.0)))
	* (map->dis_proj_plane);
	map->ptr->y = (PROJ_PLANE_Y / 2) - (wall->slice_height / 2);
	if (map->ptr->y < 0 || map->ptr->y > PROJ_PLANE_Y)
		map->ptr->y = 0;
	if (wall->hor)
		map->ptr->color = 0xF654AB;
	else
		map->ptr->color = 0xFF6541;
	tmp = map->ptr->y;
	while (map->ptr->y <= tmp + wall->slice_height
	&& map->ptr->y < PROJ_PLANE_Y)
	{
		str[map->ptr->size_l / 4 * map->ptr->y
		+ map->ptr->x] = map->ptr->color;
		map->ptr->y += 1;
	}
	return (1);
}

int				draw_wall2(t_map *map, unsigned int *str)
{
	t_pos	*wall;
	double	degree;

	degree = map->gamer->degree;
	map->gamer->degree += 30.0;
	map->ptr->x = 0;
	map->gamer->beta = 30.0;
	while (map->ptr->x < PROJ_PLANE_X)
	{
		draw_wall3(map, wall, str);
		map->gamer->degree -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->gamer->beta -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->ptr->x += 1;
		free(wall);
		wall = NULL;
	}
	map->gamer->degree = degree;
	return (1);
}
