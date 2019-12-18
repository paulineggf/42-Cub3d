/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_stock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:33:22 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 18:35:52 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_stock(t_map *map)
{
	map->i = 0;
	while (map->sprite[map->i]->mapx || map->sprite[map->i]->mapy)
	{
		if (map->sprite[map->i]->mapx == map->gamer.mapx
		&& map->sprite[map->i]->mapy == map->gamer.mapy)
			return ;
		map->i++;
		if (map->i > map->size_sprite)
			map->size_sprite = map->i;
	}
	map->sprite[map->i]->mapx = map->gamer.mapx;
	map->sprite[map->i]->mapy = map->gamer.mapy;
	sprite_distance(map);
}
