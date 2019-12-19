/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:58:27 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 16:30:36 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		define_x(char *str, int i, t_map *map)
{
	int		ret;

	ret = 0;
	while (str[i] != '\n')
	{
		if (str[i] == 1 || str[i] == 0 || str[i] == 2)
		{
			ret++;
			i++;
		}
		else
			exit_failure("Map error\n", map);
		if (str[i] == ' ')
			i++;
		else
			exit_failure("Map error\n", map);
	}
	return (ret);
}
