/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:50:35 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/17 21:16:34 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_numlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		len++;
		n /= 10;
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

static char	*main_loop(char *dst, int n)
{
	size_t	len;

	len = ft_strlen(dst);
	while (len > 0)
	{
		dst[len - 1] = '0' + n % 10;
		n /= 10;
		len--;
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		flag;

	dst = getstr(get_numlen(n));
	if (!dst)
		return (NULL);
	flag = 0;
	if (n < 0)
	{
		*dst++ = '-';
		n *= -1;
		flag++;
	}
	if (n == -2147483648)
	{
		*dst++ = '2';
		n = 147483648;
		flag++;
	}
	return (main_loop(dst, n) - flag);
}
