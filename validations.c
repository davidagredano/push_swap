/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:52:28 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/14 15:54:59 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#define ABS_INT_MAX "2147483647"
#define ABS_INT_MIN "2147483648"
#define INT_LIMITS_LEN 10

/**
 * Checks valid number number format. An optional leading positive 
 * or negative sign, followed by one or more digits.
 */
static int	is_valid_nbr(char *str)
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
 * Checks the number is in the int range
 */
static int	is_valid_int(char *str)
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

int	are_valid_arguments(char **arguments)
{
	while (*arguments)
	{
		if (!is_valid_nbr(*arguments))
			return (0);
		if (!is_valid_int(*arguments))
			return (0);
		arguments++;
	}
	return (1);
}
