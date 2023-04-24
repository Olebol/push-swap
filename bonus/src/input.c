/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:42:50 by opelser       #+#    #+#                 */
/*   Updated: 2023/04/24 17:51:34 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*create_new_node(void)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->value = 0;
	return (new_node);
}

static char	**make_strings(int argc, char **argv)
{
	char	**numbers;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (numbers == NULL)
			return (NULL);
	}
	else
		numbers = argv + 1;
	return (numbers);
}

static int	args_to_list(char **strings, t_node *node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (strings[i + 1] != NULL)
	{
		if (!ft_err_atoi(strings[i], &node->value))
			return (0);
		tmp = create_new_node();
		if (!tmp)
			return (0);
		node->next = tmp;
		node = node->next;
		i++;
	}
	if (!ft_err_atoi(strings[i], &node->value))
		return (0);
	return (1);
}

static int	check_double(t_node *checker_node)
{
	int		checker_value;
	t_node	*node;

	while (checker_node->next != NULL)
	{
		checker_value = checker_node->value;
		node = checker_node->next;
		while (node != NULL)
		{
			if (checker_value == node->value)
				return (0);
			node = node->next;
		}
		checker_node = checker_node->next;
	}
	return (1);
}

int	check_input(int argc, char **argv, t_node *stack_a)
{
	char	**strings;

	strings = make_strings(argc, argv);
	if (!strings)
		return (write(2, ERROR, sizeof(ERROR)), 0);
	if (!args_to_list(strings, stack_a))
	{
		if (argc == 2)
			free_ptr_arr(strings);
		return (write(2, ERROR, sizeof(ERROR)), 0);
	}
	if (argc == 2)
		free_ptr_arr(strings);
	if (!check_double(stack_a))
		return (write(2, ERROR, sizeof(ERROR)), 0);
	return (1);
}
