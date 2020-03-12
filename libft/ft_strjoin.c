/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:40:59 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/23 17:27:49 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*ch;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ch = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s1)
	{
		ch[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		ch[i] = *s2;
		i++;
		s2++;
	}
	ch[i] = '\0';
	return (ch);
}
