/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:52:28 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/23 17:03:33 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

/**
 * Checks if the number is within the int range.
 */
static int	argument_is_valid_int(char *str)
{
	int		negative;

	negative = 0;
	if (*str == '-')
		negative = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) < INT_LIMITS_LEN)
		return (1);
	else if (ft_strlen(str) > INT_LIMITS_LEN)
		return (0);
	else
	{
		if (negative)
			return (ft_strcmp(str, ABS_INT_MIN) <= 0);
		else
			return (ft_strcmp(str, ABS_INT_MAX) <= 0);
	}
}

/**
 * Checks if the argument is a valid number format. A valid number consists 
 * of an optional leading '+' or '-' sign, followed by one or more digits.
 */
static int	argument_is_valid_nbr(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

/**
 * Checks if all arguments are valid. A valid argument is a string 
 * representation of an integer within the range of a signed int.
 */
int	arguments_validate(char **arguments)
{
	while (*arguments)
	{
		if (!argument_is_valid_nbr(*arguments)
			|| !argument_is_valid_int(*arguments))
		{
			return (0);
		}
		arguments++;
	}
	return (1);
}

/**
 * Extracts and tokenizes words from the program arguments.
 * Allocates and populates an array of strings, handling both multi-word
 * and standalone arguments.
 */
char	**arguments_tokenize(int argc, char **argv)
{
	char	**arguments;
	int		count;
	char	*token;
	int		i;
	int		j;

	count = strs_count_words(argv, argc);
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

/**
 * Checks if all preprocessed arguments contain at least one digit.
 */
int	arguments_prevalidate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]))
				break ;
			j++;
		}
		if (!ft_isdigit(argv[i][j]))
			return (0);
		i++;
	}
	return (1);
}
