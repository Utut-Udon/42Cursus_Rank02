/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:55:00 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 17:16:09 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	parse_sub(const char *s, int i, int *err)
{
	long long	res;
	int			d;

	res = 0;
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
		{
			*err = 1;
			return (0);
		}
		d = s[i++] - '0';
		if (res > ((long long)INT_MAX + 1 - d) / 10)
		{
			*err = 1;
			return (0);
		}
		res = res * 10 + d;
	}
	return ((long)res);
}

static long	parse_num(const char *s, int *err)
{
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!s[i])
	{
		*err = 1;
		return (0);
	}
	return ((long)(parse_sub(s, i, err) * sign));
}

static void	parse_and_push(char *s, t_node **stk)
{
	int		err;
	long	val;

	err = 0;
	val = parse_num(s, &err);
	if (err || val < INT_MIN || val > INT_MAX)
		error_exit(NULL, NULL);
	append_node(stk, create_node((int)val));
}

t_node	*build_stack(char **args)
{
	t_node	*stk;
	char	**tok;
	int		i;
	int		j;

	stk = NULL;
	i = 0;
	while (args[i])
	{
		tok = ft_split(args[i], ' ');
		if (!tok)
			error_exit(NULL, NULL);
		j = 0;
		while (tok[j])
			parse_and_push(tok[j++], &stk);
		ft_free_split(tok);
		i++;
	}
	return (stk);
}

void	assign_indices(t_node *stack, int *sorted, int total)
{
	t_node	*cur;
	int		i;

	cur = stack;
	while (cur)
	{
		i = 0;
		while (i < total && sorted[i] != cur->value)
			i++;
		cur->index = i;
		cur = cur->next;
	}
}
