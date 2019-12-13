/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:41:47 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 19:00:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_x(t_map *map)
{
	if (map->gamer.side == 0)
		map->sprite[map->i]->x = map->gamer.posy + map->sprite[map->i]->distance
		* map->gamer.raydiry;
	else
		map->sprite[map->i]->x = map->gamer.posx + map->sprite[map->i]->distance
		* map->gamer.raydirx;
	map->sprite[map->i]->x -= floor(map->sprite[map->i]->x);
}
