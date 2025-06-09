/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:16:38 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 08:16:43 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	int	tv;
	int	ti;

	if (*a && (*a)->next)
	{
		tv = (*a)->value;
		ti = (*a)->index;
		(*a)->value = (*a)->next->value;
		(*a)->index = (*a)->next->index;
		(*a)->next->value = tv;
		(*a)->next->index = ti;
		write(1, "sa\n", 3);
	}
}

void	sb(t_node **b)
{
	int	tv;
	int	ti;

	if (*b && (*b)->next)
	{
		tv = (*b)->value;
		ti = (*b)->index;
		(*b)->value = (*b)->next->value;
		(*b)->index = (*b)->next->index;
		(*b)->next->value = tv;
		(*b)->next->index = ti;
		write(1, "sb\n", 3);
	}
}

void	ss(t_node **a, t_node **b)
{
	int	did;

	did = 0;
	if (*a && (*a)->next)
	{
		sa(a);
		did = 1;
	}
	if (*b && (*b)->next)
	{
		sb(b);
		did = 1;
	}
	if (did)
		write(1, "ss\n", 3);
}
