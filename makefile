# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apruvost <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 04:13:47 by apruvost          #+#    #+#              #
#    Updated: 2017/12/09 18:59:26 by fdrias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRCS = fillit.c ft_affsol.c ft_backward.c ft_checkarg.c ft_checkfile.c\
ft_gettet.c ft_init.c ft_reopen.c ft_root.c ft_solve.c\

OBJS = $(SRCS:.c=.o)

LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a
LIB_LINK = -L $(LIB_PATH) -lft

INC_DIR = fillit.h
INCS = -I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/ fclean
	@make -C libft/
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIB_LINK)

%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "Fillit Are Done !"

clean:
	rm -f $(OBJS)
		@make -C libft/ clean
		@echo "Objects files Are Deleted."

fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean
	@echo "$(NAME) Are Deleted."

re: fclean all
