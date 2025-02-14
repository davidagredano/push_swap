/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:41:13 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/14 19:32:26 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // malloc, free

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	a_len;
	int	b_len;
}			t_stacks;

/* Validations */
int			are_valid_arguments(char **arguments);
int			check_unique_values(t_stacks *stacks);

/* Stack */
t_stacks	*stacks_init(char **arguments);

/* Utils */
int			count_words(char *str);
int			count_words_arr(int argc, char **argv);

/* Log */
void		stacks_print(t_stacks *stacks);
void		print_arguments(char **strs);

#endif
