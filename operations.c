/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:29:38 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/15 14:07:53 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/**
 * Shifts down all elements of stack 'a', stack 'b', or both stacks ('r') by 1.
 * The last element moves to the first position at the top.
 */
void	reverse_rotate(char stack, t_stacks *stacks)
{
	int	tmp;
	int	i_top;
	int	i;

	if ((stack == 'a' || stack == 'r') && stacks->a_len > 1)
	{
		i_top = stacks->a_len - 1;
		i = 0;
		tmp = stacks->a[i];
		while (++i <= i_top)
			stacks->a[i - 1] = stacks->a[i];
		stacks->a[i_top] = tmp;
	}
	if ((stack == 'b' || stack == 'r') && stacks->b_len > 1)
	{
		i_top = stacks->b_len - 1;
		i = 0;
		tmp = stacks->b[i];
		while (++i <= i_top)
			stacks->b[i - 1] = stacks->b[i];
		stacks->b[i_top] = tmp;
	}
	ft_putstr("rr");
	ft_putchar(stack);
	ft_putchar('\n');
}

/**
 * Shifts up all elements of stack 'a', stack 'b', or both stacks ('r') by 1.
 * The first element moves to the last position at the bottom.
 */
void	rotate(char stack, t_stacks *stacks)
{
	int	tmp;
	int	i;

	if ((stack == 'a' || stack == 'r') && stacks->a_len > 1)
	{
		i = stacks->a_len - 1;
		tmp = stacks->a[i];
		while (--i >= 0)
			stacks->a[i + 1] = stacks->a[i];
		stacks->a[0] = tmp;
	}
	if ((stack == 'b' || stack == 'r') && stacks->b_len > 1)
	{
		i = stacks->b_len - 1;
		tmp = stacks->b[i];
		while (--i >= 0)
			stacks->b[i + 1] = stacks->b[i];
		stacks->b[0] = tmp;
	}
	ft_putchar('r');
	ft_putchar(stack);
	ft_putchar('\n');
}

/**
 * Takes the first element at the top of stack 'b' and moves it to the top
 * of stack 'a', or vice versa.
 */
void	push(char stack, t_stacks *stacks)
{
	if (stack == 'a' && stacks->b_len > 0)
	{
		stacks->a[stacks->a_len] = stacks->b[stacks->b_len - 1];
		stacks->a_len++;
		stacks->b[stacks->b_len - 1] = 0;
		stacks->b_len--;
	}
	else if (stack == 'b' && stacks->a_len > 0)
	{
		stacks->b[stacks->b_len] = stacks->a[stacks->a_len - 1];
		stacks->b_len++;
		stacks->a[stacks->a_len - 1] = 0;
		stacks->a_len--;
	}
	ft_putchar('p');
	ft_putchar(stack);
	ft_putchar('\n');
}

/**
 * Swaps the first two elements at the top of stack 'a', stack 'b',
 * or both stacks ('s').
 */
void	swap(char stack, t_stacks *stacks)
{
	int	tmp;

	if ((stack == 'a' || stack == 's') && stacks->a_len > 1)
	{
		tmp = stacks->a[stacks->a_len - 2];
		stacks->a[stacks->a_len - 2] = stacks->a[stacks->a_len - 1];
		stacks->a[stacks->a_len - 1] = tmp;
	}
	if ((stack == 'b' || stack == 's') && stacks->b_len > 1)
	{
		tmp = stacks->b[stacks->b_len - 2];
		stacks->b[stacks->b_len - 2] = stacks->b[stacks->b_len - 1];
		stacks->b[stacks->b_len - 1] = tmp;
	}
	ft_putchar('s');
	ft_putchar(stack);
	ft_putchar('\n');
}
