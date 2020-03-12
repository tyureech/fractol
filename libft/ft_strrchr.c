/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:17:56 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/22 20:41:17 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *i;

	i = (char *)str + ft_strlen((char*)str);
	while (*i != ch)
	{
		if (i == str)
			return (0);
		i--;
	}
	return (i);
}
