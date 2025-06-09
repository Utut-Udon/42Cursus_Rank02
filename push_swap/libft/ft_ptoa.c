/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:03:23 by hfujita           #+#    #+#             */
/*   Updated: 2024/08/19 14:25:44 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_numlen_p(unsigned long long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static char	*getstr_p(size_t len)
{
	char	*dst;
	size_t	idx;

	idx = 0;
	dst = malloc(len + 1);
	if (!dst)
	{
		dst = NULL;
		return (NULL);
	}
	while (idx < len)
	{
		dst[idx] = '0';
		idx++;
	}
	dst[idx] = '\0';
	return (dst);
}

static char	*main_loop(char *dst, unsigned long long n)
{
	size_t	len;
	char	*hex_digits;

	len = ft_strlen(dst);
	hex_digits = "0123456789abcdef";
	while (len > 0)
	{
		dst[len - 1] = hex_digits[n % 16];
		n /= 16;
		len--;
	}
	return (dst);
}

char	*ft_ptoa(unsigned long long n)
{
	char	*dst;

	dst = getstr_p(get_numlen_p(n));
	if (!dst)
		return (NULL);
	return (main_loop(dst, n));
}
