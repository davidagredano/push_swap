/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:32:56 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/21 17:59:33 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * Executes each instruction from the list, modifying the stacks in place.
 */
void	instructions_execute(t_list **instructions, t_stack **stacks)
{
	char	*instruction;
	t_list	*ptr;

	ptr = *instructions;
	while (ptr)
	{
		instruction = (char *) ptr->content;
		if (instruction[0] == 's')
			swap(instruction[1], stacks);
		else if (instruction[0] == 'p')
			push(instruction[1], stacks);
		else if (instruction[0] == 'r' && ft_strlen(instruction) == 3)
			rotate(instruction[1], stacks);
		else if (instruction[0] == 'r' && ft_strlen(instruction) == 4)
			reverse_rotate(instruction[2], stacks);
		ptr = ptr->next;
	}
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
