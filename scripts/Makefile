NAME = auto42

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./includes

SRCS = $(shell find -name '*.c')
 
OBJS = ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean: 
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re
