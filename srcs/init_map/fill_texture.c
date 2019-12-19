/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:13:26 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 18:30:29 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		fill_texture(char *str, int *i, int len_text, char **texture)
{
	int		tmp;

	tmp = *i;
	while (str[*i] == ' ')
		(*i)++;
	if (tmp == *i)
		return (0);
	ft_strncpy(*texture, str + *i, len_text);
	*i += len_text;
	return (1);
}
