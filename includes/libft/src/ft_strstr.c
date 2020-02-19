/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:47:25 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/10 20:16:35 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	lneedle;

	lneedle = ft_strlen(needle);
	if (!needle || *needle == '\0')
		return ((char*)haystack);
	while (*(haystack) != '\0')
	{
		if (ft_memcmp(haystack, needle, lneedle) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
