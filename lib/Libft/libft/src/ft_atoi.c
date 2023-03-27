/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 17:06:26 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/27 23:30:07 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	The atoi() function converts the initial portion of the string
		pointed to by nptr to int. The converted value or 0 on error.
*/

#include <limits.h>
#include "libft.h"

int	ft_atoi(const char *str, long *result)
{
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	*result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		*result = *result * 10 + (str[i] - '0');
		i++;
	}
	*result *= sign;
	if (*result < INT_MIN || *result > INT_MAX)
		return (0);
	return (1);
}

// #include "libft.h"
// int	main()
// {
// 	const char	str[] = "2147483649";

// 	printf("%d\n", ft_atoi(str));

// 	printf("%d", atoi(str));
// }