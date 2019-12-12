/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_wallx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:36:46 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/12 19:30:53 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_wallx(t_map *map)
{
	if (map->gamer->side == 0)
		map->gamer->wallx = map->gamer->posy + map->gamer->perpwalldist
		* map->gamer->raydiry;
	else
		map->gamer->wallx = map->gamer->posx + map->gamer->perpwalldist
		* map->gamer->raydirx;
	map->gamer->wallx -= floor(map->gamer->wallx);
}
