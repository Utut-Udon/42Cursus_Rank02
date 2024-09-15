/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:18:25 by hfujita           #+#    #+#             */
/*   Updated: 2024/09/15 17:34:00 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int open_id)
{
	int	fd;

	if (open_id == INFILE)
		fd = open(file, O_RDONLY);
	else if (open_id == OUTFILE)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
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
			break;
		i++;
	}
	if (!paths[i])
		notfound_error(INVALID_PATH);
	free(basename);
	destroy_words(paths);
	return (cmd_path);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**cmd_split;
	char	*cmd_path;
	char	*basename;
	int		flag;

	cmd_split = ft_split(cmd, ' ');
	basename = ft_strrchr(cmd_split[0], '/');
	flag = 0;
	if (!basename)
	{
		basename = ft_strjoin("/", cmd_split[0]);
		if (!basename)
			perror_exit();
		cmd_path = find_path(basename, envp);
	}
	else
		cmd_path = ft_strdup(cmd_split[0]);
	flag = execve(cmd_path, cmd_split, envp);
	destroy_words(cmd_split);
	free(cmd_path);
	if (flag == -1)
		perror_exit();
}
