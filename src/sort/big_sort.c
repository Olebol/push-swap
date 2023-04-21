/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:34:39 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/21 17:54:26 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_node **a, t_node **b)
{
	int			bit;
	int			len;

	bit = 1;
	while (!is_sorted(*a, *b))
	{
		len = list_size(*a);
		while (len)
		{
			if ((*a)->index & bit)
				rotate(a, "ra\n");
			else
				push(a, b, "pb\n");
			len--;
		}
		bit <<= 1;
		while (*b)
			push(b, a, "pa\n");
	}
}
