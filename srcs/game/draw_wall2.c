/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:13:45 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/04 16:48:09 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		draw_wall3(t_map *map, unsigned int *str)
{
	int		tmp;
	t_pos	*wall;

	if (!(wall = is_wall(map)))
		return (0);
	wall->slice_height = (double)(BLOCK_SIZE)
	/ (wall->dis * cos((double)(map->gamer->beta * M_PI / 180.0)))
	* (map->dis_proj_plane);
	map->ptr->y = (PROJ_PLANE_Y / 2) - (wall->slice_height / 2);
	if (map->ptr->y < 0 || map->ptr->y > PROJ_PLANE_Y)
		map->ptr->y = 0;
	if (wall->hor)
		map->ptr->color = 0xF6582B;
	else
		map->ptr->color = 0x174541;
	if (map->gamer->degree == 0)
		map->ptr->color = 0x6587FA;
	if (map->gamer->degree == 90)
		map->ptr->color = 0xF7F40F;
	if (map->gamer->degree == 180)
		map->ptr->color = 0xF60FF7;
	if (map->gamer->degree == 270)
		map->ptr->color = 0x39F70F;
	if (map->gamer->degree == 360)
		map->ptr->color = 0x358974;
	tmp = map->ptr->y;
	while (map->ptr->y <= tmp + wall->slice_height
	&& map->ptr->y < PROJ_PLANE_Y)
	{
		str[map->ptr->size_l / 4 * map->ptr->y
		+ map->ptr->x] = map->ptr->color;
		map->ptr->y += 1;
	}
	free(wall);
	wall = NULL;
	return (1);
}

int				draw_wall2(t_map *map, unsigned int *str)
{
	double	degree;

	degree = map->gamer->degree;
	map->gamer->degree += 30.0;
	map->ptr->x = 0;
	map->gamer->beta = 30.0;
	while (map->ptr->x < PROJ_PLANE_X)
	{
		if (map->gamer->degree >= 360)
			map->gamer->degree -= 360;
		if (map->gamer->degree < 0)
			map->gamer->degree += 360;
		if (!(draw_wall3(map, str)))
			return (0);
		map->gamer->degree -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->gamer->beta -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->ptr->x += 1;
	}
	map->gamer->degree = degree;
	return (1);
}
