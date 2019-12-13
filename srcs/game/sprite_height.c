/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_height.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:37:35 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 22:09:06 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_height(t_map *map)
{
	if (map->sprite[map->i]->distance > 0)
		map->sprite[map->i]->height = (double)RES_Y / map->sprite[map->i]->distance;
	else
		map->sprite[map->i]->height = ((double)RES_Y - 1.0);
	map->sprite[map->i]->real_drawstart = (RES_Y / 2) - (map->sprite[map->i]->height / 2);
	if (map->sprite[map->i]->real_drawstart <= 0)
		map->sprite[map->i]->drawstart = 0;
	else
		map->sprite[map->i]->drawstart = map->sprite[map->i]->real_drawstart;
	map->sprite[map->i]->drawend = map->sprite[map->i]->drawstart + map->sprite[map->i]->height;
	if (map->sprite[map->i]->drawend >= RES_Y)
		map->sprite[map->i]->drawend = RES_Y - 1;
}
