#include "tests.h"
#include "../push_swap.h"

static void	are_valid_arguments_test_case(char *argument, int expected)
{
	char	*arguments[2];
	int		returned;
	char	*result;

	arguments[0] = strdup(argument);
	arguments[1] = NULL;
	returned = are_valid_arguments(arguments);
	if (returned == expected)
		result = OK;
	else
		result = KO;
	printf("%s", result);
	printf(" %s| Expected %d, got %d", GRAY, expected, returned);
	printf(" | arguments =%s { \"%s\", NULL }\n", COLOR_RESET, argument);
	free(arguments[0]);
}

static void	are_valid_arguments_tests(void)
{
	ft_print_test_header("int are_valid_arguments(char **arguments)");
	are_valid_arguments_test_case("42", 1);
	are_valid_arguments_test_case("+42", 1);
	are_valid_arguments_test_case("-42", 1);
	are_valid_arguments_test_case("2147483647", 1);
	are_valid_arguments_test_case("+2147483647", 1);
	are_valid_arguments_test_case("-2147483648", 1);
	are_valid_arguments_test_case("0", 1);
	are_valid_arguments_test_case("+0", 1);
	are_valid_arguments_test_case("-0", 1);
	are_valid_arguments_test_case("00000", 1);
	are_valid_arguments_test_case("0000000042", 1);
	are_valid_arguments_test_case("-0000000000000000000042", 1);
	are_valid_arguments_test_case("-00000002147483648", 1);
	are_valid_arguments_test_case("00000000000000000002147483647", 1);
	are_valid_arguments_test_case("a0", 0);
	are_valid_arguments_test_case("one", 0);
	are_valid_arguments_test_case("2?", 0);
	are_valid_arguments_test_case("3th", 0);
	are_valid_arguments_test_case("+", 0);
	are_valid_arguments_test_case("-", 0);
	are_valid_arguments_test_case("++", 0);
	are_valid_arguments_test_case("--", 0);
	are_valid_arguments_test_case("+-", 0);
	are_valid_arguments_test_case("-+", 0);
	are_valid_arguments_test_case("-2147483649", 0);
	are_valid_arguments_test_case("2147483648", 0);
	are_valid_arguments_test_case("-98723544748364", 0);
	are_valid_arguments_test_case("818256341233426", 0);
}

int	main(void)
{
	are_valid_arguments_tests();
}
