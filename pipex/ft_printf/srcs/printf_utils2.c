/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:23:05 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/08/19 14:28:27 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_puthex(unsigned int num, const char format)
{
	char	*hex;
	int		len;

	hex = ft_htoa(num, format);
	if (!hex)
		return (-1);
	len = printf_putstr(hex);
	free(hex);
	hex = NULL;
	return (len);
}
