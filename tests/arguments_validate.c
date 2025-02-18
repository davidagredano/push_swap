#include "../push_swap.h"

# define RED "\e[31m"
# define GREEN "\e[32m"
# define CYAN "\e[36m"
# define GRAY "\e[2;37m"
# define COLOR_RESET "\e[0m"

# define KO "\e[31mKO\e[0m"
# define OK "\e[32mOK\e[0m"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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

static void	arguments_validate_test_case(char *argument, int expected)
{
	char	*arguments[2];
	int		returned;
	char	*result;

	arguments[0] = strdup(argument);
	arguments[1] = NULL;
	returned = arguments_validate(arguments);
	if (returned == expected)
		result = OK;
	else
		result = KO;
	printf("%s", result);
	printf(" %s| Expected %d, got %d", GRAY, expected, returned);
	printf(" | arguments =%s { \"%s\", NULL }\n", COLOR_RESET, argument);
	free(arguments[0]);
}

static void	arguments_validate_tests(void)
{
	ft_print_test_header("int arguments_validate(char **arguments)");
	arguments_validate_test_case("42", 1);
	arguments_validate_test_case("+42", 1);
	arguments_validate_test_case("-42", 1);
	arguments_validate_test_case("2147483647", 1);
	arguments_validate_test_case("+2147483647", 1);
	arguments_validate_test_case("-2147483648", 1);
	arguments_validate_test_case("0", 1);
	arguments_validate_test_case("+0", 1);
	arguments_validate_test_case("-0", 1);
	arguments_validate_test_case("00000", 1);
	arguments_validate_test_case("0000000042", 1);
	arguments_validate_test_case("-0000000000000000000042", 1);
	arguments_validate_test_case("-00000002147483648", 1);
	arguments_validate_test_case("00000000000000000002147483647", 1);
	arguments_validate_test_case("a0", 0);
	arguments_validate_test_case("one", 0);
	arguments_validate_test_case("2?", 0);
	arguments_validate_test_case("3th", 0);
	arguments_validate_test_case("+", 0);
	arguments_validate_test_case("-", 0);
	arguments_validate_test_case("++", 0);
	arguments_validate_test_case("--", 0);
	arguments_validate_test_case("+-", 0);
	arguments_validate_test_case("-+", 0);
	arguments_validate_test_case("-2147483649", 0);
	arguments_validate_test_case("2147483648", 0);
	arguments_validate_test_case("-98723544748364", 0);
	arguments_validate_test_case("818256341233426", 0);
}

int	main(void)
{
	arguments_validate_tests();
}
