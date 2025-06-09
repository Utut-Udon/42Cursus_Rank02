/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:23:05 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 14:26:42 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_chunk(t_node **a, t_node **b, int min, int max)
{
	int	i;
	int	size;
	int	idx;

	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		idx = (*a)->index;
		if (idx >= min && idx <= max)
		{
			pb(a, b);
			if (idx > min + (max - min) / 2)
				rb(b);
		}
		else
			ra(a);
		i++;
	}
}

void	push_chunks(t_node **a, t_node **b, int total, int chunks)
{
	int	chunk;
	int	chunk_size;
	int	min;
	int	max;

	chunk_size = (total + chunks - 1) / chunks;
	chunk = 0;
	while (chunk < chunks)
	{
		min = chunk * chunk_size;
		max = min + chunk_size - 1;
		if (max >= total)
			max = total - 1;
		process_chunk(a, b, min, max);
		chunk++;
	}
}

void	push_back_sorted(t_node **a, t_node **b)
{
	int	pos;
	int	sz;

	while (*b)
	{
		pos = get_b_max_pos(b);
		sz = stack_size(*b);
		if (pos <= sz / 2)
			while (pos-- > 0)
				rb(b);
		else
			while (sz-- > pos)
				rrb(b);
		pa(a, b);
	}
}
