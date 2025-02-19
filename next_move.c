/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:13:09 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/19 15:22:10 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the given value is either the smallest or the greatest
 * among all elements in the stack.
 */
static int	value_is_extreme(int value, t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= stack->bot)
	{
		if (value > stack->val[i])
			break ;
		i--;
	}
	if (i < stack->bot)
		return (1);
	i = stack->top;
	while (i >= stack->bot)
	{
		if (value < stack->val[i])
			return (0);
		i--;
	}
	return (1);
}

/**
 * Calculates the minimum number of moves required to bring the element
 * at the given index to the top of the stack.
 */
static int	cost_to_top(int index, t_stack *stack)
{
	int	moves;
	int	pivot;

	pivot = stack->top / 2;
	if (index >= pivot)
		moves = stack->top - index;
	else
		moves = index + 1;
	return (moves);
}

/**
 * Calculates the number of moves required to bring two elements
 * (one from each stack) to the top using optimal double rotations.
 */
static int	cost_to_top_double(int a, int b, t_stack **stacks)
{
	int	moves;
	int	a_distance;
	int	b_distance;

	moves = 0;
	if (a >= stacks[0]->top / 2 && b >= stacks[1]->top / 2)
	{
		a_distance = stacks[0]->top - a;
		b_distance = stacks[1]->top - b;
		moves += min(a_distance, b_distance);
		a += moves;
		b += moves;
	}
	else if (a < stacks[0]->top / 2 && b < stacks[1]->top / 2)
	{
		a_distance = a + 1;
		b_distance = b + 1;
		moves += min(a_distance, b_distance);
		a -= moves;
		b -= moves;
	}
	moves += cost_to_top(a, stacks[0]);
	moves += cost_to_top(b, stacks[1]);
	return (moves);
}

/**
 * Finds the index in the stack where the given value should be inserted
 * to maintain order.
 * If the value is the smallest or greatest, returns the stack's starting index.
 */
static int	value_insertion_index(int value, t_stack *stack)
{
	int	i;

	if (value_is_extreme(value, stack))
		return (stack_find_start(stack));
	if (stack->val[stack->bot] < value && value < stack->val[stack->top])
		return (stack->top);
	i = stack->top;
	while (--i >= stack->bot)
	{
		if (stack->val[i + 1] < value && value < stack->val[i])
			break ;
	}
	return (i);
}

/**
 * Determines the next move by finding the pair of elements in stacks 'a'
 * and 'b' that can be moved with the least cost.
 */
void	find_next_move(t_stack **stacks)
{
	int	min_cost;
	int	cost;
	int	a;
	int	b;

	min_cost = 0;
	b = stacks[1]->bot;
	while (b <= stacks[1]->top)
	{
		a = value_insertion_index(stacks[1]->val[b], stacks[0]);
		cost = cost_to_top_double(a, b, stacks);
		if (cost < min_cost || min_cost == 0)
		{
			min_cost = cost;
			stacks[0]->next_move = a;
			stacks[1]->next_move = b;
		}
		b++;
	}
}
