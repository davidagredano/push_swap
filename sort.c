/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:33 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/20 12:37:01 by dagredan         ###   ########.fr       */
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

void	sort(t_stack **stacks)
{
	int	median;
	int	i;

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
	while (stacks[0]->len > 2)
		push('b', stacks);
	while (stacks[1]->len > 0)
	{
		find_next_move(stacks);
		put_top_double(stacks[0]->next_move, stacks[1]->next_move, stacks);
		push('a', stacks);
	}
	put_top(stack_find_start(stacks[0]), 'a', stacks);
}
