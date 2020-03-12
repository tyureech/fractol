/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:28:18 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/26 16:40:48 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long long	k;
	int					o;

	i = 0;
	k = 0;
	o = 1;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		o = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + str[i++] - '0';
		if (k > 9223372036854775807 && o == -1)
			return (0);
		if (k >= 9223372036854775807 && o == 1)
			return (-1);
	}
	return (k * o);
}
