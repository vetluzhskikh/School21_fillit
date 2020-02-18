/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:35:12 by gnelson           #+#    #+#             */
/*   Updated: 2020/01/24 16:12:20 by nyaacc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarr(char **strarr)
{
	size_t i;

	if (strarr)
	{
		i = 0;
		while (strarr[i] != NULL)
		{
			ft_putstr(strarr[i]);
			ft_putchar('\n');
			i++;
		}
	}
}
