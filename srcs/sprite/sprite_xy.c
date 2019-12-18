/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_xy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:40:07 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 20:45:26 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_xy(t_map *map)
{
	map->sprite[map->i]->spritex = (map->sprite[map->i]->mapx + 0.5)
	- map->gamer.posx;
	map->sprite[map->i]->spritey = (map->sprite[map->i]->mapy + 0.5)
	- map->gamer.posy;
}
