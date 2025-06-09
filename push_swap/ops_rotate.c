/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:17:11 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 08:17:12 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*f;
	t_node	*l;

	if (*a && (*a)->next)
	{
		f = *a;
		*a = (*a)->next;
		l = *a;
		while (l->next)
			l = l->next;
		l->next = f;
		f->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	rb(t_node **b)
{
	t_node	*f;
	t_node	*l;

	if (*b && (*b)->next)
	{
		f = *b;
		*b = (*b)->next;
		l = *b;
		while (l->next)
			l = l->next;
		l->next = f;
		f->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	rr(t_node **a, t_node **b)
{
	int	did;

	did = 0;
	if (*a && (*a)->next)
	{
		ra(a);
		did = 1;
	}
	if (*b && (*b)->next)
	{
		rb(b);
		did = 1;
	}
	if (did)
		write(1, "rr\n", 3);
}
