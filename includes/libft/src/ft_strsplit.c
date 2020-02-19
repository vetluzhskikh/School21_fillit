/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:11:21 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/16 22:44:46 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_getstring(char const *s, char *split, char c, size_t i)
{
	size_t	j;

	j = i;
	while (s[i] != c && s[i] != '\0')
		i++;
	split = ft_strsub(s, j, i - j);
	return (split);
}

static char		**mallocpoi(char **split, char const *s, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		|| (i == 0 && s[i] != c))
			k++;
		i++;
	}
	split = ft_memalloc(sizeof(char**) * (k + 1));
	if (!split)
		return (NULL);
	return (split);
}

static char		*cmon(char *split, char const *s, char c, size_t i)
{
	if (i == 0)
		--i;
	split = ft_getstring(s, split, c, ++i);
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	split = NULL;
	if (s)
	{
		split = mallocpoi(split, s, c);
		if (!split)
			return (NULL);
		while (s[i] != '\0')
		{
			if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			|| (i == 0 && s[i] != c))
			{
				split[k] = cmon(split[k], s, c, i);
				k++;
			}
			i++;
		}
		split[k] = NULL;
	}
	return (split);
}
