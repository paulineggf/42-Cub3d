/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:33:22 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 19:09:37 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	stock_sprite(t_map *map)
{
	if ((map->i == 0 && map->sprite[map->i]->mapx && map->sprite[map->i]->mapy)
	&& ((map->sprite[map->i]->mapx != map->gamer.mapx)
	|| (map->sprite[map->i]->mapy != map->gamer.mapy)))
	{
		map->i++;
		if (map->i > map->size_sprite)
			map->size_sprite = map->i;
	}
	map->sprite[map->i]->mapx = map->gamer.mapx;
	map->sprite[map->i]->mapy = map->gamer.mapy;
	map->sprite[map->i]->posx = map->gamer.mapx + 0.5;
	map->sprite[map->i]->posy = map->gamer.mapy + 0.5;
	if (!map->sprite[map->i]->f_raydirx && !map->sprite[map->i]->f_raydiry)
	{
		map->sprite[map->i]->f_raydirx = map->gamer.raydirx;
		map->sprite[map->i]->f_raydiry = map->gamer.raydiry;
	}
	else
	{
		map->sprite[map->i]->l_raydirx = map->gamer.raydirx;
		map->sprite[map->i]->l_raydiry = map->gamer.raydiry;
	}
	distance_sprite(map);
	sprite_height(map);
	sprite_x(map);
	// printf("map->i : %d\n", map->i);
	// printf("posx : %f && posy : %f\n", map->sprite[map->i]->posx, map->sprite[map->i]->posy);
	// printf("f_raydirx : %f && f_raydiry : %f\n", map->sprite[map->i]->f_raydirx, map->sprite[map->i]->f_raydiry);
	// printf("l_raydirx : %f && l_raydiry : %f\n", map->sprite[map->i]->l_raydirx, map->sprite[map->i]->l_raydiry);
	// printf("sprite distance : %f\n", map->sprite[map->i]->distance);
	// printf("height : %f\n\n\n", map->sprite[map->i]->height);
}
