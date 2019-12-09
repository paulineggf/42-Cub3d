/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:32:08 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/09 15:33:03 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left_right(t_map *map)
{
	double	x;
	double	y;

	if (map->gamer->left)
	{
		x = cos(270.0 * M_PI / 180.0) * map->gamer->dirx
		- sin(270.0 * M_PI / 180.0) * map->gamer->diry;
		y = cos(270.0 * M_PI / 180.0) * map->gamer->diry
		+ sin(270.0 * M_PI / 180.0) * map->gamer->dirx;
		map->gamer->posx += x * 0.1;
		map->gamer->posy += y * 0.1;
	}
	if (map->gamer->right)
	{
		x = cos(90.0 * M_PI / 180.0) * map->gamer->dirx
		- sin(90.0 * M_PI / 180.0) * map->gamer->diry;
		y = cos(90.0 * M_PI / 180.0) * map->gamer->diry
		+ sin(90.0 * M_PI / 180.0) * map->gamer->dirx;
		map->gamer->posx += x * 0.1;
		map->gamer->posy += y * 0.1;
	}
}
