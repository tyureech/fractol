/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 01:05:31 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/23 16:12:29 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ch;

	ch = (char*)malloc(sizeof(char) * (size + 1));
	if (!ch)
		return (NULL);
	ft_memset(ch, '\0', size + 1);
	return (ch);
}
