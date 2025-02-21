/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:29:38 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/21 21:17:11 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Shifts down all elements of stack 'a', stack 'b', or both stacks ('r') by 1.
 * The element at the bottom moves to the top.
 */
void	reverse_rotate(char key, t_stack **stacks)
{
	int		tmp;
	int		i;

	if ((key == 'a' || key == 'r') && stacks[0]->len > 1)
	{
		tmp = stacks[0]->val[stacks[0]->bot];
		i = stacks[0]->bot;
		while (++i <= stacks[0]->top)
			stacks[0]->val[i - 1] = stacks[0]->val[i];
		stacks[0]->val[stacks[0]->top] = tmp;
	}
	if ((key == 'b' || key == 'r') && stacks[1]->len > 1)
	{
		tmp = stacks[1]->val[stacks[1]->bot];
		i = stacks[1]->bot;
		while (++i <= stacks[1]->top)
			stacks[1]->val[i - 1] = stacks[1]->val[i];
		stacks[1]->val[stacks[1]->top] = tmp;
	}
	ft_putstr("rr");
	ft_putchar(key);
	ft_putchar('\n');
}

/**
 * Shifts up all elements of stack 'a', stack 'b', or both stacks ('r') by 1.
 * The element at the top moves to the bottom.
 */
void	rotate(char key, t_stack **stacks)
{
	int	tmp;
	int	i;

	if ((key == 'a' || key == 'r') && stacks[0]->len > 1)
	{
		tmp = stacks[0]->val[stacks[0]->top];
		i = stacks[0]->top;
		while (--i >= stacks[0]->bot)
			stacks[0]->val[i + 1] = stacks[0]->val[i];
		stacks[0]->val[stacks[0]->bot] = tmp;
	}
	if ((key == 'b' || key == 'r') && stacks[1]->len > 1)
	{
		tmp = stacks[1]->val[stacks[1]->top];
		i = stacks[1]->top;
		while (--i >= stacks[1]->bot)
			stacks[1]->val[i + 1] = stacks[1]->val[i];
		stacks[1]->val[stacks[1]->bot] = tmp;
	}
	ft_putchar('r');
	ft_putchar(key);
	ft_putchar('\n');
}

/**
 * Takes the first element at the top of stack 'b' and moves it to the top
 * of stack 'a', or vice versa.
 */
void	push(char key, t_stack **stacks)
{
	if (key == 'a' && stacks[0]->len > 0)
	{
		stacks[0]->val[stacks[0]->top + 1] = stacks[1]->val[stacks[1]->top];
		stacks[0]->len++;
		stacks[0]->top++;
		stacks[1]->val[stacks[1]->top] = 0;
		stacks[1]->len--;
		stacks[1]->top--;
	}
	else if (key == 'b' && stacks[0]->len > 0)
	{
		stacks[1]->val[stacks[1]->top + 1] = stacks[0]->val[stacks[0]->top];
		stacks[1]->len++;
		stacks[1]->top++;
		stacks[0]->val[stacks[0]->top] = 0;
		stacks[0]->len--;
		stacks[0]->top--;
	}
	ft_putchar('p');
	ft_putchar(key);
	ft_putchar('\n');
}

/**
 * Swaps the first two elements at the top of stack 'a', stack 'b',
 * or both stacks ('s').
 */
void	swap(char key, t_stack **stacks)
{
	int	tmp;

	if ((key == 'a' || key == 's') && stacks[0]->len > 1)
	{
		tmp = stacks[0]->val[stacks[0]->top];
		stacks[0]->val[stacks[0]->top] = stacks[0]->val[stacks[0]->top - 1];
		stacks[0]->val[stacks[0]->top - 1] = tmp;
	}
	if ((key == 'b' || key == 's') && stacks[1]->len > 1)
	{
		tmp = stacks[1]->val[stacks[1]->top];
		stacks[1]->val[stacks[1]->top] = stacks[1]->val[stacks[1]->top - 1];
		stacks[1]->val[stacks[1]->top - 1] = tmp;
	}
	ft_putchar('s');
	ft_putchar(key);
	ft_putchar('\n');
}
