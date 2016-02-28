# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchindri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/25 09:45:00 by mchindri          #+#    #+#              #
#    Updated: 2016/02/28 15:42:22 by mchindri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# :r! ls libft_src/*.c

LIBFT_SRC = ./libft_src/ft_putstr.c \
			./libft_src/ft_strnew.c\
			./libft_src/ft_isprint.c\
			./libft_src/ft_tolower.c\
			./libft_src/ft_memdel.c\
			./libft_src/ft_strnequ.c\
			./libft_src/ft_striter.c\
			./libft_src/ft_memmove.c\
			./libft_src/ft_putchar.c\
			./libft_src/ft_strmap.c\
			./libft_src/ft_isdigit.c\
			./libft_src/ft_memccpy.c\
			./libft_src/ft_strdel.c\
			./libft_src/ft_lstnew.c\
			./libft_src/ft_strstr.c\
			./libft_src/ft_strtrim.c\
			./libft_src/ft_memcpy.c\
			./libft_src/ft_strnstr.c\
			./libft_src/ft_lstdel.c\
			./libft_src/ft_strsplit.c\
			./libft_src/ft_isalnum.c\
			./libft_src/ft_isalpha.c\
			./libft_src/ft_putchar_fd.c\
			./libft_src/ft_strclr.c\
			./libft_src/ft_strcmp.c\
			./libft_src/ft_strncmp.c\
			./libft_src/ft_strdup.c\
			./libft_src/ft_strrev.c\
			./libft_src/ft_striteri.c\
			./libft_src/ft_strmapi.c\
			./libft_src/ft_itoa.c\
			./libft_src/ft_strcpy.c\
			./libft_src/ft_toupper.c\
			./libft_src/ft_putendl_fd.c\
			./libft_src/ft_memcmp.c\
			./libft_src/ft_powi.c\
			./libft_src/ft_lstiter.c\
			./libft_src/ft_strncpy.c\
			./libft_src/ft_putnbr_fd.c\
			./libft_src/ft_strlen.c\
			./libft_src/ft_strncat.c\
			./libft_src/ft_strjoin.c\
			./libft_src/ft_memchr.c\
			./libft_src/ft_strsub.c\
			./libft_src/ft_memset.c\
			./libft_src/ft_absd.c\
			./libft_src/ft_isascii.c\
			./libft_src/ft_putstr_fd.c\
			./libft_src/ft_strchr.c\
			./libft_src/ft_bzero.c\
			./libft_src/ft_sqrt.c\
			./libft_src/ft_strequ.c\
			./libft_src/ft_lstmap.c\
			./libft_src/ft_lstdelone.c\
			./libft_src/ft_strcat.c\
			./libft_src/ft_putnbr.c\
			./libft_src/ft_absi.c\
			./libft_src/ft_strrchr.c\
			./libft_src/ft_putendl.c\
			./libft_src/ft_memalloc.c\
			./libft_src/ft_swap.c\
			./libft_src/ft_lstadd.c\
			./libft_src/ft_atoi.c\
			./libft_src/ft_strlcat.c\
			./libft_src/ft_putwchar.c\
			./libft_src/ft_putwstr.c\
			./libft_src/ft_wchar_len.c\
			./libft_src/ft_strwlen.c\
			./libft_src/ft_strwdup.c\
			./libft_src/ft_itoa_base.c\
			./libft_src/get_next_line.c

# :r! find ./printf_src -name \*.c -print

PRINTF_SRC = ./printf_src/ft_printf.c \
			 ./printf_src/ft_find_convertor.c\
			 ./printf_src/ft_is_positional_arg.c\
			 ./printf_src/ft_set_format.c\
			 ./printf_src/ft_print_arg.c\
			 ./printf_src/print_functions/ft_print_number.c\
			 ./printf_src/print_functions/ft_print_fractional.c\
			 ./printf_src/print_functions/ft_print_char.c\
			 ./printf_src/print_functions/ft_format_number.c\
			 ./printf_src/print_functions/ft_print_string.c\
			 ./printf_src/print_functions/ft_print_wstring.c\
			 ./printf_src/ft_select_arg.c\
			 ./printf_src/ft_uitoa_base.c\
			 ./printf_src/ft_set_functions.c

# make ofiles
# :r! cat | ls -C *.o

OFILES =	ft_memmove.o		ft_strdup.o \
		  ft_absd.o		ft_memset.o		ft_strequ.o\
		  ft_absi.o		ft_powi.o		ft_striter.o\
		  ft_atoi.o		ft_print_arg.o		ft_striteri.o\
		  ft_bzero.o		ft_print_char.o		ft_strjoin.o\
		  ft_find_convertor.o	ft_print_fractional.o	ft_strlcat.o\
		  ft_is_positional_arg.o	ft_print_number.o	ft_strlen.o\
		  ft_isalnum.o		ft_print_string.o	ft_strmap.o\
		  ft_isalpha.o		ft_printf.o		ft_strmapi.o\
		  ft_isascii.o		ft_putchar.o		ft_strncat.o\
		  ft_isdigit.o		ft_putchar_fd.o		ft_strncmp.o\
		  ft_isprint.o		ft_putendl.o		ft_strncpy.o\
		  ft_itoa.o		ft_putendl_fd.o		ft_strnequ.o\
		  ft_uitoa_base.o		ft_putnbr.o		ft_strnew.o\
		  ft_lstadd.o		ft_putnbr_fd.o		ft_strnstr.o\
		  ft_lstdel.o		ft_putstr.o		ft_strrchr.o\
		  ft_lstdelone.o		ft_putstr_fd.o		ft_strrev.o\
		  ft_lstiter.o		ft_select_arg.o		ft_strsplit.o\
		  ft_lstmap.o		ft_set_format.o		ft_strstr.o\
		  ft_lstnew.o		ft_sqrt.o		ft_strsub.o\
		  ft_memalloc.o		ft_strcat.o		ft_strtrim.o\
		  ft_memccpy.o		ft_strchr.o		ft_swap.o\
		  ft_memchr.o		ft_strclr.o		ft_tolower.o\
		  ft_memcmp.o		ft_strcmp.o		ft_toupper.o\
		  ft_memcpy.o		ft_strcpy.o		ft_putwchar.o\
		  ft_memdel.o		ft_strdel.o		ft_format_number.o\
		  ft_putwstr.o		ft_print_wstring.o	ft_wchar_len.o\
		  ft_strwlen.o		ft_strwdup.o	ft_set_functions.o\
		  ft_itoa_base.o	get_next_line.o


FLAGS = -Wall -Wextra -Werror
MAIN = main.c
NAME = libft.a
INCLUDES = -I includes

all: $(NAME)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(INCLUDES) $(PRINTF_SRC) $(LIBFT_SRC)

ofiles: $(NAME)

clean: 
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

test: re
	@gcc $(INCLUDES) -L . -lft $(MAIN)
	./a.out

test_e: re
	@gcc $(INCLUDES) -L . -lft $(MAIN)
	./a.out | cat -e
