/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gamer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:13:36 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/09 15:37:15 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_gamer(t_map *map)
{
	if (map->gamer->forward || map->gamer->retreat)
		move_forward_retreat(map);
	if (map->gamer->left || map->gamer->right)
		move_left_right(map);
	if (map->gamer->rotate_right)
		rotate_right(map);
	if (map->gamer->rotate_left)
		rotate_left(map);
}
