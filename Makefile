# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 14:01:08 by pganglof          #+#    #+#              #
#    Updated: 2019/11/27 11:41:46 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH = ./srcs/

SRCS_NAME =	main.c				\
			define_y.c 			\
			define_x.c 			\
			init_map.c 			\
			ft_close.c			\
			malloc_map.c		\
			fill_map.c 			\
			init_pos.c


SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
HEADERS = ./includes/
HEADERS2 = ./libft/includes/
OBJS = $(SRCS:.c=.o)
NAME = Cub3D
LIB = libft/libft.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I $(HEADERS) -I $(HEADERS2)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
.PHONY: all clean fclean re
