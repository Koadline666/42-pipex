/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:22 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/12 13:10:29 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_pipe
{
	int		fd[2];
	int		id;
	int		fd_infile;
	int		fd_outfile;
	char	**str;
	char	*path;
	char	**argv;
	char	**env;
}			t_pipe;

void	ft_free2(char **str);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_get_path(char **env, char *cmd);

#endif