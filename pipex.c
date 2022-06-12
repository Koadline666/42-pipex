/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/12 16:23:15 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd1(t_pipe *pipes)
{
	char	*path;
	char	**cmd;
	int		fd_infile;

	dup2(pipes->fd[1], STDOUT_FILENO);
	ft_close(pipes->fd);
	fd_infile = open(pipes->argv[1], O_RDONLY);
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	cmd = ft_split(pipes->argv[2], ' ');
	path = ft_get_path(pipes->env, cmd[0]);
	if (execve(path, cmd, pipes->env) == -1)
	{
		perror("Error:\ncould not execute first command\n");
		exit(-1);
	}
}

void	ft_cmd2(t_pipe *pipes)
{
	char	**cmd;
	char	*path;
	int		fd_outfile;

	dup2(pipes->fd[0], STDIN_FILENO);
	ft_close(pipes->fd);
	fd_outfile = open(pipes->argv[4], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	cmd = ft_split(pipes->argv[3], ' ');
	path = ft_get_path(pipes->env, cmd[0]);
	if (execve(path, cmd, pipes->env) == -1)
	{
		perror("Error:\ncould not execute second command\n");
		exit(-1);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	pipes;
	int		id;

	pipes.argv = argv;
	pipes.env = env;
	if (argc != 5)
		perror("Error:\n not the right amount of parameters\n");
	if (pipe(pipes.fd) == -1)
		perror("Error:\n could not open pipe\n");
	id = fork();
	if (id == -1)
		perror("Error:\ncould not fork the process\n");
	if (id == 0)
		ft_cmd1(&pipes);
	id = fork();
	if (id == 0)
		ft_cmd2(&pipes);
	ft_close(pipes.fd);
	// sleep(20);
	return (0);
}
