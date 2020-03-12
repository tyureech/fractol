/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:24:33 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/24 03:08:50 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ch;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(ch = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && i < len)
	{
		ch[i] = s[start];
		start++;
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
