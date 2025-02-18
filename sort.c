/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:33 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/18 23:45:21 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_many(t_stack **stacks)
{
	int	debugging = 0; // TODO

	if (debugging)
		print_stacks(stacks, "Initial state"); // TODO

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
