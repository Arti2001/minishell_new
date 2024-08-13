/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:29:52 by amysiv            #+#    #+#             */
/*   Updated: 2024/02/09 15:22:27 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}

//int	main()
//{
//	t_list	**head = NULL;
//	int		*cont;
//	int		i = 42;
//	t_list	*newnode;

//	cont = &i;

//	printf("check\n");

//	newnode = ft_lstnew(cont);
//	head = &newnode;
//	printf("%p\n", *head);

//	ft_lstadd_front(head, ft_lstnew(cont));
//	printf("%p\n", *head);
//	return 0;
//}
