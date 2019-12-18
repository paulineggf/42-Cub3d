/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_invdet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:45:29 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 20:45:03 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_invdet(t_map *map)
{
	map->sprite[map->i]->invdet = 1.0 / (map->gamer.planex * map->gamer.diry
	- map->gamer.dirx * map->gamer.planey);
}
