/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydidenko <ydidenko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/22 17:42:25 by ydidenko      #+#    #+#                 */
/*   Updated: 2024/08/22 17:42:44 by ydidenko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"

static long	handle_overflow(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

long	ft_atol(const char *str)
{
	int			sign;
	long		total;
	char		*it_str;

	total = 0;
	sign = 1;
	it_str = (char *)str;
	while ((*it_str >= 9 && *it_str <= 13) || *it_str == 32)
		it_str++;
	if (*it_str == '-' || *it_str == '+')
	{
		if (*it_str == '-')
			sign = -1;
		it_str++;
	}
	while (*it_str >= '0' && *it_str <= '9')
	{
		if (total > (LONG_MAX - (*it_str - '0')) / 10)
			return (handle_overflow(sign));
		total = (total * 10) + (*it_str - '0');
		it_str++;
	}
	return (total * sign);
}
