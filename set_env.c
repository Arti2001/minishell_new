/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:18:51 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/16 17:15:57 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value(char *content)
{
	char *value;
	
	value = ft_strchr(content, '=');
	value = ft_strdup(++value);
	if (value == NULL)
		return (NULL);
	return (value);
}

char *get_key(char *content)
{
	int		i;
	char	*key;

	i = 0;
	while(content[i] != '\0')
	{
		if (content[i] == '=')
			break;
		i++;
	}
	key = (char *)malloc(sizeof(char) * i + 1);
	key[i--] = '\0'; 
	while (i >= 0)
	{
		key[i] = content[i];
		i--;
	}
	return (key);
}


void	append_node(t_env **head_env, char *content)
{
	t_env	*new_node;

	new_node = ft_env_lstnew(content);
	if (new_node == NULL)
		return ;
	if (*head_env == NULL)
		*head_env = new_node; 
	else
		ll_addback(head_env, new_node);
}

t_env	*set_env(char **env)
{
	int		i;
	t_env	*head_env;

	i = 0;
	head_env = NULL;
	while (env[i])
	{
		append_node(&head_env, env[i]);
		i++;
	}
	return (head_env);
}