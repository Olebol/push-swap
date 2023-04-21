/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 20:54:15 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/07 15:58:20 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *node)
{
	t_node	*tmp;

	if (node == NULL)
		return ;
	while (node->next != NULL)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(node);
}

void	free_ptr_arr(char **ptr_arr)
{
	int		i;

	i = 0;
	while (ptr_arr[i])
	{
		free(ptr_arr[i]);
		i++;
	}
	free(ptr_arr);
}
