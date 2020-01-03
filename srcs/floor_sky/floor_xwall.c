/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_xwall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:08:02 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/03 11:28:30 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_xywall(t_map *map)
{
	if (map->gamer.side == 0 && map->gamer.raydirx > 0)
	{
		map->gamer.floorxwall = map->gamer.mapx;
		map->gamer.floorywall = map->gamer.mapy + map->gamer.wallx;
	}
	else if (map->gamer.side == 0 && map->gamer.raydirx < 0)
	{
		map->gamer.floorxwall = map->gamer.mapx + 1.0;
		map->gamer.floorywall = map->gamer.mapy + map->gamer.wallx;
	}
	else if (map->gamer.side == 1 && map->gamer.raydiry > 0)
	{
		map->gamer.floorxwall = map->gamer.mapx + map->gamer.wallx;
		map->gamer.floorywall = map->gamer.mapy;
	}
	else
	{
		map->gamer.floorxwall = map->gamer.mapx + map->gamer.wallx;
		map->gamer.floorywall = map->gamer.mapy + 1.0;
	}
}
