/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 01:20:26 by mmahasim          #+#    #+#             */
/*   Updated: 2019/09/30 15:11:46 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_word(char const **s, int *i, char c)
{
	while (**s == c && **s)
		(*s)++;
	while (**s != c && **s)
	{
		(*s)++;
		(*i)++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ch;
	int		j;
	int		len;

	j = 0;
	len = 0;
	if (!s || !c)
		return (NULL);
	if (!(ch = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		len = 0;
		ft_word(&s, &len, c);
		if (*s)
			ch[j++] = ft_strsub(s - len, 0, len);
		if (ft_strsub(s - len, 0, len) == NULL)
			return (ft_del(ch));
	}
	if (len > 0)
		ch[j++] = ft_strsub(s - len, 0, len);
	ch[j] = NULL;
	return (ch);
}
