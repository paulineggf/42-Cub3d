/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:58:00 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 17:21:35 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*fill_buf(int fd, t_map *map)
{
	char	*str;
	int		ret;
	char	buf[100];

	if (!(str = malloc(sizeof(char))))
		exit_failure("Malloc failure\n", map);
	while ((ret = read(fd, buf, 99)) > 0)
	{
		buf[ret] = '\0';
		if (!(str = ft_realloc(str, buf,
		ft_strlen(str) + (sizeof(char) * (ret + 1)))))
			exit_failure("Malloc failure\n", map);
	}
	if (ret == -1)
		exit_failure("Read error\n", map);
	return (str);
}
