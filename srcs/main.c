/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:17:16 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/24 16:27:35 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Sorts stack 'a' using a multi-step process:
 * 1. Pushes all values larger than the median to stack 'b'.
 * 2. Pushes the remaining values to stack 'b' until only 2 values remain.
 * 3. Inserts the items back into stack 'a', always choosing the move that
 *    requires the least amount of operations for correct placement.
 *    This continues until stack 'b' is empty.
 * 4. Rotates stack 'a' to position the smallest number at the top.
 */
static void	sort(t_stack **stacks)
{
	if (!stack_is_sorted(stacks[0]))
	{
		batch_push_selective('b', stacks, stack_median_value(stacks[0]));
		batch_push('b', stacks, 2);
		batch_insert_a(stacks);
		put_top(stack_find_start(stacks[0]), 'a', stacks);
	}
}

/**
 * Processes the program arguments, tokenizes them, validates them,
 * and initializes a new stacks structure with them. Returns the
 * stacks structure or NULL if any step fails.
 */
static t_stack	**arguments_process(int argc, char **argv)
{
	t_stack	**stacks;
	char	**arguments;

	if (!arguments_prevalidate(argc - 1, argv + 1))
		return (NULL);
	arguments = arguments_tokenize(argc - 1, argv + 1);
	if (!arguments)
		return (NULL);
	if (!arguments_validate(arguments))
	{
		free(arguments);
		return (NULL);
	}
	stacks = stacks_init(arguments);
	if (!stacks)
	{
		free(arguments);
		return (NULL);
	}
	free(arguments);
	return (stacks);
}

/**
 * Main entry point for the program. Processes command line arguments,
 * initializes the stack, sorts it, and frees memory before exiting.
 */
int	main(int argc, char **argv)
{
	t_stack	**stacks;

	if (argc == 1)
		return (1);
	stacks = arguments_process(argc, argv);
	if (!stacks)
	{
		print_error();
		return (1);
	}
	sort(stacks);
	stacks_free(stacks);
	return (0);
}
