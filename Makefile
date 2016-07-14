# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/25 11:55:33 by arnovan-          #+#    #+#              #
#    Updated: 2016/07/09 12:07:23 by kchetty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

CC=clang

CFLAGS=-Wall -Wextra -Werror -g

RM=rm -f

INC_LIBFT= -L. -lft

FCLEAN_LIB=make -C libft/ fclean

PATH_SRC= ./src/

PATH_HD= -I includes/

SRC = $(PATH_SRC)main.c $(PATH_SRC)ft_minishell.c $(PATH_SRC)get_args.c \
	  $(PATH_SRC)ft_ls.c $(PATH_SRC)execute_args.c $(PATH_SRC)ft_echo.c \
	  $(PATH_SRC)ft_cd.c $(PATH_SRC)ft_env.c $(PATH_SRC)ft_pwd.c \
	  $(PATH_SRC)environ_check.c

OBJ = main.o ft_minishell.o get_args.o ft_ls.o execute_args.o ft_echo.o \
	  ft_cd.o ft_env.o ft_pwd.o environ_check.o

$(NAME):
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) 
	@echo "Compilation was successful!"

all: $(NAME)

x11:
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) 
	@echo "Compilation was successful!"

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object files..."
	@make -C libft/ clean
	@echo "Done cleaning!"
fclean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object & binary files..."
	@make -C libft/ fclean
	@echo "Cleaning binaries..."
	@$(RM) $(NAME)
	@echo "Done cleaning!"

norme:
	@clear
	@norminette $(SRC)

re: fclean all

run:
	cd resources
	./filler_vm

