/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:33 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/17 17:29:26 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Ensures three elements in a stack are in sequential order.
 * Swaps them if necessary.
 */
static void	align_three(char key, t_stack **stacks)
{
	t_stack	*stack;

	stack = stack_get_by_key(key, stacks);
	if (!stack_is_sequential(stack))
		swap(key, stacks);
}

/**
 * Sorts a stack of three elements.
 * Adjusts their order using swaps and rotations if necessary.
 */
void	sort_three(char key, t_stack **stacks)
{
	t_stack	*stack;

	align_three(key, stacks);
	stack = stack_get_by_key(key, stacks);
	if (stack_find_start(stack) == stack->top)
		return ;
	else if (stack_find_start(stack) == stack->top - 1)
		rotate(key, stacks);
	else if (stack_find_start(stack) == stack->bot)
		reverse_rotate(key, stacks);
}

/**
 * Sorts a stack of two elements.
 * Swaps them if they are out of order.
 */
void	sort_two(char key, t_stack **stacks)
{
	t_stack	*stack;

	stack = stack_get_by_key(key, stacks);
	if (stack_is_sorted(stack))
		return ;
	swap(key, stacks);
}
