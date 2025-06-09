/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:16:55 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 08:16:59 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*t;

	if (*b)
	{
		t = *b;
		*b = (*b)->next;
		t->next = *a;
		*a = t;
		write(1, "pa\n", 3);
	}
}

void	pb(t_node **a, t_node **b)
{
	t_node	*t;

	if (*a)
	{
		t = *a;
		*a = (*a)->next;
		t->next = *b;
		*b = t;
		write(1, "pb\n", 3);
	}
}
