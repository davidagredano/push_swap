CC	= cc
CFLAGS	= -Wall -Werror -Wextra -g
RM	= rm -f

SRCS	= main.c validations.c stack.c utils.c log.c
OBJS	= $(SRCS:.c=.o)
NAME	= push_swap

.PHONY: all
all:	$(NAME) 

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Llibft -lft -o $@

%.o:	%.c push_swap.h Makefile
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY:	clean
clean:
	$(RM) $(OBJS)

.PHONY:	fclean
fclean:	clean
	$(RM) $(NAME)

.PHONY:	re
re:	fclean all
