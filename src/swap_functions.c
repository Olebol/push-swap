/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/05 17:39:21 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/05 22:04:11 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node *stack)
{
	int		tmp;
	
	if (stack->next == NULL)
		return (0);
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	return (1);
}

int	ss(t_node *a, t_node *b)
{
	if (!swap(a))
		return (0);
	if (!swap(b))
		return (0);
	return (1);
}
