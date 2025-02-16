/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:22:57 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/16 15:45:08 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Returns a pointer to the array of values for the specified stack.
 */
static int	*stack_get_values(char target_stack, t_stacks *stacks)
{
	if (target_stack == 'a')
		return (stacks->a);
	else if (target_stack == 'b')
		return (stacks->b);
	return (NULL);
}

/**
 * Returns the length of the specified stack.
 */
static int	stack_get_len(char target_stack, t_stacks *stacks)
{
	if (target_stack == 'a')
		return (stacks->a_len);
	else if (target_stack == 'b')
		return (stacks->b_len);
	return (-1);
}

/**
 * Returns the starting index of a sequential stack. The stack may be rotated.
 * Does not work with unordered stacks.
 */
int	stack_find_start(char target_stack, t_stacks *stacks)
{
	int	*stack;
	int	len;
	int	i;

	stack = stack_get_values(target_stack, stacks);
	len = stack_get_len(target_stack, stacks);
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
int	stack_is_sequential(char target_stack, t_stacks *stacks)
{
	int	*stack;
	int	len;
	int	start_found;
	int	i;

	stack = stack_get_values(target_stack, stacks);
	len = stack_get_len(target_stack, stacks);
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
int	stack_is_sorted(char target_stack, t_stacks *stacks)
{
	int	top;

	top = stack_get_len(target_stack, stacks) - 1;
	return (stack_is_sequential(target_stack, stacks)
		&& stack_find_start(target_stack, stacks) == top);
}
