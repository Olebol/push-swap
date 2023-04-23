/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/05 22:04:19 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/19 19:45:13 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack, char *print)
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
	first->previous = tmp;
	first->next = NULL;
	(*stack)->previous = NULL;
	if (print)
		write(1, print, 3);
}

void	rr(t_node **a, t_node **b, int print)
{
	rotate(a, NULL);
	rotate(b, NULL);
	if (print)
		write(1, "rr\n", 3);
}

void	reverse(t_node **stack, char *print)
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
	(*stack)->previous = NULL;
	(*stack)->next->previous = *stack;
	if (print)
		write(1, print, 4);
}

void	rrr(t_node **a, t_node **b, int print)
{
	reverse(a, NULL);
	reverse(b, NULL);
	if (print)
		write(1, "rrr\n", 4);
}
