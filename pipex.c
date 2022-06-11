/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/11 18:43:06 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char **env, char *cmd)
{
	int		i;
	char	**split;

	i = 0;
	split = NULL;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			split = ft_split(env[i], ':');
			break ;
		}
		i++;
	}
	if (env[i] == NULL)
	{
		ft_free2(split);
		return ("./");
	}
	i = 0;
	while (split[i] != NULL)
	{
		split[i] = ft_strjoin2(split[i], ft_strdup("/"));
		split[i] = ft_strjoin2(split[i], ft_strdup(cmd));
		if (access(split[i], 0) == 0)
		{
			ft_free2(split);
			return (split[i]);
		}
		i++;
	}
	ft_free2(split);
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	int		id;
	int		fd_infile;
	int		fd_outfile;
	char	**str;
	char	*path;

	if (argc != 5)
		ft_printf("not the right amount of parameters\n");
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
		{
			perror("Error:\ncould not execute first command\n");
			exit(-1);
		}
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(0, NULL, 0);
	fd_outfile = open(argv[4], O_WRONLY);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	str = ft_split(argv[3], ' ');
	path = ft_get_path(env, str[0]);
	if (execve(path, str, env) == -1)
	{
		perror("Error:\ncould not execute second command\n");
		exit(-1);
	}
	return (0);
}
