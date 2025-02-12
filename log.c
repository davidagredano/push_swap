#include <stdio.h>

void	print_arguments(char **strs)
{
	printf("Arguments array: ");
	while (*strs)
	{
		printf("\"%s\" ", *strs);
		strs++;
	}
	printf("\n");
}
