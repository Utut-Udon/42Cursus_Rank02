/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:55:32 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 13:55:32 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*n;

	n = ft_calloc(1, sizeof(*n));
	if (!n)
		return (NULL);
	n->value = value;
	return (n);
}

void	append_node(t_node **stack, t_node *new_node)
{
	t_node	*cur;

	if (!*stack)
		*stack = new_node;
	else
	{
		cur = *stack;
		while (cur->next)
			cur = cur->next;
		cur->next = new_node;
	}
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
