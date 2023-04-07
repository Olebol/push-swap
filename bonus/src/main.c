/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 22:02:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/07 19:20:51 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "checker.h"

	// check input, make list
	// get_next_line with buffer size 3
	// 		or put all input into one string
	// execute command one by one
	// check if sorted

void	run_command(t_node *a, t_node *b, char *cmd)
{
	(void) b;
	if (!ft_strncmp(cmd, "sa\n", 3))
		swap(&a, NULL);
	if (!ft_strncmp(cmd, "ra\n", 3))
		rotate(&a, NULL);
}

void	execute_rules(t_node *a, t_node *b)
{
	char	*cmd;
	(void) b;

	cmd = get_next_line(0);
	while (cmd)
	{
		write(1, cmd, 3);
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

	// atexit(check_for_leaks);

	b = NULL;
	a = create_new_node();
	if (!a)
		return (write(2, ERROR, sizeof(ERROR)), 1);
	if (argc < 2)
		return (free_list(a), 1);
	if (!check_input(argc, argv, a))
		return (free_list(a), 1);

	print_list(a, 'a');
	execute_rules(a, b);
	if (is_sorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	print_list(a, 'a');
	free_list(a);
	free_list(b);
	return (0);
}