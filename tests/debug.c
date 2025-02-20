#include "push_swap.h"
#include <stdio.h>
#include <sys/param.h> // MAX

void	print_stacks(t_stack **stacks, char *message)
{
	int	i;
	int	a_show;
	int	b_show;

	printf("%s\n", message);
	i = MAX(stacks[0]->top, stacks[1]->top);
	while (i >= stacks[0]->bot)
	{
		a_show = i <= stacks[0]->top;
		b_show = i <= stacks[1]->top;
		if (a_show && !b_show)
			printf("%-11d\n", stacks[0]->val[i]);
		else if (a_show && b_show)
			printf("%-11d %-11d\n", stacks[0]->val[i], stacks[1]->val[i]);
		else
			printf("%-11s %-11d\n", "", stacks[1]->val[i]);
		i--;
	}
	printf("----------- -----------\n");
	printf("     A           B     \n");
}

void	print_arguments(char **arguments)
{
	printf("Arguments array: ");
	while (*arguments)
	{
		printf("\"%s\" ", *arguments);
		arguments++;
	}
	printf("\n");
}
