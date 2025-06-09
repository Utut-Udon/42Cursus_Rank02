/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:40:53 by hfujita           #+#    #+#             */
/*   Updated: 2024/08/01 17:45:03 by hfujita          ###   ########.fr       */
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

static char	*main_loop(char *dst, unsigned int n)
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

char	*ft_utoa(unsigned int n)
{
	char	*dst;

	dst = getstr(get_numlen(n));
	if (!dst)
		return (NULL);
	return (main_loop(dst, n));
}
