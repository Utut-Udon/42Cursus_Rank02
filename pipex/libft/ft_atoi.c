/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:11:40 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/18 03:14:52 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == '\v' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\f' || c == ' ');
}

static int	get_numlen(const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == '0')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		len++;
		i++;
	}
	if (len == 0)
		len++;
	return (len);
}

static int	check_of(unsigned long long num, int sign, int numlen)
{
	if ((numlen > 19 || (numlen == 19 && num > LLONG_MAX))
		&& sign == -1)
		return (0);
	else if ((numlen > 19 || (numlen == 19 && num > LLONG_MAX))
		&& sign == 1)
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	num;
	int					numlen;

	while (is_space(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	num = 0;
	numlen = get_numlen(str);
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str++ - '0');
		if (check_of(num, sign, numlen) != 1)
			return (check_of(num, sign, numlen));
	}
	return (num * sign);
}
