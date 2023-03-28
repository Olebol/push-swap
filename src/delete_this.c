/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delete_this.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 19:13:39 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/28 19:20:53 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>

void	print_list(t_node *node)
{
	while (node->next != NULL)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
}

void	check_for_leaks(void)
{
	write(1, "\n\n\n", 3);
	system("leaks -q push_swap");
}
