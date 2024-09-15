/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:42:30 by hfujita           #+#    #+#             */
/*   Updated: 2024/09/15 17:48:14 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <errno.h>

# define INFILE 0
# define OUTFILE 1
# define HERE_DOC_OUT 2
# define ENVP_NOTFOUND -1
# define INVALID_PATH -2

void	child_process(int fds[2], char *cmd, char **envp);
void	parent_process(pid_t pid, int fds[2]);
void	process(char *cmd, char **envp);
int		main(int argc, char **argv, char **envp);
int		open_file(char *file, int open_id);
void	my_dup2(int fd1, int fd2);
char	*find_path(char *basename, char **envp);
void	exec_cmd(char *cmd, char **envp);
void	perror_exit(void);
void	notfound_error(int id);
void	malloc_error_free(char *dst);
void	destroy_words_cnt(char **dst, size_t cnt);
void	destroy_words(char **dst);

#endif