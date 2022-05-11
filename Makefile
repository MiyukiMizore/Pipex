# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 17:17:09 by mfusil            #+#    #+#              #
#    Updated: 2022/05/11 15:42:12 by mfusil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra

PIPEX = pipex.c\
		pipex_process.c\
		pipex_error.c
	  
SRC = src/ft_split.c\
	  src/ft_strjoin.c\
	  src/ft_strlen.c

ALL_SRC = $(PIPEX)\
		  $(SRC)

OBJS = $(ALL_SRC:.c=.o)

all : $(NAME)

alln : all
		norminette

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all