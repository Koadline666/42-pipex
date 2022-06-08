/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:16:23 by afenzl            #+#    #+#             */
/*   Updated: 2022/05/25 09:36:39 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			k;
	unsigned char	*p;
	unsigned char	*e;

	i = 0;
	k = 0;
	p = (unsigned char *)s1;
	e = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s1[k] != s2[i] && s1[k] != '\0')
		k++;
	while (s1[k] == s2[i] && s1[k] != '\0')
	{
		if (i < n - 1)
		{
			k++;
			i++;
		}
		else
			return (0);
	}
	return (p[k] - e[i]);
}
