/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:09:53 by amysiv            #+#    #+#             */
/*   Updated: 2024/02/09 15:22:24 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		return ;
	last = ft_lstlast(*lst);
	last->next = new;
}
//int	main()
//{
//	t_list	*first_node;
//	t_list	*new_node;
//	t_list	**head;

//	first_node = ft_lstnew("Hello");
//	head = &first_node;
//	new_node = ft_lstnew("World");
//	ft_lstadd_back(head, ft_lstnew("World"));

//	return 0;
//}