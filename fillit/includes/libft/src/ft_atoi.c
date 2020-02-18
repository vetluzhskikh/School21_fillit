/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:12:42 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/21 14:21:10 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int	nbr;
	int				i;

	nbr = 0;
	i = 1;
	while (ft_isspace(*str) != 0)
		++str;
	if ((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)) != 0)
	{
		if (*str == '-')
			i = -1;
		++str;
	}
	while (ft_isdigit(*str) != 0)
	{
		if (nbr > nbr * 10 && i == -1)
			return (0);
		if (nbr > nbr * 10 && i == 1)
			return (-1);
		nbr = (nbr * 10) + (*str++ - '0');
	}
	return (i * (int)nbr);
}
