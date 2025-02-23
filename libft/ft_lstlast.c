/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:42:08 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/23 02:26:12 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * Returns the last element of the list.
 * Traverses the list until the last element, which has a NULL next pointer.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
