/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:45:54 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/26 18:47:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		fill_map(int fd, t_map *map, t_pos *gamer)
{
	int		ret;
	int		i;
	int		j;
	int		k;
	char	buf[BUFFER_CUB];

	i = 0;
	j = 0;
	while ((ret = read(fd, buf, BUFFER_CUB - 1)) > 0)
	{
		k = 0;
		buf[ret] = '\0';
		while (buf[k] && i < map->y)
		{
			while (buf[k] && j < map->x)
			{
				if (buf[k] == 'N' - 48 || buf[k] == 'W' - 48
				|| buf[k] == 'E' - 48 || buf[k] == 'S' - 48)
				{
					printf("k : %d\n", k);
					gamer->posx = j;
					gamer->posy = i;
				}
				map->map[i][j++] = buf[k++] - 48;
			}
			if (!buf[k])
				break ;
			else
				k++;
			j = 0;
			i++;
		}
	}
	return (ret);
}
