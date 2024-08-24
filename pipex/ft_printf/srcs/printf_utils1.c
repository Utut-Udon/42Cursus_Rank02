/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 05:30:28 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/08/20 18:44:45 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	printf_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	printf_putnbr(int nbr)
{
	char	*num;
	int		len;

	num = ft_itoa(nbr);
	if (!num)
		return (-1);
	len = printf_putstr(num);
	free(num);
	num = NULL;
	return (len);
}

int	printf_putuint(unsigned int unbr)
{
	char	*num;
	int		len;

	num = ft_utoa(unbr);
	if (!num)
		return (-1);
	len = printf_putstr(num);
	free(num);
	num = NULL;
	return (len);
}
