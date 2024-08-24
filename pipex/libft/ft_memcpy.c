/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 00:10:28 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/17 05:08:27 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;

	if (!dst && !src)
		return (NULL);
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	while (n-- > 0)
		*uc_dst++ = *uc_src++;
	return (dst);
}
