#include "tests.h"

void	ft_print_test_header(const char *str)
{
	size_t	size;
	size_t	i;

	size = strlen(str);
	printf("%s", CYAN);
	i = 0;
	while (i++ < size)
		printf("*");
	printf("\n%s\n", str);
	i = 0;
	while (i++ < size)
		printf("*");
	printf("%s\n", COLOR_RESET);
}
