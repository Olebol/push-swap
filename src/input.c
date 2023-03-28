/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:42:50 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/28 19:39:48 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**make_strings(int argc, char **argv)
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

static void	ft_free(char **ptr_arr)
{
	int		i;

	i = 0;
	while (ptr_arr[i])
	{
		free(ptr_arr[i]);
		i++;
	}
	free(ptr_arr);
}

int	args_to_list(char **strings, t_node *node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (strings[i] != NULL)
	{
		if (!ft_err_atoi(strings[i], &node->value))
		{
			ft_free(strings);
			return (0);
		}
		tmp = create_new_node();
		if (!tmp)
		{
			ft_free(strings);
			return (0);
		}
		node->next = tmp;
		node = node->next;
		i++;
	}
	ft_free(strings);
	return (1);
}
