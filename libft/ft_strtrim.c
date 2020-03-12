/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:01:57 by mmahasim          #+#    #+#             */
/*   Updated: 2019/04/24 00:46:21 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		end;
	size_t		len;

	i = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s);
	if (s)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		if (s[i] == '\0')
			return (ft_strnew(0));
		while (i <= end && (s[end - 1] == ' ' ||
					s[end - 1] == '\n' || s[end - 1] == '\t'))
			end--;
		len = end - i;
		if (i > end)
			return (ft_strnew(0));
		else
			return (ft_strsub(s, (unsigned int)i, len));
	}
	return (NULL);
}
