/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/12 12:04:30 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	int		id;
	int		fd_infile;
	int		fd_outfile;
	char	**str;
	char	*path;

	if (argc != 5)
		perror("Error:\n not the right amount of parameters\n");
	if (pipe(fd) == -1)
		perror("Error:\n could not open pipe\n");
	id = fork();
	if (id == -1)
		perror("Error:\ncould not fork the process\n");
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		fd_infile = open(argv[1], O_RDONLY);
		dup2(fd_infile, STDIN_FILENO);
		close(fd_infile);
		str = ft_split(argv[2], ' ');
		path = ft_get_path(env, str[0]);
		if (execve(path, str, env) == -1)
			perror("Error:\ncould not execute first command\n");
	}
	id = fork();
	if (id == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		fd_outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, RIGHTS);
		dup2(fd_outfile, STDOUT_FILENO);
		close(fd_outfile);
		str = ft_split(argv[3], ' ');
		path = ft_get_path(env, str[0]);
		if (execve(path, str, env) == -1)
			perror("Error:\ncould not execute second command\n");
	}
	// waitpid(0, NULL, 0);
	return (0);
}
