/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:19:22 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/24 16:33:09 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

/**
 * Returns the starting index of a sequential stack. The stack may be rotated.
 * Does not work with unordered stacks.
 */
int	stack_find_start(t_stack *stack)
{
	int	i;

	if (stack->val[stack->top] < stack->val[stack->bot] || stack->len == 1)
		return (stack->top);
	i = stack->top;
	while (--i >= stack->bot)
	{
		if (stack->val[i] < stack->val[i + 1])
			break ;
	}
	return (i);
}

/**
 * Checks if the numbers maintain a sequential order with a possible shift.
 * A stack is sequential if each number is greater than the one above it,
 * except for a single out-of-order element that indicates the start.
 */
int	stack_is_sequential(t_stack *stack)
{
	int	start_found;
	int	i;

	if (stack->len == 1)
		return (1);
	start_found = 0;
	if (stack->val[stack->top] < stack->val[stack->bot])
		start_found = 1;
	i = stack->top;
	while (--i >= stack->bot)
	{
		if (stack->val[i] < stack->val[i + 1])
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
int	stack_is_sorted(t_stack *stack)
{
	return (stack_is_sequential(stack)
		&& stack_find_start(stack) == stack->top);
}
