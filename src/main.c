/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:42:48 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/21 17:51:11 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	print_index(t_node *a)
{
	while (a)
	{
		printf("index:\t\t%d\t\t[%d]\n", a->index, a->value);
		a = a->next;
	}
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

	index_list(&a);
	// print_index(a);
	if (!is_sorted(a, b))
	{
		argc = new_argc(argc, a);
		if (argc <= 5)
			small_sort(argc, &a, &b);
		else
			big_sort(&a, &b);
	}
	free_list(a);
	free_list(b);
	return (0);
}
