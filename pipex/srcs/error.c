/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:36:21 by hfujita           #+#    #+#             */
/*   Updated: 2024/09/15 16:56:33 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(void)
{
	perror(strerror(errno));
	exit(EXIT_FAILURE);
}

void	notfound_error(int id)
{
	if (id == ENVP_NOTFOUND)
		ft_putstr_fd("The environment parameter PATH does not exist.", 2);
	else if (id == INVALID_PATH)
		ft_putstr_fd("Invalid path", 2);
	exit(EXIT_FAILURE);
}

void	malloc_error_free(char *dst)
{
	free(dst);
	perror_exit();
}
