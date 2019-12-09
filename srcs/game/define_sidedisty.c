/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_sidedisty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:57:48 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/09 17:26:26 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_sidedisty(t_map *map)
{
	if (map->gamer->raydiry < 0)
	{
		map->gamer->stepy = -1;
		map->gamer->sidedisty = (map->gamer->posy - map->gamer->mapy)
		* map->gamer->deltadisty;
	}
	else
	{
		map->gamer->stepy = 1;
		map->gamer->sidedisty = (map->gamer->mapy + 1.0 - map->gamer->posy)
		* map->gamer->deltadisty;
	}
}
