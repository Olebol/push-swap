/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_and_push.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/05 17:39:21 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/20 16:47:23 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **first, char *print)
{
	t_node	*second;

	if (first == NULL || (*first)->next == NULL)
		return ;
	second = (*first)->next;
	(*first)->next = second->next;
	second->next = *first;
	*first = second;
	second = (*first)->next;
	(*first)->previous = NULL;
	second->previous = *first;
	second->next->previous = second;
	if (print)
		write(1, print, 3);
}

void	ss(t_node **a, t_node **b, int print)
{
	swap(a, NULL);
	swap(b, NULL);
	if (print)
		write(1, "ss\n", 3);
}

void	push(t_node **src, t_node **dst, char *print)
{
	t_node	*second_node;

	if (*src == NULL)
		return ;
	second_node = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = second_node;
	if (*dst)
		(*dst)->previous = NULL;
	if (*src)
		(*src)->previous = NULL;
	if ((*dst)-> next != NULL)
		(*dst)->next->previous = *dst;
	if (print)
		write(1, print, 3);
}
