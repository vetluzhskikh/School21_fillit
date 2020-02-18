/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:02:56 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/18 21:17:19 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ns;
	char	*tmp;

	ns = NULL;
	tmp = NULL;
	if (s)
	{
		if (ft_strlen(s) == __SIZE_T_MAXI__)
			return (NULL);
		ns = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (ns)
		{
			tmp = ns;
			while (*s != '\0')
				*tmp++ = f(*s++);
			*tmp = '\0';
		}
	}
	return (ns);
}
