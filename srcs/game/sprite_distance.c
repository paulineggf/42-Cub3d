/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:34:44 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/17 20:40:56 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		distance_sprite(t_map *map)
{
	map->sprite[map->i]->distance = (map->gamer.posx -
	map->sprite[map->i]->mapx) * (map->gamer.posx - map->sprite[map->i]->mapx)
	+ (map->gamer.posy - map->sprite[map->i]->mapy) * (map->gamer.posy -
	map->sprite[map->i]->mapy);

	printf("map->sprite[%d]->distance : %f\n",
	map->i, map->sprite[map->i]->distance);
}
