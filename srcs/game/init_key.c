/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:05:53 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/09 16:30:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_key(int key, t_map *map)
{
	if (key == 12)
		map->gamer->forward = 1;
	if (key == 6)
		map->gamer->retreat = 1;
	if (key == 1)
		map->gamer->left = 1;
	if (key == 2)
		map->gamer->right = 1;
	if (key == 123)
		map->gamer->rotate_left = 1;
	if (key == 124)
		map->gamer->rotate_right = 1;
	return (1);
}
