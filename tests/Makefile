SRCS = $(addprefix ../,arguments.c stacks.c operations.c utils.c debug.c)

arguments_validate:
	$(CC) -o $@ $@.c utils.c $(SRCS) -L../libft -lft
	./$@
	@$(RM) $@

operations:
	$(CC) -o $@ $@.c utils.c get_next_line.c $(SRCS) -L../libft -lft

fclean:
	$(RM) arguments_validate operations
