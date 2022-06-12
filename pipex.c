/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/12 13:12:12 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd1(t_pipe *pipes)
{
	close(pipes->fd[0]);
	dup2(pipes->fd[1], STDOUT_FILENO);
	close(pipes->fd[1]);
	pipes->fd_infile = open(pipes->argv[1], O_RDONLY);
	dup2(pipes->fd_infile, STDIN_FILENO);
	close(pipes->fd_infile);
	pipes->str = ft_split(pipes->argv[2], ' ');
	pipes->path = ft_get_path(pipes->env, pipes->str[0]);
	if (execve(pipes->path, pipes->str, pipes->env) == -1)
		perror("Error:\ncould not execute first command\n");
}

void	ft_cmd2(t_pipe *pipes)
{
	dup2(pipes->fd[0], STDIN_FILENO);
	close(pipes->fd[1]);
	close(pipes->fd[0]);
	pipes->fd_outfile = open(pipes->argv[4], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(pipes->fd_outfile, STDOUT_FILENO);
	close(pipes->fd_outfile);
	pipes->str = ft_split(pipes->argv[3], ' ');
	pipes->path = ft_get_path(pipes->env, pipes->str[0]);
	if (execve(pipes->path, pipes->str, pipes->env) == -1)
		perror("Error:\ncould not execute second command\n");
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	pipes;

	pipes.argv = argv;
	pipes.env = env;
	if (argc != 5)
		perror("Error:\n not the right amount of parameters\n");
	if (pipe(pipes.fd) == -1)
		perror("Error:\n could not open pipe\n");
	pipes.id = fork();
	if (pipes.id == -1)
		perror("Error:\ncould not fork the process\n");
	if (pipes.id == 0)
		ft_cmd1(&pipes);
	pipes.id = fork();
	if (pipes.id == 0)
		ft_cmd2(&pipes);
	close(pipes.fd[1]);
	close(pipes.fd[0]);
	sleep(50);
	return (0);
}
