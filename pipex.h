/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:22 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/12 12:03:16 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# ifndef RIGHTS
#  define RIGHTS S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
# endif

typedef struct s_pipe
{
	int		fd[2];
	int		id;
	int		fd_infile;
	int		fd_outfile;
	char	**str;
	char	*path;
}			t_pipe;

void	ft_free2(char **str);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_get_path(char **env, char *cmd);

#endif
