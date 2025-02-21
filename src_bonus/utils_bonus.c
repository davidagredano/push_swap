/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:40:16 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/21 17:53:21 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * Displays the final sort status: "OK" if the main stack is sorted
 * and the stack 'b' is empty, "KO" otherwise.
 */
void	print_result(t_stack **stacks)
{
	if (stack_is_sorted(stacks[0]) && stacks[1]->len == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

/**
 * Prints an error message to the standard error output (stderr).
 */
void	print_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
}

/**
 * Counts the number of words in a string. A word is defined as a sequence 
 * of non-null, non-whitespace characters separated by whitespace.
 */
static int	str_count_words(char *str)
{
	int		n;

	n = 0;
	while (str && *str != '\0')
	{
		if (*str == ' ')
			str++;
		else
		{
			n++;
			str = ft_strchr(str, ' ');
		}
	}
	return (n);
}

/**
 * Counts the total number of words across all strings in an array.
 */
int	strs_count_words(char **strs, int len)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (i < len)
	{
		n += str_count_words(strs[i]);
		i++;
	}
	return (n);
}

/**
 * Computes the number of strings in an array of strings. Returns the count 
 * of strings in the array, excluding the NULL pointer at the end.
 */
int	strs_len(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
