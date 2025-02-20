/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:33 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/20 12:18:48 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	median_value(t_stack *stack)
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

void	sort_many(t_stack **stacks)
{
	int	debugging = 0; // TODO
	int	median;
	int	i;

	if (debugging)
		print_stacks(stacks, "Initial state"); // TODO

	median = median_value(stacks[0]);
	i = stacks[0]->top;
	while (i >= stacks[0]->bot)
	{
		if (stacks[0]->val[stacks[0]->top] < median)
			push('b', stacks);
		else
			rotate('a', stacks);
		i--;
	}

	while (stacks[0]->len > 3)
		push('b', stacks);
	if (debugging)
		print_stacks(stacks, "State after batch push:"); // TODO

	align_three('a', stacks);
	if (debugging)
		print_stacks(stacks, "State after aligning stack 'a':"); // TODO

	while (stacks[1]->len > 0)
	{
		find_next_move(stacks);
		//printf("\nNext cheapest move: insert b[%d]=%d to a[%d]=%d\n\n", b_index, stacks[1]->val[b_index], a_index, stacks[0]->val[a_index]); // TODO

		put_top_double(stacks[0]->next_move, stacks[1]->next_move, stacks);
		push('a', stacks);
		if (debugging)
			print_stacks(stacks, "State after smart insert:"); // TODO
	}
	put_top(stack_find_start(stacks[0]), 'a', stacks);
	if (debugging)
		print_stacks(stacks, "Final state:"); // TODO
}

/**
 * Ensures three elements in a stack are in sequential order.
 * Swaps them if necessary.
 */
void	align_three(char key, t_stack **stacks)
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
