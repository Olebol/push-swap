/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:42:48 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/27 23:29:15 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

#define INVALID_ARGS_MSG "\n\t\t\tInvalid arguments\n\n\
./push_swap \"[integers]\"\tor\t./push_swap [int] [int] [int]\n\n"

int	input_checker(int argc, char **argv, long *arr)
{
	int		i;
	char	**numbers;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (numbers == NULL)
			return (0);
	}
	else
		numbers = argv + 1;
	i = 0;
	while (numbers[i] != NULL)
	{
		if (!ft_atoi(numbers[i], &arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	long	numbers[11];

	if (!input_checker(argc, argv, numbers))
		return (1);
	else
	{
		for (int i = 0; i <= 11; i++)
			printf("%ld\n", numbers[i]);
	}
	return (0);
}

// "-1 0 1 100 2147483647 -2147483648 -30000000000 300000000000 abc 1abc abc1"
