/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:51:42 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/20 17:46:52 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

/**
 * Checks for duplicate values in a given stack.
 */
static int	stack_validate(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->bot;
	while (i < stack->top)
	{
		j = i + 1;
		while (j <= stack->top)
		{
			if (stack->val[i] == stack->val[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * Populates a stack from top to bottom with arguments converted to integers.
 */
static void	stack_populate(char **arguments, int len, t_stack *stack)
{
	int	i;

	stack->len = len;
	stack->top = len - 1;
	i = stack->top;
	while (*arguments)
	{
		stack->val[i] = ft_atoi(*arguments);
		i--;
		arguments++;
	}
}

/**
 * Frees both stacks and their allocated values.
 */
void	stacks_free(t_stack **stacks)
{
	if (stacks[0])
	{
		if (stacks[0]->val)
			free(stacks[0]->val);
		free(stacks[0]);
	}
	if (stacks[1])
	{
		if (stacks[1]->val)
			free(stacks[1]->val);
		free(stacks[1]);
	}
	free(stacks);
	stacks = NULL;
}

/**
 * Allocates and initializes a stack with the given key and value length.
 */
static t_stack	*stack_init(char key, int val_len)
{
	t_stack	*stack;

	stack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->key = key;
	stack->val = (int *) ft_calloc(val_len, sizeof(int));
	if (!stack->val)
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	stack->len = 0;
	stack->top = stack->len - 1;
	stack->bot = 0;
	stack->next_move = -1;
	return (stack);
}

/**
 * Allocates and initializes stacks 'a' and 'b', then populates stack 'a'
 * with the given arguments and validates there are no duplicates.
 */
t_stack	**stacks_init(char **arguments)
{
	t_stack	**stacks;
	int		arguments_len;

	stacks = (t_stack **) ft_calloc(2, sizeof(t_stack *));
	if (!stacks)
		return (NULL);
	arguments_len = strs_len(arguments);
	stacks[0] = stack_init('a', arguments_len);
	stacks[1] = stack_init('b', arguments_len);
	if (!stacks[0] || !stacks[1])
	{
		stacks_free(stacks);
		return (NULL);
	}
	stack_populate(arguments, arguments_len, stacks[0]);
	if (!stack_validate(stacks[0]))
	{
		stacks_free(stacks);
		return (NULL);
	}
	return (stacks);
}
