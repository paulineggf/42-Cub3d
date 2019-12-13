/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:34:44 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 19:00:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		distance_sprite(t_map *map)
{
	// if (map->gamer.side == 0)
	// 	map->sprite[map->i]->distance =
	// 	((double)map->sprite[map->i]->mapx - (double)map->gamer.posx
	// 	+ ((1.0 - (double)map->gamer.stepx) / 2.0)) / map->gamer.raydirx;
	// else
	// 	map->sprite[map->i]->distance =
	// 	((double)map->sprite[map->i]->mapy - (double)map->gamer.posy
	// 	+ ((1.0 - (double)map->gamer.stepy) / 2.0)) / map->gamer.raydiry;

	map->sprite[map->i]->distance = (map->gamer.posx - map->sprite[map->i]->mapx) * (map->gamer.posx - map->sprite[map->i]->mapx) 
	+ (map->gamer.posy - map->sprite[map->i]->mapy) * (map->gamer.posy - map->sprite[map->i]->mapy);
	// printf("distance : %f\n", (map->gamer.posx - map->sprite[map->i]->mapx) * (map->gamer.posx - map->sprite[map->i]->mapx) 
	// + (map->gamer.posy - map->sprite[map->i]->mapy) * (map->gamer.posy - map->sprite[map->i]->mapy));
	// ((posX - sprite[i].x) * (posX - sprite[i].x) + (posY - sprite[i].y) * (posY - sprite[i].y));	
}
