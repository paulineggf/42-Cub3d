/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:56:49 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 17:05:18 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_map(char *av, t_map *map)
{
	int		fd;
	int		i;
	char	*str;

	if ((fd = open(av, O_RDONLY)) == -1)
		exit_failure("Open file fail\n", map);
	str = fill_buf(fd, map);
	close(fd);
	define_params(str, &i, map);
	map->x = define_x(str, i, map);
	define_y(str, i, map);
	malloc_map(map);
	if ((fd = open(av, O_RDONLY)) == -1)
		exit_failure("Open file fail\n", map);
	if (fill_map(fd, map) == -1)
		return (ft_close(fd, map));
	malloc_sprite(map);
}
