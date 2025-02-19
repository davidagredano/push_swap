/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batch_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:03:39 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/19 13:39:08 by dagredan         ###   ########.fr       */
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
 * Moves two elements to the top of their respective stacks simultaneously.
 * Uses double rotation when both indices are in the top or bottom half.
 * Completes the movement with individual rotations if needed.
 */
void	put_top_double(int a_index, int b_index, t_stack **stacks)
{
	if (a_index >= stacks[0]->top / 2 && b_index >= stacks[1]->top / 2)
	{
		while (a_index < stacks[0]->top && b_index < stacks[1]->top)
		{
			rotate('r', stacks);
			a_index++;
			b_index++;
		}
	}
	else if (a_index < stacks[0]->top / 2 && b_index < stacks[1]->top / 2)
	{
		while (a_index >= stacks[0]->bot && b_index >= stacks[1]->bot)
		{
			reverse_rotate('r', stacks);
			a_index--;
			b_index--;
		}
	}
	put_top(a_index, 'a', stacks);
	put_top(b_index, 'b', stacks);
}
