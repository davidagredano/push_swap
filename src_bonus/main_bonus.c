/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:09:55 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/21 14:38:33 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../libft/libft.h"

/**
 * Checks if the given instruction is valid. Returns 1 if valid, 0 otherwise.
 */
int	instruction_is_valid(char *instruction)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		return (1);
	return (0);
}

/**
 * Frees the linked list of instructions and its contents.
 */
void	instructions_free(t_list **instructions)
{
	ft_lstclear(instructions, free);
	free(instructions);
}

/**
 * Reads instructions from standard input and validates them.
 * Stores each valid instruction in a linked list.
 * Returns the linked list of instructions, or NULL on error.
 */
t_list	**instructions_read(t_list **instructions)
{
	t_list	*node;
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!instruction_is_valid(line))
		{
			free(line);
			instructions_free(instructions);
			return (NULL);
		}
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

/**
 * Initializes the instruction list and reads instructions from standard input.
 * Allocates memory and processes input instructions.
 * Returns the linked list of instructions, or NULL on failure.
 */
t_list	**instructions_load(void)
{
	t_list	**instructions;

	instructions = (t_list **) ft_calloc(1, sizeof(t_list **));
	if (!instructions)
		return (NULL);
	instructions = instructions_read(instructions);
	if (!instructions)
		return (NULL);
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
