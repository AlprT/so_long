# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 17:48:01 by atangil           #+#    #+#              #
#    Updated: 2023/12/08 18:24:14 by atangil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC				=	./src/main/main.c \
					./src/main/so_long.c \
					./src/main/size_coin.c \
					./src/main/set_player.c \
					./src/main/end.c \
					./src/main/mov.c \
					./src/main/set_tex.c \
					./src/main/set_window.c \

OBJS			=	main.o \
					so_long.o \
					size_coin.o \
					set_player.o \
					end.o \
					mov.o \
					set_tex.o \
					set_window.o

MINILIBX_PATH	=	./src/minilibx

CHECK_PATH		=	./src/checks
CHECK			=   $(CHECK_PATH)/checker.a

LIB_PATH		=	./src/lib
LIB				=	$(LIB_PATH)/libft.a

all : $(NAME)

$(NAME):			$(LIB) $(CHECK) mlx
					@$(CC) $(FLAGS) $(SRC) $(LIB) $(CHECK) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx -o $(NAME)

$(LIB):
	@make -C $(LIB_PATH) all

$(CHECK):
	@make -C $(CHECK_PATH) all

mlx:
	@make -C $(MINILIBX_PATH) all

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) clean
	@make -C $(CHECK_PATH) clean
	@make -C $(MINILIBX_PATH) clean

fclean:
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) fclean
	@make -C $(CHECK_PATH) fclean
	@make -C $(MINILIBX_PATH) clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
