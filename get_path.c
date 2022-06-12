/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:02:32 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/12 12:03:05 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_possible_paths(char **env)
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
	// if (env[i] == NULL)
	// {
	// 	ft_free2(split);
	// 	return ("./");
	// }
	return (split);
}

char	*ft_get_path(char **env, char *cmd)
{
	int		i;
	char	**split;

	i = 0;
	split = get_possible_paths(env);
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
	return ("./");
}
