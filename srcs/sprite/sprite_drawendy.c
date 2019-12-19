/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_drawendy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:17:55 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 15:40:39 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_drawendy(t_map *map)
{
	map->sprite[map->i]->drawendy = map->sprite[map->i]->height / 2 + map->res_y / 2;
	if (map->sprite[map->i]->drawendy >= map->res_y)
		map->sprite[map->i]->drawendy = map->res_y - 1;
}
