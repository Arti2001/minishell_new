/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:38:55 by amysiv            #+#    #+#             */
/*   Updated: 2024/02/09 15:22:29 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
//int main(int argc, char *argv[])
//{
//	t_list *str;
//	t_list	*root;
//	t_list	*temp;
//	int		counter;

//	root = malloc(sizeof(t_node));
//	if (root == NULL)
//		return (0);
//	root->content = argv[1];
//	root->next = malloc(sizeof(t_node));
//	root->next->content = argv[2];
//	root->next->next = malloc(sizeof(t_node));
//	root->next->next->content = argv[3];
//	root->next->next->next = NULL;
//	temp = root;
//	str = ft_lstlast(temp);	
//	printf("%s is the last node", str);
//	free(root->next->next);
//	free(root->next);
//	return (0);
//}