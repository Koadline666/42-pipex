/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:02:32 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/12 18:20:19 by afenzl           ###   ########.fr       */
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
			split = ft_split(&(env[i][5]), ':');
			break ;
		}
		i++;
	}
	return (split);
}

char	*ft_get_path(char **env, char *cmd)
{
	int		i;
	char	**split;
	char	*tmp;

	i = 0;
	split = get_possible_paths(env);
	if (ft_strchr(cmd, '/') != 0)
		return (cmd);
	while (split[i] != NULL)
	{
		split[i] = ft_strjoin2(split[i], ft_strdup("/"));
		split[i] = ft_strjoin2(split[i], ft_strdup(cmd));
		if (access(split[i], 0) == 0)
		{
			tmp = ft_strdup(split[i]);
			ft_free2(split);
			return (tmp);
		}
		i++;
	}
	ft_free2(split);
	return (ft_strjoin2(ft_strdup("./"), cmd));
}
