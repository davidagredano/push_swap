/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:41:13 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/23 17:01:21 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define ABS_INT_MAX "2147483647"
# define ABS_INT_MIN "2147483648"
# define INT_LIMITS_LEN 10

# include "libft.h"

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
int		arguments_prevalidate(int argc, char **argv);
char	**arguments_tokenize(int argc, char **argv);
int		arguments_validate(char **arguments);

/* Stacks */
t_stack	**stacks_init(char **arguments);
void	stacks_free(t_stack **stacks);
int		stack_is_sorted(t_stack *stack);

/* Instruction */
t_list	**instructions_load(void);
t_list	**instructions_read(t_list **instructions);
void	instructions_free(t_list **instructions);
int		instruction_is_valid(char *instruction);
void	instructions_execute(t_list **instructions, t_stack **stacks);

/* Operations */
void	swap(char key, t_stack **stacks);
void	push(char key, t_stack **stacks);
void	rotate(char key, t_stack **stacks);
void	reverse_rotate(char key, t_stack **stacks);

/* Utils */
int		strs_len(char **strs);
int		strs_count_words(char **strs, int len);
void	print_error(void);
void	print_result(t_stack **stacks);

#endif
