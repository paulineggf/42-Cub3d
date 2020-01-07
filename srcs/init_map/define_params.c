/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:06:36 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/07 11:07:32 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		end_define_params(int ret, char *str, char **tmp, t_map *map)
{
	if (ret == -1)
	{
		free(*tmp);
		exit_failure("Read fail\n", map);
	}
	else if (!str[0])
	{
		free(str);
		str = NULL;
		return ;
	}
	else if (map->x != define_x(str, tmp, map))
	{
		free(str);
		free(*tmp);
		exit_failure("Error\nMap error\n", map);
	}
	free(str);
}

static void	loop_define_params(char *str, char **tmp, int *control, t_map *map)
{
	if (map->texture_north && map->texture_south && map->texture_east
	&& map->texture_west && map->texture_floor
	&& map->texture_sky && map->texture_sprite && map->x == 0)
		map->x = define_x(str, tmp, map);
	else if (map->x)
	{
		if (*control == 1)
			exit_failure("Error\nMap error\n", map);
		if (map->x != define_x(str, tmp, map))
			exit_failure("Error\nMap error\n", map);
	}
	else
		define_params2(str, 0, map);
	*control = 0;
}

void		define_params(int fd, char **tmp, t_map *map)
{
	char	*str;
	int		ret;
	int		control;

	str = NULL;
	control = 0;
	if (!(*tmp = malloc(sizeof(char) * 1)))
		exit_failure("Malloc error\n", map);
	**tmp = '\0';
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (!str[0])
		{
			free(str);
			str = NULL;
			control = 1;
			continue ;
		}
		loop_define_params(str, tmp, &control, map);
		free(str);
		str = NULL;
	}
	end_define_params(ret, str, tmp, map);
}
