/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:23:53 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 18:54:28 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_width(t_map *map)
{
	map->sprite[map->i]->width = abs((int)((double)RES_Y /
	map->sprite[map->i]->transformy));

	// printf("map->sprite[%d]->width : %d\n",
	// map->i, map->sprite[map->i]->width);
}
