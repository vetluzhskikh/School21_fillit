/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:48:32 by gnelson           #+#    #+#             */
/*   Updated: 2020/01/24 20:13:55 by nyaacc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(*str) * (1));
		if (str)
		{
			ft_memset(str, '\0', (1));
			return (str);
		}
	}
	else if (size)
	{
		str = (char *)malloc(sizeof(*str) * (size + 1));
		if (str)
		{
			ft_memset(str, '\0', (size + 1));
			return (str);
		}
	}
	return (NULL);
}
