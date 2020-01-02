/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_xy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:59:24 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 20:22:56 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_xy(t_map *map)
{
	int		hit;

	hit = 0;
	map->i = 0;
	while (hit == 0)
	{
		if (map->gamer.sidedistx < map->gamer.sidedisty)
		{
			map->gamer.sidedistx += map->gamer.deltadistx;
			map->gamer.mapx += map->gamer.stepx;
			map->gamer.side = 0;
		}
		else
		{
			map->gamer.sidedisty += map->gamer.deltadisty;
			map->gamer.mapy += map->gamer.stepy;
			map->gamer.side = 1;
		}
		if (map->map[map->gamer.mapy][map->gamer.mapx] == 1)
			hit = 1;
		if (map->map[map->gamer.mapy][map->gamer.mapx] == 2)
			sprite_stock(map);
	}
}
