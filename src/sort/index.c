/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 22:55:57 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/20 23:34:59 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	increment_index(int value, t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->value > value)
			tmp->index++;
		tmp = tmp->next;
	}
}

void	index_list(t_node **a)
{
	t_node		*tmp;

	tmp = *a;
	while (tmp)
	{
		increment_index(tmp->value, a);
		tmp = tmp->next;
	}
}

