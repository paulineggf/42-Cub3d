/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:07:39 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 15:13:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_resolution(char *buf, int *i, t_map *map)
{
	(*i)++;
	while (buf[*i] == ' ')
		(*i)++;
	map->res_x = ft_atoi(buf + *i);
	if (map->res_x > 2560)
		exit_failure("Map error\n", map);
	while (ft_isdigit(buf[*i]) || buf[*i] == ' ')
		(*i)++;
	map->res_y = ft_atoi(buf + *i);
	if (map->res_y > 1440)
		exit_failure("Map error\n", map);
	while (ft_isdigit(buf[*i]) || buf[*i] == ' ' || buf[*i] == '\n')
		(*i)++;
}
