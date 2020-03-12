/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:01:21 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/22 21:44:03 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*r;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(r = malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
		return (NULL);
	while (s[i])
	{
		r[i] = f(s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
