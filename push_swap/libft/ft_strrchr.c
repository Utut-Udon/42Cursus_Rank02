/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 03:31:04 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/06/07 06:33:02 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*str;
	char	c_c;

	len = ft_strlen(s);
	str = (char *)s;
	c_c = (char)c;
	while (len > 0)
	{
		if (str[len] == c_c)
			return (&str[len]);
		len--;
	}
	if (str[0] == c_c)
		return (str);
	return (NULL);
}
