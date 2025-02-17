/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:41:13 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/17 18:03:54 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // malloc, free

typedef struct s_stack
{
	char	key;
	int		*val;
	int		len;
	int		top;
	int		bot;
}		t_stack;

/* Arguments */
t_stack	**arguments_process(int argc, char **argv);

/* Stacks */
t_stack	**stacks_init(char **arguments);
void	stacks_free(t_stack **stacks);

/* Stack */
t_stack	*stack_get_by_key(char key, t_stack **stacks);
int		stack_is_sorted(t_stack *stack);
int		stack_is_sequential(t_stack *stack);
int		stack_find_start(t_stack *stack);

/* Operations */
void	swap(char key, t_stack **stacks);
void	push(char key, t_stack **stacks);
void	rotate(char key, t_stack **stacks);
void	reverse_rotate(char key, t_stack **stacks);

/* Sort few */
void	sort_two(char key, t_stack **stacks);
void	sort_three(char key, t_stack **stacks);

/* Utils */
int		strs_len(char **strs);
int		strs_count_words(char **strs, int len);
void	print_error(void);

/* Debug */
void	arguments_print(char **arguments);
void	stacks_print(t_stack **stacks);

#endif
