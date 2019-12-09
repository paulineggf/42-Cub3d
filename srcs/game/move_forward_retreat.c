/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward_retreat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:30:43 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/09 19:01:17 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move_forward_retreat(t_map *map)
{
	if (map->gamer->forward)
	{
		if (map->map[(int)(map->gamer->posy + map->gamer->diry * 0.1)]
		[(int)(map->gamer->posx + map->gamer->dirx * 0.1)] == 1)
			return (0);
		map->gamer->posx = map->gamer->posx + map->gamer->dirx * 0.1;
		map->gamer->posy = map->gamer->posy + map->gamer->diry * 0.1;
	}
	if (map->gamer->retreat)
	{
		if (map->map[(int)(map->gamer->posy - map->gamer->diry * 0.1)]
		[(int)(map->gamer->posx - map->gamer->dirx * 0.1)] == 1)
			return (0);
		map->gamer->posx = map->gamer->posx - map->gamer->dirx * 0.1;
		map->gamer->posy = map->gamer->posy - map->gamer->diry * 0.1;
	}
	return (1);
}
