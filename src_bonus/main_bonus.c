/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:09:55 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/21 12:31:24 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../libft/libft.h"

/**
 * Frees the linked list of instructions and its contents.
 */
void	instructions_free(t_list **instructions)
{
	ft_lstclear(instructions, free);
	free(instructions);
}

/**
 * Reads instructions from standard input until no input is received.
 * Stores each instruction in a linked list.
 * Returns the linked list of instructions, or NULL on error.
 */
t_list	**instructions_process(void)
{
	t_list	**instructions;
	t_list	*node;
	char	*line;

	instructions = (t_list **) ft_calloc(1, sizeof(t_list **));
	if (!instructions)
		return (NULL);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		node = ft_lstnew(line);
		if (!node)
		{
			instructions_free(instructions);
			return (NULL);
		}
		ft_lstadd_back(instructions, node);
	}
	return (instructions);
}

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
	instructions = instructions_process();
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
