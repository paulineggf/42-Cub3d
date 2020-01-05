# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 14:01:08 by pganglof          #+#    #+#              #
#    Updated: 2020/01/05 15:11:09 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_NAME = ./srcs/init_program/
PATH_INIT = ./srcs/init_map/
PATH_GAME = ./srcs/game/
PATH_SPRITE = ./srcs/sprite/
PATH_FLOOR_SKY = ./srcs/floor_sky/
PATH_BMP = ./srcs/bmp/

SRCS_NAME =	main.c					\
			exit_failure.c 			\
			easy_malloc.c

SRCS_INIT = define_x.c 				\
			ft_close.c				\
			fill_map.c 				\
			init_map.c 				\
			init_pos.c 				\
			malloc_map.c 			\
			malloc_sprite.c			\
			define_params.c 		\
			define_params2.c 		\
			define_resolution.c 	\
			fill_texture.c 			\
			init_texture.c 			\
			ft_realloc.c 			\
			malloc_texture.c 		\
			verif_map.c

SRCS_GAME =	launch_game.c 			\
			init_image.c 			\
			fill_str.c	 			\
			define_wall.c 			\
			define_color.c 			\
			define_height.c 		\
			define_diswall.c 		\
			release_key.c  			\
			move_gamer.c 			\
			rotate_left.c 			\
			rotate_right.c 			\
			move_forward_retreat.c  \
			move_left.c 			\
			move_right.c 			\
			define_sidedistx.c 		\
			define_sidedisty.c		\
			define_xy.c 			\
			draw_wall.c 			\
			define_wallx.c 			\
			press_key.c 

SRCS_SPRITE = sprite_stock.c 			\
			sprite_distance.c 		\
			sprite_height.c 		\
			sprite_draw.c			\
			sprite_xy.c 			\
			sprite_transformxy.c 	\
			sprite_invdet.c 		\
			sprite_screenx.c 		\
			sprite_drawstarty.c		\
			sprite_drawendy.c 		\
			sprite_drawstartx.c 	\
			sprite_width.c			\
			sprite_drawendx.c		\
			sprite_loop.c 			\
			sprite_combsort.c

SRCS_FLOOR_SKY = draw_floor.c		\
			floor_xwall.c 			\
			draw_sky.c

SRCS_BMP = bmp_image.c 

SRCS = $(addprefix $(PATH_NAME), $(SRCS_NAME))
SRCS2 = $(addprefix $(PATH_INIT), $(SRCS_INIT))
SRCS4 = $(addprefix $(PATH_GAME), $(SRCS_GAME))
SRCS5 = $(addprefix $(PATH_SPRITE), $(SRCS_SPRITE))
SRCS6 = $(addprefix $(PATH_FLOOR_SKY), $(SRCS_FLOOR_SKY))
SRCS7 = $(addprefix $(PATH_BMP), $(SRCS_BMP))
HEADERS = ./includes/
HEADERS2 = ./libft/includes/
OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
OBJS4 = $(SRCS4:.c=.o)
OBJS5 = $(SRCS5:.c=.o)
OBJS6 = $(SRCS6:.c=.o)
OBJS7 = $(SRCS7:.c=.o)
NAME = Cub3D
LIB = libft/libft.a
LIBFT = ./libft/srcs/*.o
MLX = minilibx_opengl_20191021/libmlx.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -I $(HEADERS) -I $(HEADERS2) -Ofast

DPDCS = $(SRCS:.c=.d) $(SRCS2:.c=.d) $(SRCS4:.c=.d) $(SRCS5:.c=.d) $(SRCS6:.c=.d) $(SRCS7:.c=.d)

all: $(NAME)

-include $(DPDCS)

$(LIBFT):
	cd ./libft/ && make && cd ..

$(NAME): $(OBJS) $(OBJS2) $(OBJS4) $(OBJS5) $(OBJS6) $(OBJS7) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS2) $(OBJS4) $(OBJS5) $(OBJS6) $(OBJS7) $(LIBFT) -I /usr/local/include/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIB) $(MLX)

clean:
	$(RM) $(OBJS) $(OBJS2) $(OBJS4) $(OBJS5) $(OBJS6) $(OBJS7) $(LIBFT) -include $(DPDCS)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
.PHONY: all clean fclean re
