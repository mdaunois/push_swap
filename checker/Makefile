# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:12:41 by clecalie          #+#    #+#              #
#    Updated: 2018/01/25 16:11:00 by mdaunois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker.a

SRCS =	test.c

OBJ = $(SRCS:.c=.o)

#FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar rc $(NAME) $(OBJ) libft/libft.a libft/*.o

 %.o: %.c
	gcc -c $< $(FLAGS) -I libft/includes

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
