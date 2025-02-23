/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:08:09 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/23 02:24:41 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * Fills a block of memory with zeros.
 * Returns nothing (void).
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
