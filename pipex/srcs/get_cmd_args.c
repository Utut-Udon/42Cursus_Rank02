/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:38:18 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/09/17 22:05:38 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_quotation(char c)
{
	return (c == '\'' || c == '\"');
}

static int	word_cnt(const char *s, char c)
{
	int	cnt;
	int	in_word;
	int	quoted;

	cnt = 0;
	in_word = 0;
	quoted = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (!quoted)
				in_word = 0;
		}
		else
		{
			if (!in_word)
				cnt++;
			quoted = (quoted + is_quotation(*s)) % 2;
			in_word = 1;
		}
		s++;
	}
	return (cnt);
}

int	get_word_len(char const *s, char c, int quoted)
{
	int	len;

	len = 0;
	while (s[len] && (*s == c && !quoted))
	{
		quoted = (quoted + is_quotation(*s)) % 2;
		len++;
	}
	return (len);
}

static char	*get_word(char const **s, char c)
{
	int		len;
	char	*dst;
	int		quoted;

	while ((**s) && (**s) == c)
		(*s)++;
	quoted = 0;
	if (is_quotation(**s))
	{
		(*s)++;
		quoted = 1;
	}
	len = get_word_len(*s, c, quoted);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, *s, len + 1);
	(*s) += len;
	return (dst);
}

char	**get_cmd_args(char const *s, char c)
{
	int		wc;
	int		cnt;
	char	**dst;

	if (!s)
		return (NULL);
	wc = word_cnt(s, c);
	dst = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!dst)
		return (NULL);
	cnt = 0;
	while (cnt < wc)
	{
		dst[cnt] = get_word(&s, c);
		if (!dst[cnt])
		{
			destroy_words_cnt(dst, cnt);
			return (NULL);
		}
		cnt++;
	}
	dst[cnt] = NULL;
	return (dst);
}
