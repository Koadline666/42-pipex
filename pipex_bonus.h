/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:15:18 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/14 13:02:39 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_pipe
{
	int		fd[2];
	int		fd_prev[2];
	int		cmd_num;
	int		argc;
	int		here_doc;
	char	*lim;
	char	**argv;
	char	**env;
}			t_pipe;

void	ft_free2(char **str);
void	ft_close(int *fd);
void	ft_error(int errorcode);
void	assign_int_arr(t_pipe *pipes);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_get_path(char **env, char *cmd);
void	ft_exec_cmd(t_pipe *pipes, int *id);

#endif