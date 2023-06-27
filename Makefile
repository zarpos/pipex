# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 17:53:36 by drubio-m          #+#    #+#              #
#    Updated: 2023/06/27 20:49:06 by drubio-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pipex.c utils.c utils2.c
SRC_DIR = src
OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
C = gcc
FLAGS = -Wall -Wextra -Werror #-g  -fsanitize=address
NAME = pipex
RM = rm -rf

LIBFT_DIR = libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

all: $(NAME)

.SILENT:

$(NAME): $(OBJS)
	@echo "\033[36;49;1;3m----Compiling lib----\n"
	@make bonus -C $(LIBFT_DIR) --silent
	@gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[32;49;1;3mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ"

clean:
	@$(RM) $(OBJS) $(LIBFT_A)
	@make -C $(LIBFT_DIR) clean --silent 

fclean:	clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent 
	@echo "\033[35;49;1mHEAVY CLEANING, EVERYTHING HAS BEEN DELETED\n"

re:	fclean
	@make all
	@echo "\033[33;49;1;3m\nEaster Egg ;)"
	
.PHONY:	all clean fclean re