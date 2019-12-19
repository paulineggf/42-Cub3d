/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:57:35 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 17:03:35 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		define_y(char *str, int i, t_map *map)
{
	int		ret;

	map->y = 1;
	while (str[i])
	{
		i += map->x;
		if (str[i] == '1' || str[i] == '2' || str[i] == '0')
			ret = define_x(str, i, map);
		else
			break ;
		if (ret != map->x)
			exit_failure("Map error\n", map);
		else
			map->y++;
	}
	while ((str[i] == ' ' || str[i] == '\n') && str[i])
		i++;
	if (str[i] != '\0')
		exit_failure("Map error\n", map);
}
