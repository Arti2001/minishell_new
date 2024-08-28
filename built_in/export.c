/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:55:48 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/28 15:08:33 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_var_syntax(char *str)
{
	int		i;

	i = 0;
	if (ft_isdigit(str[i]) == 1)
	{
		printf("bash: export: '%s': not a valid identifier\n", str);
		return (0);
	}
	while(str[i])
	{
		if (ft_isalpha(str[i]) == 1 || str[i] == '_')
			i++;
		else
		{
			printf("bash: export: '%s': not a valid identifier\n", str);
			return (0);
		}
	}
	return (1);
}
int	check_equel(char *str)
{
	while (*str)
	{
		if (*(str + 0) == '=')
			return (1);
		str++;
	}	
	return (0);
}

int	is_exist(t_env *env, char *name)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->name, name, ft_strlen(name)) == 0)
			return (1);
		env = env->next;
	}
	return (0);
}

void	print_export_env(t_env *env)
{
		while (env != NULL)
		{
			if (check_equel(env->content) == 1)
				printf("declare -x %s=\"%s\"\n", env->name, env->value);
			else
				printf("declare -x %s\n", env->content);
			env = env->next;
		}
	return ;
}
void	ft_export(t_env *env, char **commands)
{
	t_env	*new_node;
	char	*name;
	char 	*value;
	
	if (env == NULL)
		return ;
	name = get_key(*(commands + 1));
	if (*(commands + 1) == NULL)
	{
		print_export_env(env);
		return ;
	}
	if (is_exist(env, name) && check_equel(*(commands + 1)))
	{
		value = get_value(*(commands + 1));
		ch_env_value(env, name, value);
		return ;
	}
	
	if (check_var_syntax(get_key(name)) == 0)
	{
		free(name);
		return ;
	}
	else if(*(commands + 1) != NULL)
	{
		new_node = ft_env_lstnew(*(commands + 1));
		if (is_exist(env, new_node->name) == 0)
			ll_addback(&env, new_node);
	}
	return ;
}





