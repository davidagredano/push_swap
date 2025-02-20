/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:41:13 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/20 13:32:28 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // free

typedef struct s_stack
{
	char	key;
	int		*val;
	int		len;
	int		top;
	int		bot;
	int		next_move;
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
int		stack_median_value(t_stack *stack);

/* Operations */
void	swap(char key, t_stack **stacks);
void	push(char key, t_stack **stacks);
void	rotate(char key, t_stack **stacks);
void	reverse_rotate(char key, t_stack **stacks);

/* Batch Operations */
void	batch_push_selective(char key, t_stack **stacks, int cut_off_value);
void	batch_push(char key, t_stack **stacks, int values_to_leave);
void	batch_insert_a(t_stack **stacks);
void	put_top_double(int a_index, int b_index, t_stack **stacks);
void	put_top(int index, char key, t_stack **stacks);

/* Sort */
void	find_next_move(t_stack **stacks);

/* Utils */
int		strs_len(char **strs);
int		strs_count_words(char **strs, int len);
void	print_error(void);
int		min(int a, int b);

/* Debug */
void	print_arguments(char **arguments);
void	print_stacks(t_stack **stacks, char *message);

#endif
