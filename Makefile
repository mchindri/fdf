# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchindri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/07 12:55:24 by mchindri          #+#    #+#              #
#    Updated: 2016/02/28 15:41:54 by mchindri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c ft_read_file.c ft_draw_map.c mlx_put_pixel_to_image.c\
	  config_map.c ft_preset_map.c
OFILES = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
MAIN = main.c
NAME = fdf 
INCLUDES = -I . -I libft/includes
TEST = 42.fdf

$(NAME):
		@gcc -c $(FLAGS) $(INCLUDES) $(SRC)
		@gcc -o $(NAME) $(OFILES) -L minilibx_macos -lmlx -framework \
			OpenGL -framework AppKit -L libft -lft
lib:
		@make -C libft/ re

mlx:
		@make -C minilibx_macos re

clean:
		@rm -f $(OFILES)
		@rm -f $(NAME)
		@rm -f a.out

fclean: clean
		@make -C libft fclean
		@make -C minilibx_macos clean

all: mlx lib $(NAME)

re: clean $(NAME)

test: re
	./$(NAME) $(TEST)

