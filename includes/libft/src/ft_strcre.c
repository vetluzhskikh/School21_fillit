/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:10:46 by gnelson           #+#    #+#             */
/*   Updated: 2020/02/18 20:54:34 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strcre(char *str, char ch1, char ch2)
{
	unsigned char *ptr;

	ptr = (unsigned char *)str;
	while (*ptr)
	{
		if (*ptr == ch1)
			*ptr = ch2;
		ptr++;
	}
	if (*ptr == ch1)
		*ptr = ch2;
}
