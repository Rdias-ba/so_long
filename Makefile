# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:36:56 by rdias-ba          #+#    #+#              #
#    Updated: 2023/05/25 20:47:32 by rdias-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= so_long
LIB_NAME			= libft
MLX_NAME			= mlx
CC					= gcc
CFLAGS				= -Wextra -Werror -Wall
MLX_DEPENDENCIES 	= -lmlx -lX11 -lXext -lbsd -lm -lz

SRCS_DIR	= srcs/
OBJS_DIR	= objs/
LIB_DIR		= libft/
MLX_DIR		= mlx/
HEADERS_DIR	= headers/

HEADERS		= so_long.h

SRCS		= main.c error.c map_utils.c map_checking.c map_path_checking.c \
				game_control.c images_control.c move_player.c animation.c\

OBJS		= $(SRCS:%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(OBJS_DIR):
			mkdir -p $@

$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS_DIR)$(HEADERS)
			$(CC) $(CFLAGS) -I$(MLX_NAME) -I$(LIB_NAME) -O3 -g -c $< -o $@

$(NAME): $(OBJS_DIR) $(LIB_DIR)$(LIB_NAME).a $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(MLX_DEPENDENCIES) $(LIB_DIR)$(LIB_NAME).a -o $@

$(LIB_DIR)$(LIB_NAME).a:
			$(MAKE) -C $(LIB_DIR)
			$(MAKE) -C $(MLX_DIR)

clean: 
			rm -rf $(OBJS_DIR)
			$(MAKE) -C $(LIB_DIR) clean
			$(MAKE) -C $(MLX_DIR) clean

fclean: clean
			rm -rf $(NAME)
			$(MAKE) -C $(LIB_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re