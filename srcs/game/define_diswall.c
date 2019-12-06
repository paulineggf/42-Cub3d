/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_diswall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:23:52 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/06 19:48:47 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_diswall(t_map *map, int side, int mapx, int mapy)
{
	printf("stepx : %d\n", map->gamer->stepx);
	printf("stepy : %d\n", map->gamer->stepy);
	printf("raydirx : %f\n", map->gamer->raydirx);
	printf("raydiry : %f\n", map->gamer->raydiry);
	if (side == 0)
		map->gamer->perpwalldist = ((mapx - map->gamer->posx) + (1 - map->gamer->stepx) / 2) / map->gamer->raydirx;
	else
		map->gamer->perpwalldist = ((mapy - map->gamer->posy) + (1 - map->gamer->stepy) / 2) / map->gamer->raydiry;
}
