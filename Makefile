# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 14:01:08 by pganglof          #+#    #+#              #
#    Updated: 2019/11/29 17:05:22 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_NAME = ./srcs/
PATH_INIT = ./srcs/init_map/
PATH_WALL = ./srcs/isitwall/
PATH_GAME = ./srcs/game/

SRCS_NAME =	main.c

SRCS_INIT = define_x.c 				\
			define_y.c 				\
			fill_map.c 				\
			ft_close.c				\
			init_map.c 				\
			init_pos.c 				\
			malloc_map.c

SRCS_WALL = dis_wall.c 				\
			free_wall.c				\
			isitwall.c 				\
			fill_wall_hor.c 		\
			fill_wall_ver.c 		\
			ft_closer.c

SRCS_GAME =	draw_wall.c 			\
			launch_game.c

SRCS = $(addprefix $(PATH_NAME), $(SRCS_NAME))
SRCS2 = $(addprefix $(PATH_INIT), $(SRCS_INIT))
SRCS3 = $(addprefix $(PATH_WALL), $(SRCS_WALL))
SRCS4 = $(addprefix $(PATH_GAME), $(SRCS_GAME))
HEADERS = ./includes/
HEADERS2 = ./libft/includes/
OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
OBJS3 = $(SRCS3:.c=.o)
OBJS4 = $(SRCS4:.c=.o)
NAME = Cub3D
LIB = libft/libft.a
MLX = minilibx_opengl_20191021/libmlx.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -I $(HEADERS) -I $(HEADERS2) 

all: $(NAME)

$(NAME): $(OBJS) $(OBJS2) $(OBJS3) $(OBJS4)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS2) $(OBJS3) $(OBJS4) -I /usr/local/include/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIB) $(MLX)

clean:
	$(RM) $(OBJS) $(OBJS2) $(OBJS3) $(OBJS4)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
.PHONY: all clean fclean re
