/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_drawendx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:34:40 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 15:40:06 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_drawendx(t_map *map)
{
	map->sprite[map->i]->drawendx = map->sprite[map->i]->width / 2
	+ map->sprite[map->i]->screenx;
	if (map->sprite[map->i]->drawendx >= map->res_x)
		map->sprite[map->i]->drawendx = map->res_x - 1;
}
