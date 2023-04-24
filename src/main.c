/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:42:48 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/24 18:32:48 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	sort(int argc, t_node **a, t_node **b)
{
	index_list(a);
	argc = new_argc(argc, *a);
	if (argc <= 5)
		small_sort(argc, a, b);
	else
		big_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	b = NULL;
	a = create_new_node();
	if (!a)
		return (write(2, ERROR, sizeof(ERROR)), 1);
	if (argc < 2)
		return (free_list(a), 1);
	if (!check_input(argc, argv, a))
		return (free_list(a), 1);
	if (is_sorted(a, b))
		return (free_list(a), free_list(b), 0);
	sort(argc, &a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
