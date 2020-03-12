/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:22:52 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/26 18:04:07 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t m;

	i = (ft_strlen((char *)src));
	j = (ft_strlen(dst));
	m = 0;
	if (size <= j)
		return (i + size);
	while (dst[m] && m < size - 1)
		m++;
	while (*src && m < size - 1)
	{
		dst[m] = *src;
		m++;
		src++;
	}
	dst[m] = '\0';
	return (j + i);
}
