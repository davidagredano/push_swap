/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:17:16 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/26 13:00:46 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Sorts a stack of three elements.
 * Adjusts their order using swaps and rotations if necessary.
 */
static void	sort_three(char key, t_stack **stacks)
{
	t_stack	*stack;

	stack = stack_get_by_key(key, stacks);
	if (stack->len != 3)
		return ;
	if (!stack_is_sequential(stack))
		swap('a', stacks);
	if (stack_find_start(stack) == stack->top)
		return ;
	else if (stack_find_start(stack) == stack->bot)
		reverse_rotate('a', stacks);
	else
		rotate('a', stacks);
}

/**
 * Handles the sorting operations based on the stack size.
 */
static void	sort(t_stack **stacks)
{
	t_stack	*a;

	a = stack_get_by_key('a', stacks);
	if (stack_is_sorted(a))
		return ;
	if (a->len == 2)
		swap('a', stacks);
	else if (a->len == 3)
		sort_three('a', stacks);
	else if (a->len <= 5)
	{
		batch_push('b', stacks, 3);
		sort_three('a', stacks);
		batch_insert_a(stacks);
		put_top(stack_find_start(a), 'a', stacks);
	}
	else if (a->len > 5)
	{
		batch_push_selective('b', stacks, stack_median_value(a));
		batch_push('b', stacks, 2);
		batch_insert_a(stacks);
		put_top(stack_find_start(a), 'a', stacks);
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
