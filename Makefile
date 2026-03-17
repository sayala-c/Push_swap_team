# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 19:21:00 by oduran-m          #+#    #+#              #
#    Updated: 2026/03/17 21:27:47 by oduran-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
LIBFTNAME =	libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra 
LIBFTDIR = ./libft

SRC = push_swap.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

makelibft:
			@make -C $(LIBFTDIR)
			@cp $(LIBFTDIR)/$(LIBFTNAME) .
			@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c Makefile push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		cd $(LIBFTDIR) && make clean

fclean: clean
		rm -f $(NAME)
		cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
