/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:54:32 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/06 19:31:35 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ws(t_map *map, int orientation)
{
	if (orientation == 'W')
	{
		map->gamer->dirx = -1;
		map->gamer->diry = 0;
		map->gamer->planex = 0;
		map->gamer->planey = 0.66;
	}
	if (orientation == 'S')
	{
		map->gamer->dirx = 0;
		map->gamer->diry = -1;
		map->gamer->planex = 0.66;
		map->gamer->planey = 0;
	}
}

void		init_pos(t_map *map, int orientation, int x, int y)
{
	map->gamer->posx = x;
	map->gamer->posy = y;
	if (orientation == 'N')
	{
		map->gamer->dirx = 0;
		map->gamer->diry = 1;
		map->gamer->planex = 0.66;
		map->gamer->planey = 0;
	}
	if (orientation == 'E')
	{
		map->gamer->dirx = 1;
		map->gamer->diry = 0;
		map->gamer->planex = 0;
		map->gamer->planey = 0.66;
	}
	init_ws(map, orientation);
}
