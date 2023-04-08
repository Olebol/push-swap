/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:42:48 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/08 13:37:32 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

// for push, add edge case for if theres nothing on there.
// 			it needs to create a new node

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	// atexit(check_for_leaks);

	b = NULL;
	a = create_new_node();
	if (!a)
		return (write(2, ERROR, sizeof(ERROR)), 1);
	if (argc < 2)
		return (free_list(a), 1);
	if (!check_input(argc, argv, a))
		return (free_list(a), 1);

	// print_list(a, 'a');
	// print_list(b, 'b');
	bubble_sort(&a);
	print_list(a, 'a');
	// print_list(a, 'a');
	// print_list(b, 'b');

	free_list(a);
	free_list(b);
	return (0);
}
