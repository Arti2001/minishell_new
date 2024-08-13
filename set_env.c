/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:31:46 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/13 17:33:48 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	devide(char *str)
{
	int	i;
	t_env	*new_node;

	i = 0;
	
	while(str[i] != '=' || str[i])
	{
		i++;
	}
	str[i]='\0';
	printf("%s\n", str + 1);
	new_node->name = str + i;
}

t_env	*ft_env_lstnew(char *content)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env ));
	if (new_node == NULL)
		return (NULL);
	devide(content);
	new_node->content = content;
	new_node->next = NULL;
}

void	*put_list()
{
	
}