/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_drawstartx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:20:47 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 20:25:11 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_drawstartx(t_map *map)
{
	map->sprite[map->i]->drawstartx = -map->sprite[map->i]->width / 2
	+ map->sprite[map->i]->screenx;
	if (map->sprite[map->i]->drawstartx < 0)
		map->sprite[map->i]->drawstartx = 0;
}
