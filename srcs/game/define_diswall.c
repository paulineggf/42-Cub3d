/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_diswall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:23:52 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/09 17:26:23 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_diswall(t_map *map)
{
	if (map->gamer->side == 0)
		map->gamer->perpwalldist =
		((double)map->gamer->mapx - (double)map->gamer->posx
		+ ((1.0 - (double)map->gamer->stepx) / 2.0)) / map->gamer->raydirx;
	else
		map->gamer->perpwalldist =
		((double)map->gamer->mapy - (double)map->gamer->posy
		+ ((1.0 - (double)map->gamer->stepy) / 2.0)) / map->gamer->raydiry;
}
