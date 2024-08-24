/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:17:00 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/17 06:28:54 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (!lst || !del)
		return ;
	tmp_1 = *lst;
	while (tmp_1)
	{
		tmp_2 = tmp_1->next;
		ft_lstdelone(tmp_1, del);
		tmp_1 = tmp_2;
	}
	*lst = NULL;
}
