/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:55:23 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 15:14:34 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	cnt;

	cnt = 0;
	while (stack)
	{
		cnt++;
		stack = stack->next;
	}
	return (cnt);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		else
			stack = stack->next;
	}
	return (1);
}

int	get_min_pos(t_node *stack)
{
	int	pos;
	int	best;
	int	mn;

	pos = 0;
	best = 0;
	mn = stack->index;
	while (stack)
	{
		if (stack->index < mn)
		{
			mn = stack->index;
			best = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (best);
}

int	get_b_max_pos(t_node **b)
{
	t_node	*n;
	int		pos;
	int		best;
	int		mx;

	n = *b;
	pos = 0;
	best = 0;
	if (n)
		mx = n->index;
	else
		return (0);
	while (n)
	{
		if (n->index > mx)
		{
			mx = n->index;
			best = pos;
		}
		n = n->next;
		pos++;
	}
	return (best);
}
