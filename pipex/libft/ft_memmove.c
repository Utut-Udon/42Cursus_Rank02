/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 00:35:20 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/27 05:46:19 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_dst;
	char	*c_src;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	c_dst = (char *)dst;
	c_src = (char *)src;
	if (c_dst > c_src)
		while (len-- > 0)
			c_dst[len] = c_src[len];
	else
	{
		i = 0;
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
	return (dst);
}
