/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:42:48 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/19 19:02:23 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

// for push, add edge case for if theres nothing on there.
// 			it needs to create a new node

int	new_argc(int argc, t_node *a)
{
	if (argc > 2)
		return (argc - 1);
	argc = 0;
	while (a != NULL)
	{
		a = a->next;
		argc++;
	}
	return (argc);
}

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

	argc = new_argc(argc, a);
	if (argc <= 5)
		small_sort(argc, &a, &b);
	else
		sort(&a, &b);
	// print_list(a, 'a');
	// print_list(a, 'a');
	// print_list(b, 'b');

	free_list(a);
	free_list(b);
	return (0);
}
