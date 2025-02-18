/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batch_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:03:39 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/19 00:00:43 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Moves the element at the given index to the top of the specified stack.
 * Uses the most efficient method (rotate or reverse rotate) based on
 * the index position.
 */
void	put_top(int index, char key, t_stack **stacks)
{
	t_stack	*stack;

	stack = stack_get_by_key(key, stacks);
	if (index >= stack->top / 2)
	{
		while (index++ < stack->top)
			rotate(key, stacks);
	}
	else
	{
		while (index-- >= stack->bot)
			reverse_rotate(key, stacks);
	}
}

/**
 * Moves the elements at the given indices to the top of their stacks.
 */
void	put_top_double(int a_index, int b_index, t_stack **stacks)
{
	put_top(a_index, 'a', stacks);
	put_top(b_index, 'b', stacks);
}
