/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:17:16 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/14 19:34:27 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/**
 * Allocates and populates an array of strings by tokenizing each word
 * found in the program arguments.
 */
static char	**get_unique_arguments(int argc, char **argv)
{
	char	**arguments;
	int		count;
	char	*token;
	int		i;
	int		j;

	count = count_words_arr(argc, argv);
	arguments = (char **) ft_calloc((count + 1), sizeof(char *));
	if (!arguments)
		return (NULL);
	i = 0;
	j = 0;
	while (i < argc)
	{
		token = ft_strtok(argv[i], " ");
		while (token)
		{
			arguments[j++] = token;
			token = ft_strtok(NULL, " ");
		}
		i++;
	}
	return (arguments);
}

int	main(int argc, char **argv)
{
	char		**arguments;
	t_stacks	*stacks;

	if (argc == 1)
		return (1);
	arguments = get_unique_arguments(argc - 1, argv + 1);
	if (!arguments)
		return (1);
	if (!are_valid_arguments(arguments))
	{
		free(arguments);
		return (1);
	}
	stacks = stacks_init(arguments);
	if (!stacks)
	{
		free(arguments);
		return (1);
	}
	if (!check_unique_values(stacks))
	{
		free(stacks->a);
		free(stacks->b);
		free(stacks);
		return (1);
	}
	stacks_print(stacks);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (0);
}
