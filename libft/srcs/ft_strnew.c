/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:48:32 by gnelson           #+#    #+#             */
/*   Updated: 2019/10/06 14:59:05 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (size + 1 == 0)
		return (NULL);
	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (i != size + 1)
		str[i++] = '\0';
	return (str);
}
