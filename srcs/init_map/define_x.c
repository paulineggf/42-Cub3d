/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:58:27 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/12 16:37:45 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_x(int fd, char *buf, t_map *map, int *ret)
{
	map->x = 0;
	while ((*ret = read(fd, buf, 32)) > 0)
	{
		buf[*ret] = '\0';
		while (buf[map->x] && buf[map->x] != '\n')
			map->x++;
		if (map->x != *ret)
			break ;
	}
	if (*ret == -1)
		ft_close(fd, map);
}
