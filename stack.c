/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:51:42 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/14 18:12:06 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

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

static t_stacks	*stacks_new(void)
{
	t_stacks	*stacks;

	stacks = (t_stacks *) ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->a_len = 0;
	stacks->b_len = 0;
	return (stacks);
}

t_stacks	*stacks_init(char **arguments)
{
	t_stacks	*stacks;

	stacks = stacks_new();
	if (!stacks)
		return (NULL);
	stacks->a_len = arr_len(arguments);
	stacks->a = (int *) ft_calloc(stacks->a_len, sizeof(int));
	if (!stacks->a)
	{
		free(stacks);
		return (NULL);
	}
	stacks->b = (int *) ft_calloc(stacks->a_len, sizeof(int));
	if (!stacks->b)
	{
		free(stacks->a);
		free(stacks);
		return (NULL);
	}
	stacks_populate(stacks, arguments);
	free(arguments);
	return (stacks);
}
