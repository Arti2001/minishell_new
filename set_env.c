/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:18:51 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/28 14:58:59 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value(char *content)
{
	char *value;
	if (check_equel(content) == 0)
		return (NULL);
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
	if (content == NULL)
		return (NULL);
	if (content[i] == '=')
		return (content);
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

void	ch_env_value(t_env *env, char *var_name, char *new)
{
	char *path;
	
	path = new;
	while (env != NULL)
	{
		if (ft_strncmp(env->name, var_name, ft_strlen(var_name)) == 0)
		{
			free(env->value);
			env->value = ft_strdup(path);
			if (env->value == NULL)
				return ;
			concat_new_val(env, path);
		}
		env = env->next;
	}
}

void	concat_new_val(t_env *node,char *new_val)
{
	size_t		i;
	size_t		j;
	size_t		full_len;
	char		*new;
	
	i = 0;
	j = 0;
	full_len = ft_strlen(node->name) + ft_strlen(new_val) + 1;
	new = (char *)malloc(sizeof(char) * full_len + 1);
	while (i <ft_strlen(node->name) + 1) 
	{
		new[i] = node->content[i];
		i++;
	}
	while (new_val[j])
	{
		new[i] = new_val[j];
		i++;
		j++;
	}
	new[i] = '\0';
	node->content = new;
}