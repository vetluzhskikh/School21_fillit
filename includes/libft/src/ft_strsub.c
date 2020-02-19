/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:25:21 by gnelson           #+#    #+#             */
/*   Updated: 2019/10/23 18:44:05 by nyaacc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	char			*tmp;
	unsigned int	i;

	subs = NULL;
	tmp = NULL;
	i = start;
	if (s)
	{
		if (!(subs = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		if (subs)
		{
			tmp = subs;
			while (i != len + start)
				*tmp++ = s[i++];
			*tmp = '\0';
		}
	}
	return (subs);
}
