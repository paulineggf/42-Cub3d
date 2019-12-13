/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:54:32 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 19:00:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ws(t_map *map, int orientation)
{
	if (orientation == 'W')
	{
		map->gamer.dirx = -1;
		map->gamer.diry = 0;
		map->gamer.planex = 0;
		map->gamer.planey = -0.60;
	}
	if (orientation == 'E')
	{
		map->gamer.dirx = 1;
		map->gamer.diry = 0;
		map->gamer.planex = 0;
		map->gamer.planey = 0.60;
	}
}

void		init_pos(t_map *map, int orientation, int x, int y)
{
	map->gamer.posx = x + 0.5;
	map->gamer.posy = y + 0.5;
	if (orientation == 'N')
	{
		map->gamer.dirx = 0;
		map->gamer.diry = -1;
		map->gamer.planex = 0.60;
		map->gamer.planey = 0;
	}
	if (orientation == 'S')
	{
		map->gamer.dirx = 0;
		map->gamer.diry = 1;
		map->gamer.planex = -0.60;
		map->gamer.planey = 0;
	}
	init_ws(map, orientation);
}
