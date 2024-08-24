/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:06:08 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/17 20:22:31 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	judge_delim(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		len;
	char	*dst;

	if (!s)
		return (NULL);
	while (judge_delim(*s, set))
		s++;
	if (*s == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s);
	while (len > 0 && judge_delim(s[len - 1], set))
		len--;
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}
