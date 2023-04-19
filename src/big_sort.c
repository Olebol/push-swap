/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:34:39 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/19 19:27:53 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check how many moves it takes for one val right place in b

int	push_b_moves(int val, t_node *b)
{
	int		i;

	i = 0;
	while (b != NULL && val < b->value)
	{
		b = b->next;
		i++;
	}
	return (i);
}

void	execute_commands(int a_moves, int b_moves, t_node **a, t_node **b)
{
	int		i;

	i = 0;
	while (a_moves)
	{
		rotate(a, "ra\n");
		a_moves--;
	}
	while (i < b_moves)
	{
		rotate(b, "rb\n");
		i++;
	}
	push(a, b, "pb\n");
	while (b_moves)
	{
		reverse(b, "rrb\n");
		b_moves--;
	}
}

void	calculate(t_node **a, t_node **b)
{
	t_node *tmp;
	int		least_moves;
	int		least_i;
	int		i;
	int		tmp_val;

	tmp = (*a);
	i = 0;
	least_moves = -1;
	while (tmp != NULL)
	{
		tmp_val = push_b_moves((*a)->value, (*b));
		if ((tmp_val + i) < least_moves || least_moves == -1)
		{
			least_moves = tmp_val;
			least_i = i;
		}
		tmp = tmp->next;
		i++;
	}
	execute_commands(least_i, least_moves, a, b);
}

int		list_size(t_node *a)
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

void	sort(t_node **a, t_node **b)
{
	push(a, b, "pb\n");
	push(a, b, "pb\n");
	while (list_size((*a)))
		calculate(a, b);
	while (list_size((*b)))
		push(b, a, "pa\n");
}