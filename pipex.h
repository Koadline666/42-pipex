/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:22 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/12 21:12:39 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_pipe
{
	int		fd[2];
	char	**argv;
	char	**env;
}			t_pipe;

void	ft_free2(char **str);
void	ft_close(int *fd);
void	ft_error(int errorcode);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_get_path(char **env, char *cmd);

#endif