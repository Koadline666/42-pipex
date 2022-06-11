/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:22 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/11 18:38:23 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_fd
{
	int		fd[2];
	int		id;
	int		fd_infile;
	int		fd_outfile;
	char	**str;
	char	*path;
}			t_fd;

void	ft_free2(char **str);
char	*ft_strjoin2(char *s1, char *s2);

//to check for leaks
		// int pid = getpid();
		// char *p_name = ft_strjoin2(ft_strdup("leaks "), ft_itoa(pid));
		// // p_name = ft_strjoin(p_name, " a.out");
		// system(p_name);

//to read the output of pid
	// char	*tmp = "";
	// while (tmp != NULL)
	// {
	// 	tmp = get_next_line(STDIN_FILENO);
	// 	if (tmp != NULL)
	// 	{
	// 		ft_printf("PIPED: %s\n", tmp);
	// 		free(tmp);
	// 	}
	// }

// fd[0] = read end
// fd[1] = write end

//to print char**
	// int	ft_print2(char **str)
	// {
	// 	int	i;

	// 	i = 0;
	// 	while (str[i] != NULL)
	// 	{
	// 		printf("-->%s\n", str[i]);
	// 		i++;
	// 	}
	// 	return (0);
	// }

#endif