/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:46:53 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/14 22:00:03 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	*ft_memccpy(void *s, const void *c, int sim, size_t len)
{
	unsigned char			*s1;
	const unsigned char		*c1;
	unsigned char			sim1;
	size_t					i;

	s1 = s;
	c1 = c;
	sim1 = sim;
	i = 0;
	while (i < len)
	{
		s1[i] = c1[i];
		if (c1[i] == sim1)
			return (s + i + 1);
		i++;
	}
	return (NULL);
}
