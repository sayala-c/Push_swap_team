# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 19:21:00 by oduran-m          #+#    #+#              #
#    Updated: 2026/04/07 20:12:34 by oduran-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra 

LIBFT_DIR = ./libft
LIBFT =	$(LIBFT_DIR)/libft.a

SRC = push_swap.c parseo.c inits.c index.c rotate_operations.c push_operations.c \
		swap_operations.c parseo_tools.c push_swap_ejec.c complex_algorithm.c \
		simple_algorithm.c adaptative_algorithm.c bench.c
OBJS = $(SRC:.c=.o)

INCLUDES = -I. -I$(LIBFT_DIR) 

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
		rm -f $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
