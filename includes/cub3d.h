/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:27:29 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/03 15:30:34 by pganglof         ###   ########.fr       */
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

# define BUFFER_CUB		33

enum
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	SPRITE,
	SKY,
	FLOOR,
	LAST,
};

union				bmp
{
	int		size;
	char	size_char[4];
};

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
	int				run;
	int				retreat;
	int				retreat_fast;
	int				jump;
	int				tmp_jump;
	int				tmp2_jump;
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
	double			floorxwall;
	double			floorywall;
}					t_pos;

typedef	struct		s_sprite
{
	int				mapx;
	int				mapy;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				screenx;
	int				drawstarty;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
	int				width;
	double			distance;
	int				height;
	int				real_drawstart;
}					t_sprite;

typedef struct		s_win
{
	int				x;
	int				y;
	int				i;
	int				color;
	void			*mlx;
	void			*win;
	void			*img;
	void			*text;
	int				b_p;
	int				size_l;
	int				endian;
	unsigned int	*str;
}					t_win;

typedef struct		s_floor
{
	double			currentdist;
	double			weight;
	double			currentfloorx;
	double			currentfloory;
	double			distwall;
	double			displayer;
	int				floortextx;
	int				floortexty;
}					t_floor;

typedef struct		s_map
{
	int				x;
	int				y;
	int				res_x;
	int				res_y;
	int				stripe;
	int				i;
	int				**map;
	int				size_sprite;
	double			*zbuffer;
	char			*texture_north;
	char			*texture_south;
	char			*texture_east;
	char			*texture_west;
	char			*texture_sprite;
	char			*texture_sky;
	char			*texture_floor;
	t_win			ptr;
	t_pos			gamer;
	t_floor			floor;
	t_win			**text;
	t_list			*garbage_collector;
	t_sprite		**sprite;
}					t_map;

void				malloc_map(t_map *map);
void				init_map(char *av, t_map *map);
void				define_y(char *str, int i, t_map *map);
int					define_x(char *str, char **tmp, t_map *map);
void				ft_close(int fd, t_map *map);
void				fill_map(char *tmp, int i, t_map *map);
void				init_pos(t_map *map, int orientation, int x, int y);
int					launch_game(t_map *map);
int					press_key(int key, t_map *map);
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
void				draw_wall(t_map *map);
void				draw_sky(t_map *map);
void				define_wallx(t_map *map);
void				init_texture(t_map *map);
void				exit_failure(char *str, t_map *map);
void				easy_malloc(void **content, size_t n, t_map *map);
int					init_image(t_map *map);
void				sprite_stock(t_map *map);
void				sprite_distance(t_map *map);
void				sprite_height(t_map *map);
void				sprite_draw(t_map *map);
void				sprite_xy(t_map *map);
void				sprite_invdet(t_map *map);
void				sprite_transformxy(t_map *map);
void				sprite_screenx(t_map *map);
void				sprite_drawstarty(t_map *map);
void				sprite_drawendy(t_map *map);
void				sprite_drawstartx(t_map *map);
void				sprite_width(t_map *map);
void				sprite_drawendx(t_map *map);
void				sprite_loop(t_map *map);
void				malloc_texture(t_map *map);
void				sprite_combsort(t_map *map);
void				draw_floor(t_map *map);
void				floor_xywall(t_map *map);
void				malloc_sprite(t_map *map);
void				define_params(int fd, char **tmp, t_map *map);
void				define_params2(char *str, int i, t_map *map);
void				define_resolution(char *str, int i, t_map *map);
void				fill_texture(char *str, int i, char **texture, t_map *map);
char				*ft_realloc(char *str, char *buf, int n);
void				verif_map(t_map *map);
void				bmp_image(t_map *map);

#endif
