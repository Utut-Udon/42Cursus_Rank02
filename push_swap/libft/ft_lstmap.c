/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:30:44 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/06/07 10:59:13 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*do_1stmalloc(t_list *lst, t_list **map,
		void *(*f)(void *), void (*del)(void *))
{
	void	*content;

	content = f(lst->content);
	*map = ft_lstnew(content);
	if (!(*map))
	{
		del(content);
		return (NULL);
	}
	return (*map);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*origin;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	origin = do_1stmalloc(lst, &map, f, del);
	if (!origin)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		map->next = ft_lstnew(content);
		if (map->next == NULL)
		{
			del(content);
			ft_lstclear(&origin, del);
			return (NULL);
		}
		map = map->next;
		lst = lst->next;
	}
	return (origin);
}
