/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:07:39 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 17:18:13 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_resolution(char *str, int i, t_map *map)
{
	while (str[i] == ' ')
		i++;
	map->res_x = ft_atoi(str + i);
	if (map->res_x > 2560)
		exit_failure("Error\nWrong resolution\n", map);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	map->res_y = ft_atoi(str + i);
	if (map->res_y > 1440)
		exit_failure("Error\nWrong resolution", map);
}
