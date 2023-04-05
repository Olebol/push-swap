/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/05 22:04:19 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/05 22:04:34 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_node **stack)
{
	t_node		*first;
	t_node		*tmp;

	if ((*stack)->next == NULL)
		return (0);
	first = *stack;
	tmp = first;
	*stack = first->next;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	return (1);
}

int rr(t_node *a, t_node *b)
{
	if (!rotate(&a))
		return (0);
	if (!rotate(&b))
		return (0);
	return (1);
}

int reverse(t_node **stack)
{
	t_node		*first;
	t_node		*tmp;

	if ((*stack)->next == NULL)
		return (0);
	first = *stack;
	tmp = first;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	*stack = tmp->next;
	tmp->next->next = first;
	tmp->next = NULL;
	return (1);
}

int rrr(t_node *a, t_node *b)
{
	if (!reverse(&a))
		return (0);
	if (!reverse(&b))
		return (0);
	return (1);
}