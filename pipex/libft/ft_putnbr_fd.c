/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:19:56 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/04/10 23:49:23 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n < 0)
	{
		write (fd, "-", 1);
		n *= -1;
	}
	if (n == -2147483648)
	{
		write (fd, "2", 1);
		n = 147483648;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	num = n % 10 + '0';
	write (fd, &num, 1);
}
