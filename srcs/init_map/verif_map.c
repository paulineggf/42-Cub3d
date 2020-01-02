/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:29:03 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 19:39:06 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_cmp(int *map, int cmp, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (map[i] != cmp)
			return (0);
		i++;
	}
	return (1);
}

void		verif_map(t_map *map)
{
	if (!ft_cmp(map->map[0], 1, map->x))
		exit_failure("Error\nMap error\n", map);
	if (!ft_cmp(map->map[map->y - 1], 1, map->x))
		exit_failure("Error\nMap error\n", map);
}
