/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 05:28:37 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 16:25:17 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

t_node	*parse_input(int argc, char **argv);
void	error_exit(t_node *a, t_node *b);

t_node	*build_stack(char **args);
void	assign_indices(t_node *stack, int *sorted, int total);

int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);
int		get_min_pos(t_node *stack);
int		get_b_max_pos(t_node **b);

t_node	*create_node(int value);
void	append_node(t_node **stack, t_node *new_node);
void	free_stack(t_node *stack);

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

void	sort_small(t_node **a, t_node **b);

void	push_chunks(t_node **a, t_node **b, int total, int chunks);
void	push_back_sorted(t_node **a, t_node **b);

void	sort_big(t_node **a, t_node **b);

#endif
