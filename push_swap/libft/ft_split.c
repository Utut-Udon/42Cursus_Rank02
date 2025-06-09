/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:43:13 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/21 04:25:25 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	word_count(char const *s, char c)
{
	int		flag;
	size_t	count;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else
		{
			if (flag == 0)
				count++;
			flag = 1;
		}
		s++;
	}
	return (count);
}

static char	*move_ptr(char const *s, char c, size_t count)
{
	int		flag;
	size_t	tmp_count;

	flag = 0;
	tmp_count = 0;
	while (*s && tmp_count < count)
	{
		if (*s == c)
			flag = 0;
		else
		{
			if (flag == 0)
				tmp_count++;
			flag = 1;
		}
		s++;
	}
	s--;
	return ((char *)s);
}

static char	*get_word(char const *s, char c, size_t count)
{
	size_t	w_len;
	char	*dst;

	s = move_ptr(s, c, count);
	w_len = 0;
	while (s[w_len] != c && s[w_len])
		w_len++;
	dst = malloc(w_len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, w_len + 1);
	return (dst);
}

static void	destroy_words(char **dst, size_t count)
{
	while (count-- > 0)
		free (dst[count]);
	free (dst);
}

char	**ft_split(char const *s, char c)
{
	size_t	wc;
	size_t	count;
	char	**dst;

	if (!s)
		return (NULL);
	wc = word_count(s, c);
	dst = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!dst)
		return (NULL);
	count = 0;
	while (count < wc)
	{
		dst[count] = get_word(s, c, count + 1);
		if (!dst[count])
		{
			destroy_words(dst, count);
			return (NULL);
		}
		count++;
	}
	dst[count] = NULL;
	return (dst);
}
