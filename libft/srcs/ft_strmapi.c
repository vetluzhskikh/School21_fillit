/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:13:57 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/18 21:16:47 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ns;
	unsigned int	i;

	ns = NULL;
	i = 0;
	if (s)
	{
		if (ft_strlen(s) == __SIZE_T_MAXI__)
			return (NULL);
		ns = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (ns)
		{
			while (s[i] != '\0')
			{
				ns[i] = f(i, s[i]);
				i++;
			}
			ns[i] = '\0';
		}
	}
	return (ns);
}
