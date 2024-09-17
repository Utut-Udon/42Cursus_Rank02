/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:37:20 by hfujita           #+#    #+#             */
/*   Updated: 2024/09/17 22:13:31 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int fds[2], char *cmd, char **envp)
{
	if (close(fds[0]) == -1)
		perror_exit();
	my_dup2(fds[1], STDOUT_FILENO);
	exec_cmd(cmd, envp);
	exit(EXIT_SUCCESS);
}

void	parent_process(pid_t pid, int fds[2])
{
	int	status;

	if (close(fds[1]) == -1)
		perror_exit();
	my_dup2(fds[0], STDIN_FILENO);
	waitpid(pid, &status, 0);
}

void	process(char *cmd, char **envp)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		perror_exit();
	pid = fork();
	if (pid == -1)
		perror_exit();
	else if (pid != 0)
		parent_process(pid, fds);
	else
		child_process(fds, cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	in_fd;
	int	out_fd;
	int	i;

	ft_putchar_fd('0' + 2, 2);
	ft_putchar_fd('\n', 2);
	if (argc == 5)
	{
		in_fd = open_file(argv[1], INFILE);
		out_fd = open_file(argv[argc - 1], OUTFILE);
		ft_putchar_fd('0' + 2, 2);
		ft_putchar_fd('\n', 2);
		my_dup2(in_fd, STDIN_FILENO);
		i = 2;
		while (i < argc - 2)
		{
			process(argv[i], envp);
			i++;
		}
		my_dup2(out_fd, STDOUT_FILENO);
		exec_cmd(argv[i], envp);
	}
	return (0);
}
