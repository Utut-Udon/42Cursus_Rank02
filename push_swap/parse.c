/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:37:42 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 17:20:03 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*make_array(t_node *stack, int total)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = ft_calloc(total, sizeof(*arr));
	if (!arr)
		exit(EXIT_FAILURE);
	i = 0;
	cur = stack;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	return (arr);
}

static void	check_duplicates(int *arr, int total, t_node *stack)
{
	int	i;

	i = 0;
	while (i + 1 < total)
	{
		if (arr[i] == arr[i + 1])
			error_exit(stack, NULL);
		i++;
	}
}

t_node	*parse_input(int argc, char **argv)
{
	t_node	*stack;
	int		total;
	int		*sorted;

	if (argc < 2)
		return (NULL);
	stack = build_stack(argv + 1);
	total = stack_size(stack);
	sorted = make_array(stack, total);
	ft_qsort_int(sorted, total);
	check_duplicates(sorted, total, stack);
	assign_indices(stack, sorted, total);
	free(sorted);
	return (stack);
}

void	error_exit(t_node *a, t_node *b)
{
	write(2, "Error\n", 6);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(EXIT_FAILURE);
}
