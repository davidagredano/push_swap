/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:40:16 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/12 18:34:27 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	count_words(char *str)
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

int	count_words_arr(int argc, char **argv)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (i < argc)
	{
		n += count_words(argv[i]);
		i++;
	}
	return (n);
}
