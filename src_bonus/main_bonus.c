/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:09:55 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/21 16:42:13 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	**stacks;
	t_list	**instructions;

	if (argc == 1)
		return (1);
	stacks = arguments_process(argc, argv);
	if (!stacks)
	{
		print_error();
		return (1);
	}
	instructions = instructions_load();
	if (!instructions)
	{
		stacks_free(stacks);
		print_error();
		return (1);
	}
	// TODO
	instructions_free(instructions);
	stacks_free(stacks);
	return (0);
}
