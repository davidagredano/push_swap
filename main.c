/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:17:16 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/17 17:59:03 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Handles the sorting operations based on the initial stack size.
 */
static void	sort(t_stack **stacks)
{
	if (stacks[0]->len == 2)
		sort_two('a', stacks);
	else if (stacks[0]->len == 3)
		sort_three('a', stacks);
}

int	main(int argc, char **argv)
{
	t_stack	**stacks;

	if (argc == 1)
		return (1);
	stacks = arguments_process(argc, argv);
	if (!stacks)
	{
		print_error();
		return (1);
	}
	sort(stacks);
	stacks_free(stacks);
	return (0);
}
