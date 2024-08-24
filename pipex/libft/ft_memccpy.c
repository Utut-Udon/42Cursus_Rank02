/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 23:09:24 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/10 18:04:17 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	unsigned char	uc;
	int				flag;

	flag = 0;
	uc = (unsigned char)c;
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	while (*uc_src && flag == 0 && n-- > 0)
	{
		*uc_dst = *uc_src;
		if (*uc_src == uc)
			flag = 1;
		uc_dst++;
		uc_src++;
	}
	if (flag == 1)
		return (uc_dst);
	else
		return (NULL);
}
