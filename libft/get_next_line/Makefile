# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 14:37:39 by afenzl            #+#    #+#              #
#    Updated: 2022/05/22 13:40:12 by afenzl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC	:= cc
CFLAGS := -Wall -Werror -Wextra
RM := rm -f

### VARIABLES ###
NAME = gnl.a
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
BON = get_next_line_bonus.c get_next_line_utils_bonus.C
BONOBJ = $(BON:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: all $(BONOBJ)
	ar rcs $(NAME) $(OBJ) $(BONOBJ)

clean:
	$(RM) $(OBJ) $(BONOBJ)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus