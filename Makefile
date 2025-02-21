CC =	cc
CFLAGS = -Wall -Werror -Wextra -g
RM =	rm -f

SRCS =	$(addprefix src/, main.c arguments.c stacks.c stack.c operations.c \
	batch_operations.c find_next_move.c utils.c)
OBJS =	$(SRCS:.c=.o)
NAME =	push_swap

SRCS_BONUS = $(addprefix src_bonus/, main_bonus.c arguments_bonus.c \
	stacks_bonus.c get_next_line.c utils_bonus.c)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME_BONUS = checker

.PHONY:	all
all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -Llibft -lft -o $@

%.o: %.c src/push_swap.h src_bonus/checker.h Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY:	clean
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

.PHONY:	fclean
fclean:	clean
	$(RM) $(NAME) $(NAME_BONUS)

.PHONY:	re
re:	fclean all

.PHONY:	bonus
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $^ -Llibft -lft -o $(NAME_BONUS)
