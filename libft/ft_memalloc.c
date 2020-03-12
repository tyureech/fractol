/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 00:49:59 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/19 01:28:14 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	p = (void*)malloc(sizeof(p) * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
