/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:30:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 18:30:31 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		define_params(char *str, int *i, t_map *map)
{
	int		len_text;

	while (str[*i])
	{
		while (str[*i] == ' ' || str[*i] == '\n')
			(*i)++;
		if (!ft_strncmp("R", str + *i, 1))
			define_resolution(str, i, map);
		if (!ft_strncmp("NO", str + *i, 2) && map->texture_north == NULL)
		{
			*i += 2;
			len_text = (int)ft_strnlen(str + *i, '\n');
			easy_malloc((void**)&map->texture_north, sizeof(char) * len_text, map);
			if (!(fill_texture(str, i, len_text, &map->texture_north)))
				exit_failure("Map error\n", map);
		}
		if (!ft_strncmp("SO", str + *i, 2) && map->texture_south == NULL)
		{
			*i += 2;
			len_text = (int)ft_strnlen(str + *i, '\n');
			easy_malloc((void**)&map->texture_south, sizeof(char) * len_text, map);
			if (!(fill_texture(str, i, len_text, &map->texture_south)))
				exit_failure("Map error\n", map);
		}
		if (!ft_strncmp("WE", str + *i, 2) && map->texture_west == NULL)
		{
			*i += 2;
			len_text = (int)ft_strnlen(str + *i, '\n');
			easy_malloc((void**)&map->texture_west, sizeof(char) * len_text, map);
			if (!(fill_texture(str, i, len_text, &map->texture_west)))
				exit_failure("Map error\n", map);
		}
		if (!ft_strncmp("EA", str + *i, 2) && map->texture_east == NULL)
		{
			*i += 2;
			len_text = (int)ft_strnlen(str + *i, '\n');
			easy_malloc((void**)&map->texture_east, sizeof(char) * len_text, map);
			if (!(fill_texture(str, i, len_text, &map->texture_east)))
				exit_failure("Map error\n", map);
		}
		if (!ft_strncmp("S", str + *i, 1) && map->texture_sprite == NULL
		&& ft_strncmp("O", str + *i + 1, 1))
		{
			*i += 1;
			len_text = (int)ft_strnlen(str + *i, '\n');
			easy_malloc((void**)&map->texture_sprite, sizeof(char) * len_text, map);
			if (!(fill_texture(str, i, len_text, &map->texture_sprite)))
				exit_failure("Map error\n", map);
		}
		if (!ft_strncmp("F", str + *i, 1) && map->texture_floor == NULL)
		{
			*i += 1;
			len_text = (int)ft_strnlen(str + *i, '\n');
			easy_malloc((void**)&map->texture_floor, sizeof(char) * len_text, map);
			if (!(fill_texture(str, i, len_text, &map->texture_floor)))
				exit_failure("Map error\n", map);
		}
		if (!ft_strncmp("C", str + *i, 1) && map->texture_sky == NULL)
		{
			*i += 1;
			len_text = (int)ft_strnlen(str + *i, '\n');
			easy_malloc((void**)&map->texture_sky, sizeof(char) * len_text, map);	
			if (!(fill_texture(str, i, len_text, &map->texture_sky)))
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
