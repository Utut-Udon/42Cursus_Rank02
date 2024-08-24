/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:58:15 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/08/20 18:53:48 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putptr(unsigned long long num)
{
	char	*ptr;
	int		len_1;
	int		len_2;

	if (num == 0)
		return (printf_putstr("(nil)"));
	ptr = ft_ptoa(num);
	if (!ptr)
		return (-1);
	len_1 = printf_putstr("0x");
	if (len_1 == -1)
	{
		free(ptr);
		ptr = NULL;
		return (-1);
	}
	len_2 = printf_putstr(ptr);
	free(ptr);
	ptr = NULL;
	if (len_2 == -1)
		return (-1);
	return (len_1 + len_2);
}
