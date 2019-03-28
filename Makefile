#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 17:34:53 by oshyiata          #+#    #+#              #
#    Updated: 2019/02/28 17:34:54 by oshyiata         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CFLAGS		= # -Wall -Wextra -Werror
NAME		= fdf
SRC_NAME 	= main.c tools.c data_work.c ft_my_atoi.c display.c set_key.c sin_cos.c parse_str.c brazenkhem.c put_text.c set_key2.c
LIBFT_DIR	= ./libft/
LIBFT		= ./libft/libft.a
SRC			=$(addprefix ./srcs/, $(SRC_NAME))
OBJ			= $(SRC:%.c=%.o)

.PHONY: norm all re clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(CFLAGS) $(OBJ) -I ./includes -I /usr/local/include -I -r $(LIBFT) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME) -lm 

%.o:%.c $(LIBFT) ./includes/fdf.h
	gcc $(CFLAGS) -c $< -o $@ -I ./includes

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all