/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:58:30 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 16:51:44 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_texture_sky(t_map *map)
{
	t_list	*sky;

	if (!(map->text[SKY]->text = mlx_xpm_file_to_image(map->ptr.mlx,
	"./textures_hi/Earth-globe-planet-space-world-1560003-wallhere.com.XPM",
	&map->text[SKY]->x, &map->text[SKY]->y)))
		exit_failure("Wrong Texture\n", map);
	if (!(map->text[SKY]->str =
	(unsigned int*)mlx_get_data_addr(map->text[SKY]->text,
	&map->text[SKY]->b_p, &map->text[SKY]->size_l, &map->text[SKY]->endian)))
		exit_failure("Malloc failure\n", map);
	if (!(sky = ft_lstnew(map->text[SKY]->str)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), sky);
}

static void		init_texture_sprite(t_map *map)
{
	t_list	*new_sprite;

	if (!(map->text[SPRITE]->text = mlx_xpm_file_to_image(map->ptr.mlx,
	"./textures_hi/greenlight.XPM",
	&map->text[SPRITE]->x, &map->text[SPRITE]->y)))
		exit_failure("Wrong Texture\n", map);
	if (!(map->text[SPRITE]->str =
	(unsigned int*)mlx_get_data_addr(map->text[SPRITE]->text,
	&map->text[SPRITE]->b_p,
	&map->text[SPRITE]->size_l, &map->text[SPRITE]->endian)))
		exit_failure("Malloc failure\n", map);
	if (!(new_sprite = ft_lstnew(map->text[SPRITE]->str)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new_sprite);
}

static void		init_texture3(t_map *map)
{
	t_list	*new_s;

	if (!(map->text[SOUTH]->text = mlx_xpm_file_to_image(map->ptr.mlx,
	"./textures_hi/anon_vert.xpm", &map->text[SOUTH]->x, &map->text[SOUTH]->y)))
		exit_failure("Wrong Texture\n", map);
	if (!(map->text[SOUTH]->str =
	(unsigned int*)mlx_get_data_addr(map->text[SOUTH]->text,
	&map->text[SOUTH]->b_p, &map->text[SOUTH]->size_l,
	&map->text[SOUTH]->endian)))
		exit_failure("Malloc failure\n", map);
	if (!(new_s = ft_lstnew(map->text[SOUTH]->str)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new_s);
}

static void		init_texture2(t_map *map)
{
	t_list	*new_e;
	t_list	*new_w;

	if (!(map->text[EAST]->text = mlx_xpm_file_to_image(map->ptr.mlx,
	"./textures_hi/EqdAgN.xpm", &map->text[EAST]->x, &map->text[EAST]->y)))
		exit_failure("Wrong Texture\n", map);
	if (!(map->text[EAST]->str =
	(unsigned int*)mlx_get_data_addr(map->text[EAST]->text,
	&map->text[EAST]->b_p, &map->text[EAST]->size_l, &map->text[EAST]->endian)))
		exit_failure("Malloc failure\n", map);
	if (!(new_e = ft_lstnew(map->text[EAST]->str)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new_e);
	if (!(map->text[WEST]->text = mlx_xpm_file_to_image(map->ptr.mlx,
	"./textures_hi/anon.xpm", &map->text[WEST]->x, &map->text[WEST]->y)))
		exit_failure("Wrong Texture\n", map);
	if (!(map->text[WEST]->str =
	(unsigned int*)mlx_get_data_addr(map->text[WEST]->text,
	&map->text[WEST]->b_p, &map->text[WEST]->size_l, &map->text[WEST]->endian)))
		exit_failure("Malloc failure\n", map);
	if (!(new_w = ft_lstnew(map->text[WEST]->str)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new_w);
}

void			init_texture(t_map *map)
{
	t_list	*new_n;

	if (!(map->text[NORTH]->text = mlx_xpm_file_to_image(map->ptr.mlx,
	"./textures_hi/B_v-for-vend_nAkdIAig.xpm",
	&map->text[NORTH]->x, &map->text[NORTH]->y)))
		exit_failure("Wrong Texture\n", map);
	if (!(map->text[NORTH]->str =
	(unsigned int*)mlx_get_data_addr(map->text[NORTH]->text,
	&map->text[NORTH]->b_p, &map->text[NORTH]->size_l,
	&map->text[NORTH]->endian)))
		exit_failure("Malloc failure\n", map);
	if (!(new_n = ft_lstnew(map->text[NORTH]->str)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new_n);
	init_texture2(map);
	init_texture3(map);
	init_texture_sky(map);
	init_texture_sprite(map);
}
