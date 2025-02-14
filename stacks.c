/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:51:42 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/14 23:24:52 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/**
 * Checks for duplicate values in stack 'a'.
 */
static int	stacks_validate(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->a_len - 1)
	{
		j = i + 1;
		while (j < stacks->a_len)
		{
			if (stacks->a[i] == stacks->a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * Populates stack 'a' from top to bottom with arguments converted to integers.
 */
static void	stacks_populate(t_stacks *stacks, char **arguments)
{
	int	i;

	i = stacks->a_len - 1;
	while (*arguments)
	{
		stacks->a[i] = ft_atoi(*arguments);
		i--;
		arguments++;
	}
}

/**
 * Frees the memory allocated for both stacks and the stacks structure itself.
 */
void	stacks_free(t_stacks *stacks)
{
	if (stacks->a) 
		free(stacks->a);
	if (stacks->b) 
		free(stacks->b);
	free(stacks);
	stacks = NULL;
}

/**
 * Allocates and initializes a new stacks structure with two integer arrays for
 * stack 'a' and stack 'b'. Populates stack 'a' with the arguments converted
 * to integers. Returns the stacks structure or NULL if any step fails.
 */
t_stacks	*stacks_init(char **arguments)
{
	t_stacks	*stacks;

	stacks = (t_stacks *) ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a_len = strs_len(arguments);
	stacks->b_len = 0;
	stacks->a = (int *) ft_calloc(stacks->a_len, sizeof(int));
	stacks->b = (int *) ft_calloc(stacks->a_len, sizeof(int));
	if (!stacks->a || !stacks->b)
	{
		stacks_free(stacks);
		return (NULL);
	}
	stacks_populate(stacks, arguments);
	if (!stacks_validate(stacks))
	{
		stacks_free(stacks);
		return (NULL);
	}
	return (stacks);
}
