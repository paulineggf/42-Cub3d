/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:34:32 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/11 18:37:41 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_map *map)
{
	double	x;
	double	y;

	x = cos(3.0 * M_PI / 180.0) * map->gamer->dirx
	- sin(3.0 * M_PI / 180.0) * map->gamer->diry;
	y = cos(3.0 * M_PI / 180.0) * map->gamer->diry
	+ sin(3.0 * M_PI / 180.0) * map->gamer->dirx;
	map->gamer->dirx = x;
	map->gamer->diry = y;
	x = cos(3.0 * M_PI / 180.0) * map->gamer->planex
	- sin(3.0 * M_PI / 180.0) * map->gamer->planey;
	y = cos(3.0 * M_PI / 180.0) * map->gamer->planey
	+ sin(3.0 * M_PI / 180.0) * map->gamer->planex;
	map->gamer->planex = x;
	map->gamer->planey = y;
}
