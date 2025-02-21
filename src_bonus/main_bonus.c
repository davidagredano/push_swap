/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:09:55 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/21 17:46:33 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * Entry point of the program.
 * Processes arguments and load instructions reading from standard input.
 * Executes the instructions on the stacks, then displays whether the
 * stack is sorted ("OK") or not ("KO") after execution.
 * Frees all resources before exiting.
 */
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
	instructions_execute(instructions, stacks);
	print_result(stacks);
	instructions_free(instructions);
	stacks_free(stacks);
	return (0);
}
