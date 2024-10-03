/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:55:48 by amysiv            #+#    #+#             */
/*   Updated: 2024/10/03 17:17:57 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_var_syntax(char *str)
{
	int		i;

	i = 0;

	if (!ft_isalpha(str[0]) && !(str[0] == '_'))
	{
		printf("bash: export: '%s': not a valid identifier\n", str);
		return (0);
	}
	while(str[i])
	{
		if (ft_isalpha(str[i])|| (str[i] == '_') || ft_isdigit(str[i]))
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
		if (ft_strncmp(name, env->name, ft_strlen(env->name)) == 0)
			return 2;
		env = env->next;
	}
	return (0);
}


void	print_export_env(t_env *env)
{
		while (env != NULL)
		{
			if (env->value == NULL)
				printf("declare -x %s\n", env->name);
			else
				printf("declare -x %s=\"%s\"\n", env->name, env->value);
			env = env->next;
		}
	return ;
}

int	add_var(t_env *env, char *arg)
{
	char	*name;
	char 	*value;

		name = get_key(arg);
		value = get_value(arg);
		if (is_exist(env, name) == 2)
			return(ch_env_value(env, name, value), free(name), 0);
		if (check_var_syntax(get_key(name)) == 0)
			return (free(name), free(value), 1);
		free(name);
		free(value);
		return (2);
}

int ft_export(t_env *env, char **commands)
{
	int		i;
	t_env	*new_node;

	i = 1;
	if (commands[i] == NULL)
		return (print_export_env(env), 0);
	while (commands[i] != NULL)
	{
		if (add_var(env, commands[i]) == 2)
		{
			new_node = ft_env_lstnew(commands[i]);
			ll_addback(&env, new_node);
		}
		i++;
	}
	return (0);
}




