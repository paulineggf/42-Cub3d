/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:33:22 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/11 19:58:56 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	stock_sprite(t_map *map)
{
	map->gamer->sprite[map->gamer->i_sprite][0] = map->gamer->posx + 0.5;
	map->gamer->sprite[map->gamer->i_sprite][1] = map->gamer->posy + 0.5;
	map->gamer->i_sprite++;
}
