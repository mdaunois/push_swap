# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:12:41 by clecalie          #+#    #+#              #
#    Updated: 2018/02/14 16:35:41 by mdaunois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = checker

NAME_2 = push_swap

SRCS_CHECKER =		checker.c\
			mouv.c\
			init.c\
			outil.c\

SRCS_PUSH_SWAP =	push_swap.c\
			mouv.c\
			init.c\
			outil.c\
			outil2.c\
			sort.c\
			quicksort.c\
			do_quicksort.c\
			light_pile.c\
			do_mouv.c

OBJ_CHECKER = $(SRCS_CHECKER:.c=.o)

OBJ_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

OBJ_LIBFT = libft/get_next_line.o\
		   	libft/ft_strndup.o\
		   	libft/ft_atoi.o\
		   	libft/ft_bzero.o\
		   	libft/ft_isalnum.o\
			libft/ft_isalpha.o\
		   	libft/ft_isascii.o\
		   	libft/ft_isdigit.o\
		   	libft/ft_isprint.o\
		   	libft/ft_itoa.o\
		   	libft/ft_lstadd.o\
		   	libft/ft_lstdel.o\
		   	libft/ft_lstdelone.o\
		   	libft/ft_lstiter.o\
		   	libft/ft_lstmap.o\
		   	libft/ft_lstnew.o\
		   	libft/ft_memalloc.o\
		   	libft/ft_memccpy.o\
		   	libft/ft_memchr.o\
		   	libft/ft_memcmp.o\
			libft/ft_memcpy.o\
		   	libft/ft_memdel.o\
		   	libft/ft_memmove.o\
		   	libft/ft_memset.o\
		   	libft/ft_putchar.o\
		   	libft/ft_putchar_fd.o\
		   	libft/ft_putendl.o\
		   	libft/ft_putendl_fd.o\
		   	libft/ft_putnbr.o\
		   	libft/ft_putnbr_fd.o\
		   	libft/ft_putstr.o\
		   	libft/ft_putstr_fd.o\
		   	libft/ft_strcat.o\
		   	libft/ft_strchr.o\
		   	libft/ft_strclr.o\
		   	libft/ft_strcmp.o\
		   	libft/ft_strcpy.o\
		   	libft/ft_strdel.o\
			libft/ft_strdup.o\
		   	libft/ft_strequ.o\
		   	libft/ft_striter.o\
		   	libft/ft_striteri.o\
		   	libft/ft_strjoin.o\
			libft/ft_strlcat.o\
		   	libft/ft_strlen.o\
		   	libft/ft_strmap.o\
		   	libft/ft_strmapi.o\
		   	libft/ft_strncat.o\
		   	libft/ft_strncmp.o\
		   	libft/ft_strncpy.o\
		   	libft/ft_strnequ.o\
		   	libft/ft_strnew.o\
		   	libft/ft_strnstr.o\
		   	libft/ft_strrchr.o\
		   	libft/ft_strrev.o\
		   	libft/ft_strsplit.o\
		   	libft/ft_strstr.o\
		   	libft/ft_strsub.o\
		   	libft/ft_strtrim.o\
		   	libft/ft_tolower.o\
		   	libft/ft_toupper.o

FLAGS = -Wall -Werror -Wextra 

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_CHECKER)
	@echo "Compilation..."
	@make -C libft/
	@gcc $(OBJ_CHECKER)  $(OBJ_LIBFT) -o $(NAME_1)

$(NAME_2): $(OBJ_PUSH_SWAP)
	@gcc $(OBJ_PUSH_SWAP)  $(OBJ_LIBFT) -o $(NAME_2)

 %.o: %.c
	@gcc -c $< $(FLAGS) -I libft/includes

clean:
	@echo "Supretion des .o"
	@make -C libft/ clean
	@rm -f $(OBJ_PUSH_SWAP) $(OBJ_CHECKER)


fclean: clean
	@echo "et de l'executable"
	@make -C libft/ fclean
	@rm -f $(NAME_1) $(NAME_2)

re: fclean all

.PHONY: all clean fclean re
