/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:34:02 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/26 18:00:49 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*s;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
