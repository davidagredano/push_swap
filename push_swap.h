/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:41:13 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/14 23:42:32 by dagredan         ###   ########.fr       */
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

/* Arguments */
t_stacks	*arguments_process(int argc, char **argv);

/* Stacks */
t_stacks	*stacks_init(char **arguments);
void		stacks_free(t_stacks *stacks);

/* Utils */
int			strs_count_words(char **strs, int len);
int			strs_len(char **strs);

/* Debug */
void		arguments_print(char **arguments);
void		stacks_print(t_stacks *stacks);

#endif
