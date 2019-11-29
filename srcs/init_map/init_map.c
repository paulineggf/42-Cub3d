/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:56:49 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/29 19:10:11 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			init_map(char *av, t_map *map, t_pos *gamer)
{
	int		fd;
	int		ret;
	char	buf[33];

	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	if (!define_x(fd, buf, map, &ret))
		return (0);
	if (define_y(fd, buf, map, &ret) == -1)
		return (ft_close(fd));
	close(fd);
	if (!malloc_map(map))
		return (0);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	if (fill_map(fd, map, gamer) == -1)
		return (ft_close(fd));
	close(fd);
	map->dis_proj_plane = (float)((PROJ_PLANE_X / 2)
	/ tan((ALPHA / 2) * M_PI / 180));
	return (1);
}
