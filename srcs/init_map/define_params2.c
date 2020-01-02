/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_params2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:30:21 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 19:16:17 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		define_params2(char *str, int i, t_map *map)
{
	while (ft_isspace(str[i]))
		i++;
	if (!ft_strncmp("R", str + i, 1))
		define_resolution(str, i + 1, map);
	else if (!ft_strncmp("NO", str + i, 2) && map->texture_north == NULL)
		fill_texture(str, i + 2, &map->texture_north, map);
	else if (!ft_strncmp("SO", str + i, 2) && map->texture_south == NULL)
		fill_texture(str, i + 2, &map->texture_south, map);
	else if (!ft_strncmp("WE", str + i, 2) && map->texture_west == NULL)
		fill_texture(str, i + 2, &map->texture_west, map);
	else if (!ft_strncmp("EA", str + i, 2) && map->texture_east == NULL)
		fill_texture(str, i + 2, &map->texture_east, map);
	else if (!ft_strncmp("S", str + i, 1) && map->texture_sprite == NULL
	&& ft_strncmp("O", str + i + 1, 1))
		fill_texture(str, i + 1, &map->texture_sprite, map);
	else if (!ft_strncmp("F", str + i, 1) && map->texture_floor == NULL)
		fill_texture(str, i + 1, &map->texture_floor, map);
	else if (!ft_strncmp("C", str + i, 1) && map->texture_sky == NULL)
		fill_texture(str, i + 1, &map->texture_sky, map);
	else if (!str[i])
		return ;
	else
		exit_failure("Error\nIdentifier error\n", map);
}
