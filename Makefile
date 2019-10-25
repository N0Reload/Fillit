# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 22:43:33 by lmunoz-q          #+#    #+#              #
#    Updated: 2017/11/19 22:43:34 by lmunoz-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CLIB = -Llibft -lft

INC = ./ \
	  libft

INCDIRS = $(addprefix -I,$(INC))

NAME = fillit

SRCFILES = board_solver.c \
					 file_reader.c \
					 main.c \
					 pieces_list.c \
					 pieces_reader.c \
					 pieces_solver.c \
					 pieces.c \
					 points_list.c \
					 utils.c

OBJDIR = obj

OBJECTS = $(SRCFILES:%.c=%.o)

all: $(NAME)

$(NAME): libft/libft.a $(OBJECTS)
	$(CC) $(INCDIRS)  $(CLIB) -o $@ $(OBJECTS)

%.o : %.c
	$(CC) $(INCDIRS) $(CFLAGS) -c $< -o $@

libft/libft.a:
	@$(MAKE) -w -C libft/

clean:
	@rm -rf $(OBJECTS)
	@$(MAKE) -w -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -w -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
