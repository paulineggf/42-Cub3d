/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:33:22 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/17 18:35:17 by pganglof         ###   ########.fr       */
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
	// map->sprite[map->i]->posx = map->gamer.mapx + 0.5;
	// map->sprite[map->i]->posy = map->gamer.mapy + 0.5;
	// if (!map->sprite[map->i]->f_raydirx && !map->sprite[map->i]->f_raydiry)
	// {
	// 	map->sprite[map->i]->f_raydirx = map->gamer.raydirx;
	// 	map->sprite[map->i]->f_raydiry = map->gamer.raydiry;
	// }
	// else
	// {
	// 	map->sprite[map->i]->l_raydirx = map->gamer.raydirx;
	// 	map->sprite[map->i]->l_raydiry = map->gamer.raydiry;
	// }
}
