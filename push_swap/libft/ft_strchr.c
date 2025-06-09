/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:17:57 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/15 23:11:26 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	c_c;

	str = (char *)s;
	c_c = (char)c;
	while (*str != c_c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
