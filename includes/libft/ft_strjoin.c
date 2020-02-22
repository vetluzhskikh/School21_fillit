/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:38:35 by gnelson           #+#    #+#             */
/*   Updated: 2019/10/23 19:01:36 by nyaacc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	char	*tmp;

	ns = NULL;
	tmp = NULL;
	if (s1 && s2)
	{
		if (ft_strlen(s1) + ft_strlen(s2) == __SIZE_T_MAXI__ ||
		ft_strlen(s2) == __SIZE_T_MAXI__ || ft_strlen(s1) == __SIZE_T_MAXI__)
			return (NULL);
		ns = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (ns)
		{
			tmp = ns;
			while (*s1 != '\0')
				*tmp++ = *s1++;
			while (*s2 != '\0')
				*tmp++ = *s2++;
			*tmp = '\0';
		}
	}
	return (ns);
}
