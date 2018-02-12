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

NAME = checker.a

SRCS =	checker.c\
		mouv.c\
		init.c\
		outil.c\
		outil2.c\
		sort.c\
		quicksort.c\
		do_quicksort.c\
		light_pile.c

OBJ = $(SRCS:.c=.o)

#FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation..."
	@make -C libft/
	@ar rc $(NAME) $(OBJ) libft/libft.a libft/*.o

 %.o: %.c
	@gcc -c $< $(FLAGS) -I libft/includes

clean:
	@echo "Supretion des .o"
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "et de l'executable"
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
