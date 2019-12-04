/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gamer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:30:00 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/04 16:16:10 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_gamer(int key, t_map *map)
{
	if (key == 12)
		if (!(move_forward(map)))
			return ;
	if (key == 6)
		if (!(move_back(map)))
			return ;
	if (key == 2)
		map->gamer->degree--;
	if (key == 1)
		map->gamer->degree++;
	if (map->gamer->degree < 0)
		map->gamer->degree += 360;
	if (map->gamer->degree >= 360)
		map->gamer->degree -= 360;
	orientation(map);
}
