/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 04:50:26 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/17 23:22:45 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	mem_buf;

	if (size != 0 && UINT_MAX / size < count)
		return (NULL);
	mem_buf = size * count;
	mem = (void *)malloc(mem_buf);
	if (!mem)
		return (NULL);
	ft_bzero (mem, mem_buf);
	return (mem);
}
