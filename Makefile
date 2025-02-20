CC =	cc
CFLAGS = -Wall -Werror -Wextra -g
RM =	rm -f

SRCS =	$(addprefix src/, main.c arguments.c stacks.c stack.c operations.c \
	batch_operations.c find_next_move.c utils.c)
OBJS =	$(SRCS:.c=.o)
NAME =	push_swap

.PHONY:	all
all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -Llibft -lft -o $@

%.o: %.c src/push_swap.h Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY:	clean
clean:
	$(RM) $(OBJS)

.PHONY:	fclean
fclean:	clean
	$(RM) $(NAME)

.PHONY:	re
re:	fclean all
