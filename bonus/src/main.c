/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 22:02:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/08 13:08:45 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "checker.h"

void	run_command(t_node **a, t_node **b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		swap(a);
	else if (!ft_strcmp(cmd, "sb\n"))
		swap(b);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(cmd, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(cmd, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(cmd, "rra\n"))
		reverse(a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		reverse(b);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b);
}

void	execute_rules(t_node **a, t_node **b)
{
	char	*cmd;
	(void) b;

	cmd = get_next_line(0);
	while (cmd)
	{
		run_command(a, b, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
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

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	atexit(check_for_leaks);

	b = NULL;
	a = create_new_node();
	if (!a)
		return (write(2, ERROR, sizeof(ERROR)), 1);
	if (argc < 2)
		return (free_list(a), 1);
	if (!check_input(argc, argv, a))
		return (free_list(a), 1);

	execute_rules(&a, &b);
	if (is_sorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	free_list(a);
	free_list(b);
	return (0);
}
