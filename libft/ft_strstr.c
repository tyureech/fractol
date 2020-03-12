/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:17:52 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/15 21:13:34 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int		i;
	int		j;

	i = 0;
	if (str2[i] == '\0')
		return ((char *)str1);
	while (str1[i])
	{
		j = 0;
		while (str1[i + j] == str2[j])
		{
			if (str2[j + 1] == '\0')
				return ((char *)str1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
