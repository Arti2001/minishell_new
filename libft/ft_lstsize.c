/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:22:39 by amysiv            #+#    #+#             */
/*   Updated: 2024/03/31 18:08:19 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
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
//int	main()
//{
//	t_node	*root;
//	t_node	*temp;
//	int		counter;

//	root = malloc(sizeof(t_node));
//	if (root == NULL)
//		return (NULL);
//	root->content = 1;
//	root->next = malloc(sizeof(t_node));
//	root->next->content = 2;
//	root->next->next = NULL;
//	temp = root;
//	counter = ft_lstsize(temp);
//	printf("%d", counter);
//	//while (temp != NULL)
//	//{
//	//	printf("%d node contains %d\n", counter, temp->content);
//	//	temp = temp->next;
//	//	counter++;
//	//}
//	free(root->next->next);
//	free(root->next);
//	return (counter);
//}