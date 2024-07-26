# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 20:39:05 by nsakanou          #+#    #+#              #
#    Updated: 2024/07/26 16:48:50 by nsakanou         ###   ########.fr        #
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

SRCS =	srcs/color/set_color.c \
		srcs/color/color.c \
		srcs/main.c \
		srcs/mlx/close_window.c \
		srcs/mlx/draw.c \
		srcs/mlx/init_mlx.c \
		srcs/mlx/pixel_put.c \
		srcs/mlx/set_hook.c \
		srcs/scene/ambient.c \
		srcs/scene/camera.c \
		srcs/scene/init/init_cylinder.c \
		srcs/scene/init/init_plane.c \
		srcs/scene/init/init_scene.c \
		srcs/scene/init/init_scene_utils.c \
		srcs/scene/init/init_sphere.c \
		srcs/scene/intersection/inter_cylinder.c \
		srcs/scene/intersection/inter_plane.c \
		srcs/scene/intersection/inter_sphere.c \
		srcs/scene/intersection/intersect.c \
		srcs/scene/light.c \
		srcs/scene/object.c \
		srcs/scene/raytrace.c \
		srcs/scene/ref.c \
		srcs/scene/vec.c \
		srcs/utils/error.c \
		srcs/utils/free.c \
		srcs/utils/get_next_line.c \
		srcs/utils/rt_atof.c \
		srcs/utils/rt_sprit.c \
		srcs/utils/split_count.c \
		srcs/vector/basis.c \
		srcs/vector/vec_arithmetics.c \
		srcs/vector/vector.c \

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