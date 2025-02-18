SRCS = $(addprefix ../,arguments.c stacks.c operations.c utils.c debug.c)

arguments_validate:
	$(CC) -o $@ $@.c utils.c $(SRCS) -L../libft -lft
	./$@
	@$(RM) $@

fclean:
	$(RM) arguments_validate
