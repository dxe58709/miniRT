# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 20:39:05 by nsakanou          #+#    #+#              #
#    Updated: 2024/07/02 15:52:55 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

INCLUDES = -I ./includes -I ./srcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	srcs/vector/vector.c \
		srcs/vector/set_vec.c \
		srcs/vector/arithmetics.c \
		srcs/main.c \

OBJS = $(SRCS:%.c=%.o)

LIBDIR = ./srcs/libft
LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

clean:
	$(RM) $(OBJS) $(LIBFT)
	@$(MAKE) -C $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean

re: fclean all

__debug_configure__:
	$(eval CC := gcc)
	$(eval CFLAGS := -g -fsanitize=address -Wall -Wextra -Werror)

debug: fclean __debug_configure__ all

norminette: $(SRCS)
	norminette $^ minirt.h

norm: norminette

.PHONY: all clean fclean re debug norminette norm