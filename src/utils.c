/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 17:38:28 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/24 15:43:37 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_node *a)
{
	int		i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int	new_argc(int argc, t_node *a)
{
	if (argc > 2)
		return (argc - 1);
	return (list_size(a));
}

int	is_sorted(t_node *a, t_node *b)
{
	if (b != NULL)
		return (0);
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

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
