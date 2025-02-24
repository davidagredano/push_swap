/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:22:57 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/24 16:33:24 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Finds the median value of the stack, the value that has an equal number
 * of elements smaller and larger than it.
 * Returns the median value, or 0 if no median is found.
 */
int	stack_median_value(t_stack *stack)
{
	int	count[2];
	int	i;
	int	j;

	i = stack->bot;
	while (i <= stack->top)
	{
		count[0] = 0;
		count[1] = 0;
		j = stack->bot;
		while (j <= stack->top)
		{
			if (stack->val[j] < stack->val[i])
				count[0]++;
			else if (stack->val[j] > stack->val[i])
				count[1]++;
			if (count[0] > stack->top / 2 || count[1] > stack->len / 2)
				break ;
			j++;
		}
		if (count[0] == stack->top / 2 && count[1] == stack->len / 2)
			return (stack->val[i]);
		i++;
	}
	return (0);
}

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

/**
 * Retrieves the stack corresponding to the given key ('a' or 'b').
 */
t_stack	*stack_get_by_key(char key, t_stack **stacks)
{
	if (key == 'a')
		return (stacks[0]);
	else if (key == 'b')
		return (stacks[1]);
	return (NULL);
}
