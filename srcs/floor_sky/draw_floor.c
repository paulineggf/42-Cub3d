/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:24:20 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 20:40:55 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		floor_loop(t_map *map, int *y)
{
	while (*y < RES_Y)
	{
		map->floor.currentdist =
		(double)RES_Y / (2.0 * (double)*y - (double)RES_Y);
		map->floor.weight =
		(map->floor.currentdist - map->floor.displayer)
		/ (map->floor.distwall - map->floor.displayer);
		map->floor.currentfloorx = map->floor.weight * map->gamer.floorxwall
		+ (1.0 - map->floor.weight) * map->gamer.posx;
		map->floor.currentfloory = map->floor.weight * map->gamer.floorywall
		+ (1.0 - map->floor.weight) * map->gamer.posy;
		map->floor.floortextx = (int)(map->floor.currentfloorx
		* map->text[FLOOR]->x) % map->text[FLOOR]->x;
		map->floor.floortexty = (int)(map->floor.currentfloory
		* map->text[FLOOR]->y) % map->text[FLOOR]->y;
		map->ptr.str[(map->ptr.size_l / 4) * *y + map->stripe] =
		map->text[FLOOR]->str[(map->text[FLOOR]->x * map->floor.floortexty
		+ map->floor.floortextx)];
		(*y)++;
	}
}

void			draw_floor(t_map *map)
{
	int		y;

	map->floor.displayer = 0.0;
	floor_xywall(map);
	map->floor.distwall = map->gamer.perpwalldist;
	if (map->gamer.drawend < 0)
		map->gamer.drawend = RES_Y;
	y = map->gamer.drawend + 1;
	floor_loop(map, &y);
}
