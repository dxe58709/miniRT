# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 20:39:05 by nsakanou          #+#    #+#              #
#    Updated: 2024/09/19 20:52:56 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

MLXDIR = ./minilibx_opengl_20191021
MLX = $(MLXDIR)/libmlx.a

INCLUDES = -I./includes -I ./srcs -I $(LIBDIR) -I $(MLXDIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -f

SRCS = srcs/color/cal_color.c \
       srcs/color/color.c \
       srcs/utils/rt_atof.c \
       srcs/utils/get_next_line.c \
       srcs/utils/rt_sprit.c \
       srcs/utils/error.c \
       srcs/utils/split_count.c \
       srcs/utils/scene_utils.c \
       srcs/main.c \
       srcs/scene/object.c \
       srcs/scene/scene.c \
       srcs/scene/light.c \
       srcs/scene/vec.c \
       srcs/scene/ambient.c \
       srcs/scene/intersection.c \
       srcs/scene/cylinder.c \
       srcs/scene/sphere.c \
       srcs/scene/camera.c \
       srcs/scene/plane.c \
       srcs/vector/vector.c \
       srcs/vector/cal_vec.c \
       srcs/vector/basis.c \
       srcs/mlx/close_window.c \
       srcs/mlx/draw.c \
       srcs/mlx/hook.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) -framework OpenGL -framework AppKit

$(LIBFT):
	$(MAKE) -C $(LIBDIR)
$(MLX):
	$(MAKE) -C $(MLXDIR)

clean:
	$(RM) $(OBJS) $(MLX) $(LIBFT)
	@$(MAKE) -C $(LIBDIR) clean
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

# __debug_configure__:
# 	$(eval CC := gcc)
# 	$(eval CFLAGS := -g -fsanitize=address -Wall -Wextra -Werror)

debug: fclean __debug_configure__ all

norminette: $(SRCS)
	norminette $^ minirt.h

norm: norminette

.PHONY: all clean fclean re debug norminette norm