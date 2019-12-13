/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:27:29 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 22:06:49 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

# define ALPHA			60
# define BLOCK_SIZE 	64
# define BUFFER_CUB		33
# define RES_X			1920
# define RES_Y			1080

typedef struct		s_pos
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	int				stepx;
	int				stepy;
	double			perpwalldist;
	double			lineheight;
	int				drawstart;
	int				real_drawstart;
	int				drawend;
	double			beta;
	int				forward;
	int				retreat;
	int				left;
	int				right;
	int				rotate_right;
	int				rotate_left;
	int				mapx;
	int				mapy;
	double			deltadistx;
	double			deltadisty;
	int				side;
	double			wallx;
}					t_pos;

typedef	struct		s_sprite
{
	int				mapx;
	int				mapy;
	double			posx;
	double			posy;
	double			spritex;
	double			spritey;
	double			indvet;
	double			transformx;
	double			transformy;
	int				screenx;
	int				drawstarty;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
	int				width;
	double			f_raydirx;
	double			f_raydiry;
	double			l_raydirx;
	double			l_raydiry;
	double			distance;
	double			height;
	double			x;
	int				real_drawstart;
	int				drawstart;
	int				drawend;
}					t_sprite;

typedef struct		s_win
{
	int				x;
	int				sky_x;
	int				sky_y;
	int				sprite_x;
	int				sprite_y;
	int				y;
	int				i;
	int				color;
	void			*mlx;
	void			*win;
	void			*img;
	void			*n_text;
	void			*s_text;
	void			*e_text;
	void			*w_text;
	void			*sky_text;
	void			*sprite_text;
	int				b_p;
	int				b_p_sky;
	int				b_p_sprite;
	int				size_l;
	int				size_l_sky;
	int				size_l_sprite;
	int				endian;
	int				endian_sky;
	int				endian_sprite;
	unsigned int	*str;
	unsigned int	*sky;
	unsigned int	*str_n;
	unsigned int	*str_s;
	unsigned int	*str_e;
	unsigned int	*str_w;
	unsigned int	*str_sprite;
}					t_win;

typedef struct		s_map
{
	int				x;
	int				y;
	int				i;
	int				**map;
	int				size_sprite;
	t_win			ptr;
	t_pos			gamer;
	t_win			text;
	t_list			*garbage_collector;
	t_sprite		**sprite;
}					t_map;

void				malloc_map(t_map *map);
void				init_map(char *av, t_map *map);
int					define_y(int fd, char *buf, t_map *map, int *ret);
void				define_x(int fd, char *buf, t_map *map, int *ret);
void				ft_close(int fd, t_map *map);
int					fill_map(int fd, t_map *map);
void				init_pos(t_map *map, int orientation, int x, int y);
int					launch_game(t_map *map);
int					press_key(int key, void *param);
int					main(int argc, char **argv);
void				define_color(t_map *map);
void				define_height(t_map *map);
void				define_diswall(t_map *map);
int					release_key(int key, void *param);
int					move_gamer(t_map *map);
void				define_wall(t_map *map);
void				define_sidedistx(t_map *map);
void				define_sidedisty(t_map *map);
void				define_xy(t_map *map);
int					move_forward_retreat(t_map *map);
int					move_left(t_map *map);
int					move_right(t_map *map);
void				rotate_right(t_map *map);
void				rotate_left(t_map *map);
void				fill_str(t_map *map);
void				draw_wall(t_map *map, int *x);
void				draw_sky_ground(t_map *map, int *x);
void				define_wallx(t_map *map);
void				init_texture(t_map *map);
void				exit_failure(char *str, t_map *map);
void				easy_malloc(void **content, size_t n, t_map *map);
int					init_image(t_map *map);
void				stock_sprite(t_map *map);
void				distance_sprite(t_map *map);
void				sprite_height(t_map *map);
void				sprite_x(t_map *map);
void				draw_sprite(t_map *map);

#endif