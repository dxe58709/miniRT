# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 20:39:05 by nsakanou          #+#    #+#              #
#    Updated: 2024/07/19 16:16:00 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

MLXDIR = minilibx_mms_20200219
MLX = $(MLXDIR)/libmlx.dylib

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

INCLUDES = -I ./includes -I ./srcs -I $(MLXDIR) 
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	srcs/utils/get_next_line.c \
		srcs/utils/error.c \
		srcs/utils/free.c \
		srcs/main.c \
		srcs/scene/init/init_scene.c \
		srcs/scene/init/init_scene_utils.c \
		srcs/scene/init/init_shape.c \
		srcs/scene/camera.c \
		srcs/vector/vector.c \
		srcs/vector/set_vec.c \
		srcs/vector/arithmetics.c \
		srcs/mlx/close_window.c \
		srcs/mlx/pixel_put.c \
		srcs/mlx/init_mlx.c \
		srcs/mlx/set_hook.c \
		srcs/mlx/image_put.c \
		srcs/color/set_color.c \
		srcs/color/color.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBDIR) clean
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean
	@$(MAKE) -C $(MLXDIR) fclean

fe: fclean all

__debug_configure__:
	$(eval CC := gcc)
	$(eval CFLAGS := -g -fsanitize=address -Wall -Wextra -Werror)

debug: fclean __debug_configure__ all

norminette: $(SRCS)
	norminette $^ minirt.h

norm: norminette

.PHONY: all clean fclean re debug norminette norm