#include "tests.h"
#include "../push_swap.h"
#include "../libft/libft.h"
#include "get_next_line.h"

static void	print_next_operation(char *operation, t_stacks *stacks)
{
	printf("%s-----------------------\n", GREEN);
	printf("      Execute %s", operation);
	printf("-----------------------%s\n", COLOR_RESET);
	stacks_print(stacks);
}

static void	execute_next_operation(char *operation, t_stacks *stacks)
{
	if (ft_strcmp(operation, "sa\n") == 0)
		swap('a', stacks);
	else if (ft_strcmp(operation, "sb\n") == 0)
		swap('b', stacks);
	else if (ft_strcmp(operation, "ss\n") == 0)
		swap('s', stacks);
	else if (ft_strcmp(operation, "pa\n") == 0)
		push('a', stacks);
	else if (ft_strcmp(operation, "pb\n") == 0)
		push('b', stacks);
	else if (ft_strcmp(operation, "ra\n") == 0)
		rotate('a', stacks);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rotate('b', stacks);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rotate('r', stacks);
	else if (ft_strcmp(operation, "rra\n") == 0)
		reverse_rotate('a', stacks);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		reverse_rotate('b', stacks);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		reverse_rotate('r', stacks);
}

static void	operations_tests(int fd, t_stacks *stacks)
{
	char	*operation;

	ft_print_test_header("Operations tests");
	operation = "";
	while (operation)
	{
		operation = get_next_line(fd);
		if (operation)
		{
			execute_next_operation(operation, stacks);
			print_next_operation(operation, stacks);
		}
		free(operation);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			fd;

	if (argc == 1)
		return (1);
	stacks = arguments_process(argc, argv);
	if (!stacks)
	{
		print_error();
		return (1);
	}
	fd = open("test.txt", O_RDONLY);
	stacks_print(stacks);
	operations_tests(fd, stacks);
	close(fd);
	stacks_free(stacks);
	return (0);
}
