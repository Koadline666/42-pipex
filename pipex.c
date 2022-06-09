/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/09 16:26:01 by afenzl           ###   ########.fr       */
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

char	*ft_get_path(char **env)
{
	int i;
	char *path;
	char **split;

	i = 0;
	while(env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PATH=",ft_strlen(env[i])) != NULL)
		{
			path = ft_strnstr(env[i], "PATH=",ft_strlen(env[i])) + 5;
			split = ft_split(path, ':');
		}
	}
	i = 0;
	while (split[i] != NULL)
	{
		if (access(split[i], F_OK) == 0)
			return(split[i]);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	id;
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
		str = ft_split(argv[2], ' ');
		// path = "/bin/ls";
		path = ft_get_path(env);
		printf("%s", path);
		return (0);
		// if (execve(path, str, env) == -1)
		// {
		// 	perror("Error:\ncould not execute first command\n");
		// 	exit(-1);
		// }
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(0, NULL, 0);
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	// ft_printf("the PATH: %s\n", env[3]);
	// ft_print2(env);
	// ft_printf("\n||\n");
	// ft_print2(argv);
	return (0);
}
