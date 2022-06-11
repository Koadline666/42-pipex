/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/11 17:16:00 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// fd[0] = read end
// fd[1] = write end

int	ft_print2(char **str)
{
	int i;

	i = 0;
	while(str[i] != NULL)
	{
		printf("-->%s\n", str[i]);
		i++;
	}
	return(0);
}

char	*ft_get_path(char **env, char *cmd)
{
	int i;
	char *path;
	char **split;

	i = 0;
	while(env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			split = ft_split(env[i], ':');
			break ;
		}
		i++;
	}
	if (env == NULL)
		return ("./");
	i = 0;
	printf("the cmd is: %s\n", cmd);
	while (split[i] != NULL)
	{
		path = ft_strjoin(split[i], "/");
		path = ft_strjoin(path, cmd);
		printf("the path is: %s\n", path);
		if (access(path, 0) == 0)
		{
			printf("accessed this path: %s\n", path);
			return(path);
		}
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	id;
	int fd_read_file;
	char **str;
	char *path;

	if (argc < 0)
		ft_printf("invalid given papramters\n");
	if (pipe(fd) == -1)
		perror("Error:\n could not open pipe\n");
	id = fork();
	if (id == -1)
		perror("Error:\ncould not fork the process\n");
	str = NULL;
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		fd_read_file = open(argv[1], O_RDONLY);
		dup2(fd_read_file, STDIN_FILENO);
		close(fd_read_file);
		str = ft_split(argv[2], ' ');
		path = ft_get_path(env, str[0]);
		printf("=====>%s\n", path);
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
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	// ft_printf("the PATH: %s\n", env[3]);
	// ft_print2(env);
	// ft_printf("\n||\n");
	// ft_print2(argv);
	return (0);
}
