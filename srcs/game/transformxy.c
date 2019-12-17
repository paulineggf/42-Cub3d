/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformxy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:18:50 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/17 15:42:43 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	transformxy(t_map *map)
{
	map->sprite[map->i]->transformx = map->sprite[map->i]->invdet *
	((map->gamer.diry * map->sprite[map->i]->spritex) - (map->gamer.dirx
	* map->sprite[map->i]->spritey));

	map->sprite[map->i]->transformy = map->sprite[map->i]->invdet *
	((map->gamer.planey * -1 * map->sprite[map->i]->spritex)
	+ (map->gamer.planex * map->sprite[map->i]->spritey));

	printf("map->sprite[%d]->transformx : %f\n",
	map->i, map->sprite[map->i]->transformx);
	printf("map->sprite[%d]->transformy : %f\n\n",
	map->i, map->sprite[map->i]->transformy);
}
