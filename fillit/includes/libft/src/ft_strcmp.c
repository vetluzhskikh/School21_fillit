/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:10:46 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/10 21:36:46 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	while (*s1 != '\0')
	{
		if (*((unsigned char*)s1) != *((unsigned char*)s2))
			return (*((unsigned char*)s1) - *((unsigned char*)s2));
		s1++;
		s2++;
	}
	if (*((unsigned char*)s1) != *((unsigned char*)s2))
		return (*((unsigned char*)s1) - *((unsigned char*)s2));
	return (0);
}
