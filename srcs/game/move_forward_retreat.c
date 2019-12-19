/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward_retreat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:30:43 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 11:13:39 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	move_fast(t_map *map)
{
	if (map->gamer.run)
	{
		if (map->map[(int)(map->gamer.posy + map->gamer.diry * 0.3)]
		[(int)(map->gamer.posx + map->gamer.dirx * 0.3)] == 1 ||
		map->map[(int)(map->gamer.posy + map->gamer.diry * 0.3)]
		[(int)(map->gamer.posx + map->gamer.dirx * 0.3)] == 2)
			return (0);
		map->gamer.posx = map->gamer.posx + map->gamer.dirx * 0.3;
		map->gamer.posy = map->gamer.posy + map->gamer.diry * 0.3;
	}
	if (map->gamer.retreat_fast)
	{
		if (map->map[(int)(map->gamer.posy - map->gamer.diry * 0.3)]
		[(int)(map->gamer.posx - map->gamer.dirx * 0.3)] == 1 ||
		map->map[(int)(map->gamer.posy - map->gamer.diry * 0.3)]
		[(int)(map->gamer.posx - map->gamer.dirx * 0.3)] == 2)
			return (0);
		map->gamer.posx = map->gamer.posx - map->gamer.dirx * 0.3;
		map->gamer.posy = map->gamer.posy - map->gamer.diry * 0.3;
	}
	return (1);
}

int			move_forward_retreat(t_map *map)
{
	if (map->gamer.forward)
	{
		if (map->map[(int)(map->gamer.posy + map->gamer.diry * 0.1)]
		[(int)(map->gamer.posx + map->gamer.dirx * 0.1)] == 1 ||
		map->map[(int)(map->gamer.posy + map->gamer.diry * 0.1)]
		[(int)(map->gamer.posx + map->gamer.dirx * 0.1)] == 2)
			return (0);
		map->gamer.posx = map->gamer.posx + map->gamer.dirx * 0.1;
		map->gamer.posy = map->gamer.posy + map->gamer.diry * 0.1;
	}
	if (map->gamer.retreat)
	{
		if (map->map[(int)(map->gamer.posy - map->gamer.diry * 0.1)]
		[(int)(map->gamer.posx - map->gamer.dirx * 0.1)] == 1 ||
		map->map[(int)(map->gamer.posy - map->gamer.diry * 0.1)]
		[(int)(map->gamer.posx - map->gamer.dirx * 0.1)] == 2)
			return (0);
		map->gamer.posx = map->gamer.posx - map->gamer.dirx * 0.1;
		map->gamer.posy = map->gamer.posy - map->gamer.diry * 0.1;
	}
	if (map->gamer.run || map->gamer.retreat_fast)
		if (!(move_fast(map)))
			return (0);
	return (1);
}
