/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:29:20 by hfujita           #+#    #+#             */
/*   Updated: 2024/09/15 17:47:15 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	destroy_words_cnt(char **dst, size_t cnt)
{
	while (cnt-- > 0)
		free (dst[cnt]);
	free (dst);
}

void	destroy_words(char **dst)
{
	int	i;

	i = -1;
	while (dst[++i])
		free (dst[i]);
	free (dst);
}
