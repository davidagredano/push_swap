/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:33 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/16 15:40:58 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Ensures three elements in a stack are in sequential order.
 * Swaps them if necessary.
 */
static void	align_three(char target_stack, t_stacks *stacks)
{
	if (!stack_is_sequential(target_stack, stacks))
		swap(target_stack, stacks);
}

/**
 * Sorts a stack of three elements.
 * Adjusts their order using swaps and rotations if necessary.
 */
void	sort_three(char target_stack, t_stacks *stacks)
{
	align_three(target_stack, stacks);
	if (stack_find_start(target_stack, stacks) == 2)
		return ;
	else if (stack_find_start(target_stack, stacks) == 1)
		rotate(target_stack, stacks);
	else if (stack_find_start(target_stack, stacks) == 0)
		reverse_rotate(target_stack, stacks);
}

/**
 * Sorts a stack of two elements.
 * Swaps them if they are out of order.
 */
void	sort_two(char target_stack, t_stacks *stacks)
{
	if (stack_is_sorted(target_stack, stacks))
		return ;
	swap(target_stack, stacks);
}
