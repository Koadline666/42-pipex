/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/11 17:56:16 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//to check for leaks
		// int pid = getpid();
		// char *p_name = ft_strjoin2(ft_strdup("leaks "), ft_itoa(pid));
		// // p_name = ft_strjoin(p_name, " a.out");
		// system(p_name);

// fd[0] = read end
// fd[1] = write end

static char	*join(char *s1, char *s2, char *new)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(*new) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
	{
		return (NULL);
	}
	join(s1, s2, new);
	free(s1);
	free(s2);
	return (new);
}

int	ft_print2(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		printf("-->%s\n", str[i]);
		i++;
	}
	return (0);
}

void	ft_free2(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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
		return ("./");
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
	int		fd_read_file;
	char	**str;
	char	*path;

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
	int	tmp;
	tmp = "";
	while (tmp != NULL)
	{
		tmp = get_next_line(STDIN_FILENO);
		if (tmp != NULL)
		{
			ft_printf("PIPED: %s\n", tmp);
			free(tmp);
		}
	}
	return (0);
}
