/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_revrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:17:26 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 08:17:26 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*p;
	t_node	*l;

	if (*a && (*a)->next)
	{
		p = NULL;
		l = *a;
		while (l->next)
		{
			p = l;
			l = l->next;
		}
		p->next = NULL;
		l->next = *a;
		*a = l;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_node **b)
{
	t_node	*p;
	t_node	*l;

	if (*b && (*b)->next)
	{
		p = NULL;
		l = *b;
		while (l->next)
		{
			p = l;
			l = l->next;
		}
		p->next = NULL;
		l->next = *b;
		*b = l;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_node **a, t_node **b)
{
	int	did;

	did = 0;
	if (*a && (*a)->next)
	{
		rra(a);
		did = 1;
	}
	if (*b && (*b)->next)
	{
		rrb(b);
		did = 1;
	}
	if (did)
		write(1, "rrr\n", 4);
}
