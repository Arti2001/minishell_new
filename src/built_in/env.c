/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:19:28 by amysiv            #+#    #+#             */
/*   Updated: 2024/10/03 17:17:50 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_env *env)
{
	while (env != NULL)
	{
		if (env->value != NULL)
			printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
	return (0);
}