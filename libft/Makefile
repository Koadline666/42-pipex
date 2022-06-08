# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:28:49 by afenzl            #+#    #+#              #
#    Updated: 2022/05/22 14:39:45 by afenzl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC	:= cc
CFLAGS := -Wall -Werror -Wextra
RM := rm -f

### VARIABLES ###
NAME = libft.a
SRC = ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_isalpha.c 	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c 	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		./get_next_line/get_next_line.c	\
		./get_next_line/get_next_line_utils.c	\

OBJ = $(SRC:.c=.o)
BON = ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c			
BONOBJ = $(BON:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^
	make -C ./ft_printf
	ar rcs $(NAME) ./ft_printf/libftprintf.a

clean:
	make fclean -C ./ft_printf
	$(RM) $(OBJ) $(BONOBJ)

fclean: clean
	make fclean -C ./ft_printf
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ) $(BONOBJ)
	ar rcs $(NAME) $(OBJ) $(BONOBJ)

.PHONY: all clean fclean re bonus