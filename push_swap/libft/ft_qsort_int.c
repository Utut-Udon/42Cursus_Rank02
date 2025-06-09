/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:43:17 by fujitaharuk       #+#    #+#             */
/*   Updated: 2025/06/09 13:43:34 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qsort_int(int *arr, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	pivot;
	int		tmp;

	if (n < 2)
		return ;
	pivot = n - 1;
	i = 0;
	j = 0;
	while (i < pivot)
	{
		if (arr[i] < arr[pivot])
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j++] = tmp;
		}
		i++;
	}
	tmp = arr[j];
	arr[j] = arr[pivot];
	arr[pivot] = tmp;
	ft_qsort_int(arr, j);
	ft_qsort_int(arr + j + 1, n - j - 1);
}
