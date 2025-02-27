/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batch_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:03:39 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/27 17:06:12 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		while (index < stack->top)
		{
			rotate(key, stacks);
			index++;
		}
	}
	else
	{
		while (index >= stack->bot)
		{
			reverse_rotate(key, stacks);
			index--;
		}
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

/**
 * Moves all elements from stack 'b' to stack 'a' in an optimized order,
 * selecting the item that requires the fewest moves for insertion each time.
 */
void	batch_insert_a(t_stack **stacks)
{
	while (stacks[1]->len > 0)
	{
		find_next_move(stacks);
		put_top_double(stacks[0]->next_move, stacks[1]->next_move, stacks);
		push('a', stacks);
	}
}

/**
 * Moves elements from one stack to another, leaving only
 * the specified number of values in the source stack.
 */
void	batch_push(char key, t_stack **stacks, int leave)
{
	t_stack	*src;

	if (key == 'a')
		src = stack_get_by_key('b', stacks);
	else if (key == 'b')
		src = stack_get_by_key('a', stacks);
	while (src->len > leave)
		push(key, stacks);
}

/**
 * Pushes elements smaller than the given cutoff value to another stack.
 * Leaves the specified number of elements in the source stack.
 * Elements not meeting the condition are rotated to the bottom.
 */
void	batch_push_smallest(char key, t_stack **stacks, int cutoff, int leave)
{
	t_stack	*src;
	int		i;

	if (key == 'a')
		src = stack_get_by_key('b', stacks);
	else if (key == 'b')
		src = stack_get_by_key('a', stacks);
	i = src->top;
	while (i >= leave)
	{
		if (src->val[src->top] < cutoff)
			push(key, stacks);
		else
			rotate(src->key, stacks);
		i--;
	}
}
