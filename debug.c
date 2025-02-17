#include "push_swap.h"
#include <stdio.h>
#include <sys/param.h> // MAX

void	stacks_print(t_stacks *stacks)
{
	int	i;
	int	a_show;
	int	b_show;

	i = MAX(stacks->a_len - 1, stacks->b_len - 1);
	while (i >= 0)
	{
		a_show = i < stacks->a_len;
		b_show = i < stacks->b_len;
		if (a_show && !b_show)
			printf("%-11d\n", stacks->a[i]);
		else if (a_show && b_show)
			printf("%-11d %-11d\n", stacks->a[i], stacks->b[i]);
		else
			printf("%-11s %-11d\n", "", stacks->b[i]);
		i--;
	}
	printf("----------- -----------\n");
	printf("     A           B     \n");
}

void	arguments_print(char **arguments)
{
	printf("Arguments array: ");
	while (*arguments)
	{
		printf("\"%s\" ", *arguments);
		arguments++;
	}
	printf("\n");
}
