/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:18:25 by hfujita           #+#    #+#             */
/*   Updated: 2024/09/17 22:09:00 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int open_id)
{
	int	fd;

	if (open_id == INFILE)
		fd = open(file, O_RDONLY);
	else if (open_id == OUTFILE)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror_exit();
		return (-1);
	}
	else
		return (fd);
}

void	my_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		perror_exit();
}

char	*find_path(char *basename, char **envp)
{
	char	**paths;
	char	*cmd_path;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		notfound_error(ENVP_NOTFOUND);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		malloc_error_free(basename);
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], basename);
		if (access(cmd_path, F_OK) == 0)
			break ;
		i++;
	}
	if (!paths[i])
		notfound_error(INVALID_PATH);
	free(basename);
	destroy_words(paths);
	return (cmd_path);
}

void	print_args(char **args)
{
	while (*args)
	{
		ft_putstr_fd(*args, 2);
		ft_putstr_fd("\n", 2);
		args++;
	}
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*cmd_path;
	char	*basename;
	int		flag;

	cmd_args = get_cmd_args(cmd, ' ');
	basename = ft_strrchr(cmd_args[0], '/');
	flag = 0;
	if (!basename)
	{
		basename = ft_strjoin("/", cmd_args[0]);
		if (!basename)
			perror_exit();
		cmd_path = find_path(basename, envp);
	}
	else
		cmd_path = ft_strdup(cmd_args[0]);
	flag = execve(cmd_path, cmd_args, envp);
	destroy_words(cmd_args);
	free(cmd_path);
	if (flag == -1)
		perror_exit();
}
