/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:42:55 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/21 17:27:36 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/libft/include/libft.h"
# define ERROR "Error\n"

typedef struct s_node{
	int				value;
	int				index;
	struct s_node	*previous;
	struct s_node	*next;
}	t_node;

//		~ input.c

char	**make_strings(int argc, char **argv);
t_node	*create_new_node(void);
int		args_to_list(char **strings, t_node *node);
int		check_double(t_node *checker_node);
int		check_input(int argc, char **argv, t_node *stack_a);

//		~ delete_this.c

void	print_list(t_node *node, char stack);
void	check_for_leaks(void);

//		~ cleanup.c

void	free_list(t_node *node);
void	free_ptr_arr(char **ptr_arr);

//		~ swap_and_push_functions.c

void	swap(t_node **first, char *print);
void	ss(t_node *a, t_node *b, int print);
void	push(t_node **src, t_node **dst, char *print);

//		~ rotate_functions.c

void	rotate(t_node **stack, char *print);
void	rr(t_node *a, t_node *b, int print);
void	reverse(t_node **stack, char *print);
void	rrr(t_node *a, t_node *b, int print);

//		~ small_sort.c

void	small_sort(int argc, t_node **a, t_node **b);

//		~ big_sort.c

void	big_sort(t_node **a, t_node **b);

//		~ utils.c

int		is_sorted(t_node *a, t_node *b);
int		new_argc(int argc, t_node *a);
int		list_size(t_node *a);

//		~ index.c

void	index_list(t_node **a);

#endif