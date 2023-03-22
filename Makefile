# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 15:27:07 by afenzl            #+#    #+#              #
#    Updated: 2023/03/22 12:05:43 by afenzl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra 
RM := rm -f

SRC =  pipex.c utils.c get_path.c error.c
OBJ = $(SRC:.c=.o)

BONSRC =	./bonus/main_bonus.c ./bonus/pipex_bonus.c ./bonus/utils_bonus.c	\
			./bonus/get_path_bonus.c ./bonus/error_bonus.c
BONOBJ = $(BONSRC:.c=.o)

LIBFT = ./libft/libft.a
LIBFTSRC = ./libft/ft_memset.c	\
		./libft/ft_bzero.c		\
		./libft/ft_memcpy.c		\
		./libft/ft_memmove.c	\
		./libft/ft_memchr.c		\
		./libft/ft_memcmp.c		\
		./libft/ft_strlen.c		\
		./libft/ft_isalpha.c	\
		./libft/ft_isdigit.c	\
		./libft/ft_isalnum.c	\
		./libft/ft_isascii.c	\
		./libft/ft_isprint.c	\
		./libft/ft_toupper.c	\
		./libft/ft_tolower.c	\
		./libft/ft_strchr.c		\
		./libft/ft_strrchr.c	\
		./libft/ft_strncmp.c	\
		./libft/ft_strlcpy.c	\
		./libft/ft_strlcat.c	\
		./libft/ft_strnstr.c	\
		./libft/ft_atoi.c		\
		./libft/ft_calloc.c		\
		./libft/ft_strdup.c		\
		./libft/ft_substr.c		\
		./libft/ft_strjoin.c 	\
		./libft/ft_strtrim.c	\
		./libft/ft_split.c		\
		./libft/ft_itoa.c		\
		./libft/ft_strmapi.c	\
		./libft/ft_striteri.c	\
		./libft/ft_putchar_fd.c	\
		./libft/ft_putstr_fd.c	\
		./libft/ft_putendl_fd.c	\
		./libft/ft_putnbr_fd.c	\
		./libft/ft_lstnew.c			\
		./libft/ft_lstadd_front.c	\
		./libft/ft_lstsize.c		\
		./libft/ft_lstlast.c		\
		./libft/ft_lstadd_back.c	\
		./libft/ft_lstclear.c		\
		./libft/ft_lstdelone.c		\
		./libft/ft_lstiter.c		\
		./libft/ft_lstmap.c			\
		./libft/get_next_line/get_next_line.c	\
		./libft/get_next_line/get_next_line_utils.c	\

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTSRC)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[0;32mplease run the program with ./pipex file1 cmd1 cmd2 file2 \033[0m"

bonus: $(BONOBJ) $(LIBFTSRC)
	make -C ./libft
	$(CC) $(CFLAGS) $(LIBFT) $(BONOBJ) -o $(NAME)
	@echo "\033[0;32mplease run the program with ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2 \033[0m"
	@echo "\033[0;32mor to use here_doc:         ./pipex here_doc LIMITER cmd cmd1 ... cmdn file \033[0m"

clean:
	make fclean -C ./libft/
	$(RM) $(OBJ) $(BONOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
