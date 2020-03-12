/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:26:41 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/16 18:34:10 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (str2[i] == '\0')
		return ((char *)str1);
	while (str1[i] && i < n)
	{
		j = 0;
		while (str1[i + j] == str2[j] && (i + j) < n)
		{
			j++;
			if (str2[j] == '\0')
				return ((char *)str1 + i);
		}
		i++;
	}
	return (0);
}
