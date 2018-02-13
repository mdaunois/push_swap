# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:12:41 by clecalie          #+#    #+#              #
#    Updated: 2018/02/12 13:16:59 by mdaunois         ###   ########.fr        #
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
			light_pile.c

OBJ_CHECKER = $(SRCS_CHECKER:.c=.o)

OBJ_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

#FLAGS = -Wall -Werror -Wextra 

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_CHECKER)
	@echo "Compilation..."
	@make -C libft/
	@gcc $(OBJ_CHECKER)  libft/*.o -o $(NAME_1)

$(NAME_2): $(OBJ_PUSH_SWAP)
	@gcc $(OBJ_PUSH_SWAP)  libft/*.o -o $(NAME_2)

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
