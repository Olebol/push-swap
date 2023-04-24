/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:42:55 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/24 15:55:09 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../../lib/libft/include/libft.h"
# define ERROR "Error\n"

typedef struct s_node{
	int				value;
	struct s_node	*next;
}	t_node;

//		~ input.c

t_node	*create_new_node(void);
int		check_input(int argc, char **argv, t_node *stack_a);

//		~ cleanup.c

void	free_list(t_node *node);
void	free_ptr_arr(char **ptr_arr);

//		~ swap_and_push_functions.c

void	swap(t_node **first);
void	ss(t_node **a, t_node **b);
void	push(t_node **src, t_node **dst);

//		~ rotate_functions.c

void	rotate(t_node **stack);
void	rr(t_node **a, t_node **b);
void	reverse(t_node **stack);
void	rrr(t_node **a, t_node **b);

#endif
