/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:58:27 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 19:56:56 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		define_x2(char *str, int *i, int *ret)
{
	if (str[*i] == '1' || str[*i] == '0' || str[*i] == '2'
	|| str[*i] == 'N' || str[*i] == 'S' || str[*i] == 'E' || str[*i] == 'W')
	{
		(*ret)++;
		(*i)++;
	}
	else
		return (0);
	return (1);
}

static void		exit_failure_static(char *str, char **tmp, t_map *map)
{
	free(str);
	free(*tmp);
	exit_failure("Error\nMap error\n", map);
}

int				define_x(char *str, char **tmp, t_map *map)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	if (str[0] != '1')
		exit_failure("Error\nMap error\n", map);
	while (str[i])
	{
		if (!(define_x2(str, &i, &ret)))
			exit_failure_static(str, tmp, map);
		if (str[i] == ' ')
			i++;
		else if (!str[i] && str[i - 1] == '1')
		{
			*tmp = ft_realloc(*tmp, str, ft_strlen(*tmp) + i + 2);
			map->y += 1;
			return (ret);
		}
		else
			exit_failure_static(str, tmp, map);
	}
	return (ret);
}
