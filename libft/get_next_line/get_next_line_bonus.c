/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:13:39 by afenzl            #+#    #+#             */
/*   Updated: 2022/05/18 13:37:11 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (left_str[i] != '\n' && left_str[i] != '\0')
		i++;
	new = malloc(ft_strlen(left_str) - i + 1);
	if (new == NULL)
		return (NULL);
	if (left_str[i] == '\n')
		i++;
	while (left_str[i] != '\0')
		new[j++] = left_str[i++];
	new[j] = '\0';
	free(left_str);
	return (new);
}

char	*read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	rd_bytes = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = read_to_left_str(fd, left_str[fd]);
	if (left_str[fd] == NULL)
		return (NULL);
	line = ft_get_line(left_str[fd]);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	left_str[fd] = ft_new_left_str(left_str[fd]);
	if (left_str[fd] == NULL)
	{
		free(left_str[fd]);
		return (NULL);
	}
	return (line);
}
