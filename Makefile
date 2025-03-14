# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 21:51:28 by uzyberaj          #+#    #+#              #
#    Updated: 2025/03/13 18:01:18 by uzyberaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
ARCHIVE = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE_LIB = ar -rcs

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = $(wildcard bonus/*.c)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE): $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(ARCHIVE)
	$(CC) $(BONUS_OBJS) $(ARCHIVE) -o $(BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(ARCHIVE)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus