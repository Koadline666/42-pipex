/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/08 20:05:11 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// fd[0] = read end
// fd[1] = write end

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	id;

	if (argc < 0)
		ft_printf("invalid given papramters\n");
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
		// find_path;
		printf("hey, this is from child\nlol");
		return (0);
		char **tmp = ft_split(argv[2], ' ');
		char **str = malloc(3);
		str[0] = "type";
		str[1] = tmp[0];
		str[2] = NULL;
		if (execve("/usr/bin/type", str, env) == -1)
			perror("Error:\ncould not execute first command\n");
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(0, NULL, 0);
	ft_printf("PIPED: %s\n", get_next_line(STDIN_FILENO));
	return (0);
}

// char *find_path(char *cmd)
// {
// 	char **tmp;

// 	tmp = split(cmd);
// 	char **str = malloc(3 * sizeof(char *));
// 	if (str == NULL)
// 		return(NULL);
// 	str[0] = "type";
// 	str[1] = tmp[0];
// 	str[2] = NULL;
// 	while
// 	return (str);
// }