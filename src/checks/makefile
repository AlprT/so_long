NAME = checker.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = create_map.c \
		free_map.c \
		is_ber.c \
		is_rectangle.c \
		is_valid.c

OBJS = create_map.o \
		free_map.o \
		is_ber.o \
		is_rectangle.o \
		is_valid.o

all : $(NAME)

$(NAME) :
		@$(CC) $(FLAGS) -c $(SRCS)
		@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f  $(OBJS)

fclean:
	@rm -f  $(OBJS)
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re