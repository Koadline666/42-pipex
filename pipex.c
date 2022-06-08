/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/08 15:58:01 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		perror("Error:\n could not open pipe\n");
	printf("the fd are %i & %i\n", fd[0], fd[1]);
	if (fork() == -1)
		perror("Error:\ncould not fork the process\n");
	if (id == 0)
	{
		printf("hey\n");
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve();
	}
	// dup2(fd[1], )
	// close(fd[1]);
	// close(fd[0]);
	// // execve()

	return (0);
}