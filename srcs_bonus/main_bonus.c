/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:09:55 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/23 17:02:06 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

/**
 * Processes the program arguments, tokenizes them, validates them,
 * and initializes a new stacks structure with them. Returns the
 * stacks structure or NULL if any step fails.
 */
static t_stack	**arguments_process(int argc, char **argv)
{
	t_stack	**stacks;
	char	**arguments;

	if (!arguments_prevalidate(argc - 1, argv + 1))
		return (NULL);
	arguments = arguments_tokenize(argc - 1, argv + 1);
	if (!arguments)
		return (NULL);
	if (!arguments_validate(arguments))
	{
		free(arguments);
		return (NULL);
	}
	stacks = stacks_init(arguments);
	if (!stacks)
	{
		free(arguments);
		return (NULL);
	}
	free(arguments);
	return (stacks);
}

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
