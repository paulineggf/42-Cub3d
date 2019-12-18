# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 14:01:08 by pganglof          #+#    #+#              #
#    Updated: 2019/12/18 12:16:27 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_NAME = ./srcs/
PATH_INIT = ./srcs/init_map/
PATH_WALL = ./srcs/isitwall/
PATH_GAME = ./srcs/game/
PATH_SPRITE = ./srcs/sprite/

SRCS_NAME =	main.c					\
			exit_failure.c 			\
			easy_malloc.c 

SRCS_INIT = define_x.c 				\
			define_y.c 				\
			fill_map.c 				\
			ft_close.c				\
			init_map.c 				\
			init_pos.c 				\
			malloc_map.c

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
			draw_sky_ground.c 		\
			define_wallx.c 			\
			init_texture.c 			\
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
			sprite_loop.c
			

SRCS = $(addprefix $(PATH_NAME), $(SRCS_NAME))
SRCS2 = $(addprefix $(PATH_INIT), $(SRCS_INIT))
SRCS3 = $(addprefix $(PATH_WALL), $(SRCS_WALL))
SRCS4 = $(addprefix $(PATH_GAME), $(SRCS_GAME))
SRCS5 = $(addprefix $(PATH_SPRITE), $(SRCS_SPRITE))
HEADERS = ./includes/
HEADERS2 = ./libft/includes/
OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
OBJS3 = $(SRCS3:.c=.o)
OBJS4 = $(SRCS4:.c=.o)
OBJS5 = $(SRCS5:.c=.o)
NAME = Cub3D
LIB = libft/libft.a
MLX = minilibx_opengl_20191021/libmlx.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -fsanitize=address -I $(HEADERS) -I $(HEADERS2) -Ofast

DPDCS = $(SRCS:.c=.d) $(SRCS2:.c=.d) $(SRCS3:.c=.d) $(SRCS4:.c=.d) $(SRCS5:.c=.d) 

all: $(NAME)

-include $(DPDCS)

$(NAME): $(OBJS) $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS5)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS5) -I /usr/local/include/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIB) $(MLX)

clean:
	$(RM) $(OBJS) $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS5) -include $(DPDCS)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
.PHONY: all clean fclean re
