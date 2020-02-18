/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:16:00 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/05 22:03:26 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n == 0)
		ft_putchar('0');
	if (n < 0 && n != -2147483648)
	{
		ft_putchar('-');
		n = -1 * n;
	}
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = -1 * (n % 1000000000);
	}
	if (n / 10 != 0)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	if (n / 10 == 0 && n != 0)
		ft_putchar(n + '0');
}
