/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:57:37 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/08/27 18:30:27 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_write(int in_fd, int out_fd)
{
	char	buf[PIPE_BUF];
	int		rd_size;
	
	rd_size = read(in_fd, buf, PIPE_BUF);
	if (rd_size < 0)
		return (-1);
	while (rd_size > 0)
	{
		if (write(out_fd, buf, rd_size) < 0)
			return (-1);
		rd_size = read(in_fd, buf, PIPE_BUF);
		if (rd_size < 0)
			return (-1);
	}
	return (0);
}

int	open_infile(int argc, const char **argv)
{
	int		fd;
	int		fds[2];
	pid_t	pid;
	int		status;
	int		i;

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
		if (read_write(fd, 0) == -1)
			perror_exit();
		exit(99);
	}
	else
	{
		close (fd);
		waitpid(pid, &status, 0);
		i = 0;
		while (++i < argc - 1)
		{
		}
	}
}

int	exec_cmd(int argc, const char **argv, int arg_idx)
{
	
	execve(argv[arg_idx], argv, NULL);
}