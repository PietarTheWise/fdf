# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 15:50:48 by pnoutere          #+#    #+#              #
#    Updated: 2022/04/06 13:36:48 by pnoutere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror -g
CC = gcc
LIBFT_H = libft/
MAIN = main.c
FILES = draw.c initiating_funcs.c geometric_utils.c controls.c colors.c main_helpers.c

all: $(NAME)

$(NAME):
		make -C libft
		$(CC) $(FLAGS) $(MAIN) $(FILES) -o $(NAME) -I $(LIBFT_H) -I /usr/local/include -L /usr/local/lib -lmlx -L libft/ -lft -framework OpenGL -framework AppKit 

clean:
		make clean -C libft
		rm -f $(OBJECTS)

fclean:
		make fclean -C libft
		rm -f $(NAME) $(OBJECTS)

re: fclean all
