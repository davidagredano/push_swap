/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:33 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/15 20:51:38 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Returns the starting index of a sequential stack. The stack may be rotated.
 * Does not work with unordered stacks.
 */
static int	stack_find_start(int *stack, int len)
{
	int	i;

	i = len - 1;
	if (stack[i] < stack[0])
		return (i);
	while (--i >= 0)
	{
		if (stack[i] < stack[i + 1])
			break ;
	}
	return (i);
}

/**
 * Checks if the numbers maintain a sequential order with a possible shift.
 * A stack is sequential if each number is greater than the one above it,
 * except for a single out-of-order element that indicates the start.
 */
static int	stack_is_sequential(int *stack, int len)
{
	int	start_found;
	int	i;

	start_found = 0;
	i = len - 1;
	if (stack[i] < stack[0])
		start_found = 1;
	while (--i >= 0)
	{
		if (stack[i] < stack[i + 1])
		{
			if (!start_found)
				start_found = 1;
			else
				return (0);
		}
	}
	return (1);
}

/**
 * Checks if the numbers are in ascending order, from smallest at the top
 * (the end of the array) to largest at the bottom (the start of the array).
 */
static int	stack_is_sorted(int *stack, int len)
{
	return (stack_is_sequential(stack, len)
		&& stack_find_start(stack, len) == len - 1);
}

/**
 * Sorts a stack of three elements.
 * Adjusts their order using swaps and rotations if necessary.
 */
void	sort_three(t_stacks *stacks)
{
	if (!stack_is_sequential(stacks->a, stacks->a_len))
		swap('a', stacks);
	if (stack_find_start(stacks->a, stacks->a_len) == 2)
		return ;
	else if (stack_find_start(stacks->a, stacks->a_len) == 1)
		rotate('a', stacks);
	else if (stack_find_start(stacks->a, stacks->a_len) == 0)
		reverse_rotate('a', stacks);
}

/**
 * Sorts a stack of two elements.
 * Swaps them if they are out of order.
 */
void	sort_two(t_stacks *stacks)
{
	if (stack_is_sorted(stacks->a, stacks->a_len))
		return ;
	swap('a', stacks);
}
