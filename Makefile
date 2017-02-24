# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefille                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 13:53:35 by bchin             #+#    #+#              #
#    Updated: 2017/02/23 19:20:32 by jinfeld          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS=$(wildcard *.c)

OBJS=$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all

	.PHONY: clean fclean re all
