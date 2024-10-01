/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:18:51 by amysiv            #+#    #+#             */
/*   Updated: 2024/09/06 13:24:04 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value(char *content)
{
	char *value;
	
	value = ft_strchr(content, '=');
	if (value  == NULL)
		return (NULL);
	else if (*(value + 1) == '\0')
		return (ft_strdup(""));
	else	
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
	if (new == NULL)
		return;
	while (env != NULL)
	{
		if (ft_strncmp(env->name, var_name, ft_strlen(var_name)) == 0)
		{
			if (env->value != NULL)
				free(env->value);
			env->value = ft_strdup(new);
			return ;
		}
		env = env->next;
	}
}
char *key_val_join(t_env *env)
{
	char *equel_char;
	char *full_str;
	
	equel_char= ft_strjoin(env->name, "=");
	full_str = ft_strjoin(equel_char, env->value);
	free(equel_char);
	return (full_str);
}

/*This function turns  our environment back into a double array.
To do : during copying nodes into a double array, we MUST free the node we are copying values from */
char **back_to_array(t_env **env)
{
	char **ptr_env;
	int		size;
	int		count;

	count = 0;
	size = ft_lst_size(*env);
	ptr_env= (char **)malloc(sizeof(char *) * size + 1);
	while ((*env) != NULL)
	{
		(*env)->content = key_val_join(*env);
		ptr_env[count] = (*env)->content;
		(*env) = (*env)->next;
	}
	return (ptr_env);
}