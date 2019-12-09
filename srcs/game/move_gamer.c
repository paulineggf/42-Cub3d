/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gamer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:13:36 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/09 19:17:56 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move_gamer(t_map *map)
{
	if (map->gamer->forward || map->gamer->retreat)
		if (!(move_forward_retreat(map)))
			return (0);
	if (map->gamer->left)
		if (!(move_left(map)))
			return (0);
	if (map->gamer->right)
		if (!(move_right(map)))
			return (0);
	if (map->gamer->rotate_right)
		rotate_right(map);
	if (map->gamer->rotate_left)
		rotate_left(map);
	return (1);
}
