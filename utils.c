/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:36:34 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/12 15:27:18 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_close(int *fd)
{
	close(fd[1]);
	close(fd[0]);
}
