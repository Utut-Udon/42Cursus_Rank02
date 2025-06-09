/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:43:55 by hfujita           #+#    #+#             */
/*   Updated: 2024/08/19 14:01:22 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_numlen(unsigned int n)
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

static char	*getstr(size_t len)
{
	char	*dst;
	size_t	idx;

	idx = 0;
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	while (idx < len)
	{
		dst[idx] = '0';
		idx++;
	}
	dst[idx] = '\0';
	return (dst);
}

static char	*main_loop(char *dst, unsigned int n, const char format)
{
	size_t	len;
	char	*hex_digits;

	len = ft_strlen(dst);
	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	while (len > 0)
	{
		dst[len - 1] = hex_digits[n % 16];
		n /= 16;
		len--;
	}
	return (dst);
}

char	*ft_htoa(unsigned int n, const char format)
{
	char	*dst;

	dst = getstr(get_numlen(n));
	if (!dst)
		return (NULL);
	return (main_loop(dst, n, format));
}
