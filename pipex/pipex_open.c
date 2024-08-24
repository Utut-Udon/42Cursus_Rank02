/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:57:37 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/08/24 23:29:39 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(int argc, const char **argv)
{
	int		fd;
	int		fds[2];
	pid_t	pid;
	int		status;

	if (access(argv[1], R_OK) == -1)
		peeor_exit();
	fd = open(argv[1], O_RDONLY);
	if (dup2(fd, 0) == -1)
		peeor_exit();
	fds[0] = 0;
	fds[1] = fd;
	pipe(fds);
	pid = fork();
	if (pid < 0)
		peeor_exit();
	else if (pid == 0)
	{
		
	}
	else
	{
		close (fd);
		waitpid(pid, &status, 0);
	}
}

int	exec_cmd(int argc, const char **argv, int arg_idx)
{
	
	execve(argv[arg_idx], argv, NULL);
}