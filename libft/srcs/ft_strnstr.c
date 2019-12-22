/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:18:34 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/22 14:50:01 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	lneedle;
	size_t	i;

	i = 0;
	lneedle = ft_strlen(needle);
	if (!needle || *needle == '\0')
		return ((char*)haystack);
	while (*(haystack) != '\0' && lneedle <= len--)
	{
		while (haystack[i] == needle[i] && needle[i] && haystack[i])
			i++;
		if (needle[i] == '\0')
			return ((char*)haystack);
		haystack++;
		i = 0;
	}
	return (NULL);
}
