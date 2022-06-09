/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:59:02 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/09 15:43:12 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_get_path(char **env)
{
	int i;
	char *path;

	i = 0;
	while(env[i] != NULL)
	{
		if ()
		{
			
		}
		i++;
	}
	return (path);
}

int	main(int argc, char **argv, char **env)
{
	char *path;
	
	if (argc == 0 && argv == NULL)
		write(1, "\n", 1);
	path = ft_get_path(env);
	printf("path is %s\n", path);
	return(0);
}
