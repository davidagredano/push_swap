/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:41:13 by dagredan          #+#    #+#             */
/*   Updated: 2025/02/20 20:17:15 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 512

# include <stdlib.h> // free
# include <unistd.h> // read

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

/* Utils */
int		strs_len(char **strs);
int		strs_count_words(char **strs, int len);
void	print_error(void);
char	*get_next_line(int fd);

#endif
