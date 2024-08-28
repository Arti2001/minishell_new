/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:19:28 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/27 16:03:48 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_env *env)
{
	while(env != NULL)
	{
		if (check_equel(env->content) == 1 )
			ft_putendl_fd(env->content, 1);
		env = env->next;
	}
}