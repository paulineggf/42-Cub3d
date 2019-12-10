/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_sidedistx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:56:34 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/10 14:35:40 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_sidedistx(t_map *map)
{
	if (map->gamer->raydirx < 0)
	{
		map->gamer->stepx = -1;
		map->gamer->sidedistx = (map->gamer->posx - map->gamer->mapx)
		* map->gamer->deltadistx;
	}
	else
	{
		map->gamer->stepx = 1;
		map->gamer->sidedistx = (map->gamer->mapx + 1.0 - map->gamer->posx)
		* map->gamer->deltadistx;
	}
}
