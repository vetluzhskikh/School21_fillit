/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:09:27 by gnelson           #+#    #+#             */
/*   Updated: 2019/10/26 13:48:46 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*s2;

	size = 0;
	i = 0;
	s2 = NULL;
	size = ft_strlen(s1);
	if (size + 1 == 0)
		return (NULL);
	if (!(s2 = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		((unsigned char*)s2)[i] = s1[i];
		i++;
	}
	return (s2);
}
