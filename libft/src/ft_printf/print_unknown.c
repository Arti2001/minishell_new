/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_unknown.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydidenko <ydidenko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 18:31:51 by ydidenko      #+#    #+#                 */
/*   Updated: 2024/09/04 16:18:40 by ydidenko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unknown(t_data *data, va_list args)
{
	(void)args;
	ft_putchar_fd('%', 1);
	ft_putchar_fd(*data->fmt, 1);
	return (2);
}
