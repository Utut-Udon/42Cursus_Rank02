/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:56:42 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 16:29:45 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_node **a, t_node **b)
{
	int	total;
	int	chunks;

	total = stack_size(*a);
	if (total <= 100)
		chunks = 5;
	else
		chunks = 15;
	push_chunks(a, b, total, chunks);
	push_back_sorted(a, b);
}
