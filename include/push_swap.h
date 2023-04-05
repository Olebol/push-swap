/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:42:55 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/05 17:03:42 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/Libft/libft/lib/libft.h"
# define ERROR "Error\n"

typedef struct s_node{
	int				value;
	struct s_node	*next;
}	t_node;

//		~ input.c

char	**make_strings(int argc, char **argv);
t_node	*create_new_node(void);
int		args_to_list(char **strings, t_node *node);
int		check_double(t_node *checker_node);

//		~ delete_this.c

void	print_list(t_node *node);
void	check_for_leaks(void);

//		~ cleanup.c

void	free_list(t_node *node);
void	ft_free(char **ptr_arr);

#endif