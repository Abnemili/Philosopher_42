# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 14:51:41 by abnemili          #+#    #+#              #
#    Updated: 2025/04/20 15:03:37 by abnemili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -rf

SRC = main.c functions.c check_input.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
