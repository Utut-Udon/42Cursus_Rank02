/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 05:46:31 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/21 04:26:27 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	idx;

	if (!s || !f)
		return (NULL);
	map = malloc(ft_strlen(s) + 1);
	if (!map)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		map[idx] = f(idx, s[idx]);
		idx++;
	}
	map[idx] = '\0';
	return (map);
}
