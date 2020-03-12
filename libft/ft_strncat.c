/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:06:42 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/14 23:31:38 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t len)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (str1[i])
		i++;
	while (len != 0 && str2[j])
	{
		str1[i] = str2[j];
		i++;
		j++;
		len--;
	}
	str1[i] = '\0';
	return (str1);
}
