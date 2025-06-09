/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:56:54 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 14:39:07 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		n;

	a = parse_input(argc, argv);
	b = NULL;
	if (!a)
		return (0);
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	n = stack_size(a);
	if (n <= 5)
		sort_small(&a, &b);
	else
		sort_big(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
