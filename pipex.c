/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/12 20:46:09 by afenzl           ###   ########.fr       */
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
		ft_error(3);
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
		ft_error(4);
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	pipes;
	int		id[2];
	// int		cmd_num;

	pipes.argv = argv;
	pipes.env = env;
	if (argc != 5)
		ft_error(0);
	if (pipe(pipes.fd) == -1)
		ft_error(1);
	id[0] = fork();
	if (id[0] == -1)
		ft_error(2);
	if (id[0] == 0)
		ft_cmd1(&pipes);
	id[1] = fork();
	if (id[1] == -1)
		ft_error(2);
	if (id[1] == 0)
		ft_cmd2(&pipes);
	ft_close(pipes.fd);
	waitpid(id[0], NULL, 0);
	waitpid(id[1], NULL, 0);
	return (0);
}
