/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:13:06 by amysiv            #+#    #+#             */
/*   Updated: 2024/09/05 08:32:54 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ll_last(t_env *last)
{
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

int	ft_lst_size(t_env *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ll_addback(t_env **env_head, t_env *new_node)
{
	t_env	*last

;	if (*env_head == NULL)
		return ;
	last = ll_last(*env_head);
	last->next = new_node;
}

t_env	*ft_env_lstnew(char *content)
{
	t_env	*new_node;
	
	new_node = (t_env *)malloc(sizeof(t_env ));
	if (new_node == NULL)
		return (NULL);
	new_node->content = ft_strdup(content);
	new_node->name = get_key(content);
	new_node->value= get_value(content);
	new_node->next = NULL;
	return (new_node);
}