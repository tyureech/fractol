/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 01:21:53 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/26 16:22:10 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		schet(int n)
{
	int				i;
	unsigned int	res;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		res = n * (-1);
		i++;
	}
	else
		res = n;
	while (res != 0)
	{
		res = res / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*ch;
	int				len;
	unsigned int	res;

	len = schet(n);
	if (!(ch = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0)
		ch[0] = '0';
	if (n < 0)
	{
		ch[0] = '-';
		res = n * (-1);
	}
	else
		res = n;
	ch[len--] = '\0';
	while (res != 0)
	{
		ch[len--] = (res % 10) + '0';
		res = res / 10;
	}
	return (ch);
}
