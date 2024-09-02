/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:58:32 by amysiv            #+#    #+#             */
/*   Updated: 2024/09/02 18:09:29 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_node(t_env *node)
{
	if (node)
	{
		free(node->content);
		free(node->name);
		free(node->value);
		free(node);
	}
}

int	find_unset(t_env **env, char *str)
{
	t_env	*tmp;
	t_env	*current;
	
	if (!env || !(*env))
		return (0);
	tmp = NULL;
	if (ft_strncmp(str, (*env)->name, ft_strlen((*env)->name)) == 0)
	{
		tmp = (*env)->next;
		free_node(*env);
	printf("here\n");
		(*env) = tmp;
		return (1); 
	}
	current = *env;
	while(current->next != NULL)
	{
		if (ft_strncmp(str, current->next->name, ft_strlen(current->next->name)) == 0)
		{
			tmp = current->next->next;
			free(current->next);
			current->next = tmp;
			return (1);
		}
		current = current->next;
	}
	return (0);
}


int	ft_unset(t_env **env, char **arg)
{
	int	i;

	i = 1;
	if (arg[i] == NULL)
		return (0);	
	while (arg[i])
	{
		find_unset(env, arg[i]);
		i++;
	}
	return (0);
}