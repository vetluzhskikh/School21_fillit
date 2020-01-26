/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:10:46 by gnelson           #+#    #+#             */
/*   Updated: 2020/01/24 16:10:27 by nyaacc           ###   ########.fr       */
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
