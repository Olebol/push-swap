/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:42:48 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/05 17:29:56 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int check_input(int argc, char **argv, t_node *stack_a)
{
	char	**strings;

	strings = make_strings(argc, argv);
	if (!strings)
		return (write(2, ERROR, sizeof(ERROR)), 0);
	if (!args_to_list(strings, stack_a))
	{
		if (argc == 2)
			ft_free(strings);
		return (write(2, ERROR, sizeof(ERROR)), 0);
	}
	if (argc == 2)
		ft_free(strings);
	if (!check_double(stack_a))
		return (write(2, ERROR, sizeof(ERROR)), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	atexit(check_for_leaks);

	stack_a = create_new_node();
	if (!stack_a)
		return (write(2, ERROR, sizeof(ERROR)), 1);
	
	if (argc < 2)
		return (free_list(stack_a), 1);
	if (!check_input(argc, argv, stack_a))
		return (free_list(stack_a), 1);

	print_list(stack_a);
	free_list(stack_a);
	return (0);
}
