/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:17:41 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 14:36:38 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_small_to_b(t_node **a, t_node **b)
{
	int	pos;
	int	sz;

	while (stack_size(*a) > 3)
	{
		pos = get_min_pos(*a);
		sz = stack_size(*a);
		if (pos <= sz / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (sz-- > pos)
				rra(a);
		pb(a, b);
	}
}

static void	restore_small(t_node **a, t_node **b)
{
	while (*b)
		pa(a, b);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

static void	sort_three(t_node **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->index;
	s = (*a)->next->index;
	t = (*a)->next->next->index;
	if (f > s && s < t && f < t)
		sa(a);
	else if (f > s && s > t)
	{
		sa(a);
		rra(a);
	}
	else if (f > s && s < t && f > t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(a);
		ra(a);
	}
	else if (f < s && s > t && f > t)
		rra(a);
}

void	sort_small(t_node **a, t_node **b)
{
	int	n;

	n = stack_size(*a);
	if (n <= 1)
		return ;
	if (n == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
		return ;
	}
	if (n == 3)
	{
		sort_three(a);
		return ;
	}
	push_small_to_b(a, b);
	sort_three(a);
	restore_small(a, b);
}
