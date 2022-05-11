# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 17:17:09 by mfusil            #+#    #+#              #
#    Updated: 2022/05/11 16:27:41 by mfusil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

RM = rm -f

CC = gcc

CFLAGS = -Wall -Werror -Wextra

PIPEX = pipex.c\
		pipex_process.c\
		pipex_error.c
	  
UTILS = utils/ft_split.c\
	  utils/ft_strjoin.c\
	  utils/ft_strlen.c

ALL_SRC = $(PIPEX)\
		  $(UTILS)

all : 
	$(CC) $(CFLAGS) -o $(NAME) $(ALL_SRC)
	clear

alln : all
		norminette
		clear

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all