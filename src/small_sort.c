/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/08 12:57:42 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/10 21:36:57 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_node **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		swap(a, "sa\n");
		reverse(a, "rra\n");
		return ;
	}
	if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value)
		reverse(a, "rra\n");
	if ((*a)->value > (*a)->next->next->value)
		rotate(a, "ra\n");
	if ((*a)->next->value > (*a)->next->next->value)
		reverse(a, "rra\n");
	if ((*a)->value > (*a)->next->value)
		swap(a, "sa\n");
	if ((*a)->value > (*a)->next->next->value)
		rotate(a, "ra\n");
}

void	four_sort(t_node **a, t_node **b)
{
	t_node	*tmp;
	int		low;

	tmp = *a;
	low = tmp->value;
	while (tmp->next != NULL)
	{
		if (tmp->next->value < low)
			low = tmp->next->value;
		tmp = tmp->next;
	}
	if (tmp->value == low)
		reverse(a, "rra\n");
	else
	{
		while ((*a)->value != low)
			rotate(a, "ra\n");
	}
	push(a, b, "pb\n");
	three_sort(a);
	push(b, a, "pa\n");
}

void	five_sort(t_node **a, t_node **b)
{
	t_node	*tmp;
	int		low;

	tmp = *a;
	low = tmp->value;
	while (tmp->next != NULL)
	{
		if (tmp->next->value < low)
			low = tmp->next->value;
		tmp = tmp->next;
	}
	if (tmp->value == low)
		reverse(a, "rra\n");
	else
	{
		while ((*a)->value != low)
			rotate(a, "ra\n");
	}
	push(a, b, "pb\n");
	four_sort(a, b);
	push(b, a, "pa\n");
}

void	small_sort(int argc, t_node **a, t_node **b)
{
	if (argc == 3)
		three_sort(a);
	if (argc == 4)
		four_sort(a, b);
	if (argc == 5)
		five_sort(a, b);
}
