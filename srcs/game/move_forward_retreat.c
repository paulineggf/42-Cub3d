/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:30:43 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/09 15:37:30 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward_retreat(t_map *map)
{
	if (map->gamer->forward)
	{
		map->gamer->posx = map->gamer->posx + map->gamer->dirx * 0.1;
		map->gamer->posy = map->gamer->posy + map->gamer->diry * 0.1;
	}
	if (map->gamer->retreat)
	{
		map->gamer->posx = map->gamer->posx - map->gamer->dirx * 0.1;
		map->gamer->posy = map->gamer->posy - map->gamer->diry * 0.1;
	}
}
