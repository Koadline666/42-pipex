/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:58:23 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/27 19:54:03 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_pipe	pipes;
	int		id[2];
	int		i;

	i = 0;
	pipes.argc = argc;
	pipes.argv = argv;
	pipes.env = env;
	pipes.cmd_num = argc - 5;
	if (argc < 5)
		ft_error(0);
	pipes.here_doc = ft_strncmp(argv[1], "here_doc", 9);
	if (pipe(pipes.fd) == -1)
		ft_error(1);
	ft_exec_cmd(&pipes, id, i);
	while (wait(NULL) != -1 || errno != ECHILD)
		continue ;
	return (0);
}
