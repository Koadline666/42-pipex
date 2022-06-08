# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 10:22:00 by afenzl            #+#    #+#              #
#    Updated: 2022/05/20 14:15:11 by afenzl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC	:= cc
CFLAGS := -Wall -Werror -Wextra
RM := rm -f

### VARIABLES ###
NAME = libftprintf.a
SRC = ft_printf.c ft_types.c ft_print_sciu.c ft_print_p.c ft_print_x.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cp  ../libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) ft_printf.h.gch

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus