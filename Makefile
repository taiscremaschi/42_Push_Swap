# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 11:40:38 by tbolzan-          #+#    #+#              #
#    Updated: 2023/08/29 21:21:13 by tbolzan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .SILENT:

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address 
RM = rm -f

AR = ar -rsc

SRC = double_moves.c ft_utils.c main.c make_3_5.c make_all.c mov.c utils.c utils_make_all.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(CFLAGS) -L. -o $(NAME)

%.o: %.c
	cc -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re