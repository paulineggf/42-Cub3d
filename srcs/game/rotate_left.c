/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:36:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 12:59:39 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_map *map)
{
	double	x;
	double	y;

	x = cos(355.0 * M_PI / 180.0) * map->gamer.dirx
	- sin(355.0 * M_PI / 180.0) * map->gamer.diry;
	y = cos(355.0 * M_PI / 180.0) * map->gamer.diry
	+ sin(355.0 * M_PI / 180.0) * map->gamer.dirx;
	map->gamer.dirx = x;
	map->gamer.diry = y;
	x = cos(355.0 * M_PI / 180.0) * map->gamer.planex
	- sin(355.0 * M_PI / 180.0) * map->gamer.planey;
	y = cos(355.0 * M_PI / 180.0) * map->gamer.planey
	+ sin(355.0 * M_PI / 180.0) * map->gamer.planex;
	map->gamer.planex = x;
	map->gamer.planey = y;
}
