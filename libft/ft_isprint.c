/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:58:25 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/23 02:25:28 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if a character is printable (32-126).
 * Returns 1 if character is printable, 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
