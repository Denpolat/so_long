# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/29 00:28:00 by denpolat          #+#    #+#              #
#    Updated: 2026/07/02 00:34:15 by denpolat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name	= so_long

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

INCLUDES	:= -I include -I libft -I src/gnl -I mlx

SRCS		:=	src/main.c \
                src/parsing/parse_map.c \
                src/parsing/valid_map.c \
                src/parsing/valid_map2.c \
                src/utils.c \
                src/game/init.c \
                src/gnl/get_next_line.c \
                src/gnl/get_next_line_utils.c

OBJS		:= $(patsubst src/%.c, obj/%.o, $(SRCS))

LIBFT		:= libft/libft.a
MLX			:= mlx/libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -L libft -lft -L mlx -lmlx -lX11 -lXext -o $(NAME)

obj/%.o: src/%.c
    @mkdir -p $(dir $@)
    $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
    make -C libft

$(MLX):
    make -C mlx

clean:
    make -C libft clean
    make -C mlx clean
    rm -rf obj

fclean: clean
    make -C libft fclean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
