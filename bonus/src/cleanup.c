/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 20:54:15 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/07 18:51:17 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_list(t_node *node)
{
	if (node == NULL)
		return ;
	while (node->next != NULL)
	{
		free(node);
		node = node->next;
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
