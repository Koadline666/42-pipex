/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:40:04 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/13 17:39:19 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(int errorcode)
{
	if (errorcode == 0)
		perror("Error:\n not enough arguments\n");
	else if (errorcode == 1)
		perror("Error:\n could not open pipe\n");
	else if (errorcode == 2)
		perror("Error:\ncould not fork the process\n");
	else if (errorcode == 3)
		perror("Error:\nfirst command not found\n");
	else if (errorcode == 4)
		perror("Error:\nsecond command not found\n");
	else if (errorcode == 5)
		perror("Error:\ncould not open given file\n");
	exit(0);
}
