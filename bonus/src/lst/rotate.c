/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/05 22:04:19 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/07 19:22:05 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_node **stack)
{
	t_node		*first;
	t_node		*tmp;

	first = *stack;
	if (first == NULL || first->next == NULL)
		return ;
	*stack = first->next;
	tmp = first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
}

void	rr(t_node *a, t_node *b)
{
	rotate(&a);
	rotate(&b);
}

void	reverse(t_node **stack)
{
	t_node		*first;
	t_node		*tmp;

	first = *stack;
	if (first == NULL || first->next == NULL)
		return ;
	tmp = first;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	*stack = tmp->next;
	tmp->next->next = first;
	tmp->next = NULL;
}

void	rrr(t_node *a, t_node *b)
{
	reverse(&a);
	reverse(&b);
}
