/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:30:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 17:11:26 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		define_params(char *str, int *i, t_map *map)
{
	while (str[*i])
	{
		while (str[*i] == ' ' || str[*i] == '\n')
			(*i)++;
		if (strncmp("R", str + *i, 1))
			define_resolution(str, i, map);
		if (strncmp("NO", str + *i, 2) && map->texture_north == NULL)
		{
			*i += 2;
			if (!(fill_texture(str, i, map->texture_north, map)))
				exit_failure("Map error\n", map);
		}
		if (strncmp("SO", str + *i, 2) && map->texture_south == NULL)
		{
			*i += 2;
			if (!(fill_texture(str, i, map->texture_south, map)))
				exit_failure("Map error\n", map);
		}
		if (strncmp("WE", str + *i, 2) && map->texture_west == NULL)
		{
			*i += 2;
			if (!(fill_texture(str, i, map->texture_west, map)))
				exit_failure("Map error\n", map);
		}
		if (strncmp("EA", str + *i, 2) && map->texture_east == NULL)
		{
			*i += 2;
			if (!(fill_texture(str, i, map->texture_east, map)))
				exit_failure("Map error\n", map);
		}
		if (strncmp("S", str + *i, 1) && map->texture_sprite == NULL
		&& !strncmp("O", str + *i + 1, 1))
		{
			*i += 1;
			if (!(fill_texture(str, i, map->texture_sprite, map)))
				exit_failure("Map error\n", map);
		}
		if (strncmp("F", str + *i, 1) && map->texture_floor == NULL)
		{
			*i += 1;
			if (!(fill_texture(str, i, map->texture_floor, map)))
				exit_failure("Map error\n", map);
		}
		if (strncmp("C", str + *i, 1) && map->texture_sky == NULL)
		{
			*i += 1;
			if (!(fill_texture(str, i, map->texture_sky, map)))
				exit_failure("Map error\n", map);
		}
		if (map->texture_north && map->texture_south && map->texture_east
		&& map->texture_west && map->texture_floor
		&& map->texture_sky && map->texture_sprite)
		{
			while (str[*i] == ' ' || str[*i] == '\n')
				(*i)++;
		}
	}
	exit_failure("Map error\n", map);
}
